/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   File.cpp
 * Author: rlcancian
 * 
 * Created on 20 de Fileembro de 2019, 20:07
 */

#include "File.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &File::GetPluginInformation;
}
#endif

ModelDataDefinition* File::NewInstance(Model* model, std::string name) {
	return new File(model, name);
}

File::File(Model* model, std::string name) : ModelDataDefinition(model, Util::TypeOf<File>(), name) {
	//_elems = elems;
}

std::string File::show() {
	return ModelDataDefinition::show() +
			"";
}

PluginInformation* File::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<File>(), &File::LoadInstance, &File::NewInstance);
	return info;
}

ModelDataDefinition* File::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	File* newElement = new File(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

bool File::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelDataDefinition::_loadInstance(fields);
	if (res) {
		try {
			//@TODO not implemented yet
			//this->attribute = LoadField(fields, "field", DEFAULT.fields);
			
		} catch (...) {
		}
	}
	return res;
}

std::map<std::string, std::string>* File::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelDataDefinition::_saveInstance(saveDefaultValues); //Util::TypeOf<File>());
	//@TODO not implemented yet
	//SaveField(fields, "orderRule", std::to_string(static_cast<int> (this->_orderRule)));
	//SaveField(fields, "attributeName", "\""+this->_attributeName+"\"");
	return fields;
}

bool File::_check(std::string* errorMessage) {
	bool resultAll = true;
	//@TODO not implemented yet
	// resultAll |= ...
	//*errorMessage += "";
	return resultAll;
}

ParserChangesInformation* File::_getParserChangesInformation() {
	ParserChangesInformation* changes = new ParserChangesInformation();
	//@TODO not implemented yet
	//changes->getProductionToAdd()->insert(...);
	//changes->getTokensToAdd()->insert(...);
	return changes;
}

