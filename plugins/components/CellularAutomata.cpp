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

CelularAutomata::CelularAutomata(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<CelularAutomata>(), name) {
}

std::string CelularAutomata::show() {
	return ModelComponent::show() + "";
}

ModelComponent* CelularAutomata::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	CelularAutomata* newComponent = new CelularAutomata(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void CelularAutomata::_execute(Entity* entity) {
	_parentModel->getTracer()->traceSimulation(this, "I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool CelularAutomata::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

//void CelularAutomata::_initBetweenReplications() {}

std::map<std::string, std::string>* CelularAutomata::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool CelularAutomata::_check(std::string* errorMessage) {
	bool resultAll = true;
	*errorMessage += "";
	// @TODO: not implemented yet
	return resultAll;
}

PluginInformation* CelularAutomata::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<CelularAutomata>(), &CelularAutomata::LoadInstance);
	info->setCategory("Logic");
	info->setDescriptionHelp("//@TODO");
	return info;
}

