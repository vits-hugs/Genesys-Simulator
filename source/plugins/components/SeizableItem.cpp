/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SeizableItem.cpp
 * Author: rlcancian
 *
 * Created on 10 de abril de 2021, 08:45
 */

#include "SeizableItem.h"
#include "../../kernel/simulator/ModelDataDefinition.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Simulator.h"
#include <cassert>

SeizableItem::SeizableItem(ModelDataDefinition* resourceOrSet, std::string quantityExpression, SeizableItem::SelectionRule selectionRule, std::string saveAttribute, std::string index) {
    SeizableItem::SeizableType resourceType;
    if (dynamic_cast<Resource*> (resourceOrSet) != nullptr) {
        resourceType = SeizableItem::SeizableType::RESOURCE;
    } else if (dynamic_cast<Set*> (resourceOrSet) != nullptr) {
        resourceType = SeizableItem::SeizableType::SET;
    } else {
        //assert(false);//@TODO
    }
    _seizableType = resourceType;
    _resourceOrSet = resourceOrSet;
    _quantityExpression = quantityExpression;
    _selectionRule = selectionRule;
    _saveAttribute = saveAttribute;
    _index = index;
}

SeizableItem::SeizableItem(Model* model, std::string resourceName, std::string quantityExpression, SeizableItem::SelectionRule selectionRule, std::string saveAttribute, std::string index) {
    ModelDataDefinition* resource = model->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), resourceName);
    if (resource == nullptr && model->isAutomaticallyCreatesModelDataDefinitions()) {
        resource = model->getParentSimulator()->getPlugins()->newInstance<Resource>(model, resourceName);
    }
    SeizableItem(resource, quantityExpression, selectionRule, saveAttribute, index);
}

/*
SeizableItem::SeizableItem(ModelDataDefinition* resourceOrSet, SeizableItem::SeizableType resourceType, std::string quantityExpression, SeizableItem::SelectionRule selectionRule, std::string saveAttribute, std::string index) {
        // TODO: It could infer _seizableType from resourceOrSet and avoid resourceType parameter
        _seizableType = resourceType;
        _resourceOrSet = resourceOrSet;
        _quantityExpression = quantityExpression;
        _selectionRule = selectionRule;
        _saveAttribute = saveAttribute;
        _index = index;
}
 */

bool SeizableItem::loadInstance(std::map<std::string, std::string>* fields) {
    bool res = true;
    try {
        _seizableType = static_cast<SeizableItem::SeizableType> (LoadField(fields, "requestSeizableType", static_cast<int> (DEFAULT.seizableType)));
        _seizableName = LoadField(fields, "requestSeizable", "");
        _quantityExpression = LoadField(fields, "requestQuantityExpression", DEFAULT.quantityExpression);
        _selectionRule = static_cast<SeizableItem::SelectionRule> (LoadField(fields, "requestSelectionRule", static_cast<int> (DEFAULT.selectionRule)));
        _saveAttribute = LoadField(fields, "requestSaveAttribute", DEFAULT.saveAttribute);
        _index = LoadField(fields, "requestIndex", DEFAULT.index);
        if (_modeldataManager != nullptr) {
            if (_seizableType == SeizableItem::SeizableType::RESOURCE) {
                _resourceOrSet = _modeldataManager->getDataDefinition(Util::TypeOf<Resource>(), _seizableName);
            } else if (_seizableType == SeizableItem::SeizableType::SET) {
                _resourceOrSet = _modeldataManager->getDataDefinition(Util::TypeOf<Set>(), _seizableName);
            }
            //assert(_resourceOrSet != nullptr); // @TODO TraceError
        }
    } catch (...) {
        res = false;
    }
    return res;
}

bool SeizableItem::loadInstance(std::map<std::string, std::string>* fields, unsigned int parentIndex) {
    bool res = true;
    std::string num = strIndex(parentIndex);
    try {
        _seizableType = static_cast<SeizableItem::SeizableType> (LoadField(fields, "requestSeizableType" + num, static_cast<int> (DEFAULT.seizableType)));
        _seizableName = LoadField(fields, "requestSeizable" + num, "");
        _quantityExpression = LoadField(fields, "requestQuantityExpression" + num, DEFAULT.quantityExpression);
        _selectionRule = static_cast<SeizableItem::SelectionRule> (LoadField(fields, "requestSelectionRule" + num, static_cast<int> (DEFAULT.selectionRule)));
        _saveAttribute = LoadField(fields, "requestSaveAttribute" + num, DEFAULT.saveAttribute);
        _index = LoadField(fields, "requestIndex" + num, DEFAULT.index);
        if (_modeldataManager != nullptr) {
            if (_seizableType == SeizableItem::SeizableType::RESOURCE) {
                _resourceOrSet = _modeldataManager->getDataDefinition(Util::TypeOf<Resource>(), _seizableName);
            } else if (_seizableType == SeizableItem::SeizableType::SET) {
                _resourceOrSet = _modeldataManager->getDataDefinition(Util::TypeOf<Set>(), _seizableName);
            } else {
                _resourceOrSet = nullptr;
                _modeldataManager->getParentModel()->getTracer()->traceError("SeizableItem named '" + _seizableName + "' could not be found on loading");
            }
            //assert(_resourceOrSet != nullptr); // @TODO TraceError
        }
    } catch (...) {
        res = false;
    }
    return res;
}

