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

#include "../../kernel/simulator/Simulator.h"
#include "../../kernel/simulator/Attribute.h"
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Dispose.h"
#include "../../plugins/components/Assign.h"
#include "../../plugins/components/Batch.h"
#include "../../plugins/components/Delay.h"
#include "../../plugins/components/Separate.h"

Smart_BatchSeparate::Smart_BatchSeparate() {
}

int Smart_BatchSeparate::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);
	Model* m = new Model(genesys);
	Create* cr = new Create(m);
	cr->setEntityType(new EntityType(m, "normal"));
	cr->setMaxCreations(50);
	Assign* as = new Assign(m);
	new Attribute(m, "batchNum");
	as->getAssignments()->insert(new Assign::Assignment("batchNum", "trunc(unif(0,5))"));
	Batch* ba = new Batch(m);
	ba->setBatchSize("4");
	ba->setRule(Batch::Rule::ByAttribute);
	ba->setAttributeName("batchNum");
	ba->setGroupedAttributes(Batch::GroupedAttribs::SumAttributes);
	ba->setGroupedEntityType(new EntityType(m, "grouped"));
	Delay* de = new Delay(m);
	de->setDelay(25);
	Separate* se = new Separate(m);
	Dispose* di = new Dispose(m);
	cr->getConnections()->insert(as);
	as->getConnections()->insert(ba);
	ba->getConnections()->insert(de);
	de->getConnections()->insert(se);
	se->getConnections()->insert(di);
	ModelSimulation* sim = m->getSimulation();
	sim->setReplicationLength(100);
	sim->setShowReportsAfterReplication(false);
	sim->setShowReportsAfterSimulation(false);
	m->getTracer()->setTraceLevel(Util::TraceLevel::L7_internal);
	m->getTracer()->setTraceSimulationRuleAllAllowed(false);
	m->getTracer()->addTraceSimulationExceptionRuleModelData(ba);
	m->getTracer()->addTraceSimulationExceptionRuleModelData(se);
	m->getTracer()->addTraceSimulationExceptionRuleModelData(sim);
	m->save("./models/Smart_BatchSeparate.gen");
	sim->start();
	return 0;
}