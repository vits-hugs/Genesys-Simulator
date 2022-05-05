/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   QueueableItem.cpp
 * Author: rlcancian
 *
 * Created on 23 de abril de 2021, 15:09
 */

#include "QueueableItem.h"
#include "../../kernel/simulator/ModelDataDefinition.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Simulator.h"
#include <cassert>

QueueableItem::QueueableItem(ModelDataDefinition* queueOrSet, QueueableItem::QueueableType queueableType, std::string index) {
	_queueableType = queueableType;
	_queueOrSet = queueOrSet;
	_index = index;
}

QueueableItem::QueueableItem(Model* model, std::string queueName = "") {
	_queueableType = QueueableItem::QueueableType::QUEUE;
	ModelDataDefinition* data = model->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), queueName);
	if (data != nullptr) {
		_queueOrSet = dynamic_cast<Queue*> (data);
	} else {
		_queueOrSet = model->getParentSimulator()->getPlugins()->newInstance<Queue>(model, queueName);
	}
	_index = "0";
}

/* Queue* QueueableItem::getRequestedQueue() const {
	if (_queueableType == QueueableItem::QueueableType::QUEUE) {
		return static_cast<Queue*> (_queueOrSet);
	} else {
		// assume it is a set ==> _queueableType == QueueableItem::QueueableType::SET
		unsigned int index = this-> ??? ->parse(...)
	}
} */
bool QueueableItem::loadInstance(std::map<std::string, std::string>* fields) {
	bool res = true;
	try {
		_queueableType = static_cast<QueueableItem::QueueableType> (LoadField(fields, "queueableType", static_cast<int> (DEFAULT.queueableType)));
		_queueableName = LoadField(fields, "queueable", "");
		_index = LoadField(fields, "index", DEFAULT.index);
		if (_modeldataManager != nullptr) {
			if (_queueableType == QueueableItem::QueueableType::QUEUE) {
				_queueOrSet = _modeldataManager->getDataDefinition(Util::TypeOf<Queue>(), _queueableName);
			} else if (_queueableType == QueueableItem::QueueableType::SET) {
				_queueOrSet = _modeldataManager->getDataDefinition(Util::TypeOf<Queue>(), _queueableName);
				//            } else if (_queueableType == QueueableItem::QueueableType::HOLD) {
				//                _queueOrSet = _modeldataManager->getDataDefinition(Util::TypeOf<Hold>(), _queueableName);
			}
			//assert(_queueOrSet != nullptr);
		}
	} catch (...) {
		res = false;
	}
	return res;
}

std::map<std::string, std::string>* QueueableItem::saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
	SaveField(fields, "queueableType", static_cast<int> (_queueableType), static_cast<int> (DEFAULT.queueableType), saveDefaultValues);
	SaveField(fields, "queueable", _queueOrSet->getName());
	SaveField(fields, "index", _index, DEFAULT.index, saveDefaultValues);
	return fields;
}

/*
bool QueueableItem::_loadInstance(std::map<std::string, std::string>* fields, unsigned int parentIndex) {
	bool res = true;
	std::string num = strIndex(parentIndex);
	try {
		_queueableType = static_cast<QueueableItem::QueueableType> (LoadField(fields, "queueableType" + num, static_cast<int> (DEFAULT.queueableType)));
		_queueableName = LoadField(fields, "queueable" + num, "");
		_index = LoadField(fields, "index" + num, DEFAULT.index);
	} catch (...) {
		res = false;
	}
	return res;
}

std::map<std::string, std::string>* QueueableItem::_saveInstance(unsigned int parentIndex) {
	std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
	std::string num = strIndex(parentIndex);
	SaveField(fields, "queueableType" + num, static_cast<int> (_queueableType), static_cast<int> (DEFAULT.queueableType));
	//SaveField(fields, "queueId" + num, _queueOrSet->getId());
	SaveField(fields, "queueable" + num, _queueOrSet->getName(), "");
	SaveField(fields, "index" + num, _index, DEFAULT.index);
	return fields;
}
 */


std::string QueueableItem::show() {
	return "queueType=" + std::to_string(static_cast<int> (_queueableType)) + ",queue=\"" + _queueOrSet->getName() + "\",index=\"" + _index + "\"";
}

void QueueableItem::setIndex(std::string index) {
	this->_index = index;
}

std::string QueueableItem::getIndex() const {
	return _index;
}

std::string QueueableItem::getQueueableName() const {
	return _queueableName;
}

void QueueableItem::setQueue(Queue* queue) {
	this->_queueOrSet = queue;
	_queueableName = queue->getName();
}

Queue* QueueableItem::getQueue() const {
	return static_cast<Queue*> (_queueOrSet);
}

void QueueableItem::setSet(Set* set) {
	this->_queueOrSet = set;
	_queueableName = set->getName();
}

Set* QueueableItem::getSet() const {
	return static_cast<Set*> (_queueOrSet);
}

void QueueableItem::setQueueableType(QueueableItem::QueueableType queueableType) {
	this->_queueableType = queueableType;
}

QueueableItem::QueueableType QueueableItem::getQueueableType() const {
	return _queueableType;
}

ModelDataDefinition* QueueableItem::getQueueable() const {
	return _queueOrSet;
}

void QueueableItem::setElementManager(ModelDataManager* _modeldataManager) {
	this->_modeldataManager = _modeldataManager;
}

//void QueueableItem::setComponentManager(ComponentManager* componentManager) {
//    this->_componentManager = componentManager;
//}
