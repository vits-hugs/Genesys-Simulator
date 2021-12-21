/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 19:41
 */

#include "Event.h"

//using namespace GenesysKernel;

Event::Event(double time, Entity* entity, ModelComponent* component, unsigned int componentInputNumber) {
    _time = time;
    _entity = entity;
    _component = component;
    _componentInputNumber = componentInputNumber;
}

Event::Event(double time, Entity* entity, Connection* connection) {
    _time = time;
    _entity = entity;
    _component = connection->first;
    _componentInputNumber = connection->second;
}

std::string Event::show() {
    std::string message = "time=" + std::to_string(_time) + //Util::StrTimeUnit(???)+
            ",entity=" + _entity->getName() + //std::to_string(_entity->entityNumber()) +
            ",component=\"" + _component->getName() + "\""; //+std::to_string(_component->getId())+"}";
    if (this->_componentInputNumber > 0) {
        message += ",input=" + std::to_string(this->_componentInputNumber);
    }
    return message;
}

unsigned int Event::getComponentInputNumber() const {
    return _componentInputNumber;
}

double Event::getTime() const {
    return _time;
}

ModelComponent* Event::getComponent() const {
    return _component;
}

Entity* Event::getEntity() const {
    return _entity;
}

