/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Storage.cpp
 * Author: rlcancian
 *
 * Created on 20 de Storageembro de 2019, 20:06
 */

#include "Storage.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
    return &Storage::GetPluginInformation;
}
#endif

ModelDataDefinition* Storage::NewInstance(Model* model, std::string name) {
    return new Storage(model, name);
}

Storage::Storage(Model* model, std::string name) : ModelDataDefinition(model, Util::TypeOf<Storage>(), name) {
}

std::string Storage::show() {
    return ModelDataDefinition::show() +
            "";
}

void Storage::setTotalArea(double _totalArea) {
    this->_totalArea = _totalArea;
}

double Storage::getTotalArea() const {
    return _totalArea;
}

void Storage::setCapacity(unsigned int _capacity) {
    this->_capacity = _capacity;
}

unsigned int Storage::getCapacity() const {
    return _capacity;
}

void Storage::setUnitsPerArea(double _unitsPerArea) {
    this->_unitsPerArea = _unitsPerArea;
}

double Storage::getUnitsPerArea() const {
    return _unitsPerArea;
}

PluginInformation* Storage::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<Storage>(), &Storage::LoadInstance, &Storage::NewInstance);
    return info;
}

ModelDataDefinition* Storage::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Storage* newElement = new Storage(model);
    try {
        newElement->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newElement;
}

bool Storage::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelDataDefinition::_loadInstance(fields);
    if (res) {
        try {
            this->_capacity = LoadField(fields, "capacity", DEFAULT.capacity);
            this->_totalArea = LoadField(fields, "totalArea", DEFAULT.totalArea);
            this->_unitsPerArea = LoadField(fields, "unitPerArea", DEFAULT.unitsPerArea);
        } catch (...) {
        }
    }
    return res;
}

std::map<std::string, std::string>* Storage::_saveInstance(bool saveDefaultValues) {
    std::map<std::string, std::string>* fields = ModelDataDefinition::_saveInstance(saveDefaultValues); //Util::TypeOf<Storage>());
    //SaveField(fields, "orderRule", std::to_string(static_cast<int> (this->_orderRule)));
    //SaveField(fields, "attributeName", "\""+this->_attributeName+"\"");
    return fields;
}

bool Storage::_check(std::string* errorMessage) {
    bool resultAll = true;
    // resultAll |= ...
    *errorMessage += "";
    return resultAll;
}

ParserChangesInformation* Storage::_getParserChangesInformation() {
    ParserChangesInformation* changes = new ParserChangesInformation();
    //changes->getProductionToAdd()->insert(...);
    //changes->getTokensToAdd()->insert(...);
    return changes;
}

