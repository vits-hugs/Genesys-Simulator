/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Example_SistemaOperacional03.cpp
 * Author: rlcancian
 * 
 * Created on 23 de abril de 2021, 14:03
 */

#include "Example_SistemaOperacional03.h"

#include "../../kernel/simulator/Simulator.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Attribute.h"

#include "../../plugins/elements/Queue.h"
#include "../../plugins/elements/Resource.h"
#include "../../plugins/elements/Station.h"

#include "../../plugins/components/Create.h"
#include "../../plugins/components/Seize.h"
#include "../../plugins/components/Delay.h"
#include "../../plugins/components/Release.h"
#include "../../plugins/components/Dispose.h"
#include "../../plugins/components/Assign.h"
#include "../../plugins/components/Decide.h"
#include "../../plugins/components/Enter.h"
#include "../../plugins/components/Route.h"

#include <iostream>

Example_SistemaOperacional03::Example_SistemaOperacional03() {
}

int Example_SistemaOperacional03::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->insertFakePluginsByHand(genesys);
	this->setDefaultTraceHandlers(genesys->getTracer());
	Model* model = genesys->getModels()->newModel();
	//
	// CREATE Processo é criado no computador
	EntityType* et = new EntityType(model, "processo");
	Create* createProc = new Create(model);
	createProc->setDescription("Processo é criado no computador");
	createProc->setEntityType(et);
	createProc->setTimeBetweenCreationsExpression("expo(4)");
	createProc->setTimeUnit(Util::TimeUnit::milisecond);
	//
	// ASSIGN Define informacoes do processo
	Assign* assignProc = new Assign(model);
	assignProc->setDescription("Define informacoes do processo");
	assignProc->getAssignments()->insert(new Assign::Assignment("memoriaOcupada", "TRUNC(UNIF(2,32))"));
	assignProc->getAssignments()->insert(new Assign::Assignment("tempoExecucao", "NORM(6,2) * memoriaOcupada/5"));
	assignProc->getAssignments()->insert(new Assign::Assignment("processoSO", "UNIF(0,1) < 0.1"));
	// atributos (não precisa guardar objetos se não for usar)
	new Attribute(model, "memoriaOcupada");
	new Attribute(model, "tempoExecucao");
	new Attribute(model, "processoSO");

	createProc->getNextComponents()->insert(assignProc);
	//
	// SEIZE memoria
	Resource* memoria = new Resource(model, "memoria");
	memoria->setCapacity(256);
	Queue* queueMem = new Queue(model, "Fila_Alocacao_Memoria");
	Seize* seizeMem = new Seize(model);
	seizeMem->setDescription("Processo aloca memória");
	seizeMem->setQueue(queueMem);
	seizeMem->getSeizeRequests()->insert(new SeizableItemRequest(memoria, "memoriaOcupada"));

	assignProc->getNextComponents()->insert(seizeMem);
	//
	// DECIDE Define nucleo execucao do processo
	Decide* decideNucleo = new Decide(model);
	decideNucleo->setDescription("Define nucleo execucao do processo");
	decideNucleo->getConditions()->insert("processoSO == 1");
	decideNucleo->getConditions()->insert("NQ(filaNucleo1) <= NQ(filaNucleo2) and NQ(filaNucleo1) <= NQ(filaNucleo3)");
	decideNucleo->getConditions()->insert("NQ(filaNucleo2) <= NQ(filaNucleo1) and NQ(filaNucleo2) <= NQ(filaNucleo3)");

	seizeMem->getNextComponents()->insert(decideNucleo);
	//
	// ASSIGN Nucleo 0
	Assign* assignDefNucleo0 = new Assign(model);
	assignDefNucleo0->getAssignments()->insert(new Assign::Assignment("nucleoExecucao", "0"));
	new Attribute(model, "nucleoExecucao");
	//
	// ASSIGN Nucleo 1
	Assign* assignDefNucleo1 = new Assign(model);
	assignDefNucleo1->getAssignments()->insert(new Assign::Assignment("nucleoExecucao", "1"));
	//
	// ASSIGN Nucleo 2
	Assign* assignDefNucleo2 = new Assign(model);
	assignDefNucleo2->getAssignments()->insert(new Assign::Assignment("nucleoExecucao", "2"));
	//
	// ASSIGN Nucleo 3
	Assign* assignDefNucleo3 = new Assign(model);
	assignDefNucleo3->getAssignments()->insert(new Assign::Assignment("nucleoExecucao", "3"));

	decideNucleo->getNextComponents()->insert(assignDefNucleo0);
	decideNucleo->getNextComponents()->insert(assignDefNucleo1);
	decideNucleo->getNextComponents()->insert(assignDefNucleo2);
	decideNucleo->getNextComponents()->insert(assignDefNucleo3);
	//
	// ROUTE Processo é enviado para execução na CPU
	Station* stationExecucao = new Station(model, "Estacao_de_Execucao");
	Route* routeExecucao1 = new Route(model);
	routeExecucao1->setDescription("Processo é enviado para execução na CPU");
	routeExecucao1->setStation(stationExecucao);

	assignDefNucleo0->getNextComponents()->insert(routeExecucao1);
	assignDefNucleo1->getNextComponents()->insert(routeExecucao1);
	assignDefNucleo2->getNextComponents()->insert(routeExecucao1);
	assignDefNucleo3->getNextComponents()->insert(routeExecucao1);

	//
	// ENTER Processo chega para ser executado
	Enter* enterStationExecucao = new Enter(model);
	enterStationExecucao->setDescription("Processo chega para ser executado");
	enterStationExecucao->setStation(stationExecucao);
	//
	// SEIZE Processo aloca Núcleo de Execução
	//     SET RESOURCES
	Set* setNucleos = new Set(model, "Set_Nucleos");
	setNucleos->setSetOfType(Util::TypeOf<Resource>());
	setNucleos->getElementSet()->insert(new Resource(model, "nucleo0"));
	setNucleos->getElementSet()->insert(new Resource(model, "nucleo1"));
	setNucleos->getElementSet()->insert(new Resource(model, "nucleo2"));
	setNucleos->getElementSet()->insert(new Resource(model, "nucleo3"));
	//std::cout << setNucleos->getElementSet()->show() << std::endl;
	//     SET QUEUES
	Set* setFilas = new Set(model, "Set_Filas");
	setFilas->setSetOfType(Util::TypeOf<Queue>());
	setFilas->getElementSet()->insert(new Queue(model, "filaNucleo0"));
	setFilas->getElementSet()->insert(new Queue(model, "filaNucleo1"));
	setFilas->getElementSet()->insert(new Queue(model, "filaNucleo2"));
	setFilas->getElementSet()->insert(new Queue(model, "filaNucleo3"));
	std::cout << setFilas->getElementSet()->show() << std::endl;
	// SEIZE
	Seize* seizeNucleo = new Seize(model);
	seizeNucleo->setDescription("Processo aloca Núcleo de Execução");
	seizeNucleo->setQueueableItem(new QueueableItemRequest(setFilas, QueueableItemRequest::QueueableType::SET, "nucleoExecucao"));
	seizeNucleo->getSeizeRequests()->insert(new SeizableItemRequest(setNucleos, "1", SeizableItemRequest::SeizableType::SET, SeizableItemRequest::SelectionRule::SPECIFICMEMBER, "", "nucleoExecucao"));

	enterStationExecucao->getNextComponents()->insert(seizeNucleo);
	//
	// DECIDE Define tempo de execução da fatia de tempo atual
	Decide* decideFatiaTempo = new Decide(model);
	decideFatiaTempo->setDescription("Define tempo de execução da fatia de tempo atual");
	decideFatiaTempo->getConditions()->insert("tempoExecucao >= 2");

	seizeNucleo->getNextComponents()->insert(decideFatiaTempo);
	//
	// ASSIGN Define execucao por um quantum de tempo
	Assign* assignExecFatia = new Assign(model);
	assignExecFatia->setDescription("Define execucao por um quantum de tempo");
	assignExecFatia->getAssignments()->insert(new Assign::Assignment("fatiaTempo", "2"));
	assignExecFatia->getAssignments()->insert(new Assign::Assignment("tempoExecucao", "tempoExecucao-fatiaTempo"));
	new Attribute(model, "fatiaTempo");

	decideFatiaTempo->getNextComponents()->insert(assignExecFatia);
	//
	// ASSIGN Executa até o final
	Assign* assignExecAteFinal = new Assign(model);
	assignExecAteFinal->setDescription("Executa até o final");
	assignExecAteFinal->getAssignments()->insert(new Assign::Assignment("fatiaTempo", "tempoExecucao"));
	assignExecAteFinal->getAssignments()->insert(new Assign::Assignment("tempoExecucao", "tempoExecucao - fatiaTempo"));

	decideFatiaTempo->getNextComponents()->insert(assignExecAteFinal);
	//
	// DELAY Processo executa no nucleo de execucao
	Delay* delayProcExecNucleo = new Delay(model);
	delayProcExecNucleo->setDescription("Processo executa no nucleo de execucao");
	delayProcExecNucleo->setDelayExpression("fatiaTempo");
	delayProcExecNucleo->setDelayTimeUnit(Util::TimeUnit::milisecond);

	assignExecFatia->getNextComponents()->insert(delayProcExecNucleo);
	assignExecAteFinal->getNextComponents()->insert(delayProcExecNucleo);
	//
	// RELEASE Processo libera nucleo execucao
	Release* releaseNucleo = new Release(model);
	releaseNucleo->setDescription("Processo libera nucleo execucao");
	releaseNucleo->getReleaseRequests()->insert(new SeizableItemRequest(setNucleos, "1", SeizableItemRequest::SeizableType::SET, SeizableItemRequest::SelectionRule::SPECIFICMEMBER, "", "nucleoExecucao"));

	delayProcExecNucleo->getNextComponents()->insert(releaseNucleo);
	//
	// DECIDE Se processo ainda precisa executar então vai para estação de execução
	Decide* decideAindaExec = new Decide(model);
	decideAindaExec->setDescription("Se processo ainda precisa executar então vai para estação de execução");
	decideAindaExec->getConditions()->insert("tempoExecucao > 0");

	releaseNucleo->getNextComponents()->insert(decideAindaExec);
	//
	// ROUTE Processo é enviado de volta para execução
	Route* routeExecucao2 = new Route(model);
	routeExecucao2->setDescription("Processo é enviado de volta para execução");
	routeExecucao2->setStation(stationExecucao);

	decideAindaExec->getNextComponents()->insert(routeExecucao2);
	// ROUTE Processo é enviado para liberar memória
	Station* stationLiberaMem = new Station(model, "Estacao_de_liberacao_de_memoria");
	Route* routeLiberaMem = new Route(model);
	routeLiberaMem->setDescription("Processo é enviado para liberar memória");
	routeLiberaMem->setStation(stationLiberaMem);

	decideAindaExec->getNextComponents()->insert(routeLiberaMem);
	//
	// ENTER Processo chega para liberar memória
	Enter* enterStationLibera = new Enter(model);
	enterStationLibera->setDescription("Processo chega para liberar memória");
	enterStationLibera->setStation(stationLiberaMem);
	//
	// RELEASE 	Processo libera memória
	Release* releaseMem = new Release(model);
	releaseMem->setDescription("Processo libera memória");
	releaseMem->getReleaseRequests()->insert(new SeizableItemRequest(memoria, "memoriaOcupada"));

	enterStationLibera->getNextComponents()->insert(releaseMem);
	//
	// DISPOSE Processo é encerrado
	Dispose* disp1 = new Dispose(model);
	disp1->setDescription("Processo é encerrado");

	releaseMem->getNextComponents()->insert(disp1);

	//
	// AJUSTA EXPERIMENTO (MODEL SIMULATION)
	ModelSimulation* sim = model->getSimulation();
	sim->setReplicationLength(2);
	sim->setReplicationLengthTimeUnit(Util::TimeUnit::second);
	sim->setReplicationReportBaseTimeUnit(Util::TimeUnit::milisecond);
	sim->setNumberOfReplications(200);
	sim->setWarmUpPeriod(0.02);
	sim->setWarmUpPeriodTimeUnit(Util::TimeUnit::second);
	sim->setShowReportsAfterReplication(true);
	sim->setShowReportsAfterSimulation(true);
	//sim->getBreakpointsOnComponent()->insert(routeExecucao1);
	//sim->getBreakpointsOnComponent()->insert(assignDefNucleo0);
	//sim->getBreakpointsOnComponent()->insert(assignDefNucleo1);
	//sim->getBreakpointsOnComponent()->insert(assignDefNucleo2);
	//sim->getBreakpointsOnComponent()->insert(assignDefNucleo3);
	model->save("./models/SistemaOperacional03.txt");
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L2_results); // :L9_mostDetailed);
	do {
		sim->start(); //step();
		if (sim->isPaused()) {
			std::cout << "Press ENTER to continue...";
			std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
		}
	} while (sim->isPaused());
	return 0;
}


