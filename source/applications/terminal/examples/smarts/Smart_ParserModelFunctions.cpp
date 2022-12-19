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
#include "../../../../kernel/simulator/Simulator.h"

// Model Components
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/Process.h"
#include "../../../../plugins/components/Write.h"
#include "../../../../plugins/components/Dispose.h"
#include "../../../../plugins/data/Set.h"
#include "../../../../plugins/data/Formula.h"

// Model data definitions
#include "../../../../kernel/simulator/Attribute.h"

Smart_ParserModelFunctions::Smart_ParserModelFunctions() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Smart_ParserModelFunctions::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);
	// create model
	Model* m = genesys->getModels()->newModel();
	PluginManager* plugins = genesys->getPlugins();
	Create* c1 = plugins->newInstance<Create>(m);
	plugins->newInstance<Attribute>(m, "att1");
	Set* s = plugins->newInstance<Set>(m);
	s->getElementSet()->insert(plugins->newInstance<Resource>(m));
	s->getElementSet()->insert(plugins->newInstance<Resource>(m));
	s->setSetOfType("Resource");
	Process* p1 = plugins->newInstance<Process>(m);
	p1->getSeizeRequests()->insert(new SeizableItem(s, "1", SeizableItem::SelectionRule::LARGESTREMAININGCAPACITY, "saveAttribute"));
	p1->setQueueableItem(new QueueableItem(plugins->newInstance<Queue>(m)));
	Dispose* d1 = plugins->newInstance<Dispose>(m);
	// other part to write parser expressions 
	Formula* formula1 = plugins->newInstance<Formula>(m, "FormulaChegada");
	formula1->setExpression("NORM(10,1)", "1,1");
	formula1->setExpression("EXP(10)", "1,2");
	formula1->setExpression("TRIA(8,10,12)", "2,1");
	formula1->setExpression("UNIF(8,12)", "2,2");
	Create * c2 = plugins->newInstance<Create>(m);
	c2->setEntityTypeName("control"); //(plugins->newInstance<EntityType>(m, "control"));
	c2->setTimeBetweenCreationsExpression("FormulaChegada[2,1]");

	Write* w = plugins->newInstance<Write>(m);
	Dispose* d2 = plugins->newInstance<Dispose>(m);
	// connect model components to create a "workflow"
	c1->getConnections()->insert(p1);
	p1->getConnections()->insert(d1);
	c2->getConnections()->insert(w);
	w->getConnections()->insert(d2);
	// insert several "run-time" expressions to be interpreted by the parser
	w->insertText({"Simulation TNOW=", "@tnow", ", ", "@tfin", ", ", "@maxrep", ", ", "@numrep", ", ", "@ident"});
	w->insertText({"Resouce_2 NR=", "@nr(Resource_2)", ", MR=", "@mr(Resource_2)", ", STATE=", "@state(Resource_2)"}); //, ", RESSEIZES=", "@ressizes(Resource_2)"});
	w->insertText({"Queue_1 NQ=", "@nq(Queue_1)", ", FIRSTINQ=", "@firstinq(Queue_1)", ", LASTINQ=", "@lastinq(Queue_1)", ", SAQUE=", "@saque(Queue_1, att1)"});
	w->insertText({"Set_1 NUMSET=", "@numset(Set_1)"});
	w->insertText({"StatCollector TAVG=", "@tavg(entitytype.TotalTimeInSystem)"});
	w->insertText({"Resource.Counter COUNT=", "@count(Resource_1.CountNumberIn)"});
	w->insertText({"Dispose.Counter COUNT=", "@count(Dispose_1.Seizes)"});
	w->insertText({"----------------", "\n"});
	// set options, save and simulate
	m->getSimulation()->setReplicationLength(5);
	m->getSimulation()->setShowReportsAfterReplication(false);
	m->getSimulation()->setShowReportsAfterSimulation(false);
	genesys->getTracer()->setTraceLevel(TraceManager::Level::L9_mostDetailed);
	m->check();
	genesys->getTracer()->setTraceLevel(TraceManager::Level::L4_warning);
	m->getSimulation()->start();
	delete genesys;
	return 0;

	/*
	write1->getWrites()->insert(new WritelnText(""));
	write1->getWrites()->insert(new WriteText("Atributo index: "));
	write1->getWrites()->insert(new WritelnExpression("index"));
	write1->getWrites()->insert(new WriteText("Variável nextIndex: "));
	write1->getWrites()->insert(new WritelnExpression("varNextIndex"));
	write1->getWrites()->insert(new WriteText("Quantidade ocupada das máquinas: "));
	write1->getWrites()->insert(new WriteExpression("NR( Machine_1 )"));
	write1->getWrites()->insert(new WriteText(", "));
	write1->getWrites()->insert(new WriteExpression("NR(Machine_2)"));
	write1->getWrites()->insert(new WriteText(", "));
	write1->getWrites()->insert(new WritelnExpression("NR(Machine_3)"));
	write1->getWrites()->insert(new WriteText("Estado das máquinas: "));
	write1->getWrites()->insert(new WriteExpression("STATE(Machine_1)"));
	write1->getWrites()->insert(new WriteText(", "));
	write1->getWrites()->insert(new WriteExpression("STATE(Machine_2)"));
	write1->getWrites()->insert(new WriteText(", "));
	write1->getWrites()->insert(new WritelnExpression("STATE(Machine_3)"));
	write1->getWrites()->insert(new WriteText("Quantidade de máquinas ocupadas no Set: "));
	write1->getWrites()->insert(new WritelnExpression("SETSUM(Machine_Set)"));
	write1->getWrites()->insert(new WriteText("Quantidade de entidades na fila 3: "));
	write1->getWrites()->insert(new WritelnExpression("NQ(Queue_Seize_3)"));
	write1->getWrites()->insert(new WriteText("Somatório do atributo 'index' das entidades na fila 3: "));
	write1->getWrites()->insert(new WritelnExpression("SAQUE(Queue_Seize_3,index)"));
	write1->getWrites()->insert(new WriteText("Valor do atributo 'index' da 2ª entidade na fila 3: "));
	write1->getWrites()->insert(new WritelnExpression("AQUE(Queue_Seize_3,2,index)"));
	write1->getWrites()->insert(new WriteText("Tempo médio das entidades na fila 3: "));
	write1->getWrites()->insert(new WritelnExpression("TAVG(Queue_Seize_3.TimeInQueue)"));
	 */

};

