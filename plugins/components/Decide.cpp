/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Decide.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 9 de Agosto de 2018, 20:39
 */

#include "Decide.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Counter.h"

Decide::Decide(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Decide>(), name) {
}

List<std::string>* Decide::getConditions() const {
	return _conditions;
}

std::string Decide::show() {
	return ModelComponent::show() + "";
}

void Decide::_execute(Entity* entity) {
	double value;
	unsigned short i = 0;
	for (std::list<std::string>::iterator it = _conditions->list()->begin(); it != _conditions->list()->end(); it++) {
		value = _parentModel->parseExpression((*it));
		_parentModel->getTracer()->traceSimulation(_parentModel->getSimulation()->getSimulatedTime(), entity, this, std::to_string(i + 1) + "th condition evaluated to " + strTruncIfInt(std::to_string(value)) + "  // " + (*it));
		if (value) {
			if (_reportStatistics) {
				_numberOuts->getAtRank(i)->incCountValue();
			}
			_parentModel->sendEntityToComponent(entity, this->getConnections()->getConnectionAtRank(i));
			return;
		}
		i++;
	}
	_parentModel->getTracer()->traceSimulation(_parentModel->getSimulation()->getSimulatedTime(), entity, this, "No condition has been evaluated true");
	if (_reportStatistics) {
		_numberOuts->getAtRank(i)->incCountValue();
	}
	_parentModel->sendEntityToComponent(entity, this->getConnections()->getConnectionAtRank(i));
}

void Decide::_initBetweenReplications() {
	if (_numberOuts != nullptr) {
		for (Counter* counter : *_numberOuts->list()) {
			counter->clear();
		}
	}
}

bool Decide::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		unsigned int nv = LoadField(fields, "conditions", 0);
		for (unsigned int i = 0; i < nv; i++) {
			this->_conditions->insert(LoadField(fields, "condition" + std::to_string(i), ""));
		}
	}
	return res;
}

std::map<std::string, std::string>* Decide::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(); //Util::TypeOf<Decide>());
	SaveField(fields, "conditions", _conditions->size(), 0u);
	unsigned short i = 0;
	for (std::list<std::string>::iterator it = _conditions->list()->begin(); it != _conditions->list()->end(); it++, i++) {
		SaveField(fields, "condition" + std::to_string(i), (*it), "");
	}
	return fields;
}

bool Decide::_check(std::string* errorMessage) {
	bool allResult = true;
	std::string condition;
	for (std::list<std::string>::iterator it = _conditions->list()->begin(); it != _conditions->list()->end(); it++) {
		condition = (*it);
		allResult &= _parentModel->checkExpression(condition, "condition", errorMessage);
	}
	return allResult;
}

void Decide::_createInternalElements() {
	if (_reportStatistics && _numberOuts == nullptr) {
		_numberOuts = new List<Counter*>();
		for (unsigned int i = 0; i<this->_connections->size(); i++) {
			Counter* counter = new Counter(_parentModel, getName() + "." + "CountNumberOut" + std::to_string(i), this);
			_numberOuts->insert(counter);
			_childrenElements->insert({"CountNumberOut" + std::to_string(i), counter});
		}
	} else if (!_reportStatistics && _numberOuts != nullptr) {
		this->_removeChildrenElements();
		_numberOuts = nullptr;
	}

}

PluginInformation* Decide::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Decide>(), &Decide::LoadInstance);
	//Decide* comp = new Decide(nullptr);
	//info->setFields(comp->_saveInstance());
	//comp->~Decide();
	return info;
}

ModelComponent* Decide::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Decide* newComponent = new Decide(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}
