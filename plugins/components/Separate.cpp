/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Separate.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:14
 */

#include "Separate.h"

#include "../../kernel/simulator/Model.h"
#include "plugins/elements/EntityGroup.h"

Separate::Separate(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Separate>(), name) {
}

std::string Separate::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Separate::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Separate* newComponent = new Separate(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Separate::_execute(Entity* entity) {
	unsigned int groupId = entity->getAttributeValue("Entity.Group"); //This attribute refers to the Batch internal element EntityGroup (which may contain several groups --map--
	if (groupId == 0) {
		_parentModel->getTracer()->traceSimulation(Util::TraceLevel::L7_internal, "Entity is not grouped. Nothing to do");
		this->_parentModel->sendEntityToComponent(entity, getConnections()->getFrontConnection());
	} else {
		EntityGroup* eg = dynamic_cast<EntityGroup*> (_parentModel->getElements()->getElement(Util::TypeOf<EntityGroup>(), groupId));
		if (eg == nullptr) {
			_parentModel->getTracer()->traceSimulation(Util::TraceLevel::L3_errorRecover, "Error: Could not find EntityGroup Id=" + std::to_string(groupId));
		} else {
			Entity* e;
			unsigned int idGroupKey = entity->getId();
			while ((e = eg->getGroup(idGroupKey)->front()) != nullptr) {
				eg->removeElement(idGroupKey, e);
				_parentModel->getTracer()->traceSimulation(Util::TraceLevel::L7_internal, "Entity " + e ->getName() + " was separated out of the group " + std::to_string(idGroupKey));
				_parentModel->sendEntityToComponent(e, _connections->getFrontConnection());
			}
			_parentModel->getElements()-> remove(Util::TypeOf<EntityGroup>(), eg);
			_parentModel->removeEntity(entity);
		}
	}
}

bool Separate::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

//void Separate::_initBetweenReplications() {}

std::map<std::string, std::string>* Separate::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool Separate::_check(std::string* errorMessage) {
	bool resultAll = true;
	// @TODO: not implemented yet
	*errorMessage += "";
	return resultAll;
}

PluginInformation* Separate::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Separate>(), &Separate::LoadInstance);
	// ...
	return info;
}

