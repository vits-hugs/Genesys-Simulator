/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Smart_CppForG.cpp
 * Author: rlcancian
 * 
 * Created on 11 de janeiro de 2022, 22:39
 */

#include "Smart_CppForG.h"

#include "../../../../kernel/simulator/Simulator.h"
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/CppForG.h"
#include "../../../../plugins/components/Dispose.h"
#include "../../../../kernel/simulator/ModelSimulation.h"

Smart_CppForG::Smart_CppForG() {
}

int Smart_CppForG::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);
	genesys->getTracer()->setTraceLevel(TraceManager::Level::L9_mostDetailed);
	// crete model
	Model* m = genesys->getModels()->newModel();
	PluginManager* plugins = genesys->getPlugins();
	Create* cr = plugins->newInstance<Create>(m);
	CppForG* sc = plugins->newInstance<CppForG>(m);
	Dispose* di = plugins->newInstance<Dispose>(m);
	// connect model components to create a "workflow"
	cr->getConnections()->insert(sc);
	sc->getConnections()->insert(di);
	// set options, save and simulate
	ModelSimulation* s = m->getSimulation();
	s->setReplicationLength(10);
	s->setShowReportsAfterReplication(false);
	s->setShowReportsAfterSimulation(false);
	m->save("./models/Smart_SourceCode.gen");
	s->start();
	delete genesys;
	return 0;
}

