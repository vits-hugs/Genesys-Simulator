/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Failure.cpp
 * Author: rlcancian
 *
 * Created on 20 de Failureembro de 2019, 20:07
 */

#include "Failure.h"
#include "../../kernel/simulator/Model.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
    return &Failure::GetPluginInformation;
}
#endif

ModelDataDefinition* Failure::NewInstance(Model* model, std::string name) {
    return new Failure(model, name);
}

Failure::Failure(Model* model, std::string name) : ModelDataDefinition(model, Util::TypeOf<Failure>(), name) {
}

std::string Failure::show() {
    return ModelDataDefinition::show() +
            "";
}

bool Failure::isGoingToFailOnCount(Resource* resource) {
    std::map<Resource*, unsigned int>::iterator it;
    it = _releaseCounts->find(resource);
    if (it == _releaseCounts->end()) {
        _releaseCounts->insert({resource, 0});
        it = _releaseCounts->find(resource);
    }
    it->second++;
    unsigned int count = _parentModel->parseExpression(countExpression);
    return it->second >= count;
}

void Failure::setFailureType(FailureType _failureType) {
    this->_failureType = _failureType;
}

Failure::FailureType Failure::getFailureType() const {
    return _failureType;
}

void Failure::setCountExpression(std::string countExpression) {
    this->countExpression = countExpression;
}

std::string Failure::getCountExpression() const {
    return countExpression;
}

void Failure::setDownTimeTimeUnit(Util::TimeUnit downTimeTimeUnit) {
    this->downTimeTimeUnit = downTimeTimeUnit;
}

Util::TimeUnit Failure::getDownTimeTimeUnit() const {
    return downTimeTimeUnit;
}

void Failure::setDownTimeExpression(std::string downTimeExpression) {
    this->downTimeExpression = downTimeExpression;
}

std::string Failure::getDownTimeExpression() const {
    return downTimeExpression;
}

void Failure::setUpTimeTimeUnit(Util::TimeUnit upTimeTimeUnit) {
    this->upTimeTimeUnit = upTimeTimeUnit;
}

Util::TimeUnit Failure::getUpTimeTimeUnit() const {
    return upTimeTimeUnit;
}

void Failure::setUpTimeExpression(std::string upTimeExpression) {
    this->upTimeExpression = upTimeExpression;
}

std::string Failure::getUpTimeExpression() const {
    return upTimeExpression;
}

void Failure::setFailureRule(FailureRule _failureRule) {
    this->_failureRule = _failureRule;
}

Failure::FailureRule Failure::getFailureRule() const {
    return _failureRule;
}

PluginInformation* Failure::GetPluginInformation() {
    //@TODO not implemented yet
    PluginInformation* info = new PluginInformation(Util::TypeOf<Failure>(), &Failure::LoadInstance, &Failure::NewInstance);
    //info->insertDynamicLibFileDependence("resource.so"); -- Circular dependence!! Do not add it
    return info;
}

ModelDataDefinition* Failure::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Failure* newElement = new Failure(model);
    try {
        newElement->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newElement;
}

bool Failure::_loadInstance(std::map<std::string, std::string>* fields) {
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

std::map<std::string, std::string>* Failure::_saveInstance(bool saveDefaultValues) {
    std::map<std::string, std::string>* fields = ModelDataDefinition::_saveInstance(saveDefaultValues); //Util::TypeOf<Failure>());
    //@TODO not implemented yet
    //SaveField(fields, "orderRule", std::to_string(static_cast<int> (this->_orderRule)));
    //SaveField(fields, "attributeName", "\""+this->_attributeName+"\"");
    return fields;
}

bool Failure::_check(std::string* errorMessage) {
    bool resultAll = true;
    //@TODO not implemented yet
    // resultAll |= ...
    *errorMessage += "";
    return resultAll;
}

void Failure::_initBetweenReplications() {
    _releaseCounts->clear();
}