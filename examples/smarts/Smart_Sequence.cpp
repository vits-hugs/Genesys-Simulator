/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_Sequence.cpp
 * Author: rlcancian
 * 
 * Created on 12 de março de 2021, 15:39
 */

#include "Smart_Sequence.h"

#include "../../kernel/simulator/Simulator.h"

#include "../../plugins/components/Create.h"
#include "../../plugins/components/Route.h"
#include "../../plugins/components/Enter.h"
#include "../../plugins/components/Leave.h"
#include "../../plugins/components/Dispose.h"
#include "../../plugins/components/Delay.h"
#include "../../plugins/components/Assign.h"

#include "../../plugins/elements/Sequence.h"
#include "../../plugins/elements/Station.h"
#include "../../kernel/simulator/EntityType.h"

Smart_Sequence::Smart_Sequence() {
}

int Smart_Sequence::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->insertFakePluginsByHand(genesys);
	this->setDefaultTraceHandlers(genesys->getTracer());
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L6_arrival);
	//genesys->getModels()->loadModel("./models/Smart_StatationRouteSequence.gen");
	//genesys->getModels()->current()->getSimulation()->start();
	//return;
	Model* m = genesys->getModels()->newModel();
	m->getSimulation()->setReplicationLength(60);
	Create* c1 = new Create(m);
	c1->setEntityType(new EntityType(m));
	c1->setTimeBetweenCreationsExpression("10");
	Station* s1 = new Station(m);
	Route* r0 = new Route(m);
	r0->setRouteDestinationType(Route::DestinationType::BySequence); //(Route::DestinationType::Station);
	//r0->setStation(s1);
	r0->setRouteTimeExpression("0.1");
	Enter* e1 = new Enter(m);
	e1->setStation(s1);
	Delay* d1 = new Delay(m);
	Station* s2 = new Station(m);
	Leave* l1 = new Leave(m);
	l1->setStation(s1);
	Route* r1 = new Route(m);
	r1->setRouteDestinationType(Route::DestinationType::BySequence); //(Route::DestinationType::Station);
	//r1->setStation(s2);
	r1->setRouteTimeExpression("0.2");
	Enter* e2 = new Enter(m);
	e2->setStation(s2);
	Delay* d2 = new Delay(m);
	d2->setDelayExpression("2");
	Leave* l2 = new Leave(m);
	l2->setStation(s2);
	Station* s3 = new Station(m);
	Route* r2 = new Route(m);
	r2->setRouteDestinationType(Route::DestinationType::BySequence); //(Route::DestinationType::Station);
	//r2->setStation(s3);
	r2->setRouteTimeExpression("0.3");
	Enter* e3 = new Enter(m);
	e3->setStation(s3);
	Dispose* dp1 = new Dispose(m);

	Sequence* seq = new Sequence(m);
	seq->getSteps()->insert(new SequenceStep(s1));
	seq->getSteps()->insert(new SequenceStep(s2));
	seq->getSteps()->insert(new SequenceStep(s1));
	seq->getSteps()->insert(new SequenceStep(s1));
	seq->getSteps()->insert(new SequenceStep(s3));

	Assign* a1 = new Assign(m);
	a1->getAssignments()->insert(new Assign::Assignment("Entity.Sequence", std::to_string(seq->getId())));

	c1->getConnections()->insert(a1);
	a1->getConnections()->insert(r0);
	e1->getConnections()->insert(d1);
	d1->getConnections()->insert(l1);
	l1->getConnections()->insert(r1);
	e2->getConnections()->insert(d2);
	d2->getConnections()->insert(l2);
	l2->getConnections()->insert(r2);
	e3->getConnections()->insert(dp1);

	ModelSimulation* sim = m->getSimulation();
	sim->getBreakpointsOnComponent()->insert(a1);
	sim->getBreakpointsOnComponent()->insert(l2);
	sim->getBreakpointsOnTime()->insert(40.0);
	sim->getBreakpointsOnTime()->insert(20.0);
	sim->setShowReportsAfterReplication(false);
	sim->setShowReportsAfterSimulation(false);

	m->save("./models/Smart_Sequence.gen");

	do {
		sim->start();
	} while (sim->isPaused());
	return 0;
}