/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hold.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:20
 */

#include "Hold.h"
#include "../../kernel/simulator/Model.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Hold::GetPluginInformation;
}
#endif

ModelDataDefinition* Hold::NewInstance(Model* model, std::string name) {
	return new Hold(model, name);
}

Hold::Hold(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Hold>(), name) {
}

std::string Hold::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Hold::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Hold* newComponent = new Hold(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Hold::_onDispatchEvent(Entity* entity, unsigned int inputNumber) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

//void Hold::_initBetweenReplications() {}

bool Hold::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

std::map<std::string, std::string>* Hold::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool Hold::_check(std::string* errorMessage) {
	bool resultAll = true;
	// @TODO: not implemented yet
	//*errorMessage += "";
	return resultAll;
}

PluginInformation* Hold::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Hold>(), &Hold::LoadInstance, &Hold::NewInstance);
	info->setCategory("Decisions");
	return info;
}

