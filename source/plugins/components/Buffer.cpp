/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Buffer.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on
 */

#include "Buffer.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Simulator.h"
#include "../../kernel/simulator/PluginManager.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Buffer::GetPluginInformation;
}
#endif

ModelDataDefinition* Buffer::NewInstance(Model* model, std::string name) {
	return new Buffer(model, name);
}

Buffer::Buffer(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Buffer>(), name) {
}

std::string Buffer::show() {
	return ModelComponent::show() + "";
}

// public static 

ModelComponent* Buffer::LoadInstance(Model* model, PersistenceRecord *fields) {
	Buffer* newComponent = new Buffer(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

PluginInformation* Buffer::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Buffer>(), &Buffer::LoadInstance, &Buffer::NewInstance);
	info->setDescriptionHelp("//@TODO");
	info->insertDynamicLibFileDependence("queue.so");
	info->insertDynamicLibFileDependence("signaldata.so");
	return info;
}

// protected virtual -- must be overriden

void Buffer::_onDispatchEvent(Entity* entity, unsigned int inputPortNumber) {
	if (_internalQueue->size() == _capacity) { //full buffer
		if (this->_advanceOn == AdvanceOn::NewArrivals) { // that's fine. Buffer advances on new arrivals
			Waiting *first = _internalQueue->first();
			_internalQueue->removeElement(first);
			// TODO: Collect statistics about waiting
			_parentModel->getTracer()->trace("Entity "+first->getEntity()->getName()+" leaves the buffer");
			this->_parentModel->sendEntityToComponent(first->getEntity(), this->getConnections()->getFrontConnection());
			// enqueue
			_parentModel->getTracer()->trace("Entity "+entity->getName()+" enters on the buffer at position "+std::to_string(_internalQueue->size()+1)+"/"+std::to_string(_capacity));
			_internalQueue->insertElement(new Waiting(entity, _parentModel->getSimulation()->getSimulatedTime(), this));
		} else { // ops. Arrival in a full buffer that doesn't advance on new arrivals
			if (_arrivalOnFullBufferRule == ArrivalOnFullBufferRule::SendToBulkPort) {
				_parentModel->getTracer()->trace("Entity " + entity->getName()+" got a full buffer and will be send to the bulk port");
				_parentModel->sendEntityToComponent(entity, this->getConnections()->getConnectionAtPort(1)); // port 1 is the bulk one
			} else if (_arrivalOnFullBufferRule == ArrivalOnFullBufferRule::Dispose) {
				_parentModel->getTracer()->trace("Entity " + entity->getName()+" got a full buffer and will be just removed");
				_parentModel->removeEntity(entity);
			} else if (_arrivalOnFullBufferRule == ArrivalOnFullBufferRule::ReplaceLastPosition) {
				Waiting *lastEntity = _internalQueue->getAtRank(_internalQueue->size()-1);
				_parentModel->getTracer()->trace("Entity " + entity->getName()+" got a full buffer and will replace entity "+lastEntity->getEntity()->getName()+" in the buffer, wich will be just removed");
				_internalQueue->removeElement(lastEntity);
				_parentModel->removeEntity(lastEntity->getEntity());
				delete(lastEntity);
				// will enqueue current entity
				// enqueue
				_parentModel->getTracer()->trace("Entity "+entity->getName()+" enters on the buffer at position "+std::to_string(_internalQueue->size()+1)+"/"+std::to_string(_capacity));
				_internalQueue->insertElement(new Waiting(entity, _parentModel->getSimulation()->getSimulatedTime(), this));
			}
		}
	} else {
		// enqueue
		_parentModel->getTracer()->trace("Entity "+entity->getName()+" enters on the buffer at position "+std::to_string(_internalQueue->size()+1)+"/"+std::to_string(_capacity));
		_internalQueue->insertElement(new Waiting(entity, _parentModel->getSimulation()->getSimulatedTime(), this));
	}
}

