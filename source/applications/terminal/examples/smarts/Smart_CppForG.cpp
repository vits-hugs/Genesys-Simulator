/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Smart_CppForG.cpp
 * Author: rlcancian
 * 
 * Created on 11 de janeiro de 2022, 22:39
 */

#include "Smart_CppForG.h"

#include "../../../../kernel/simulator/Simulator.h"
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/CppForG.h"
#include "../../../../plugins/components/Dispose.h"
#include "../../../../kernel/simulator/ModelSimulation.h"

Smart_CppForG::Smart_CppForG() {
}

int Smart_CppForG::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);
	genesys->getTracer()->setTraceLevel(TraceManager::Level::L9_mostDetailed);
	// crete model
	Model* model = genesys->getModels()->newModel();
	PluginManager* plugins = genesys->getPlugins();
	Create* create = plugins->newInstance<Create>(model);
	CppForG* cpp = plugins->newInstance<CppForG>(model);
	Dispose* dispose = plugins->newInstance<Dispose>(model);
	std::string includeCode = "\
#include \"../../source/kernel/simulator/ModelSimulation.h\"\n\
";
	cpp->setIncludesCode(includeCode);
	std::string cppDispachEventCode = "\
	std::cout << \"Executando código do usuário\" << std::endl;\n\
	unsigned int numComponentes = model->getComponents()->getAllComponents()->size();\n\
	std::cout << \"Este modelo tem \" << numComponentes << \" componentes\" << std::endl;\n\
	double tnow = model->getSimulation()->getSimulatedTime();\n\
	std::cout << \"O tempo simulado atual é \" << tnow << std::endl;\n\
	";
	cpp->setOnDispatchEventCode(cppDispachEventCode);
	std::string initCode = "\
	std::cout << \"Inicializando meu código\" << std::endl;\n\
	// mais nada\
	";
	cpp->setInitBetweenReplicationCode(initCode);
	// connect model components to create a "workflow"
	create->getConnections()->insert(cpp);
	cpp->getConnections()->insert(dispose);
	// set options, save and simulate
	ModelSimulation* s = model->getSimulation();
	s->setReplicationLength(10);
	s->setShowReportsAfterReplication(false);
	s->setShowReportsAfterSimulation(false);
	model->save("./models/Smart_CppForG.gen");
	s->start();
	delete genesys;
	return 0;
}