std::map<std::string, std::string>* SeizableItem::saveInstance(unsigned int parentIndex, bool saveDefaults) {
    std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
    std::string num = strIndex(parentIndex);
    SaveField(fields, "requestSeizableType" + num, static_cast<int> (_seizableType), static_cast<int> (DEFAULT.seizableType), saveDefaults);
    SaveField(fields, "requestSeizable" + num, _resourceOrSet->getName(), "", saveDefaults);
    SaveField(fields, "requestQuantityExpression" + num, _quantityExpression, DEFAULT.quantityExpression, saveDefaults);
    SaveField(fields, "requestSelectionRule" + num, static_cast<int> (_selectionRule), static_cast<int> (DEFAULT.selectionRule), saveDefaults);
    SaveField(fields, "requestSaveAttribute" + num, _saveAttribute, DEFAULT.saveAttribute, saveDefaults);
    SaveField(fields, "requestIndex" + num, _index, DEFAULT.index, saveDefaults);
    return fields;
}

std::map<std::string, std::string>* SeizableItem::saveInstance(bool saveDefaults) {
    std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
    SaveField(fields, "requestSeizableType", static_cast<int> (_seizableType), static_cast<int> (DEFAULT.seizableType), saveDefaults);
    //SaveField(fields, "resourceId", _resourceOrSet->getId());
    SaveField(fields, "requestSeizable", _resourceOrSet->getName(), "", saveDefaults);
    SaveField(fields, "requestQuantityExpression", _quantityExpression, DEFAULT.quantityExpression, saveDefaults);
    SaveField(fields, "requestSelectionRule", static_cast<int> (_selectionRule), static_cast<int> (DEFAULT.selectionRule), saveDefaults);
    SaveField(fields, "requestSaveAttribute", _saveAttribute, DEFAULT.saveAttribute, saveDefaults);
    SaveField(fields, "requestIndex", _index, DEFAULT.index, saveDefaults);
    return fields;
}

std::string SeizableItem::show() {
    return "resourceType=" + std::to_string(static_cast<int> (_seizableType)) + ",resource=\"" + _resourceOrSet->getName() + "\",quantityExpression=\"" + _quantityExpression + "\", selectionRule=" + std::to_string(static_cast<int> (_selectionRule)) + ", _saveAttribute=\"" + _saveAttribute + "\",index=\"" + _index + "\"";
}

void SeizableItem::setIndex(std::string index) {
    this->_index = index;
}

std::string SeizableItem::getIndex() const {
    return _index;
}

void SeizableItem::setSaveAttribute(std::string saveAttribute) {
    this->_saveAttribute = saveAttribute;
}

std::string SeizableItem::getSaveAttribute() const {
    return _saveAttribute;
}

void SeizableItem::setSelectionRule(SeizableItem::SelectionRule selectionRule) {
    this->_selectionRule = selectionRule;
}

SeizableItem::SelectionRule SeizableItem::getSelectionRule() const {
    return _selectionRule;
}

void SeizableItem::setQuantityExpression(std::string quantityExpression) {
    this->_quantityExpression = quantityExpression;
}

std::string SeizableItem::getQuantityExpression() const {
    return _quantityExpression;
}

std::string SeizableItem::getResourceName() const {
    return _seizableName;
}

void SeizableItem::setResource(Resource* resource) {
    this->_resourceOrSet = resource;
    _seizableName = resource->getName();
}

Resource* SeizableItem::getResource() const {
    return static_cast<Resource*> (_resourceOrSet);
}

void SeizableItem::setSet(Set* set) {
    this->_resourceOrSet = set;
    _seizableName = set->getName();
}

Set* SeizableItem::getSet() const {
    return static_cast<Set*> (_resourceOrSet);
}

void SeizableItem::setSeizableType(SeizableItem::SeizableType resourceType) {
    this->_seizableType = resourceType;
}

SeizableItem::SeizableType SeizableItem::getSeizableType() const {
    return _seizableType;
}

void SeizableItem::setLastMemberSeized(unsigned int lastMemberSeized) {
    this->_lastMemberSeized = lastMemberSeized;
}

unsigned int SeizableItem::getLastMemberSeized() const {
    return _lastMemberSeized;
}

ModelDataDefinition* SeizableItem::getSeizable() const {
    return _resourceOrSet;
}

void SeizableItem::setElementManager(ModelDataManager* _modeldataManager) {
    this->_modeldataManager = _modeldataManager;
}

//void SeizableItem::setComponentManager(ComponentManager* _componentManager) {
//	this->_componentManager = _componentManager;
//}

