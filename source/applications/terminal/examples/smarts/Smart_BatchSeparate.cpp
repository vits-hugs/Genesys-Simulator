/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Smart_BatchSeparate.cpp
 * Author: rlcancian
 * 
 * Created on 15 de janeiro de 2022, 09:51
 */

#include "Smart_BatchSeparate.h"

#include "../../../../kernel/simulator/Simulator.h"
#include "../../../../kernel/simulator/Attribute.h"
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/Dispose.h"
#include "../../../../plugins/components/Assign.h"
#include "../../../../plugins/components/Batch.h"
#include "../../../../plugins/components/Delay.h"
#include "../../../../plugins/components/Separate.h"

Smart_BatchSeparate::Smart_BatchSeparate() {
}

int Smart_BatchSeparate::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);
	// create model
	Model* m = new Model(genesys);
	PluginManager* plugins = genesys->getPlugins();
	Create* cr = plugins->newInstance<Create>(m);
	cr->setEntityTypeName("normal");
	cr->setMaxCreations(50);
	Assign* as = plugins->newInstance<Assign>(m);
	as->getAssignments()->insert(new Assignment(m, "batchNum", "trunc(unif(0,5))"));
	Batch* ba = plugins->newInstance<Batch>(m);
	ba->setBatchSize("4");
	ba->setRule(Batch::Rule::ByAttribute);
	ba->setAttributeName("batchNum");
	ba->setGroupedAttributes(Batch::GroupedAttribs::SumAttributes);
	ba->setGroupedEntityTypeName("grouped");
	Delay* de = plugins->newInstance<Delay>(m);
	de->setDelay(25);
	Separate* se = plugins->newInstance<Separate>(m);
	Dispose* di = plugins->newInstance<Dispose>(m);
	// connect model components to create a "workflow"
	cr->getConnections()->insert(as);
	as->getConnections()->insert(ba);
	ba->getConnections()->insert(de);
	de->getConnections()->insert(se);
	se->getConnections()->insert(di);
	// save, trace specific modules and aimulate
	ModelSimulation* sim = m->getSimulation();
	sim->setReplicationLength(100);
	sim->setShowReportsAfterReplication(false);
	sim->setShowReportsAfterSimulation(false);
	m->getTracer()->setTraceLevel(TraceManager::Level::L7_internal);
	m->getTracer()->setTraceSimulationRuleAllAllowed(false);
	m->getTracer()->addTraceSimulationExceptionRuleModelData(ba);
	m->getTracer()->addTraceSimulationExceptionRuleModelData(se);
	m->getTracer()->addTraceSimulationExceptionRuleModelData(sim);
	m->save("./models/Smart_BatchSeparate.gen");
	sim->start();
	delete genesys;
	return 0;
}