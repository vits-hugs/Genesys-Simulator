/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CelularAutomata.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:14
 */

#include "CellularAutomata.h"
#include "../../kernel/simulator/Model.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &CellularAutomata::GetPluginInformation;
}
#endif

ModelDataDefinition* CellularAutomata::NewInstance(Model* model, std::string name) {
	return new CellularAutomata(model, name);
}

CellularAutomata::CellularAutomata(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<CellularAutomata>(), name) {
}

std::string CellularAutomata::show() {
	return ModelComponent::show() + "";
}

ModelComponent* CellularAutomata::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	CellularAutomata* newComponent = new CellularAutomata(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void CellularAutomata::_onDispatchEvent(Entity* entity) {
	_parentModel->getTracer()->traceSimulation(this, "I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool CellularAutomata::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

//void CelularAutomata::_initBetweenReplications() {}

std::map<std::string, std::string>* CellularAutomata::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool CellularAutomata::_check(std::string* errorMessage) {
	bool resultAll = true;
	//*errorMessage += "";
	// @TODO: not implemented yet
	return resultAll;
}

PluginInformation* CellularAutomata::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<CellularAutomata>(), &CellularAutomata::LoadInstance, &CellularAutomata::NewInstance);
	info->setCategory("Logic");
	info->setDescriptionHelp("//@TODO");
	return info;
}

