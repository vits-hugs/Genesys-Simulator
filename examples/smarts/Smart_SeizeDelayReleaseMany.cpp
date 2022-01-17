/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_SeizeDelayReleaseMany.cpp
 * Author: rlcancian
 * 
 * Created on 9 de abril de 2021, 18:09
 */

#include "Smart_SeizeDelayReleaseMany.h"

// you have to included need libs

// GEnSyS Simulator
#include "../../kernel/simulator/Simulator.h"

// Model Components
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Seize.h"
#include "../../plugins/components/Delay.h"
#include "../../plugins/components/Release.h"
#include "../../plugins/components/Dispose.h"

// Model data definitions
#include "../../kernel/simulator/EntityType.h"

Smart_SeizeDelayReleaseMany::Smart_SeizeDelayReleaseMany() {
}

/**
 * This is the main function of the application.
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Smart_SeizeDelayReleaseMany::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->insertFakePluginsByHand(genesys);
	this->setDefaultTraceHandlers(genesys->getTracer());
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L9_mostDetailed);
	Model* m = genesys->getModels()->newModel();
	//m->load("./models/Smart_SeizeDelayReleaseMany.gen");
	//genesys->getModels()->current()->getSimulation()->start();
	//return 0;

	EntityType* customer = new EntityType(m, "Customer");
	Create* create1 = new Create(m);
	create1->setEntityType(customer);
	create1->setTimeBetweenCreationsExpression("1");
	Resource* machine1 = new Resource(m);
	Resource* machine2 = new Resource(m);
	Resource* machine3 = new Resource(m);
	Resource* machine4 = new Resource(m);
	Resource* machine5 = new Resource(m);
	Queue* queueSeize1 = new Queue(m);
	queueSeize1->setOrderRule(Queue::OrderRule::FIFO);
	Seize* seize1 = new Seize(m);
	seize1->getSeizeRequests()->insert(new SeizableItem(machine1));
	seize1->getSeizeRequests()->insert(new SeizableItem(machine2));
	seize1->getSeizeRequests()->insert(new SeizableItem(machine3));
	seize1->getSeizeRequests()->insert(new SeizableItem(machine4));
	seize1->getSeizeRequests()->insert(new SeizableItem(machine5));
	seize1->setQueue(queueSeize1);
	Delay* delay1 = new Delay(m);
	delay1->setDelayExpression("unif(0.8,1.2)");
	Release* release1 = new Release(m);
	release1->getReleaseRequests()->insert(new SeizableItem(machine1));
	release1->getReleaseRequests()->insert(new SeizableItem(machine2));
	release1->getReleaseRequests()->insert(new SeizableItem(machine3));
	release1->getReleaseRequests()->insert(new SeizableItem(machine4));
	release1->getReleaseRequests()->insert(new SeizableItem(machine5));
	Dispose* dispose1 = new Dispose(m);
	// connect model components to create a "workflow"
	create1->getConnections()->insert(seize1);
	seize1->getConnections()->insert(delay1);
	delay1->getConnections()->insert(release1);
	release1->getConnections()->insert(dispose1);
	// save the model into a text file
	ModelSimulation* sim = m->getSimulation();
	sim->setReplicationLength(10);
	sim->setNumberOfReplications(3);
	m->save("./models/Smart_SeizeDelayReleaseMany.gen");
	//sim->start();

	do {
		sim->step();
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
	} while (sim->isPaused());
	return 0;
};
