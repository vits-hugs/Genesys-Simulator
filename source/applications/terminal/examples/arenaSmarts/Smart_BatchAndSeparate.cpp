/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include "Smart_BatchAndSeparate.h"

#include "../../../../kernel/simulator/Simulator.h"
#include "../../../../kernel/simulator/Attribute.h"
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/Dispose.h"
#include "../../../../plugins/components/Assign.h"
#include "../../../../plugins/components/Batch.h"
#include "../../../../plugins/components/Delay.h"
#include "../../../../plugins/components/Separate.h"

Smart_BatchAndSeparate::Smart_BatchAndSeparate() {
}

int Smart_BatchAndSeparate::main(int argc, char** argv) {
    Simulator* genesys = new Simulator();
    genesys->getTracer()->setTraceLevel(TraceManager::Level::L2_results);
    this->setDefaultTraceHandlers(genesys->getTracer());
    genesys->getPlugins()->autoInsertPlugins("autoloadplugins.txt");

    Model* m = new Model(genesys);
    PluginManager* plugins = genesys->getPlugins();

    Create* cr1 = plugins->newInstance<Create>(m);
    cr1->setEntityTypeName("Entity 1");
    cr1->setTimeBetweenCreationsExpression("expo(8)", Util::TimeUnit::minute);
    cr1->setEntitiesPerCreation(1);
    
    Create* cr2 = plugins->newInstance<Create>(m);
    cr2->setEntityTypeName("Entity 1");
    cr2->setTimeBetweenCreationsExpression("expo(8)", Util::TimeUnit::minute);
    cr2->setEntitiesPerCreation(1);
    
    Batch* ba1 = plugins->newInstance<Batch>(m);
    // permanente pelo modelo do arena, mas aqui é temporário;
    ba1->setBatchSize("5");
    ba1->setGroupedAttributes(Batch::GroupedAttribs::LastEntity);
    
    Batch* ba2 = plugins->newInstance<Batch>(m);
    ba2->setBatchSize("10");
    ba1->setGroupedAttributes(Batch::GroupedAttribs::LastEntity);
    
    Separate* se2 = plugins->newInstance<Separate>(m);
    
    Dispose* di1 = plugins->newInstance<Dispose>(m);
    
    Dispose* di2 = plugins->newInstance<Dispose>(m);

    cr1->getConnections()->insert(ba1);
    ba1->getConnections()->insert(di1);
    
    cr2->getConnections()->insert(ba2);
    ba2->getConnections()->insert(se2);
    se2->getConnections()->insert(di2);
    
    ModelSimulation* s = m->getSimulation();
    s->setNumberOfReplications(300);
    double replicationLength = 2700;
    s->setReplicationLength(1000);
    s->setReplicationLength(replicationLength, Util::TimeUnit::minute);
    s->setWarmUpPeriod(replicationLength * 0.05);
    s->setWarmUpPeriodTimeUnit(Util::TimeUnit::minute);
    m->save("./models/Smart_BatchAndSeparate.gen");
    s->start();
    
    delete genesys;
    return 0;
}