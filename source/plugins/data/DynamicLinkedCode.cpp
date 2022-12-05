/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   DynamicLinkedCode.cpp
 * Author: rlcancian
 * 
 * Created on 11 de janeiro de 2022, 22:24
 */

#include "DynamicLinkedCode.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &DynamicLinkedCode::GetPluginInformation;
}
#endif

ModelDataDefinition* DynamicLinkedCode::NewInstance(Model* model, std::string name) {
	return new DynamicLinkedCode(model, name);
}

DynamicLinkedCode::DynamicLinkedCode(Model* model, std::string name) : ModelDataDefinition(model, Util::TypeOf<DynamicLinkedCode>(), name) {
}

// static 

ModelDataDefinition* DynamicLinkedCode::LoadInstance(Model* model, PersistenceRecord *fields) {
	DynamicLinkedCode* newElement = new DynamicLinkedCode(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

PluginInformation* DynamicLinkedCode::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<DynamicLinkedCode>(), &DynamicLinkedCode::LoadInstance, &DynamicLinkedCode::NewInstance);
	info->setDescriptionHelp("//@TODO");
	//info->setObservation("");
	//info->setMinimumOutputs();
	//info->setDynamicLibFilenameDependencies();
	//info->setFields();
	// ...
	return info;
}

//

std::string DynamicLinkedCode::show() {
	return ModelDataDefinition::show();
}

void DynamicLinkedCode::setCode(std::string _code) {
	this->_code = _code;
}

std::string DynamicLinkedCode::getCode() const {
	return _code;
}
// must be overriden 

bool DynamicLinkedCode::_loadInstance(PersistenceRecord *fields) {
	bool res = ModelDataDefinition::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

void DynamicLinkedCode::_saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {
	ModelDataDefinition::_saveInstance(fields, saveDefaultValues);
	// @TODO: not implemented yet
}

// could be overriden 

bool DynamicLinkedCode::_check(std::string* errorMessage) {
	return true;
}

void DynamicLinkedCode::_createInternalAndAttachedData() {
}

DynamicLinkedCode::CodeResult DynamicLinkedCode::compile() {
	DynamicLinkedCode::CodeResult result;
	return result;
}

DynamicLinkedCode::CodeResult DynamicLinkedCode::loadLibrary() {
	DynamicLinkedCode::CodeResult result;
	return result;
}

DynamicLinkedCode::CodeResult DynamicLinkedCode::unloadLibrary() {
	DynamicLinkedCode::CodeResult result;
	return result;
}

bool DynamicLinkedCode::IsLibraryLoaded() const {
	return libraryLoaded;
}

