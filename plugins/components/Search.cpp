/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Search.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:20
 */

#include "Search.h"
#include "../../kernel/simulator/Model.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Search::GetPluginInformation;
}
#endif

ModelDataDefinition* Search::NewInstance(Model* model, std::string name) {
	return new Search(model, name);
}

Search::Search(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Search>(), name) {
}

std::string Search::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Search::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Search* newComponent = new Search(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Search::_onDispatchEvent(Entity* entity) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool Search::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

//void Search::_initBetweenReplications() {}

std::map<std::string, std::string>* Search::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool Search::_check(std::string* errorMessage) {
	bool resultAll = true;
	// @TODO: not implemented yet
	*errorMessage += "";
	return resultAll;
}

PluginInformation* Search::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Search>(), &Search::LoadInstance, &Search::NewInstance);
	// ...
	return info;
}


