/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ExFiStatMac.cpp
 * Author: rlcancian
 * 
 * Created on 7 de agosto de 2022, 12:14
 */

#include "ExFiStatMac.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &ExFiStatMac::GetPluginInformation;
}
#endif

// constructors

ModelDataDefinition* ExFiStatMac::NewInstance(Model* model, std::string name) {
	return new ExFiStatMac(model, name);
}

ExFiStatMac::ExFiStatMac(Model* model, std::string name) : ModelDataDefinition(model, Util::TypeOf<ExFiStatMac>(), name) {
}

//public

std::string ExFiStatMac::show() {
	return ModelDataDefinition::show();
}

// public static 

ModelDataDefinition* ExFiStatMac::LoadInstance(Model* model, PersistenceRecord *fields) {
	ExFiStatMac* newElement = new ExFiStatMac(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

PluginInformation* ExFiStatMac::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<ExFiStatMac>(), &ExFiStatMac::LoadInstance, &ExFiStatMac::NewInstance);
	info->setDescriptionHelp("//@TODO");
	//info->setDescriptionHelp("");
	//info->setObservation("");
	//info->setMinimumOutputs();
	//info->setDynamicLibFilenameDependencies();
	//info->setFields();
	// ...
	return info;
}

// protected virtual -- must be overriden 

bool ExFiStatMac::_loadInstance(PersistenceRecord *fields) {
	bool res = ModelDataDefinition::_loadInstance(fields);
	if (res) {
		try {
			this->_someString = fields->loadField("someString", DEFAULT.someString);
			this->_someUint = fields->loadField("someUint", DEFAULT.someUint);
		} catch (...) {
		}
	}
	return res;
}

void ExFiStatMac::_saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {
	ModelDataDefinition::_saveInstance(fields, saveDefaultValues);
	fields->saveField("someUint", _someUint, DEFAULT.someUint);
	fields->saveField("someString", _someString, DEFAULT.someString);
}

// protected virtual -- could be overriden 

//ParserChangesInformation* ExFiStatMac::_getParserChangesInformation() {}

bool ExFiStatMac::_check(std::string* errorMessage) {
	bool resultAll = true;
	resultAll &= _someString != "";
	resultAll &= _someUint > 0;
	return resultAll;
}

void ExFiStatMac::_initBetweenReplications() {
	_someString = "Test";
	_someUint = 1;
}

void ExFiStatMac::_createInternalAndAttachedData() {
	if (_reportStatistics) {
		//if (_internal == nullptr) {
		//	_internal = new StatisticsCollector(_parentModel, getName() + "." + "NumberInQueue", this); 
		//	_internelElementsInsert("NumberInQueue", _internal);
		//}
	} else { //if (_cstatNumberInQueue != nullptr) {
		this->_internalDataClear();
	}
}


