/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Signal.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:20
 */

#include "Signal.h"

#include "../../kernel/simulator/Model.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Signal::GetPluginInformation;
}
#endif

ModelDataDefinition* Signal::NewInstance(Model* model, std::string name) {
	return new Signal(model, name);
}

Signal::Signal(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Signal>(), name) {
}

std::string Signal::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Signal::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Signal* newComponent = new Signal(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Signal::_onDispatchEvent(Entity* entity, unsigned int inputNumber) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool Signal::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

//void Signal::_initBetweenReplications() {}

std::map<std::string, std::string>* Signal::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool Signal::_check(std::string* errorMessage) {
	bool resultAll = true;
	// @TODO: not implemented yet
	//*errorMessage += "";
	return resultAll;
}

PluginInformation* Signal::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Signal>(), &Signal::LoadInstance, &Signal::NewInstance);
	info->setCategory("Decisions");
	// ...
	return info;
}


