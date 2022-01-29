/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leave.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:14
 */

#include "Leave.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Simulator.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Leave::GetPluginInformation;
}
#endif

ModelDataDefinition* Leave::NewInstance(Model* model, std::string name) {
	return new Leave(model, name);
}

Leave::Leave(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Leave>(), name) {
}

std::string Leave::show() {
	return ModelComponent::show() + ",station=" + this->_station->getName();
}

ModelComponent* Leave::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Leave* newComponent = new Leave(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Leave::setStation(Station* _station) {
	this->_station = _station;
}

void Leave::setStationName(std::string stationName) {
	ModelDataDefinition* data = _parentModel->getDataManager()->getDataDefinition(Util::TypeOf<Station>(), stationName);
	if (data != nullptr) {
		_station = dynamic_cast<Station*> (data);
	} else {
		_station = _parentModel->getParentSimulator()->getPlugins()->newInstance<Station>(_parentModel, stationName);
	}
	_station->setEnterIntoStationComponent(this);
}

Station* Leave::getStation() const {
	return _station;
}

void Leave::_onDispatchEvent(Entity* entity) {
	if (_reportStatistics)
		_numberIn->incCountValue();
	_station->leave(entity);
	_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool Leave::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		std::string stationName = LoadField(fields, "station", "");
		Station* station = dynamic_cast<Station*> (_parentModel->getDataManager()->getDataDefinition(Util::TypeOf<Station>(), stationName));
		this->_station = station;
	}
	return res;
}

//void Leave::_initBetweenReplications() {}

std::map<std::string, std::string>* Leave::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	std::string text = "";
	if (_station != nullptr) {
		text = _station->getName();
	}
	SaveField(fields, "station", text, "", saveDefaultValues);
	return fields;
}

bool Leave::_check(std::string* errorMessage) {
	bool resultAll = true;
	resultAll &= _parentModel->getDataManager()->check(Util::TypeOf<Station>(), _station, "Station", errorMessage);
	return resultAll;
}

PluginInformation* Leave::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Leave>(), &Leave::LoadInstance, &Leave::NewInstance);
	info->insertDynamicLibFileDependence("station.so");
	info->setCategory("Material Handling");
	return info;
}

void Leave::_createInternalData() {
	if (_parentModel->isAutomaticallyCreatesModelDataDefinitions()) {
		if (_station == nullptr) {
			_station = _parentModel->getParentSimulator()->getPlugins()->newInstance<Station>(_parentModel);
			_station->setEnterIntoStationComponent(this);
		}
	}
	if (_reportStatistics) {
		if (_numberIn == nullptr) {
			_numberIn = new Counter(_parentModel, getName() + "." + "CountNumberIn", this);
			_internalData->insert({"CountNumberIn", _numberIn});
		} else
			if (_numberIn != nullptr) {
			_removeInternalDatas();
		}
	}
}

