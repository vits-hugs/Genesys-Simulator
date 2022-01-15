/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Match.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:14
 */

#include "Match.h"

#include "../../kernel/simulator/Model.h"

Match::Match(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Match>(), name) {
}

std::string Match::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Match::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Match* newComponent = new Match(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Match::_execute(Entity* entity) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool Match::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

//void Match::_initBetweenReplications() {}

std::map<std::string, std::string>* Match::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool Match::_check(std::string* errorMessage) {
	bool resultAll = true;
	// @TODO: not implemented yet
	*errorMessage += "";
	return resultAll;
}

PluginInformation* Match::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Match>(), &Match::LoadInstance);
	// ...
	return info;
}

