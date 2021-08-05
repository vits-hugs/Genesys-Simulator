/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Start.cpp
 * Author: rlcancian
 * 
 * Created on 11 de Setembro de 2019, 13:15
 */

#include "Start.h"

#include "../../kernel/simulator/Model.h"

Start::Start(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Start>(), name) {
}

std::string Start::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Start::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Start* newComponent = new Start(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Start::_execute(Entity* entity) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getNextComponents()->getFrontConnection(), 0.0);
}

bool Start::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// \todo: not implemented yet
	}
	return res;
}

void Start::_initBetweenReplications() {
}

std::map<std::string, std::string>* Start::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
	// \todo: not implemented yet
	return fields;
}

bool Start::_check(std::string* errorMessage) {
	bool resultAll = true;
	// \todo: not implemented yet
	return resultAll;
}

PluginInformation* Start::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Start>(), &Start::LoadInstance);
	// ...
	return info;
}


