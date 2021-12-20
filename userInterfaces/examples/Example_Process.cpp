/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FirstExampleOfSimulation.cpp
 * Author: rlcancian
 * 
 * Created on 3 de Setembro de 2019, 18:34
 */

#include "Example_Process.h"

// you have to included need libs

// GEnSyS Simulator
#include "../../kernel/simulator/Simulator.h"

// Model Components
#include "../../plugins/components/Create.h"
#include "../../plugins/components/Delay.h"
#include "../../plugins/components/Dispose.h"

// Model elements
#include "../../kernel/simulator/EntityType.h"
#include "plugins/components/Process.h"

Example_Process::Example_Process() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Example_Process::main(int argc, char** argv) {
    Simulator* genesys = new Simulator();
    this->insertFakePluginsByHand(genesys);
    this->setDefaultTraceHandlers(genesys->getTracer());
    Model* model = genesys->getModels()->newModel();
    Process* process = new Process(model);
    process->getSeizeRequests()->insert(new SeizableItem(new Resource(model)));
    process->setQueueableItem(new QueueableItem(new Queue(model)));
    model->save("./models/Example_Process.txt");
    model->getSimulation()->start();
    genesys->~Simulator();
    return 0;
};

