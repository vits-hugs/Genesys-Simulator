/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   CppForG.cpp
 * Author: rlcancian
 * 
 * Created on 11 de janeiro de 2022, 22:37
 */

#include "CppForG.h"
#include "../../kernel/simulator/Model.h"

CppForG::CppForG(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<CppForG>(), name) {
	_createInternalData();
}

std::string CppForG::show() {
	return ModelComponent::show() + "";
}

ModelComponent* CppForG::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	CppForG* newComponent = new CppForG(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void CppForG::setSourceCode(std::string _sourceCode) {
	this->_cppcode->setCode(_sourceCode);
}

std::string CppForG::getSourceCode() const {
	return _cppcode->getCode();
}

void CppForG::_execute(Entity* entity) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool CppForG::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

//void CppForG::_initBetweenReplications() {}

std::map<std::string, std::string>* CppForG::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

bool CppForG::_check(std::string* errorMessage) {
	bool resultAll = true;
	CppCode::CodeResult result;
	if (_cppcode->IsLibraryLoaded()) {
		result = _cppcode->unloadLibrary();
		resultAll = result.success;
	}
	if (resultAll) {
		result = _cppcode->compile();
		resultAll = result.success;
		if (resultAll) {
			result = _cppcode->loadLibrary();
			resultAll = result.success;
		}
	}
	if (!resultAll) {
		*errorMessage += result.generalMessage;
	}
	return resultAll;
}

void CppForG::_createInternalData() {
	if (_cppcode == nullptr) {
		_cppcode = new CppCode(_parentModel, getName() + ".CppCode");
		_internalData->insert({"CppCode", _cppcode});
	}
}

PluginInformation* CppForG::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<CppForG>(), &CppForG::LoadInstance);
	info->insertDynamicLibFileDependence("cppcode.so");
	info->setDescriptionHelp("//@TODO");
	return info;
}

