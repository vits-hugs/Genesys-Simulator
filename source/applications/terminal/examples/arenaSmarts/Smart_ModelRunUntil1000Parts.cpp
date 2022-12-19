/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_ModelRunUntil1000Parts.cpp
 * Author: guifrrs and LuizValdiero
 * 
 * Created on December 10, 2022, 8:04 PM
 */

#include "./Smart_ModelRunUntil1000Parts.h"

// Including the GEnSys Simulator
#include "../../../../kernel/simulator/Simulator.h"

// Components for the model
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/Dispose.h"
#include "../../../../plugins/components/Record.h"
#include "../../../../plugins/components/Process.h"
#include "../../../../plugins/components/Assign.h"

#include "../../../../plugins/data/Variable.h"
#include "../../../../kernel/simulator/Attribute.h"


Smart_ModelRunUntil1000Parts::Smart_ModelRunUntil1000Parts() {

}

/**
 * This is the main function of the application. 
 * It create a new simulator instance, 
 * builds a simulation model and 
 * then simulate that model.
*/
int Smart_ModelRunUntil1000Parts::main(int argc, char** argv) {
    // Create a new simulator instance.
    Simulator* genesys = new Simulator();
    this->setDefaultTraceHandlers(genesys->getTracer());
    this->insertFakePluginsByHand(genesys);

    bool isDevelop = false;    

    if (isDevelop) {
        genesys->getTracer()->setTraceLevel(TraceManager::Level::L9_mostDetailed);
    } else {
        genesys->getTracer()->setTraceLevel(TraceManager::Level::L2_results);
    }

    // Create the model and components instances.
    Model* model = genesys->getModels()->newModel();
    PluginManager* plugins = genesys->getPlugins();

    Create* create_1 = plugins->newInstance<Create>(model, "Create_1");
    Process* process_1 = plugins->newInstance<Process>(model, "Process_1");
    Record* record_1 = plugins->newInstance<Record>(model, "Record_1");
    Dispose* dispose_1 = plugins->newInstance<Dispose>(model, "Dispose_1");

    // Create 1
    create_1->getConnections()->insert(process_1);
    create_1->setEntityTypeName("Entity 1");
    create_1->setTimeBetweenCreationsExpression("EXPO(8)");
    create_1->setTimeUnit(Util::TimeUnit::minute);
    create_1->setEntitiesPerCreation(1);
    create_1->setFirstCreation(0.0);

    // Process 1
    process_1->getConnections()->insert(record_1);
    process_1->setDelayExpression("TRIA(4, 8, 10)");
    process_1->setDelayTimeUnit(Util::TimeUnit::minute);

    Resource* resource_1 = plugins->newInstance<Resource>(model);
    resource_1->setCapacity(1);
	process_1->getSeizeRequests()->insert(new SeizableItem(resource_1));

    Queue* process1Queue = plugins->newInstance<Queue>(model);
    process1Queue->setName("Process1Queue");
    process1Queue->setOrderRule(Queue::OrderRule::FIFO);
    process_1->setQueueableItem(new QueueableItem(process1Queue));

    // Record
    record_1->getConnections()->insert(dispose_1);
    record_1->setName("Record_1");
    record_1->setExpressionName("How_Many");

    // Set options, save and run simulation.
    model->getInfos()->setName("Model Run Until 1000 Parts Produced");
    model->save("./models/Smart_ModelRunUntil1000Parts.gen");

    auto replicationLength = 8031; // +/- Needed to achieve 1k entities
	model->getSimulation()->setReplicationLength(std::numeric_limits<double>::max(), Util::TimeUnit::week); // This is a "infinity" value.

    model->getSimulation()->setNumberOfReplications(300);
    model->getSimulation()->setReplicationReportBaseTimeUnit(Util::TimeUnit::minute);

    // Warmup should be 5% of replication length
    model->getSimulation()->setWarmUpPeriod(replicationLength * 0.05);
    model->getSimulation()->setWarmUpPeriodTimeUnit(Util::TimeUnit::minute);

    model->getSimulation()->setTerminatingCondition("COUNT(Dispose_1.CountNumberIn) > 1000");

    model->getSimulation()->start();

	for (int i = 0; i < 1e9; i++);

    delete genesys;
    return 0;
}