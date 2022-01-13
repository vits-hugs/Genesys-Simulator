/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Set.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:11
 */

#include "Set.h"
#include "../../kernel/simulator/Model.h"

Set::Set(Model* model, std::string name) : ModelElement(model, Util::TypeOf<Set>(), name) {
}

std::string Set::show() {
	return ModelElement::show() +
			"";
}

void Set::setSetOfType(std::string _setOfType) {
	this->_setOfType = _setOfType;
}

std::string Set::getSetOfType() const {
	return _setOfType;
}

List<ModelElement*>* Set::getElementSet() const {
	return _elementSet;
}

PluginInformation* Set::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Set>(), &Set::LoadInstance);
	return info;
}

ModelElement* Set::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Set* newElement = new Set(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

bool Set::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelElement::_loadInstance(fields);
	if (res) {
		try {
			_setOfType = LoadField(fields, "type", DEFAULT.setOfType);
			unsigned int memberSize = LoadField(fields, "memberSize", DEFAULT.membersSize);
			for (unsigned int i = 0; i < memberSize; i++) {
				std::string memberName = LoadField(fields, "member" + std::to_string(i));
				ModelElement* member = _parentModel->getElements()->getElement(_setOfType, memberName);
				if (member == nullptr) { // not found. That's a problem. Resource not loaded yet (or mismatch name
					_parentModel->getTracer()->trace("ERROR: Could not found " + _setOfType + " set member named \"" + memberName + "\"", Util::TraceLevel::L1_errorFatal);
				} else {//found
					_elementSet->insert(member);
				}
			}
		} catch (...) {
		}
	}
	return res;
}

std::map<std::string, std::string>* Set::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelElement::_saveInstance(saveDefaultValues); //Util::TypeOf<Set>());
	SaveField(fields, "type", _setOfType, DEFAULT.setOfType, saveDefaultValues);
	SaveField(fields, "membersSize", _elementSet->size(), DEFAULT.membersSize, saveDefaultValues);
	unsigned int i = 0;
	for (ModelElement* element : *_elementSet->list()) {
		SaveField(fields, "member" + std::to_string(i), element->getName(), saveDefaultValues);
		i++;
	}
	return fields;
}

bool Set::_check(std::string* errorMessage) {
	bool resultAll = true;
	if (_elementSet->size() > 0) {
		std::string typeOfFirstElement = _elementSet->front()->getClassname();
		if (_setOfType == "") {
			_setOfType = typeOfFirstElement;
		} else if (_setOfType != typeOfFirstElement) {
			resultAll = false;
			*errorMessage += "Set is of type \"" + _setOfType + "\" and first element is of type \"" + typeOfFirstElement + "\"";
		}
	}
	*errorMessage += "";
	return resultAll;
}

ParserChangesInformation* Set::_getParserChangesInformation() {
	ParserChangesInformation* changes = new ParserChangesInformation();
	//changes->getProductionToAdd()->insert(...);
	//changes->getTokensToAdd()->insert(...);
	return changes;
}

