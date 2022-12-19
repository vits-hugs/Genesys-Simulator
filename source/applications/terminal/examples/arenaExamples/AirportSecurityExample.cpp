#include "AirportSecurityExample.h"
#include "../../../../kernel/simulator/Simulator.h"
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/Process.h"
#include "../../../../plugins/components/Decide.h"
#include "../../../../plugins/components/Dispose.h"

AirportSecurityExample::AirportSecurityExample() {
}

int AirportSecurityExample::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);
	Model* model = genesys->getModels()->newModel();
	PluginManager* plugins = genesys->getPlugins();
	
	Create* create = plugins->newInstance<Create>(model);
	create->setDescription("Passengers arrive to security");
	create->setEntityTypeName("Passenger");
	create->setTimeBetweenCreationsExpression("expo(2)");
	create->setTimeUnit(Util::TimeUnit::minute);
	create->setEntitiesPerCreation(1);
	create->setFirstCreation(0.0);

	Resource* officer = plugins->newInstance<Resource>(model, "Transportation Security Officer");
	officer->setCapacity(1);
        
	Process* process = plugins->newInstance<Process>(model);
	process->setDescription("Check for proper identification");
	process->getSeizeRequests()->insert(new SeizableItem(officer));
	process->setQueueableItem(new QueueableItem(model, "Check for Proper Identification.Queue"));
	process->setDelayExpression("tria(0.75, 1.5, 3)");
	process->setDelayTimeUnit(Util::TimeUnit::minute);

	Decide* decide = plugins->newInstance<Decide>(model);
	decide->setDescription("Pass security?");
	decide->getConditions()->insert("unif(0, 1) < 0.96");

	Dispose* disposeCleared = plugins->newInstance<Dispose>(model);
	disposeCleared->setDescription("Cleared");
	Dispose* disposeDenied = plugins->newInstance<Dispose>(model);
	disposeDenied->setDescription("Denied");
	
	create->getConnections()->insert(process);
	process->getConnections()->insert(decide);
	decide->getConnections()->insert(disposeCleared);
	decide->getConnections()->insert(disposeDenied);
	
        genesys->getTracer()->setTraceLevel(TraceManager::Level::L2_results);
        // genesys->getTracer()->setTraceLevel(TraceManager::Level::L9_mostDetailed);
	model->getSimulation()->setReplicationLength(2, Util::TimeUnit::day);
	model->getSimulation()->setNumberOfReplications(300);
        model->getSimulation()->setWarmUpPeriod(0.1);
        model->getSimulation()->setWarmUpPeriodTimeUnit(Util::TimeUnit::day);
	model->getSimulation()->start();
        
	delete genesys;
	return 0;
}

