/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_SeizeDelayRelease.cpp
 * Author: rlcancian
 * 
 * Created on 24 de Setembro de 2019, 16:43
 */

#include "Smart_SeizeDelayRelease.h"

// you have to included need libs

// GEnSyS Simulator
#include "../../kernel/simulator/Simulator.h"

// Model Components
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Seize.h"
#include "../../plugins/components/Delay.h"
#include "../../plugins/components/Release.h"
#include "../../plugins/components/Dispose.h"

// Model elements
#include "../../kernel/simulator/EntityType.h"

Smart_SeizeDelayRelease::Smart_SeizeDelayRelease() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Smart_SeizeDelayRelease::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	// Handle traces and simulation events to output them
	// insert plugins
	this->insertFakePluginsByHand(genesys);
	this->setDefaultTraceHandlers(genesys->getTracer());
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L9_mostDetailed);
	Model* model = genesys->getModels()->newModel();
	if (false) {
		// build the simulation model
		// set model infos
		ModelSimulation* sim = model->getSimulation();
		sim->setReplicationLength(120);
		sim->setReplicationLengthTimeUnit(Util::TimeUnit::second);
		sim->setNumberOfReplications(2);
		//
		EntityType* customer = new EntityType(model, "Customer");
		//
		Create* create1 = new Create(model);
		create1->setEntityType(customer);
		create1->setTimeBetweenCreationsExpression("expo(20)");
		create1->setTimeUnit(Util::TimeUnit::second);
		create1->setEntitiesPerCreation(1);
		create1->setFirstCreation(0.0);
		//
		Resource* machine1 = new Resource(model, "Machine_1");
		machine1->setCapacity(1);
		//
		Queue* queueSeize1 = new Queue(model, "Seize_1.Queue");
		queueSeize1->setOrderRule(Queue::OrderRule::FIFO);
		//
		Seize* seize1 = new Seize(model);
		seize1->getSeizeRequests()->insert(new SeizableItem(machine1, "1"));
		seize1->setQueue(queueSeize1);
		//
		Delay* delay1 = new Delay(model);
		delay1->setDelayExpression("unif(15,30)");
		delay1->setDelayTimeUnit(Util::TimeUnit::second);
		//
		Release* release1 = new Release(model);
		release1->getReleaseRequests()->insert(new SeizableItem(machine1, "1"));
		//
		Dispose* dispose1 = new Dispose(model);
		// connect model components to create a "workflow"
		create1->getConnections()->insert(seize1);
		seize1->getConnections()->insert(delay1);
		delay1->getConnections()->insert(release1);
		release1->getConnections()->insert(dispose1);
		// save the model into a text file
		model->save("./models/Smart_SeizeDelayRelease.txt");
		// execute the simulation
		sim->start();
	} else {
		model->load("./models/Smart_SeizeDelayRelease.txt");
		model->show();
		model->getSimulation()->start();
	}

	return 0;
};
