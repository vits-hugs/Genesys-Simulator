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
#include "../../kernel/simulator/Simulator.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Process::GetPluginInformation;
}
#endif

ModelDataDefinition* Process::NewInstance(Model* model, std::string name) {
	return new Process(model, name);
}

Process::Process(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Process>(), name) {
	_createInternalData(); // its's called by the constructor because internal components can be accessed by process' public methods, so they must exist ever since
}

std::string Process::show() {
	return ModelComponent::show() + "";
}

void Process::setPriority(unsigned short _priority) {
	_seize->setPriority(_priority);
}

unsigned short Process::getPriority() const {
	return _seize->getPriority();
}

void Process::setAllocationType(unsigned int _allocationType) {
	_seize->setAllocationType(_allocationType);
}

unsigned int Process::getAllocationType() const {
	return _seize->getAllocationType();
}

List<SeizableItem*>* Process::getSeizeRequests() const {
	return _seize->getSeizeRequests();
}

void Process::setQueueableItem(QueueableItem* _queueableItem) {
	_seize->setQueueableItem(_queueableItem);
}

QueueableItem* Process::getQueueableItem() const {
	return _seize->getQueueableItem();
}

void Process::setSaveAttribute(std::string _saveAttribute) {
	_seize->setSaveAttribute(_saveAttribute);
}

std::string Process::getSaveAttribute() const {
	return _seize->getSaveAttribute();
}

void Process::setDelayExpression(std::string _delayExpression) {
	_delay->setDelayExpression(_delayExpression);
}

std::string Process::delayExpression() const {
	return _delay->delayExpression();
}

void Process::setDelayTimeUnit(Util::TimeUnit _delayTimeUnit) {
	_delay->setDelayTimeUnit(_delayTimeUnit);
}

Util::TimeUnit Process::delayTimeUnit() const {
	return _delay->delayTimeUnit();
}

ModelComponent* Process::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Process* newComponent = new Process(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Process::_onDispatchEvent(Entity* entity) {
	this->_parentModel->sendEntityToComponent(entity, _seize, 0.0);
}

void Process::_adjustConnections() {
	if (getConnections()->size() > 0 && getConnections()->front() != _seize) {
		// chance connections so Process is connected to Seize, and Release to the one that Process was connected to
		Connection* connection = new Connection();
		connection->first = getConnections()->getFrontConnection()->first;
		connection->second = getConnections()->getFrontConnection()->second;
		getConnections()->getFrontConnection()->first = _seize;
		getConnections()->getFrontConnection()->second = 0;
		_release->getConnections()->list()->clear();
		_release->getConnections()->insert(connection);
	}
}

void Process::_createInternalData() {
	if (_seize == nullptr) {
		PluginManager* plugins = _parentModel->getParentSimulator()->getPlugins();
		// the following components are created into the "_id" model level (a submodel) and therefore will not be saved
		_seize = plugins->newInstance<Seize>(_parentModel, getName() + ".Seize");
		_delay = plugins->newInstance<Delay>(_parentModel, getName() + ".Delay");
		_release = plugins->newInstance<Release>(_parentModel, getName() + ".Release");
		_seize->setModelLevel(_id); // set level as subcomponent
		_delay->setModelLevel(_id); // set level as subcomponent
		_release->setModelLevel(_id); // set level as subcomponent
		_seize->getConnections()->insert(_delay);
		_delay->getConnections()->insert(_release);
		_internalData->insert({"Seize", _seize});
		_internalData->insert({"Delay", _delay});
		_internalData->insert({"Release", _release});
	}
	_adjustConnections();
}

bool Process::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		_seize->setAllocationType(LoadField(fields, "allocationType", _seize->DEFAULT.allocationType));
		_seize->setPriority(LoadField(fields, "priority", _seize->DEFAULT.priority));
		_seize->setSaveAttribute(LoadField(fields, "saveAttribute", _seize->DEFAULT.saveAttribute));
		QueueableItem* queueableItem = new QueueableItem(nullptr);
		queueableItem->setElementManager(_parentModel->getDataManager());
		queueableItem->loadInstance(fields);
		_seize->setQueueableItem(queueableItem);
		unsigned short numRequests = LoadField(fields, "resquests", _seize->DEFAULT.seizeRequestSize);
		for (unsigned short i = 0; i < numRequests; i++) {
			SeizableItem* item = new SeizableItem(nullptr);
			item->setElementManager(_parentModel->getDataManager());
			item->loadInstance(fields, i);
			_seize->getSeizeRequests()->insert(item);
		}
		_delay->setDelayExpression(LoadField(fields, "delayExpression", _delay->DEFAULT.delayExpression));
		_delay->setDelayTimeUnit(LoadField(fields, "delayExpressionTimeUnit", _delay->DEFAULT.delayTimeUnit));
	}
	return res;
}

std::map<std::string, std::string>* Process::_saveInstance(bool saveDefaultValues) {
	_adjustConnections();
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues); //Util::TypeOf<Assign>());
	std::map<std::string, std::string>* seizefields = ModelComponent::SaveInstance(_seize);
	seizefields->erase("id");
	seizefields->erase("typename");
	seizefields->erase("name");
	seizefields->erase("nexts");
	seizefields->erase("nextId");
	seizefields->erase("caption");
	seizefields->erase("reportStatistics");
	fields->insert(seizefields->begin(), seizefields->end());
	std::map<std::string, std::string>* delayfields = ModelComponent::SaveInstance(_delay);
	delayfields->erase("id");
	delayfields->erase("typename");
	delayfields->erase("name");
	delayfields->erase("nexts");
	delayfields->erase("nextId");
	delayfields->erase("caption");
	delayfields->erase("reportStatistics");
	fields->insert(delayfields->begin(), delayfields->end());
	std::map<std::string, std::string>* releasefields = ModelComponent::SaveInstance(_release);
	fields->erase("nextId");
	std::map<std::string, std::string>::iterator it = releasefields->find("nextId");
	fields->insert((*it));
	return fields;
}

bool Process::_check(std::string* errorMessage) {
	bool resultAll = true;
	// garantee that release releases exactlly what seize seizes
	_release->getReleaseRequests()->clear();
	for (SeizableItem* item : *_seize->getSeizeRequests()->list()) {
		_release->getReleaseRequests()->insert(item);
	}
	resultAll &= ModelComponent::Check(_seize);
	resultAll &= ModelComponent::Check(_delay);
	resultAll &= ModelComponent::Check(_release);
	//*errorMessage += "";
	return resultAll;
}

PluginInformation* Process::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Process>(), &Process::LoadInstance, &Process::NewInstance);
	info->insertDynamicLibFileDependence("seize.so");
	info->insertDynamicLibFileDependence("delay.so");
	info->insertDynamicLibFileDependence("release.so");
	return info;
}