bool Buffer::_loadInstance(PersistenceRecord *fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

void Buffer::_saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {
	ModelComponent::_saveInstance(fields, saveDefaultValues);
	// @TODO: not implemented yet
}


// protected virtual -- could be overriden 

//ParserChangesInformation* DummyElement::_getParserChangesInformation() {}

bool Buffer::_check(std::string* errorMessage) {
	bool resultAll = true;
	resultAll &= _parentModel->checkExpression(_advanceTimeExpression, "Advance Time Expession", errorMessage);
	return resultAll;
}

ParserChangesInformation* Buffer::_getParserChangesInformation() {
	ParserChangesInformation* changes = new ParserChangesInformation();
	//@TODO not implemented yet
	//changes->getProductionToAdd()->insert(...);
	//changes->getTokensToAdd()->insert(...);
	return changes;
}

void Buffer::_initBetweenReplications() {
//	_someString = "Test";
//	_someUint = 1;
}

unsigned int Buffer::_handlerForSignalDataEvent(SignalData* signalData) {
	// got a signal. Buffer will advance
	_parentModel->getTracer()->trace("Buffer "+this->getName()+" received signal "+signalData->getName());
	if (_internalQueue->size() > 0) {
		Waiting *first = _internalQueue->first();
		_internalQueue->removeElement(first);
		// TODO: Collect statistics about waiting
		_parentModel->getTracer()->trace("Entity "+first->getEntity()->getName()+" leaves the buffer");
		this->_parentModel->sendEntityToComponent(first->getEntity(), this->getConnections()->getFrontConnection());
		return 1; // one entity was "freed"
	} else {
		_parentModel->getTracer()->trace("Buffer is empty. Nothing happens");
		return 0; // no entity was "freed" (sent forward)
	}
}


void Buffer::_createInternalAndAttachedData() {
	PluginManager* pm = _parentModel->getParentSimulator()->getPlugins();
	if (_internalQueue == nullptr) {
		_internalQueue = pm->newInstance<Queue>(_parentModel, getName() + "." + "Queue");
		_internalDataInsert("Queue", _internalQueue);
	}
	//attached
	if (_advanceOn == AdvanceOn::Signal) {
		if (_attachedSignal  == nullptr) {
			if (_parentModel->isAutomaticallyCreatesModelDataDefinitions()) {
				_attachedSignal = pm->newInstance<SignalData>(_parentModel, getName() + "." + "SignalData");
			}
			SignalData::SignalDataEventHandler handler = SignalData::SetSignalDataEventHandler<Buffer>(&Buffer::_handlerForSignalDataEvent, this);
			_attachedSignal->addSignalDataEventHandler(handler, this);
			_attachedDataInsert("SignalData", _attachedSignal);
		}
	} else {
		_attachedDataRemove("SignalData");
	}
}

void Buffer::_addProperty(PropertyBase* property) {

}

Util::TimeUnit Buffer::getadvanceTimeTimeUnit() const {
	return _advanceTimeTimeUnit;
}

void Buffer::setAdvanceTimeTimeUnit(Util::TimeUnit newAdvanceTimeTimeUnit) {
	_advanceTimeTimeUnit = newAdvanceTimeTimeUnit;
}

std::string Buffer::getadvanceTimeExpression() const {
	return _advanceTimeExpression;
}

void Buffer::setAdvanceTimeExpression(const std::string &newAdvanceTimeExpression, Util::TimeUnit timeunit) {
	_advanceTimeExpression = newAdvanceTimeExpression;
	if (timeunit != Util::TimeUnit::unknown) {
		_advanceTimeTimeUnit = timeunit;
	}
}

SignalData *Buffer::getsignal() const {
	return _attachedSignal;
}

void Buffer::setSignal(SignalData *newSignal) {
	_attachedSignal = newSignal;
}

Queue *Buffer::getinternalQueue() const {
	return _internalQueue;
}

void Buffer::setInternalQueue(Queue *newInternalQueue) {
	_internalQueue = newInternalQueue;
}

unsigned int Buffer::getcapacity() const {
	return _capacity;
}

void Buffer::setCapacity(unsigned int newCapacity) {
	_capacity = newCapacity;
}

Buffer::AdvanceOn Buffer::getadvanceOn() const {
	return _advanceOn;
}

void Buffer::setAdvanceOn(Buffer::AdvanceOn newAdvanceOn) {
	_advanceOn = newAdvanceOn;
}

Buffer::ArrivalOnFullBufferRule Buffer::getarrivalOnFullBufferRule() const {
	return _arrivalOnFullBufferRule;
}

void Buffer::setArrivalOnFullBufferRule(Buffer::ArrivalOnFullBufferRule newArrivalOnFullBufferRule){
	_arrivalOnFullBufferRule = newArrivalOnFullBufferRule;
}
