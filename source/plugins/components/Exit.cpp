/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Exit.cpp
 * Author: rlcancian
 * 
 * Created on 11 de Setembro de 2019, 13:15
 */

#include "Exit.h"

#include "../../kernel/simulator/Model.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Exit::GetPluginInformation;
}
#endif

ModelDataDefinition* Exit::NewInstance(Model* model, std::string name) {
	return new Exit(model, name);
}

Exit::Exit(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Exit>(), name) {
}

std::string Exit::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Exit::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Exit* newComponent = new Exit(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Exit::_onDispatchEvent(Entity* entity, unsigned int inputPortNumber) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

//void Exit::_initBetweenReplications() {}

bool Exit::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

std::map<std::string, std::string>* Exit::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool Exit::_check(std::string* errorMessage) {
	bool resultAll = true;
	// @TODO: not implemented yet
	*errorMessage += "";
	return resultAll;
}

PluginInformation* Exit::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Exit>(), &Exit::LoadInstance, &Exit::NewInstance);
	info->setCategory("Material Handling");
	return info;
}


