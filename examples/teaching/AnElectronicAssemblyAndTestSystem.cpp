/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Smart_AnElectronicAssemblyAndTestSystem.cpp
 * Author: rlcancian
 * 
 * Created on 6 de dezembro de 2021, 11:09
 */


#include "AnElectronicAssemblyAndTestSystem.h"
// GEnSyS Simulator
#include "../../kernel/simulator/Simulator.h"
// Model Components
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Delay.h"
#include "../../plugins/components/Dispose.h"
#include "../../plugins/components/Assign.h"
#include "../../plugins/components/Record.h"
#include "../../plugins/components/Seize.h"
#include "../../plugins/components/Release.h"
#include "plugins/components/Decide.h"
// Model elements
#include "../../kernel/simulator/EntityType.h"
#include "../../kernel/simulator/Attribute.h"
#include "../../plugins/components/SeizableItem.h"
#include "../../plugins/components/QueueableItem.h"

AnElectronicAssemblyAndTestSystem::AnElectronicAssemblyAndTestSystem() {
}

int AnElectronicAssemblyAndTestSystem::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->insertFakePluginsByHand(genesys);
	this->setDefaultTraceHandlers(genesys->getTracer());
	Model* model = genesys->getModels()->newModel();
	ModelInfo* infos = model->getInfos();
	infos->setName("An Electronic Assembly And Test System");
	infos->setDescription("Example 4.1 from chapter 4 \"Modeling Basic Operations and Inputs\" of the Book \"...\"");
	model->getTracer()->setTraceLevel(Util::TraceLevel::L9_mostDetailed);
	Create* create1 = new Create(model, "Part A Arrive");
	Create* create2 = new Create(model, "Part B Arrive");
	Assign* assign1 = new Assign(model, "Assign Part A Sealer and Arrivel Time");
	Assign* assign2 = new Assign(model, "Assign Part B Sealer and Arrivel Time");
	Seize* seize1 = new Seize(model, "Prep A Process Seize");
	Delay* delay1 = new Delay(model, "Prep A Process Delay");
	Release* release1 = new Release(model, "Prep A Process Relase");
	Seize* seize2 = new Seize(model, "Prep B Process Seize");
	Delay* delay2 = new Delay(model, "Prep B Process Delay");
	Release* release2 = new Release(model, "Prep B Process Releese");
	Seize* seize3 = new Seize(model, "Sealer Seize");
	Delay* delay3 = new Delay(model, "Sealer Delay");
	Release* release3 = new Release(model, "Sealer Release");
	Seize* seize4 = new Seize(model, "Rework Seize");
	Delay* delay4 = new Delay(model, "Rework Delay");
	Release* release4 = new Release(model, "Rework Release");
	Decide* decide1 = new Decide(model, "Failed Sealer Inspector");
	Decide* decide2 = new Decide(model, "Failed Rework Inspection");
	Record* record1 = new Record(model, "Record Screpped Parts");
	Record* record2 = new Record(model, "Record Salvaged Parts");
	Record* record3 = new Record(model, "Recorded Shipped Parts");
	Dispose* dispose1 = new Dispose(model, "Scrapped");
	Dispose* dispose2 = new Dispose(model, "Salvaged");
	Dispose* dispose3 = new Dispose(model, "Shipped");
	// connecting the components
	create1->getConnections()->insert(assign1);
	assign1->getConnections()->insert(seize1);
	seize1->getConnections()->insert(delay1);
	delay1->getConnections()->insert(release1);
	release1->getConnections()->insert(seize3);
	seize3->getConnections()->insert(delay3);
	delay3->getConnections()->insert(release3);
	release3->getConnections()->insert(decide1);
	create2->getConnections()->insert(assign2);
	assign2->getConnections()->insert(seize2);
	seize2->getConnections()->insert(delay2);
	delay2->getConnections()->insert(release2);
	release2->getConnections()->insert(seize3);
	decide1->getConnections()->insert(seize4);
	seize4->getConnections()->insert(delay4);
	delay4->getConnections()->insert(release4);
	release4->getConnections()->insert(decide2);
	decide2->getConnections()->insert(record1);
	record1->getConnections()->insert(dispose1);
	decide2->getConnections()->insert(record2);
	record2->getConnections()->insert(dispose2);
	decide1->getConnections()->insert(record3);
	record3->getConnections()->insert(dispose3);
	// creating all ModelDatas and filling all components attributes
	EntityType* partA = new EntityType(model, "Part_A");
	create1->setEntityType(partA);
	create1->setTimeBetweenCreationsExpression("expo(5)");
	create1->setTimeUnit(Util::TimeUnit::minute);
	EntityType* partB = new EntityType(model, "Part_B");
	create2->setEntityType(partB);
	create2->setTimeBetweenCreationsExpression("expo(30)");
	create2->setTimeUnit(Util::TimeUnit::minute);
	new Attribute(model, "Sealer_Time"); // NOT SAVED IN FILE!!
	new Attribute(model, "Arrive_Time");
	assign1->getAssignments()->insert(new Assign::Assignment("Sealer_Time", "tria(1,3,4)"));
	assign1->getAssignments()->insert(new Assign::Assignment("Arrive_Time", "tnow"));
	assign2->getAssignments()->insert(new Assign::Assignment("Sealer_Time", "weib(2.5, 5.3)"));
	assign2->getAssignments()->insert(new Assign::Assignment("Arrive_Time", "tnow"));
	Resource* prepA = new Resource(model, "PrepA");
	Queue* queuePrepA = new Queue(model, "QueuePrepA");
	seize1->getSeizeRequests()->insert(new SeizableItem(prepA, "1"));
	seize1->setQueueableItem(new QueueableItem(queuePrepA));
	delay1->setDelayExpression("tria(1,4,8)");
	delay1->setDelayTimeUnit(Util::TimeUnit::minute);
	release1->getReleaseRequests()->insert(new SeizableItem(prepA, "1"));
	Resource* prepB = new Resource(model, "PrepB");
	Queue* queuePrepB = new Queue(model, "QueuePrepB");
	seize2->getSeizeRequests()->insert(new SeizableItem(prepB, "1"));
	seize2->setQueueableItem(new QueueableItem(queuePrepB));
	delay2->setDelayExpression("tria(3,5,10)");
	delay2->setDelayTimeUnit(Util::TimeUnit::minute);
	release2->getReleaseRequests()->insert(new SeizableItem(prepB, "1"));
	Resource* sealer = new Resource(model, "Sealer");
	Queue* queueSealer = new Queue(model, "QueueSealer");
	seize3->getSeizeRequests()->insert(new SeizableItem(sealer, "1"));
	seize3->setQueueableItem(new QueueableItem(queueSealer));
	delay3->setDelayExpression("Sealer_Time");
	delay3->setDelayTimeUnit(Util::TimeUnit::minute);
	release3->getReleaseRequests()->insert(new SeizableItem(sealer, "1"));
	decide1->getConditions()->insert("unif(0,1)<0.09");
	Resource* rework = new Resource(model, "Rework");
	Queue* queueRework = new Queue(model, "QueueRework");
	seize4->getSeizeRequests()->insert(new SeizableItem(rework, "1"));
	seize4->setQueueableItem(new QueueableItem(queueRework));
	delay4->setDelayExpression("45");
	delay4->setDelayTimeUnit(Util::TimeUnit::minute);
	release4->getReleaseRequests()->insert(new SeizableItem(rework, "1"));
	decide2->getConditions()->insert("unif(0,1)<0.20");
	record1->setExpression("tnow - Arrive_Time");
	record1->setExpressionName("Scrapped Parts Total Time");
	record2->setExpression("tnow - Arrive_Time");
	record2->setExpressionName("Salvaged Parts Total Time");
	record3->setExpression("tnow - Arrive_Time");
	record3->setExpressionName("Shipped Parts Total Time");
	//setting model information
	model->getInfos()->setName("An Electronic Assembly and Test System");
	model->getInfos()->setDescription("B14 Chap 04 Modeling Basic Operations ans Inputs. Example section 4.1");
	//setting simulation parameters
	ModelSimulation* sim = model->getSimulation();
	sim->setReplicationLength(8);
	sim->setReplicationLengthTimeUnit(Util::TimeUnit::hour);
	sim->setWarmUpPeriod(1);
	sim->setWarmUpPeriodTimeUnit(Util::TimeUnit::hour);
	sim->setReplicationReportBaseTimeUnit(Util::TimeUnit::minute);
	//save the model
	model->save("./models/Smart_AnElectronicAssemblyAndTestSystem.gen");
	//simulating the model
	sim->start();
	return 0;
}