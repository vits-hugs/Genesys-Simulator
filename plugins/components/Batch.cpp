/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Batch.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:14
 */

#include "Batch.h"

#include "../../kernel/simulator/Model.h"

Batch::Batch(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Batch>(), name) {
}

std::string Batch::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Batch::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Batch* newComponent = new Batch(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Batch::_execute(Entity* entity) {
	//_parentModel->getTracer()->traceSimulation("I'm just a dummy model and I'll just send the entity forward");


	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool Batch::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

std::map<std::string, std::string>* Batch::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

void Batch::_initBetweenReplications() {
}

void Batch::_createInternalElements() {
	if (_queue == nullptr) {
		_queue = new Queue(_parentModel, this->getName() + ".Queue");
		_internalElements->insert({"EntityQueue"}, _queue);
	}
}

bool Batch::_check(std::string* errorMessage) {
	bool resultAll = true;
	*errorMessage += "";
	// @TODO: not implemented yet
	return resultAll;
}

PluginInformation* Batch::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Batch>(), &Batch::LoadInstance);
	info->insertDynamicLibFileDependence("entitygroup.so");
	std::string help = "This module is intended as the grouping mechanism within the simulation model.";
	help += " Batches can be permanently or temporarily grouped.";
	help += " Temporary batches must later be split using the Separate module.";
	help += " Batches may be made with any specified number of entering entities or may be matched together based on an attribute.";
	help += " Entities arriving at the Batch module are placed in a queue until the required number of entities has accumulated.";
	help += " Once accumulated, a new representative entity is created.";
	help += " Animation showing the number of entities waiting to be batched, as well as an animated queue for waiting entities, is displayed when the module is placed.";
	help += " TYPICAL USES: (1) Collect a defined number of parts before starting processing; (2) Reassemble previously separated copies of a form;";
	help += " (3) Bring together a patient and his record before commencing an appointment";
	info->setDescriptionHelp(help);
	return info;
}


