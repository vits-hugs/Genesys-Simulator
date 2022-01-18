/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Assign.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 31 de Agosto de 2018, 10:10
 */

#include "Assign.h"
#include <string>
#include "../../kernel/simulator/Model.h"
#include "../data/Variable.h"
#include "../../kernel/simulator/Attribute.h"
#include "../data/Resource.h"

Assign::Assign(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Assign>(), name) {
}

std::string Assign::show() {
	std::string txt = ModelComponent::show() + ",assignments=[";
	for (std::list<Assignment*>::iterator it = _assignments->list()->begin(); it != _assignments->list()->end(); it++) {
		txt += (*it)->getDestination() + "=" + (*it)->getExpression() + ",";
	}
	txt = txt.substr(0, txt.length() - 1) + "]";
	return txt;
}

List<Assign::Assignment*>* Assign::getAssignments() const {
	return _assignments;
}

PluginInformation* Assign::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Assign>(), &Assign::LoadInstance);
	//info->insertDynamicLibFileDependence("attribute.so");
	info->insertDynamicLibFileDependence("variable.so");
	info->setCategory("Discrete Processing");
	std::string text = "";
	text += "This module is used for assigning new values to variables, entity attributes, entity types, entity pictures, or other system variables.";
	text += " Multiple assignments can be made with a single Assign module.";
	text += " TYPICAL USES: (1) Accumulate the number of subassemblies added to a part;";
	text += " (2) Change an entity’s type to represent the customer copy of a multi - page form;";
	text += " (3) Establish a customer’s priority";
	info->setDescriptionHelp(text);

	return info;
}

ModelComponent* Assign::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Assign* newComponent = new Assign(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}

	return newComponent;
}

void Assign::_onDispatchEvent(Entity* entity) {
	Assignment* let;
	std::list<Assignment*>* lets = this->_assignments->list();
	for (std::list<Assignment*>::iterator it = lets->begin(); it != lets->end(); it++) {

		let = (*it);
		double value = _parentModel->parseExpression(let->getExpression());
		_parentModel->parseExpression(let->getDestination() + "=" + std::to_string(value));
		_parentModel->getTracer()->traceSimulation(this, "Let \"" + let->getDestination() + "\" = " + strTruncIfInt(std::to_string(value)) + "  // " + let->getExpression());
	}

	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

//void Assign::_initBetweenReplications() {}

bool Assign::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		unsigned int nv = LoadField(fields, "assignments", DEFAULT.assignmentsSize);
		for (unsigned int i = 0; i < nv; i++) {

			std::string dest = LoadField(fields, "destination" + std::to_string(i), "");
			std::string exp = LoadField(fields, "expression" + std::to_string(i), "");
			Assignment* assmt = new Assignment(dest, exp);
			this->_assignments->insert(assmt);
		}
	}
	return res;
}

std::map<std::string, std::string>* Assign::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues); //Util::TypeOf<Assign>());
	Assignment* let;
	SaveField(fields, "assignments", _assignments->size(), DEFAULT.assignmentsSize, saveDefaultValues);
	unsigned short i = 0;
	for (std::list<Assignment*>::iterator it = _assignments->list()->begin(); it != _assignments->list()->end(); it++, i++) {

		let = (*it);
		SaveField(fields, "destination" + std::to_string(i), let->getDestination(), "", saveDefaultValues);
		SaveField(fields, "expression" + std::to_string(i), let->getExpression(), "", saveDefaultValues);
	}
	return fields;
}

bool Assign::_check(std::string* errorMessage) {
	bool resultAll = true;
	// @TODO: Reimplement it. Since 201910, attributes may have index, just like "atrrib1[2]" or "att[10,1]". Because of that, the string may contain not only the name of the attribute, but also its index and therefore, fails on the test bellow.
	for (Assignment* let : *_assignments->list()) {
		resultAll &= _parentModel->checkExpression(let->getExpression(), "assignment", errorMessage);
	}
	return resultAll;
}