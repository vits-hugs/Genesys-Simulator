/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_Process.cpp
 * Author: rlcancian
 * 
 * Created on 3 de Setembro de 2019, 18:34
 */

#include "Smart_Process.h"

// you have to included need libs

// GEnSyS Simulator
#include "../../kernel/simulator/Simulator.h"

// Model Components
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Process.h"
#include "../../plugins/components/Dispose.h"

// Model elements
#include "../../kernel/simulator/EntityType.h"

Smart_Process::Smart_Process() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Smart_Process::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->insertFakePluginsByHand(genesys);
	this->setDefaultTraceHandlers(genesys->getTracer());
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L9_mostDetailed);
	Model* model = genesys->getModels()->newModel();
	Create *create = new Create(model);
	create->setEntityType(new EntityType(model, "Client"));
	create->setTimeBetweenCreationsExpression("1");
	Process* process = new Process(model);
	process->getSeizeRequests()->insert(new SeizableItem(new Resource(model)));
	process->setQueueableItem(new QueueableItem(new Queue(model)));
	process->setDelayExpression("unif(0.8,1.2)");
	Dispose* dispose = new Dispose(model);
	create->getNextComponents()->insert(process);
	process->getNextComponents()->insert(dispose);
	model->getSimulation()->setReplicationLength(10);
	model->save("./models/Smart_Process.txt");
	do {
		model->getSimulation()->step();
		//		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
	} while (model->getSimulation()->isPaused());
	genesys->~Simulator();
	return 0;
};

