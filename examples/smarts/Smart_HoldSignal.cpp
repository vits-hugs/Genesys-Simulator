/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_HoldSignal.cpp
 * Author: rlcancian
 * 
 * Created on 3 de Setembro de 2019, 18:34
 */

#include "Smart_HoldSignal.h"

// you have to included need libs

// GEnSyS Simulator
#include "../../kernel/simulator/Simulator.h"

// Model Components
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Hold.h"
#include "../../plugins/components/Signal.h"
#include "../../plugins/components/Dispose.h"

// Model data definitions

Smart_HoldSignal::Smart_HoldSignal() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Smart_HoldSignal::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->insertFakePluginsByHand(genesys);
	this->setDefaultTraceHandlers(genesys->getTracer());
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L9_mostDetailed);
	Model* model = genesys->getModels()->newModel();
	model->save("./models/Smart_HoldSignal.gen");
	do {
		model->getSimulation()->step();
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
	} while (model->getSimulation()->isPaused());
	return 0;
};

