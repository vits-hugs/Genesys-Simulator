/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Smart_WaitSignal.cpp
 * Author: rlcancian
 *
 * Created on 3 de Setembro de 2019, 18:34
 */

#include "Smart_WaitSignal.h"

// you have to included need libs

// GEnSyS Simulator
#include "../../../../kernel/simulator/Simulator.h"

// Model Components
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/Wait.h"
#include "../../../../plugins/components/Signal.h"
#include "../../../../plugins/data/SignalData.h"
#include "../../../../plugins/components/Dispose.h"

// Model data definitions

Smart_WaitSignal::Smart_HoldSignal() {
}

/**
 * This is the main function of the application.
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Smart_WaitSignal::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);
	genesys->getTracer()->setTraceLevel(TraceManager::Level::L9_mostDetailed);
	Model* model = genesys->getModels()->newModel();
	PluginManager* plugins = genesys->getPlugins();
	//
	Create* create1 = plugins->newInstance<Create>(model);
	create1->setTimeBetweenCreationsExpression("1");
	Create* create2 = plugins->newInstance<Create>(model);
	create2->setTimeBetweenCreationsExpression("2");
	Create* create3 = plugins->newInstance<Create>(model);
	create3->setTimeBetweenCreationsExpression("5");
	create3->setFirstCreation(5);

	SignalData* sigdata1 = plugins->newInstance<SignalData>(model, "sinalD1");
	SignalData* sigdata2 = plugins->newInstance<SignalData>(model, "sinalD2");
	Wait* hold1 = plugins->newInstance<Wait>(model);
	hold1->setSignalData(sigdata1);
	Wait* hold2 = plugins->newInstance<Wait>(model);
	hold2->setSignalData(sigdata2);
	Signal* signal1 = plugins->newInstance<Signal>(model);
	signal1->setSignalData(sigdata1);
	signal1->setLimitExpression("1e6");
	Dispose* dispose1 = plugins->newInstance<Dispose>(model);
	Dispose* dispose2 = plugins->newInstance<Dispose>(model);
	//
	create1->getConnections()->insert(hold1);
	hold1->getConnections()->insert(dispose1);
	create2->getConnections()->insert(hold2);
	hold2->getConnections()->insert(dispose1);
	create3->getConnections()->insert(signal1);
	signal1->getConnections()->insert(dispose2);
	//
	ModelSimulation* simulation = model->getSimulation();
	simulation->setReplicationLength(20);
	//
	model->getTracer()->setTraceLevel(TraceManager::Level::L8_detailed);
	model->save("./models/Smart_HoldSignal.gen");
	do {
		simulation->start();
		//std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
	} while (simulation->isPaused());
	return 0;
};

