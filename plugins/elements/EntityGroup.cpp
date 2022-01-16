/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Group.cpp
 * Author: rlcancian
 *
 * Created on 12 de Junho de 2019, 19:00
 */

#include "EntityGroup.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Attribute.h"

EntityGroup::EntityGroup(Model* model, std::string name) : ModelElement(model, Util::TypeOf<EntityGroup>(), name) {
	// it is invoked in the constructor since EntityGroups are creted runtime by Components such as Batch
	this->_createInternalElements();
}

EntityGroup::~EntityGroup() {
	//_parentModel->elements()->remove(Util::TypeOf<StatisticsCollector>(), _cstatNumberInGroup);
}

std::string EntityGroup::show() {
	return ModelElement::show(); // +
	// TODO: Sow every group in the map",entities=" + this->_list->show();
}

void EntityGroup::insertElement(unsigned int idKey, Entity* element) {
	std::map<unsigned int, List<Entity*>*>::iterator it = _groupMap->find(idKey);
	while (it == _groupMap->end()) {
		_groupMap->insert({idKey, new List<Entity*>()});
		it = _groupMap->find(idKey);
	}
	(*it).second->insert(element);
	_cstatNumberInGroup->getStatistics()->getCollector()->addValue((*it).second->size());
}

void EntityGroup::removeElement(unsigned int idKey, Entity * element) {
	std::map<unsigned int, List<Entity*>*>::iterator it = _groupMap->find(idKey);
	if (it != _groupMap->end()) {
		(*it).second->remove(element);
		_cstatNumberInGroup->getStatistics()->getCollector()->addValue((*it).second->size());
	}
}

List<Entity*>* EntityGroup::getGroup(unsigned int idKey) {
	std::map<unsigned int, List<Entity*>*>::iterator it = _groupMap->find(idKey);
	if (it == _groupMap->end()) {
		return new List<Entity*>(); // not found
	} else {
		return (*it).second;
	}
}

PluginInformation * EntityGroup::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<EntityGroup>(), &EntityGroup::LoadInstance);
	info->setDescriptionHelp("//@TODO");
	return info;
}

ModelElement * EntityGroup::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	EntityGroup* newElement = new EntityGroup(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

bool EntityGroup::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelElement::_loadInstance(fields);
	if (res) {
		try {
		} catch (...) {
		}
	}
	return res;
}

std::map<std::string, std::string>* EntityGroup::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelElement::_saveInstance(saveDefaultValues); //Util::TypeOf<Group>());
	return fields;
}

bool EntityGroup::_check(std::string * errorMessage) {
	std::string newNeededAttributeName = "Entity.Group";
	if (_parentModel->getElements()->getElement(Util::TypeOf<Attribute>(), newNeededAttributeName) == nullptr) {
		new Attribute(_parentModel, newNeededAttributeName);
	}
	*errorMessage += "";
	return true;
}

void EntityGroup::_createInternalElements() {
	if (_reportStatistics) {
		if (_cstatNumberInGroup == nullptr) {
			_cstatNumberInGroup = new StatisticsCollector(_parentModel, "NumberInGroup", this);
			_internalElements->insert({"NumberInGroup", _cstatNumberInGroup});
		}
	} else
		if (_cstatNumberInGroup != nullptr) {
		_removeInternalElements();
	}
}


