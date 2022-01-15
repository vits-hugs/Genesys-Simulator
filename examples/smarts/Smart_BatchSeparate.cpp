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
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Dispose.h"
#include "../../plugins/components/Batch.h"
#include "../../plugins/components/Separate.h"

Smart_BatchSeparate::Smart_BatchSeparate() {
}

int Smart_BatchSeparate::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);
	Model* m = new Model(genesys);
	Create* cr = new Create(m);
	cr->setEntityType(new EntityType(m));
	Batch* ba = new Batch(m);
	Separate* se = new Separate(m);
	Dispose* di = new Dispose(m);
	cr->getConnections()->insert(ba);
	ba->getConnections()->insert(se);
	se->getConnections()->insert(di);
	ModelSimulation* sim = m->getSimulation();
	sim->setReplicationLength(10);
	m->save("./models/Smart_BatchSeparate.gen");
	sim->start();
}