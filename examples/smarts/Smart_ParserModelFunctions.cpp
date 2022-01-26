/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_ParserModelFunctions.cpp
 * Author: rlcancian
 * 
 * Created on 5 de Janeiro de 2022, 07:21
 */

#include "Smart_ParserModelFunctions.h"

// you have to included need libs

// GEnSyS Simulator
#include "../../kernel/simulator/Simulator.h"

// Model Components
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Process.h"
#include "../../plugins/components/Write.h"
#include "../../plugins/components/Dispose.h"
#include "../../plugins/data/Set.h"

// Model data definitions
#include "../../kernel/simulator/EntityType.h"
#include "../../kernel/simulator/Attribute.h"

Smart_ParserModelFunctions::Smart_ParserModelFunctions() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Smart_ParserModelFunctions::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->insertFakePluginsByHand(genesys);
	this->setDefaultTraceHandlers(genesys->getTracer());
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L5_event);
	Model* m = genesys->getModels()->newModel();
	PluginManager* plugins = genesys->getPlugins();
	// simple process model
	Create* c1 = plugins->newInstance<Create>(m);
	c1->setEntityType(plugins->newInstance<EntityType>(m));
	plugins->newInstance<Attribute>(m, "att1");
	Set* s = plugins->newInstance<Set>(m);
	s->getElementSet()->insert(plugins->newInstance<Resource>(m));
	s->getElementSet()->insert(plugins->newInstance<Resource>(m));
	s->setSetOfType("Resource");
	Process* p1 = plugins->newInstance<Process>(m);
	p1->getSeizeRequests()->insert(new SeizableItem(s, "1", SeizableItem::SelectionRule::LARGESTREMAININGCAPACITY, "saveAttribute"));
	p1->setQueueableItem(new QueueableItem(plugins->newInstance<Queue>(m)));
	Dispose* d1 = plugins->newInstance<Dispose>(m);
	c1->getConnections()->insert(p1);
	p1->getConnections()->insert(d1);
	// other part to write parser expressions 
	Create * c2 = plugins->newInstance<Create>(m);
	c2->setEntityType(plugins->newInstance<EntityType>(m, "control"));
	c2->setTimeBetweenCreationsExpression("1");
	Write* w = plugins->newInstance<Write>(m);
	Dispose* d2 = plugins->newInstance<Dispose>(m);
	c2->getConnections()->insert(w);
	w->getConnections()->insert(d2);
	//
	w->insertText({"Simulation TNOW=", "@tnow", ", ", "@tfin", ", ", "@maxrep", ", ", "@numrep", ", ", "@ident"});
	w->insertText({"Resouce_2 NR=", "@nr(Resource_2)", ", MR=", "@mr(Resource_2)", ", STATE=", "@state(Resource_2)"}); //, ", RESSEIZES=", "@ressizes(Resource_2)"});
	w->insertText({"Queue_1 NQ=", "@nq(Queue_1)", ", FIRSTINQ=", "@firstinq(Queue_1)", ", LASTINQ=", "@lastinq(Queue_1)", ", SAQUE=", "@saque(Queue_1, att1)"});
	w->insertText({"Set_1 NUMSET=", "@numset(Set_1)"});
	w->insertText({"StatCollector TAVG=", "@tavg(EntityType_1.TotalTimeInSystem.average)"});
	//
	m->getSimulation()->setReplicationLength(5);
	m->getSimulation()->setShowReportsAfterReplication(false);
	m->getSimulation()->setShowReportsAfterSimulation(false);
	m->getSimulation()->start();
	for (int i = 0; i < 1e6; i++);
	return 0;
};

