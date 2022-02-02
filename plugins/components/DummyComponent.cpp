/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dummy.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 22 de Maio de 2019, 18:41
 */

#include "DummyComponent.h"
#include "../../kernel/simulator/Model.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &DummyComponent::GetPluginInformation;
}
#endif

ModelDataDefinition* DummyComponent::NewInstance(Model* model, std::string name) {
	return new DummyComponent(model, name);
}

DummyComponent::DummyComponent(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<DummyComponent>(), name) {
}

std::string DummyComponent::show() {
	return ModelComponent::show() + "";
}

ModelComponent* DummyComponent::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	DummyComponent* newComponent = new DummyComponent(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void DummyComponent::_onDispatchEvent(Entity* entity) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool DummyComponent::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

//void DummyComponent::_initBetweenReplications() {}

std::map<std::string, std::string>* DummyComponent::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

//bool DummyComponent::_check(std::string* errorMessage) {
//	bool resultAll = true;
//	// @TODO: not implemented yet
//	//*errorMessage += "";
//	return resultAll;
//}

//void DummyComponent::_createInternalData() {}

PluginInformation* DummyComponent::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<DummyComponent>(), &DummyComponent::LoadInstance, &DummyComponent::NewInstance);
	info->setDescriptionHelp("//@TODO");
	return info;
}
