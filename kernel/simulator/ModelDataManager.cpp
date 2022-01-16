/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ElementManager.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 7 de Novembro de 2018, 12:48
 */

#include "ModelDataManager.h"
#include "Model.h"

//using namespace GenesysKernel;

ModelDataManager::ModelDataManager(Model* model) {
	_parentModel = model;
	/// Elements are organized as a map from a string (key), the type of an modeldatum, and a list of elements of that type
	_elements = new std::map<std::string, List<ModelData*>*>();
}

bool ModelDataManager::insert(ModelData * anElement) {
	std::string elementTypename = anElement->getClassname();
	return insert(elementTypename, anElement);
}

bool ModelDataManager::insert(std::string elementTypename, ModelData * anElement) {
	List<ModelData*>* listElements = getElementList(elementTypename);
	std::string text = "";
	bool result = false;
	if (listElements->find(anElement) == listElements->list()->end()) { //not found
		listElements->insert(anElement);
		_hasChanged = true;
		text = anElement->getClassname() + " \"" + anElement->getName() + "\"" + " successfully inserted.";
		result = true;
		//	} else {
		//		text = anElement->getClassname() + " \"" + anElement->getName() + "\" already exists.";
	}
	if (_parentModel->getSimulation()->isRunning()) {
		_parentModel->getTracer()->traceSimulation(this, Util::TraceLevel::L8_detailed, text);
	} else {
		_parentModel->getTracer()->trace(Util::TraceLevel::L8_detailed, text);
	}
	return result;
}

void ModelDataManager::remove(ModelData * anElement) {
	std::string elementTypename = anElement->getClassname();
	List<ModelData*>* listElements = getElementList(elementTypename);
	listElements->remove(anElement);
	_hasChanged = true;
	_parentModel->getTracer()->trace(Util::TraceLevel::L8_detailed, "Element successfully removed.");

}

void ModelDataManager::remove(std::string elementTypename, ModelData * anElement) {
	List<ModelData*>* listElements = getElementList(elementTypename);
	_hasChanged = true;
	listElements->remove(anElement);
}

bool ModelDataManager::check(std::string elementTypename, std::string elementName, std::string expressionName, bool mandatory, std::string * errorMessage) {
	if (elementName == "" && !mandatory) {
		return true;
	}
	bool result = getData(elementTypename, elementName) != nullptr;
	if (!result) {
		std::string msg = elementTypename + " \"" + elementName + "\" for '" + expressionName + "' is not in the model.";
		errorMessage->append(msg);
	}
	return result;
}

bool ModelDataManager::check(std::string elementTypename, ModelData* anElement, std::string expressionName, std::string * errorMessage) {
	bool result = anElement != nullptr;
	if (!result) {
		std::string msg = elementTypename + " for '" + expressionName + "' is null.";
		errorMessage->append(msg);
	} else {
		result = check(elementTypename, anElement->getName(), expressionName, true, errorMessage);
	}
	return result;
}

void ModelDataManager::clear() {
	_hasChanged = true;
	this->_elements->clear();
}

unsigned int ModelDataManager::getNumberOfElements(std::string elementTypename) {
	List<ModelData*>* listElements = getElementList(elementTypename);
	return listElements->size();
}

unsigned int ModelDataManager::getNumberOfElements() {
	unsigned int total = 0;
	for (std::map<std::string, List<ModelData*>*>::iterator it = _elements->begin(); it != _elements->end(); it++) {
		total += (*it).second->size();
	}
	return total;
}

void ModelDataManager::show() {
	_parentModel->getTracer()->trace(Util::TraceLevel::L8_detailed, "Model Elements:");
	//std::map<std::string, List<ModelData*>*>* _elements;
	std::string key;
	List<ModelData*>* list;
	Util::IncIndent();
	{
		for (std::map<std::string, List<ModelData*>*>::iterator infraIt = _elements->begin(); infraIt != _elements->end(); infraIt++) {
			key = (*infraIt).first;
			list = (*infraIt).second;
			_parentModel->getTracer()->trace(Util::TraceLevel::L8_detailed, key + ": (" + std::to_string(list->size()) + ")");
			Util::IncIndent();
			{
				for (std::list<ModelData*>::iterator it = list->list()->begin(); it != list->list()->end(); it++) {
					_parentModel->getTracer()->trace(Util::TraceLevel::L8_detailed, (*it)->show());
				}
			}
			Util::DecIndent();
		}
	}
	Util::DecIndent();
}

Model * ModelDataManager::getParentModel() const {
	return _parentModel;
}

bool ModelDataManager::hasChanged() const {
	if (_hasChanged)
		return _hasChanged;
	else {
		for (std::pair<std::string, List<ModelData*>*> pair : *_elements) {
			for (ModelData* modeldatum : *pair.second->list()) {
				if (modeldatum->hasChanged()) {
					return true;
				}
			}
		}
	}
	return false;
}

void ModelDataManager::setHasChanged(bool _hasChanged) {
	this->_hasChanged = _hasChanged;
}

List<ModelData*>* ModelDataManager::getElementList(std::string elementTypename) const {
	std::map<std::string, List<ModelData*>*>::iterator it = this->_elements->find(elementTypename);
	if (it == this->_elements->end()) {
		// list does not exists yet. Create it and set a valid iterator
		List<ModelData*>* newList = new List<ModelData*>();
		newList->setSortFunc([](const ModelData* a, const ModelData * b) {
			return a->getId() < b->getId();
		});
		_elements->insert(std::pair<std::string, List<ModelData*>*>(elementTypename, newList));
		it = this->_elements->find(elementTypename);
	}
	List<ModelData*>* infras = it->second;
	return infras;
}

ModelData * ModelDataManager::getData(std::string elementTypename, Util::identification id) {
	List<ModelData*>* list = getElementList(elementTypename);
	for (std::list<ModelData*>::iterator it = list->list()->begin(); it != list->list()->end(); it++) {
		if ((*it)->getId() == id) { // found
			return (*it);
		}
	}
	return nullptr;
}

int ModelDataManager::getRankOf(std::string elementTypename, std::string name) {
	int rank = 0;
	List<ModelData*>* list = getElementList(elementTypename);
	for (std::list<ModelData*>::iterator it = list->list()->begin(); it != list->list()->end(); it++) {
		if ((*it)->getName() == name) { // found
			return rank;
		} else {
			rank++;
		}
	}
	return -1;
}

std::list<std::string>* ModelDataManager::getElementClassnames() const {
	std::list<std::string>* keys = new std::list<std::string>();
	for (std::map<std::string, List<ModelData*>*>::iterator it = _elements->begin(); it != _elements->end(); it++) {
		keys->insert(keys->end(), (*it).first);
	}
	return keys;
}

ModelData * ModelDataManager::getData(std::string elementTypename, std::string name) {
	List<ModelData*>* list = getElementList(elementTypename);
	for (std::list<ModelData*>::iterator it = list->list()->begin(); it != list->list()->end(); it++) {
		if ((*it)->getName() == name) { // found
			return (*it);
		}
	}
	return nullptr;
}