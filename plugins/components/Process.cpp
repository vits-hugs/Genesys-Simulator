/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Process.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 22 de Maio de 2019, 18:41
 */

#include "Process.h"
//#include "../../kernel/simulator/Model.h"

Process::Process(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Process>(), name) {
	_createInternalData(); // its's called by the constructor because internal components can be accessed by process' public methods, so they must exist ever since
}

std::string Process::show() {
	return ModelComponent::show() + "";
}

void Process::setPriority(unsigned short _priority) {
	seize->setPriority(_priority);
}

unsigned short Process::getPriority() const {
	return seize->getPriority();
}

void Process::setAllocationType(unsigned int _allocationType) {
	seize->setAllocationType(_allocationType);
}

unsigned int Process::getAllocationType() const {
	return seize->getAllocationType();
}

List<SeizableItem*>* Process::getSeizeRequests() const {
	return seize->getSeizeRequests();
}

void Process::setQueueableItem(QueueableItem* _queueableItem) {
	seize->setQueueableItem(_queueableItem);
}

QueueableItem* Process::getQueueableItem() const {
	return seize->getQueueableItem();
}

void Process::setSaveAttribute(std::string _saveAttribute) {
	seize->setSaveAttribute(_saveAttribute);
}

std::string Process::getSaveAttribute() const {
	return seize->getSaveAttribute();
}

void Process::setDelayExpression(std::string _delayExpression) {
	delay->setDelayExpression(_delayExpression);
}

std::string Process::delayExpression() const {
	return delay->delayExpression();
}

void Process::setDelayTimeUnit(Util::TimeUnit _delayTimeUnit) {
	delay->setDelayTimeUnit(_delayTimeUnit);
}

Util::TimeUnit Process::delayTimeUnit() const {
	return delay->delayTimeUnit();
}

ModelComponent* Process::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Process* newComponent = new Process(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Process::_execute(Entity* entity) {
	this->_parentModel->sendEntityToComponent(entity, seize, 0.0);
}

void Process::_createInternalData() {
	if (seize == nullptr) {
		seize = new Seize(_parentModel, getName() + ".Seize");
		delay = new Delay(_parentModel, getName() + ".Delay");
		release = new Release(_parentModel, getName() + ".Release");
		seize->getConnections()->insert(delay);
		delay->getConnections()->insert(release);
		_internalData->insert({"Seize", seize});
		_internalData->insert({"Delay", delay});
		_internalData->insert({"Release", release});
	}
	release->getConnections()->list()->clear();
	if (getConnections()->size() > 0 && getConnections()->front() != seize) {
		// chance connections so Process is connected to Seize, and Release to the one Process was connected to
		_nextComponent = getConnections()->getFrontConnection()->first;
		_nextInput = getConnections()->getFrontConnection()->second;
		release->getConnections()->insert(_nextComponent, _nextInput);
		getConnections()->getFrontConnection()->first = seize;
		getConnections()->getFrontConnection()->second = 0;
	}
}

bool Process::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

std::map<std::string, std::string>* Process::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool Process::_check(std::string* errorMessage) {
	bool resultAll = true;
	// garantee that release releases exactlly whay seize seizes
	release->getReleaseRequests()->clear();
	for (SeizableItem* item : *seize->getSeizeRequests()->list()) {
		release->getReleaseRequests()->insert(item);
	}
	resultAll &= ModelComponent::Check(seize);
	resultAll &= ModelComponent::Check(delay);
	resultAll &= ModelComponent::Check(release);
	//*errorMessage += "";
	return resultAll;
}

PluginInformation* Process::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Process>(), &Process::LoadInstance);
	info->insertDynamicLibFileDependence("seize.so");
	info->insertDynamicLibFileDependence("delay.so");
	info->insertDynamicLibFileDependence("release.so");
	return info;
}
