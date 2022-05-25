/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_HoldSignal.cpp
 * Author: rlcancian
 * 
 * Created on 3 de Setembro de 2019, 18:34
 */

#include "Smart_HoldSignal.h"

// you have to included need libs

// GEnSyS Simulator
#include "../../../../kernel/simulator/Simulator.h"

// Model Components
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/Hold.h"
#include "../../../../plugins/components/Signal.h"
#include "../../../../plugins/components/Dispose.h"

// Model data definitions

Smart_HoldSignal::Smart_HoldSignal() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Smart_HoldSignal::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L9_mostDetailed);
	Model* model = genesys->getModels()->newModel();
	PluginManager* plugins = genesys->getPlugins();
	//
	Create* c1 = plugins->newInstance<Create>(model);
	c1->setTimeBetweenCreationsExpression("unif(1,2)");
	Create* c2 = plugins->newInstance<Create>(model);
	c2->setTimeBetweenCreationsExpression("unif(1,2)");
	Create* c3 = plugins->newInstance<Create>(model);
	c3->setTimeBetweenCreationsExpression("unif(5,6)");
	Hold* h1 = plugins->newInstance<Hold>(model);
	Hold* h2 = plugins->newInstance<Hold>(model);
	Signal* s3 = plugins->newInstance<Signal>(model);
	Dispose* d1 = plugins->newInstance<Dispose>(model);
	//
	c1->getConnections()->insert(h1);
	h1->getConnections()->insert(d1);
	c2->getConnections()->insert(h2);
	h2->getConnections()->insert(d1);
	c3->getConnections()->insert(s3);
	s3->getConnections()->insert(d1);
	//
	model->save("./models/Smart_HoldSignal.gen");
	do {
		model->getSimulation()->step();
		//std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
	} while (model->getSimulation()->isPaused());
	return 0;
};

