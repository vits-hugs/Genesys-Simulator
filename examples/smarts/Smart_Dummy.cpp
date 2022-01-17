/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_Dummy.cpp
 * Author: rlcancian
 * 
 * Created on 3 de Setembro de 2019, 18:34
 */

#include "Smart_Dummy.h"

// you have to included need libs

// GEnSyS Simulator
#include "../../kernel/simulator/Simulator.h"

// Model Components
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Delay.h"
#include "../../plugins/components/Dispose.h"

// Model data definitions
#include "../../kernel/simulator/EntityType.h"

Smart_Dummy::Smart_Dummy() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Smart_Dummy::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	// insert "fake plugins" since plugins based on dynamic loaded library are not implemented yet
	this->insertFakePluginsByHand(genesys);
	// Handle traces and simulation events to output them
	this->setDefaultTraceHandlers(genesys->getTracer());
	Model* model = genesys->getModels()->newModel();
	model->getSimulation()->setReplicationLength(60);
	// create a (Source)ModelDataDefinition of type EntityType, used by a ModelComponent that follows
	EntityType* entityType1 = new EntityType(model, "Type_of_Representative_Entity");
	// create a ModelComponent of type Create, used to insert entities into the model
	Create* create1 = new Create(model);
	create1->setEntityType(entityType1);
	create1->setTimeBetweenCreationsExpression("1.5"); // create one new entity every 1.5 seconds
	// create a ModelComponent of type Delay, used to represent a time delay
	Delay* delay1 = new Delay(model);
	// if nothing else is set, the delay will take 1 second
	// create a (Sink)ModelComponent of type Dispose, used to remove entities from the model
	Dispose* dispose1 = new Dispose(model); // insert the component into the model
	// connect model components to create a "workflow" -- should always start from a SourceModelComponent and end at a SinkModelComponent (it will be checked)
	create1->getConnections()->insert(delay1);
	delay1->getConnections()->insert(dispose1);
	// save the model into a text file
	model->save("./models/Smart_Dummy.gen");
	// execute the simulation util completed and show the report
	model->getSimulation()->start();
	genesys->~Simulator();
	return 0;
};

