/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Label.cpp
 * Author: rlcancian
 * 
 * Created on 15 de janeiro de 2022, 10:13
 */

#include "Label.h"
#include "kernel/simulator/Model.h"

Label::Label(Model* model, std::string name) : ModelElement(model, Util::TypeOf<Label>(), name) {
}

// static 

ModelElement* Label::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Label* newElement = new Label(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

PluginInformation* Label::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Label>(), &Label::LoadInstance);
	info->setDescriptionHelp("//@TODO");
	//info->setDescriptionHelp("");
	//info->setObservation("");
	//info->setMinimumOutputs();
	//info->setDynamicLibFilenameDependencies();
	//info->setFields();
	// ...
	return info;
}

//

std::string Label::show() {
	return ModelElement::show();
}

void Label::setLabel(std::string _label) {
	this->_label = _label;
}

std::string Label::getLabel() const {
	return _label;
}

ModelComponent* Label::getEnteringLabelComponent() const {
	return _enteringLabelComponent;
}

void Label::sendEntityToLabelComponent(Entity* entity, double timeDelay) {
	_parentModel->sendEntityToComponent(entity, _enteringLabelComponent->getConnections()->getFrontConnection(), timeDelay);
}

// must be overriden by derived classes

bool Label::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelElement::_loadInstance(fields);
	if (res) {
		try {
			//this->_attributeName = LoadField(fields, "attributeName", DEFAULT.attributeName);
			//this->_orderRule = static_cast<OrderRule> (LoadField(fields, "orderRule", static_cast<int> (DEFAULT.orderRule)));
		} catch (...) {
		}
	}
	return res;
}

std::map<std::string, std::string>* Label::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelElement::_saveInstance(saveDefaultValues); //Util::TypeOf<Queue>());
	//SaveField(fields, "orderRule", static_cast<int> (this->_orderRule), static_cast<int> (DEFAULT.orderRule));
	//SaveField(fields, "attributeName", this->_attributeName, DEFAULT.attributeName);
	return fields;
}

// could be overriden by derived classes

bool Label::_check(std::string* errorMessage) {
	bool resultAll = true;
	//resultAll &= _parentModel->getElements()->check(Util::TypeOf<Station>(), _station, "Station", errorMessage);
	return resultAll;
}

ParserChangesInformation* Label::_getParserChangesInformation() {
}

void Label::_initBetweenReplications() {
}

void Label::_createInternalElements() {
	if (_reportStatistics) {
		//if (_cstatNumberInQueue == nullptr) {
		//	_cstatNumberInQueue = new StatisticsCollector(_parentModel, getName() + "." + "NumberInQueue", this); /* @TODO: ++ WHY THIS INSERT "DISPOSE" AND "10ENTITYTYPE" STATCOLL ?? */
		//	_childrenElements->insert({"NumberInQueue", _cstatNumberInQueue});
		//}
	} else { //if (_cstatNumberInQueue != nullptr) {
		//_removeChildrenElements();
	}
}
