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
	std::string help = "Label element module represents a name to where entities can be sent to.";
	help += "Any receiving transfer module such as 'Enter' can be assigned to a label.";
	help += "Any other sending transfer module such as 'Route' can send an entity to a label, which corresponds to send it to the receiving module";
	help += "TIPICAL USES include sending an entity to somewhere else without a direct connection.";
	info->setDescriptionHelp(help);
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
	//_parentModel->sendEntityToComponent(entity, _enteringLabelComponent->getConnections()->getFrontConnection(), timeDelay);
	_parentModel->sendEntityToComponent(entity, _enteringLabelComponent, timeDelay);
}

// must be overriden by derived classes

bool Label::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelElement::_loadInstance(fields);
	if (res) {
		try {
			this->_label = LoadField(fields, "label", "");
			std::string componentName = LoadField(fields, "enteringLabelComponent", "");
			ModelComponent* comp = _parentModel->getComponents()->find(componentName);
			if (comp != nullptr) {
				this->_enteringLabelComponent = comp;
			}
		} catch (...) {
		}
	}
	return res;
}

std::map<std::string, std::string>* Label::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelElement::_saveInstance(saveDefaultValues); //Util::TypeOf<Queue>());
	SaveField(fields, "label", this->_label, "", saveDefaultValues);
	SaveField(fields, "enteringLabelComponent", this->_enteringLabelComponent->getName(), "", saveDefaultValues);
	return fields;
}

// could be overriden by derived classes

bool Label::_check(std::string* errorMessage) {
	bool resultAll = true;
	resultAll &= (_enteringLabelComponent != nullptr);
	if (!resultAll) {
		*errorMessage += "Entering Label Component was not defined";
	}
	return resultAll;
}

//ParserChangesInformation* Label::_getParserChangesInformation() {}

//void Label::_initBetweenReplications() {}

//void Label::_createInternalElements() {}
