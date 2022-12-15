/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_ResourceSets.cpp
 * Author: guifrrs and LuizValdiero
 * 
 * Created on Dezembro de 2022
 */

#include "./Smart_ResourceSets.h"

// Including the GEnSys Simulator
#include "../../../../kernel/simulator/Simulator.h"

// Components for the model
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/Process.h"
#include "../../../../plugins/components/Delay.h"
#include "../../../../plugins/components/Dispose.h"
#include "../../../../plugins/components/Decide.h"

Smart_ResourceSets::Smart_ResourceSets() {

}

/**
 * This is the main function of the application. 
 * It create a new simulator instance, 
 * builds a simulation model and 
 * then simulate that model.
*/
int Smart_ResourceSets::main(int argc, char** argv) {
    // Create a new simulator instance.
    Simulator* genesys = new Simulator();
    this->setDefaultTraceHandlers(genesys->getTracer());
    this->insertFakePluginsByHand(genesys);

    bool isDevelop = true;    

    if (isDevelop) {
        genesys->getTracer()->setTraceLevel(TraceManager::Level::L9_mostDetailed);
    } else {
        genesys->getTracer()->setTraceLevel(TraceManager::Level::L2_results);
    }

    // Create the model and components instances.
    Model* model = genesys->getModels()->newModel();
    PluginManager* plugins = genesys->getPlugins();
    
    Create* mailLoanArrives = plugins->newInstance<Create>(model, "Mail Loans Arrive");
    Create* internetLoanArrives = plugins->newInstance<Create>(model, "Internet Loans Arrive");
    Create* phoneLoanArrives = plugins->newInstance<Create>(model, "Phone Loans Arrive");
    Process* useLoanApproval = plugins->newInstance<Process>(model, "Use Loan Approval Officer Set");
    Process* useSeniorApproval = plugins->newInstance<Process>(model, "Use Senior Approval Officer Set");
    Decide* decideLoan = plugins->newInstance<Decide>(model, "Determine if loan is approved");
    Delay* sendApproval = plugins->newInstance<Delay>(model, "Send Approval");
    Delay* sendDenial = plugins->newInstance<Delay>(model, "Send Denial");
    Dispose* fileLoan = plugins->newInstance<Dispose>(model, "File Loan");
    Dispose* disposeApplication = plugins->newInstance<Dispose>(model, "Dispose of Application");

    // Mail Loans Arrive
    mailLoanArrives->getConnections()->insert(useLoanApproval);
    mailLoanArrives->setEntityTypeName("Mail Loan");
    mailLoanArrives->setTimeBetweenCreationsExpression("EXPO(10)");
    mailLoanArrives->setTimeUnit(Util::TimeUnit::minute);
    mailLoanArrives->setEntitiesPerCreation(1);
    mailLoanArrives->setFirstCreation(0.0);

    // Internet Loans Arrive
    internetLoanArrives->getConnections()->insert(useLoanApproval);
    internetLoanArrives->setEntityTypeName("Internet Loan");
    internetLoanArrives->setTimeBetweenCreationsExpression("EXPO(1)");
    internetLoanArrives->setTimeUnit(Util::TimeUnit::hour);
    internetLoanArrives->setEntitiesPerCreation(1);
    internetLoanArrives->setFirstCreation(0.0);

    // Phone Loans Arrive
    phoneLoanArrives->getConnections()->insert(useLoanApproval);
    phoneLoanArrives->setEntityTypeName("Phone Loan");
    phoneLoanArrives->setTimeBetweenCreationsExpression("EXPO(30)");
    phoneLoanArrives->setTimeUnit(Util::TimeUnit::minute);
    phoneLoanArrives->setEntitiesPerCreation(1);
    phoneLoanArrives->setFirstCreation(0.0);

    // Create the needed resources for the Process entities.
    Resource* loanOfficer1 = plugins->newInstance<Resource>(model, "Loan Officer 1");
    Resource* loanOfficer2 = plugins->newInstance<Resource>(model, "Loan Officer 2");
    Resource* loanOfficer3 = plugins->newInstance<Resource>(model, "Loan Officer 3");
    Resource* loanOfficer4 = plugins->newInstance<Resource>(model, "Loan Officer 4");
    Resource* loanOfficer5 = plugins->newInstance<Resource>(model, "Loan Officer 5");

    Resource* seniorLoanOfficer1 = plugins->newInstance<Resource>(model, "Senior Loan Officer 1");
    Resource* seniorLoanOfficer2 = plugins->newInstance<Resource>(model, "Senior Loan Officer 2");

    std::vector<Resource*> loanResource = { loanOfficer1, loanOfficer2, loanOfficer3, loanOfficer4, loanOfficer5 };
    std::vector<Resource*> seniorResources = { seniorLoanOfficer1, seniorLoanOfficer2 };

    // Use Loan Approval Officer Set
    useLoanApproval->getConnections()->insert(useSeniorApproval);
    useLoanApproval->setDelayTimeUnit(Util::TimeUnit::minute);
    useLoanApproval->setDelayExpression("NORM(7, 2)");

    Queue* loanQueue = plugins->newInstance<Queue>(model);
    loanQueue->setName("Use Loan Queue");
    loanQueue->setOrderRule(Queue::OrderRule::FIFO);

    Set* loanOfficersSet = plugins->newInstance<Set>(model);
    loanOfficersSet->setName("Loan Officers");
    loanOfficersSet->setSetOfType("Resource");

    loanOfficersSet->getElementSet()->insert(loanOfficer1);
    loanOfficersSet->getElementSet()->insert(loanOfficer2);
    loanOfficersSet->getElementSet()->insert(loanOfficer3);
    loanOfficersSet->getElementSet()->insert(loanOfficer4);
    loanOfficersSet->getElementSet()->insert(loanOfficer5);

    // for (auto r : loanResource ) {
    //     loanOfficersSet->getElementSet()->insert(r);
    // }

    // for (auto sr : seniorResources) {
    //     loanOfficersSet->getElementSet()->insert(sr);
    // }

    useLoanApproval->getSeizeRequests()->insert(new SeizableItem(loanOfficersSet, "1", SeizableItem::SelectionRule::PREFEREDORDER)); // TODO: Selection rule should be PreferredOrder
    useLoanApproval->setQueueableItem(new QueueableItem(loanQueue));
    
    // Use Senior Approval Officer Set
    useSeniorApproval->getConnections()->insert(decideLoan);
    useSeniorApproval->setDelayTimeUnit(Util::TimeUnit::hour);
    useSeniorApproval->setDelayExpression("TRIA(2, 3, 4)");

    Queue* seniorQueue = plugins->newInstance<Queue>(model);
    seniorQueue->setName("Use Senior Queue");
    seniorQueue->setOrderRule(Queue::OrderRule::FIFO);

    Set* seniorOfficersSet = plugins->newInstance<Set>(model);
    seniorOfficersSet->setName("Senior Approval Officers");
    seniorOfficersSet->setSetOfType("Resource");

    for (auto sr : seniorResources) {
        seniorOfficersSet->getElementSet()->insert(sr);
    }

    useSeniorApproval->getSeizeRequests()->insert(new SeizableItem(seniorOfficersSet, "1", SeizableItem::SelectionRule::CYCLICAL));
    useSeniorApproval->setQueueableItem(new QueueableItem(seniorQueue));

    // Determine if loan is approved
    decideLoan->getConnections()->insert(sendApproval);
    decideLoan->getConnections()->insert(sendDenial);
    decideLoan->getConditions()->insert("UNIF(0, 1) < 0.8");

    // Send approval
    // As process_3 has only a Delay action, it uses the Delay component instead but we keep the name.
    sendApproval->getConnections()->insert(fileLoan);
    sendApproval->setDelayTimeUnit(Util::TimeUnit::minute);
    sendApproval->setDelayExpression("UNIF(0.5, 2.0)");

    // Send Denial
    // As process_4 has only a Delay action, it uses the Delay component instead but we keep the name.
    sendDenial->getConnections()->insert(disposeApplication);
    sendDenial->setDelayTimeUnit(Util::TimeUnit::minute);
    sendDenial->setDelayExpression("TRIA(0.5, 1, 1.5)"); 

    // Set options, save and run simulation.
    // TODO: Add a 5% warmup and find a way to stop simulation with 1k elements.
    // TODO: Change replications to 300
    model->getInfos()->setName("Resources Sets");
    model->getSimulation()->setNumberOfReplications(1);
    model->getSimulation()->setReplicationLength(480);
    model->getSimulation()->setReplicationLengthTimeUnit(Util::TimeUnit::minute);
    model->save("./models/Smart_ResourceSets.gen");
   
 	model->getSimulation()->start();
	for (int i = 0; i < 1e3; i++);

    delete genesys;
    
    return 0;
}
