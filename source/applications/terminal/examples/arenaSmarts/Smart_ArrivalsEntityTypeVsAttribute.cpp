/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include "Smart_ArrivalsEntityTypeVsAttribute.h"

#include "../../../../kernel/simulator/Simulator.h"
#include "../../../../kernel/simulator/Attribute.h"
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/Dispose.h"
#include "../../../../plugins/components/Assign.h"
#include "../../../../plugins/components/Delay.h"
#include "../../../../plugins/components/QueueableItem.h"
#include "../../../../plugins/components/SeizableItem.h"
#include "../../../../plugins/components/Process.h"
#include "../../../../plugins/components/Decide.h"

Smart_ArrivalsEntityTypeVsAttribute::Smart_ArrivalsEntityTypeVsAttribute() {
}

int Smart_ArrivalsEntityTypeVsAttribute::main(int argc, char** argv) {
    Simulator* genesys = new Simulator();
    genesys->getTracer()->setTraceLevel(TraceManager::Level::L2_results);
    this->setDefaultTraceHandlers(genesys->getTracer());
    this->insertFakePluginsByHand(genesys);

    Model* m = new Model(genesys);
    PluginManager* plugins = genesys->getPlugins();

    Create* cr1 = plugins->newInstance<Create>(m, "Create1");
    cr1->setTimeBetweenCreationsExpression("expo(1)", Util::TimeUnit::hour);
    
    // Widget1
    Assign *assignCR1 = plugins->newInstance<Assign>(m);
    assignCR1->getAssignments()->insert(new Assignment(m, "Entity.Type", "1"));
    
    Create* cr2 = plugins->newInstance<Create>(m, "Create2");
    cr2->setTimeBetweenCreationsExpression("expo(1)", Util::TimeUnit::hour);
    
    // Widget2
    Assign *assignCR2 = plugins->newInstance<Assign>(m);
    assignCR2->getAssignments()->insert(new Assignment(m, "Entity.Type", "2"));
    
    Assign *assign = plugins->newInstance<Assign>(m);
    assign->setName("Assign 1");   
    // Checking expression "cont(0.5,10,1,20)", syntax error, unexpected ILLEGAL -> valor alterado para uma uniforme
    assign->getAssignments()->insert(new Assignment(m, "Weight", "unif(0.2,1)"));
    
    Process *process = plugins->newInstance<Process>(m);
    process->setName("Process 1");
    process->getSeizeRequests()->insert(new SeizableItem(plugins->newInstance<Resource>(m)));
    process->setQueueableItem(new QueueableItem(plugins->newInstance<Queue>(m)));
    process->setDelayExpression("Weight * 5");
    process->setDelayTimeUnit(Util::TimeUnit::hour);
    
    Decide *decide = plugins->newInstance<Decide>(m);
    decide->setName("Decide 1");
    // Não entendemos como pegar o EntityType diretamente do Create, então criamos assigns de atributos pra ele
    decide->getConditions()->insert("Entity.Type == 2");
    
    Dispose* di1 = plugins->newInstance<Dispose>(m);
    
    Dispose* di2 = plugins->newInstance<Dispose>(m);

    cr1->getConnections()->insert(assignCR1);
    cr2->getConnections()->insert(assignCR2);
   
    assignCR1->getConnections()->insert(assign);
    assignCR2->getConnections()->insert(assign);
    
    assign->getConnections()->insert(process);
    
    process->getConnections()->insert(decide);
    
    decide->getConnections()->insert(di1);
    decide->getConnections()->insert(di2);
    
    ModelSimulation* s = m->getSimulation();
    s->setNumberOfReplications(3);
    double replicationLength = 1;
    s->setReplicationLength(replicationLength, Util::TimeUnit::week);
    s->setWarmUpPeriod(replicationLength * 0.05);
    s->setWarmUpPeriodTimeUnit(Util::TimeUnit::week);
    m->save("./models/Smart_ArrivalEntityTypeVsAttribute.gen");
    s->start();
    
    delete genesys;
    return 0;
}