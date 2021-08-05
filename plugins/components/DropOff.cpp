/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DropOff.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:15
 */

#include "DropOff.h"
#include "../../kernel/simulator/Model.h"

DropOff::DropOff(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<DropOff>(), name) {
}

std::string DropOff::show() {
	return ModelComponent::show() + "";
}

ModelComponent* DropOff::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	DropOff* newComponent = new DropOff(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void DropOff::_execute(Entity* entity) {
    _parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getNextComponents()->getFrontConnection(), 0.0);
}

bool DropOff::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// \todo: not implemented yet
	}
	return res;
}

void DropOff::_initBetweenReplications() {
}

std::map<std::string, std::string>* DropOff::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
	// \todo: not implemented yet
	return fields;
}

bool DropOff::_check(std::string* errorMessage) {
	bool resultAll = true;
	// \todo: not implemented yet
	return resultAll;
}

PluginInformation* DropOff::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<DropOff>(), &DropOff::LoadInstance);
	// ...
	return info;
}

