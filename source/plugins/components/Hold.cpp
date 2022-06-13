/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Hold.cpp
 * Author: rlcancian
 *
 * Created on 03 de Junho de 2019, 15:20
 */

#include "Hold.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Simulator.h"
#include "../../kernel/simulator/PluginManager.h"
#include "../../plugins/data/Queue.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Hold::GetPluginInformation;
}
#endif

// constructors

ModelDataDefinition* Hold::NewInstance(Model* model, std::string name) {
	return new Hold(model, name);
}

Hold::Hold(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Hold>(), name) {
}

// public

std::string Hold::show() {
	return ModelComponent::show() + "";
}

void Hold::setSignalData(SignalData* signal) {
	_signalData = signal;
}


//public static

ModelComponent* Hold::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Hold* newComponent = new Hold(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

PluginInformation* Hold::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Hold>(), &Hold::LoadInstance, &Hold::NewInstance);
	info->setCategory("Decisions");
	info->insertDynamicLibFileDependence("queue.so");
	info->insertDynamicLibFileDependence("signal.so");
	return info;
}

// protected virtual must override

void Hold::_onDispatchEvent(Entity* entity, unsigned int inputPortNumber) {
	std::string message = "Entity is waiting in the queue \""+_queue->getName()+"\"";
	if (_holdType == Hold::HoldType::WaitForSignal) {
		message += " for signal \""+_signalData->getName()+"\"";
	} else if (_holdType == Hold::HoldType::ScanForCondition) {
		message += " until codition \""+_condition+"\" is true";
	} else if (_holdType == Hold::HoldType::ScanForCondition) {
		message += " indefinitely";
	}
	_parentModel->getTracer()->traceSimulation(this, _parentModel->getSimulation()->getSimulatedTime(), entity, this, message);
	Waiting* waiting = new Waiting(entity, _parentModel->getSimulation()->getSimulatedTime(), this);
	_queue->insertElement(waiting);
}

bool Hold::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

std::map<std::string, std::string>* Hold::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	// @TODO: not implemented yet
	return fields;
}

// protected virtual could override

//void Hold::_initBetweenReplications() {}

bool Hold::_check(std::string * errorMessage) {
	bool resultAll = true;
	if (_holdType==Hold::HoldType::ScanForCondition) {
		resultAll = _parentModel->checkExpression(_condition, "Condition", errorMessage);
	}
	return resultAll;
}

void Hold::_createInternalAndAttachedData(){
	// internal
	PluginManager* pm = _parentModel->getParentSimulator()->getPlugins();
	if (_queue == nullptr) {
		_queue = pm->newInstance<Queue>(_parentModel, getName() + ".Queue");
		_internalDataInsert("Queue", _queue);
	}
	//attached
	if (_holdType==Hold::HoldType::WaitForSignal) {
		if (_signalData == nullptr) {
			if (_parentModel->isAutomaticallyCreatesModelDataDefinitions()) {
				_signalData = pm->newInstance<SignalData>(_parentModel);
			}
		}
		SignalData::SignalDataEventHandler handler = SignalData::SetSignalDataEventHandler<Hold>(&Hold::_handlerForSignalDataEvent, this);
		_signalData->addSignalDataEventHandler(handler, this);
		_attachedDataInsert("SignalData", _signalData);
	} else {
		_attachedDataRemove("SignalData");
	}
}

void Hold::_initBetweenReplications() {

}

// private

unsigned int Hold::_handlerForSignalDataEvent(SignalData* signalData) {
	unsigned int freed = 0;
	while (_queue->size()>0 && signalData->remainsToLimit()>0) {
		Waiting* w=_queue->getAtRank(0);
		_queue->removeElement(w);
		freed++;
		signalData->decreaseRemainLimit();
		Entity* ent = w->getEntity();
		std::string message = "Received signal \""+signalData->getName()+"\". Entity \""+ent->getName()+"\" removed from queue \""+_queue->getName()+"\". "+std::to_string(freed)+" freed entities, limit remaining "+std::to_string(signalData->remainsToLimit());
		_parentModel->getTracer()->traceSimulation(this, TraceManager::Level::L8_detailed, _parentModel->getSimulation()->getSimulatedTime(), ent, this, message);
		_parentModel->sendEntityToComponent(w->getEntity(), w->geComponent()->getConnections()->getFrontConnection());
	}
	return freed;
}
