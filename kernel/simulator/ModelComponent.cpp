/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * File:   ModelComponent.cpp
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 15:56
 */

#include "ModelComponent.h"
#include "Model.h"
#include "../TraitsKernel.h"

//using namespace GenesysKernel;

ModelComponent::ModelComponent(Model* model, std::string componentTypename, std::string name) : ModelDataDefinition(model, componentTypename, name, false) {
	model->getComponents()->insert(this);
}

ModelComponent::~ModelComponent() {
	_parentModel->getComponents()->remove(this);
}

void ModelComponent::DispatchEvent(Event* event) {
	Entity* entity = event->getEntity();
	ModelComponent* component = event->getComponent();
	unsigned int inputNumber = event->getComponentInputNumber();
	std::string msg = /*"Entity " +std::to_string(entity->entityNumber())*/ entity->getName() + " has arrived at component \"" + component->getName() + "\"";
	if (component->getDescription() != "")
		msg += ": " + component->getDescription();
	// @TODO: How can I know the number of inputs?
	if (inputNumber > 0)
		msg += " by input " + std::to_string(inputNumber);
	component->_parentModel->getTracer()->traceSimulation(component, Util::TraceLevel::L6_arrival, msg);
	Util::IncIndent();
	try {
		component->_onDispatchEvent(entity);
	} catch (const std::exception& e) {
		component->_parentModel->getTracer()->traceError(e, "Error executing component " + component->show());
	}
	Util::DecIndent();
}

void ModelComponent::CreateInternalData(ModelComponent* component) {
	//component->_model->getTraceManager()->trace(Util::TraceLevel::blockArrival, "Writing component \"" + component->_name + "\""); //std::to_string(component->_id));
	try {
		component->_createInternalData();
	} catch (const std::exception& e) {
		component->_parentModel->getTracer()->traceError(e, "Error creating elements of component " + component->show());
	};
}

std::map<std::string, std::string>* ModelComponent::SaveInstance(ModelComponent* component) {
	component->_parentModel->getTracer()->trace(Util::TraceLevel::L9_mostDetailed, "Writing component \"" + component->getName() + "\""); //std::to_string(component->_id));
	std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
	try {
		fields = component->_saveInstance(component->_getSaveDefaultsOption());
	} catch (const std::exception& e) {
		component->_parentModel->getTracer()->traceError(e, "Error executing component " + component->show());
	}
	return fields;
}

void ModelComponent::setDescription(std::string description) {
	if (_description != description) {
		this->_description = description;
		_hasChanged = true;
	}
}

std::string ModelComponent::getDescription() const {
	return _description;
}

bool ModelComponent::Check(ModelComponent* component) {
	component->_parentModel->getTracer()->trace(Util::TraceLevel::L8_detailed, "Checking " + component->_typename + ": \"" + component->getName() + "\""); //std::to_string(component->_id));
	bool res = false;
	std::string* errorMessage = new std::string();
	Util::IncIndent();
	{
		try {
			res = component->_check(errorMessage);
			if (!res) {
				component->_parentModel->getTracer()->trace(Util::TraceLevel::L1_errorFatal, "Error: Checking has failed with message '" + *errorMessage + "'");
			}
		} catch (const std::exception& e) {
			component->_parentModel->getTracer()->traceError(e, "Error verifying component " + component->show());
		}
	}
	Util::DecIndent();
	return res;
}

ConnectionManager* ModelComponent::getConnections() const {
	return _connections; // @TODO How to know if it changes?
}

std::string ModelComponent::show() {
	return ModelDataDefinition::show(); // "{id=" + std::to_string(this->_id) + ",name=\""+this->_name + "\"}"; // , nextComponents[]=(" + _nextComponents->show() + ")}";
}

bool ModelComponent::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelDataDefinition::_loadInstance(fields);
	if (res) {
		_description = LoadField(fields, "caption", DEFAULT.description);
		// Now it should load nextComponents. The problem is that the nextComponent may not be loaded yet.
		// So, what can be done is to temporarily load the ID of the nextComponents, and to wait until all the components have been loaded to update nextComponents based on the temporarilyIDs now being loaded
		//unsigned short nextSize = std::stoi((*fields->find("nextSize")).second);
		//this->_tempLoadNextComponentsIDs = new List<Util::identification>();
		//for (unsigned short i = 0; i < nextSize; i++) {
		//    Util::identification nextId = std::stoi((*fields->find("nextId" + std::to_string(i))).second);
		//    this->_tempLoadNextComponentsIDs->insert(nextId);
		//}
	}
	return res;
}

std::map<std::string, std::string>* ModelComponent::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelDataDefinition::_saveInstance(saveDefaultValues);
	SaveField(fields, "caption", _description, DEFAULT.description, saveDefaultValues);
	if (true) {//(_connections->size() != 1) { // save nextSize only if it is != 1
		SaveField(fields, "nextSize", _connections->size(), DEFAULT.nextSize, saveDefaultValues);
	}
	unsigned short i = 0;
	for (Connection* connection : *_connections->list()) {
		if (_connections->list()->size() == 1) {
			SaveField(fields, "nextId", connection->first->_id, 0, saveDefaultValues);
		} else {
			SaveField(fields, "nextId" + std::to_string(i), connection->first->_id, 0, saveDefaultValues);
		}
		if (connection->second != 0) {//((*it)->second != 0) { // save nextInputNumber only if it is != 0
			SaveField(fields, "nextInputNumber" + std::to_string(i), connection->second, DEFAULT.nextInputNumber, saveDefaultValues);
		}
		i++;
	}
	return fields;
}

//void ModelComponent::_createInternalData() {}
