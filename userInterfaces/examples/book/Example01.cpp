/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Example01.cpp
 * Author: rlcancian
 * 
 * Created on 19 de outubro de 2021, 16:23
 */

#include "Example01.h"
#include "../../../kernel/simulator/Simulator.h"
#include "../../../kernel/simulator/EntityType.h"
#include "../../../plugins/components/Create.h"
#include "../../../plugins/components/Delay.h"
#include "../../../plugins/components/Dispose.h"

Example01::Example01() {
}

int Example01::main(int argc, char** argv) {
    Simulator* genesys = new Simulator();
    this->insertFakePluginsByHand(genesys);
    this->setDefaultTraceHandlers(genesys->getTracer());
    Model* model = genesys->getModels()->newModel();
    EntityType* entityType1 = new EntityType(model, "EntityType1");
    Create* create1 = new Create(model);
    create1->setEntityType(entityType1);
    create1->setTimeBetweenCreationsExpression("NORM(5,2)"); 
    Delay* delay1 = new Delay(model);
    delay1->setDelayExpression("unif(3,7)");
    Dispose* dispose1 = new Dispose(model);
    create1->getNextComponents()->insert(delay1);
    delay1->getNextComponents()->insert(dispose1);
    model->getSimulation()->setReplicationLength(30);
    model->getSimulation()->start();
    return 0;
}

