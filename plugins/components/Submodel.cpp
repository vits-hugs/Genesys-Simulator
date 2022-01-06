/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Submodel.cpp
 * Author: rlcancian
 * 
 * Created on 11 de Setembro de 2019, 13:04
 */

#include "Submodel.h"

#include "../../kernel/simulator/Model.h"

Submodel::Submodel(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Submodel>(), name) {
}

std::string Submodel::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Submodel::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Submodel* newComponent = new Submodel(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Submodel::_execute(Entity* entity) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getNextComponents()->getFrontConnection());
}

bool Submodel::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// \todo: not implemented yet
	}
	return res;
}

void Submodel::_initBetweenReplications() {
}

std::map<std::string, std::string>* Submodel::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
	// \todo: not implemented yet
	return fields;
}

bool Submodel::_check(std::string* errorMessage) {
	bool resultAll = true;
	// \todo: not implemented yet
	*errorMessage += "";
	return resultAll;
}

PluginInformation* Submodel::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Submodel>(), &Submodel::LoadInstance);
	// ...
	return info;
}


