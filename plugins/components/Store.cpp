/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Store.cpp
 * Author: rlcancian
 * 
 * Created on 11 de Setembro de 2019, 13:07
 */

#include "Store.h"
#include "../../kernel/simulator/Model.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Store::GetPluginInformation;
}
#endif

ModelDataDefinition* Store::NewInstance(Model* model, std::string name) {
	return new Store(model, name);
}

Store::Store(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Store>(), name) {
}

std::string Store::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Store::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Store* newComponent = new Store(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Store::_onDispatchEvent(Entity* entity, unsigned int inputNumber) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool Store::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

//void Store::_initBetweenReplications() {}

std::map<std::string, std::string>* Store::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool Store::_check(std::string* errorMessage) {
	bool resultAll = true;
	// @TODO: not implemented yet
	*errorMessage += "";
	return resultAll;
}

PluginInformation* Store::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Store>(), &Store::LoadInstance, &Store::NewInstance);
	info->setCategory("Material Handling");
	// ...
	return info;
}


