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

#include "../../kernel/simulator/Simulator.h"
#include "../../plugins/components/Create.h"
#include "../../plugins/components/CppForG.h"
#include "../../plugins/components/Dispose.h"
#include "../../kernel/simulator/EntityType.h"
#include "../../kernel/simulator/ModelSimulation.h"

Smart_CppForG::Smart_CppForG() {
}

int Smart_CppForG::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->insertFakePluginsByHand(genesys);
	this->setDefaultTraceHandlers(genesys->getTracer());
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L9_mostDetailed);
	Model* m = genesys->getModels()->newModel();
	Create* cr = new Create(m);
	cr->setEntityType(new EntityType(m));
	CppForG* sc = new CppForG(m);
	Dispose* di = new Dispose(m);
	cr->getConnections()->insert(sc);
	sc->getConnections()->insert(di);
	ModelSimulation* s = m->getSimulation();
	s->setReplicationLength(10);
	s->setShowReportsAfterReplication(false);
	s->setShowReportsAfterSimulation(false);
	m->save("./models/Smart_SourceCode.txt");
	s->start();
}

