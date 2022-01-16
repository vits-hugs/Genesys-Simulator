/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Variable.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 4 de Setembro de 2018, 18:28
 */

#include "Variable.h"
#include "../../kernel/simulator/Plugin.h"

Variable::Variable(Model* model, std::string name) : ModelData(model, Util::TypeOf<Variable>(), name) {
	setName(name);
}

std::string Variable::show() {
	std::string text = "values:{";
	for (std::pair<std::string, double> var : * this->_values) {
		text += var.first + "=" + strTruncIfInt(std::to_string(var.second)) + ", ";
	}
	text = text.substr(0, text.length() - 2);
	text += "}";
	return ModelData::show();
}

PluginInformation* Variable::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Variable>(), &Variable::LoadInstance);
	return info;
}

double Variable::getValue() {
	return getValue("");
}

double Variable::getValue(std::string index) {
	std::map<std::string, double>::iterator it = _values->find(index);
	if (it == _values->end()) {
		return 0.0; // index does not exist. Assuming sparse matrix, it's zero.
	} else {
		return it->second;
	}
}

void Variable::setValue(double value) {
	setValue("", value);
}

void Variable::setValue(std::string index, double value) {
	std::map<std::string, double>::iterator it = _values->find(index);
	if (it == _values->end()) {
		// index does not exist. Create it.
		_values->insert({index, value}); //(std::pair<std::string, double>(index, value));
	} else {
		it->second = value;
	}
}

double Variable::getInitialValue() {
	return getInitialValue("");
}

void Variable::setInitialValue(double value) {
	setInitialValue("", value);
}

double Variable::getInitialValue(std::string index) {
	std::map<std::string, double>::iterator it = _initialValues->find(index);
	if (it == _initialValues->end()) {
		return 0.0; // index does not exist. Assuming sparse matrix, it's zero.
	} else {
		return it->second;
	}
}

void Variable::setInitialValue(std::string index, double value) {
	std::map<std::string, double>::iterator it = _initialValues->find(index);
	if (it == _initialValues->end()) {
		// index does not exist. Create it.
		_initialValues->insert(std::pair<std::string, double>(index, value));
	} else {
		it->second = value;
	}
}

List<unsigned int>* Variable::getDimensionSizes() const {
	return _dimensionSizes;
}

ModelData* Variable::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Variable* newElement = new Variable(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

bool Variable::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelData::_loadInstance(fields);
	if (res) {
		std::string pos;
		double value;
		unsigned int nv;
		nv = LoadField(fields, "numDimensions", 0);
		for (unsigned int i = 0; i < nv; i++) {
			value = LoadField(fields, "dimension" + std::to_string(i), 0);
			this->_dimensionSizes->insert(value);
		}
		nv = LoadField(fields, "numValues", 0);
		for (unsigned int i = 0; i < nv; i++) {
			pos = LoadField(fields, "pos" + std::to_string(i), 0);
			value = LoadField(fields, "value" + std::to_string(i), 0);
			this->_initialValues->emplace(pos, value);
		}
	}
	return res;
}

std::map<std::string, std::string>* Variable::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelData::_saveInstance(saveDefaultValues); //Util::TypeOf<Variable>());
	unsigned int i = 0;
	SaveField(fields, "numDimensions", _dimensionSizes->list()->size(), 0u, saveDefaultValues);
	for (unsigned int dimension : *_dimensionSizes->list()) {
		SaveField(fields, "dimension" + std::to_string(i), dimension, 1u, saveDefaultValues);
	}
	SaveField(fields, "numValues", _initialValues->size(), 0);
	for (std::map<std::string, double>::iterator it = _initialValues->begin(); it != _initialValues->end(); it++, i++) {
		SaveField(fields, "pos" + std::to_string(i), (*it).first, "0", saveDefaultValues);
		SaveField(fields, "value" + std::to_string(i), (*it).second, 0.0, saveDefaultValues);
	}
	return fields;
}

bool Variable::_check(std::string* errorMessage) {
	*errorMessage += "";
	return true;
}

void Variable::_initBetweenReplications() {
	this->_values->clear();
	this->_values = this->_initialValues;
}
