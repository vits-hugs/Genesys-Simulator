/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_AssignWriteSeizes.cpp
 * Author: rlcancian
 * 
 * Created on 24 de Setembro de 2019, 20:56
 */

#include "Smart_AssignWriteSeizes.h"

// GEnSyS Simulator
#include "../../kernel/simulator/Simulator.h"

// Model Components
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Delay.h"
#include "../../plugins/components/Dispose.h"
#include "../../plugins/components/Seize.h"
#include "../../plugins/components/Release.h"
#include "../../plugins/components/Assign.h"
#include "../../plugins/components/Record.h"
#include "../../plugins/components/Decide.h"
#include "../../plugins/components/Write.h"

// Model data definitions
#include "../../kernel/simulator/ModelDataManager.h"
#include "../../kernel/simulator/EntityType.h"
#include "../../kernel/simulator/Attribute.h"
#include "../../plugins/data/Variable.h"
#include "../../plugins/data/EntityGroup.h"
#include "../../plugins/data/Set.h"

Smart_AssignWriteSeizes::Smart_AssignWriteSeizes() {
}

int Smart_AssignWriteSeizes::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L2_results); //modelResult); //componentArrival);
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);

	Model* model = genesys->getModels()->newModel();
	ModelSimulation* sim = model->getSimulation();
	sim->setNumberOfReplications(5);
	sim->setReplicationLength(100);
	PluginManager* plugins = genesys->getPlugins();
	EntityType* part = plugins->newInstance<EntityType>(model, "Part");
	Create* create1 = plugins->newInstance<Create>(model);
	create1->setEntityType(part);
	create1->setTimeBetweenCreationsExpression("norm(1.5,0.5)");
	create1->setTimeUnit(Util::TimeUnit::second);
	create1->setEntitiesPerCreation(1);
	Assign* assign1 = plugins->newInstance<Assign>(model);
	assign1->getAssignments()->insert(new Assign::Assignment("varNextIndex", "varNextIndex + 1"));
	assign1->getAssignments()->insert(new Assign::Assignment("index", "varNextIndex"));
	Attribute* attr1 = plugins->newInstance<Attribute>(model, "index");
	Variable* var1 = plugins->newInstance<Variable>(model, "varNextIndex");
	Write* write1 = plugins->newInstance<Write>(model);
	write1->setWriteToType(Write::WriteToType::SCREEN);
	write1->insertText({"\n", "Atributo index: ", "'index'"});
	write1->insertText({"Variável nextIndex: ", "'varNextIndex'"});
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
	//
	Resource* machine1 = plugins->newInstance<Resource>(model, "Machine_1");
	machine1->setCapacity(1);
	Resource* machine2 = plugins->newInstance<Resource>(model, "Machine_2");
	machine2->setCapacity(2);
	Resource* machine3 = plugins->newInstance<Resource>(model, "Machine_3");
	machine3->setCapacity(3);
	Set* machSet = plugins->newInstance<Set>(model, "Machine_Set");
	machSet->setSetOfType(Util::TypeOf<Resource>());
	machSet->getElementSet()->insert(machine1);
	machSet->getElementSet()->insert(machine2);
	machSet->getElementSet()->insert(machine3);
	Decide* decide1 = plugins->newInstance<Decide>(model);
	decide1->getConditions()->insert("NR(Machine_1) < MR(Machine_1)");
	decide1->getConditions()->insert("NR(Machine_2) < MR(Machine_2)");
	Queue* queueSeize1 = plugins->newInstance<Queue>(model, "Queue_Seize_1");
	queueSeize1->setOrderRule(Queue::OrderRule::FIFO);
	Seize* seize1 = plugins->newInstance<Seize>(model);
	seize1->getSeizeRequests()->insert(new SeizableItem(machine1));
	seize1->setQueue(queueSeize1);
	Delay* delay1 = plugins->newInstance<Delay>(model);
	delay1->setDelayExpression("norm(15,1)");
	delay1->setDelayTimeUnit(Util::TimeUnit::second);
	Release* release1 = plugins->newInstance<Release>(model);
	release1->getReleaseRequests()->insert(new SeizableItem(machine1));
	Queue* queueSeize2 = plugins->newInstance<Queue>(model, "Queue_Seize_2");
	queueSeize2->setOrderRule(Queue::OrderRule::FIFO);
	Seize* seize2 = plugins->newInstance<Seize>(model);
	seize2->getSeizeRequests()->insert(new SeizableItem(machine2));
	seize2->setQueue(queueSeize2);
	Delay* delay2 = plugins->newInstance<Delay>(model);
	delay2->setDelayExpression("norm(15,1)");
	delay2->setDelayTimeUnit(Util::TimeUnit::second);
	Release* release2 = plugins->newInstance<Release>(model);
	release2->getReleaseRequests()->insert(new SeizableItem(machine2));
	Queue* queueSeize3 = plugins->newInstance<Queue>(model, "Queue_Seize_3");
	queueSeize3->setOrderRule(Queue::OrderRule::FIFO);
	Seize* seize3 = plugins->newInstance<Seize>(model);
	seize3->getSeizeRequests()->insert(new SeizableItem(machine3));
	seize3->setQueue(queueSeize3);
	Delay* delay3 = plugins->newInstance<Delay>(model);
	delay3->setDelayExpression("norm(15,1)");
	delay3->setDelayTimeUnit(Util::TimeUnit::second);
	Release* release3 = plugins->newInstance<Release>(model);
	release3->getReleaseRequests()->insert(new SeizableItem(machine3));
	Dispose* dispose1 = plugins->newInstance<Dispose>(model);
	//
	create1->getConnections()->insert(assign1);
	assign1->getConnections()->insert(write1);
	write1->getConnections()->insert(decide1);
	decide1->getConnections()->insert(seize1);
	decide1->getConnections()->insert(seize2);
	decide1->getConnections()->insert(seize3);
	seize1->getConnections()->insert(delay1);
	delay1->getConnections()->insert(release1);
	release1->getConnections()->insert(dispose1);
	seize2->getConnections()->insert(delay2);
	delay2->getConnections()->insert(release2);
	release2->getConnections()->insert(dispose1);
	seize3->getConnections()->insert(delay3);
	delay3->getConnections()->insert(release3);
	release3->getConnections()->insert(dispose1);
	//
	model->save("./models/Smart_StatationRouteSequence.gen");
	sim->start();
	return 0;
}

