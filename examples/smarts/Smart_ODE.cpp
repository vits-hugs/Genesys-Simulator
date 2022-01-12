/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Smart_ODE.cpp
 * Author: rlcancian
 * 
 * Created on 11 de janeiro de 2022, 19:29
 */

#include "Smart_ODE.h"

#include "../../kernel/simulator/Simulator.h"
#include "../../plugins/components/Create.h"
#include "../../plugins/components/LSODE.h"
#include "../../plugins/components/Dispose.h"
#include "../../plugins/elements/Variable.h"

Smart_ODE::Smart_ODE() {
}

int Smart_ODE::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->insertFakePluginsByHand(genesys);
	this->setDefaultTraceHandlers(genesys->getTracer());
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L5_event);
	Model* model = genesys->getModels()->newModel();
	Create* create1 = new Create(model);
	create1->setEntityType(new EntityType(model));
	create1->setTimeBetweenCreationsExpression("0.5");
	Variable* varx = new Variable(model, "x");
	varx->getDimensionSizes()->insert(2);
	varx->setInitialValue("0", 1.0);
	varx->setInitialValue("1", 0.0);
	Variable* vart = new Variable(model, "t");
	LSODE* ode1 = new LSODE(model);
	ode1->setVariable(varx);
	ode1->setTimeVariable(vart);
	ode1->getDiffEquations()->insert("x[1]");
	ode1->getDiffEquations()->insert("x[0] + exp(t)");
	ode1->setStep(0.1);
	//ode1->se
	Dispose* dispose1 = new Dispose(model);
	create1->getConnections()->insert(ode1);
	ode1->getConnections()->insert(dispose1);
	model->getSimulation()->setReplicationLength(2.0);
	model->getSimulation()->setShowReportsAfterReplication(false);
	model->getSimulation()->setShowReportsAfterSimulation(false);
	model->save("./models/Smart_ODE.txt");
	model->getSimulation()->start();
	genesys->~Simulator();
	return 0;

}
