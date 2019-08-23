/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelSimulation.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 7 de Novembro de 2018, 18:04
 */

#include "ModelSimulation.h"
#include <iostream>
#include "Model.h"
#include "Simulator.h"
#include "SourceModelComponent.h"
#include "StatisticsCollector.h"
#include "Counter.h"
#include "Traits.h"
#include "SimulationControl.h"
#include "ComponentManager.h"

ModelSimulation::ModelSimulation(Model* model) {
    _model = model;
    _info = model->getInfos(); // why??
    _statsCountersSimulation->setSortFunc([](const ModelElement* a, const ModelElement * b) {
	return a->getId() < b->getId();
    });
    _simulationReporter = new Traits<SimulationReporter_if>::Implementation(this, model, this->_statsCountersSimulation);
}

ModelSimulation::ModelSimulation(const ModelSimulation& orig) {
}

ModelSimulation::~ModelSimulation() {
}

bool ModelSimulation::_isReplicationEndCondition() {
    bool finish = _model->getEvents()->size() == 0;
    finish |= _model->parseExpression(_info->getTerminatingCondition()) != 0.0;
    if (_model->getEvents()->size() > 0 && !finish) {
	// replication length has not been achieve (sor far), but next event will happen after that, so it's just fine to set tnow as the replicationLength 
	finish |= _model->getEvents()->front()->getTime() > _info->getReplicationLength();
    }
    return finish;
}

/*!
 * Checks the model and if ok then initialize the simulation, execute repeatedly each replication and then show simulation statistics
 */
void ModelSimulation::startSimulation() {
    if (!_model->checkModel()) {
	_model->getTraceManager()->trace(Util::TraceLevel::errors, "Model check failed. Cannot start simulation.");
	return;
    }
    Util::SetIndent(0); //force indentation
    _initSimulation();
    _model->getOnEventManager()->NotifySimulationStartHandlers(new SimulationEvent(0, nullptr));
    for (_currentReplicationNumber = 1; _currentReplicationNumber <= _info->getNumberOfReplications(); _currentReplicationNumber++) {
	Util::SetIndent(1);
	_initReplication();
	_model->getOnEventManager()->NotifyReplicationStartHandlers(new SimulationEvent(_currentReplicationNumber, nullptr));

	Util::IncIndent();
	{
	    while (!_isReplicationEndCondition()) {
		_stepSimulation();
		if (_pauseOnEvent) {
		    std::cout << "[paused] ...press any key to continue...";
		    std::cin.get();
		    std::cout << std::endl;
		}
	    }
	}
	Util::SetIndent(1); // force

	_model->getOnEventManager()->NotifyReplicationEndHandlers(new SimulationEvent(_currentReplicationNumber, nullptr));
	std::string causeTerminated = "";
	if (_model->getEvents()->empty()) {
	    causeTerminated = "event queue is empty";
	} else if (_stopRequested) {
	    causeTerminated = "user requested to stop";
	} else if (_model->getEvents()->front()->getTime() > _info->getReplicationLength()) {
	    causeTerminated = "replication length " + std::to_string(_info->getReplicationLength()) + " was achieved";
	} else if (_model->parseExpression(_info->getTerminatingCondition())) {
	    causeTerminated = "termination condition was achieved";
	} else causeTerminated = "unknown";
	std::string message = "Replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_info->getNumberOfReplications()) + " has finished with last event at time " + std::to_string(_simulatedTime) + " because " + causeTerminated;
	_model->getTraceManager()->trace(Util::TraceLevel::simulation, message);
	_simulationReporter->showReplicationStatistics();
	_actualizeSimulationStatistics();
    }
    _simulationReporter->showSimulationStatistics(); //_cStatsSimulation);
    Util::DecIndent();

    _model->getTraceManager()->trace(Util::TraceLevel::simulation, "Simulation of model \"" + _info->getName() + "\" has finished.\n");
    _model->getOnEventManager()->NotifySimulationEndHandlers(new SimulationEvent(0, nullptr));

}

void ModelSimulation::_actualizeSimulationStatistics() {
    const std::string UtilTypeOfStatisticsCollector = Util::TypeOf<StatisticsCollector>();
    const std::string UtilTypeOfCounter = Util::TypeOf<Counter>();

    StatisticsCollector *sc, *scSim;
    ModelElement* me;
    List<ModelElement*>* cstats = _model->getElementManager()->getElements(Util::TypeOf<StatisticsCollector>());
    for (std::list<ModelElement*>::iterator it = cstats->getList()->begin(); it != cstats->getList()->end(); it++) {
	sc = dynamic_cast<StatisticsCollector*> ((*it));
	scSim = nullptr;
	for (std::list<ModelElement*>::iterator it = _statsCountersSimulation->getList()->begin(); it != _statsCountersSimulation->getList()->end(); it++) {
	    if ((*it)->getTypename() == UtilTypeOfStatisticsCollector) {
		if ((*it)->getName() == _cte_stCountSimulNamePrefix + sc->getName() && dynamic_cast<StatisticsCollector*> (*it)->getParent() == sc->getParent()) {
		    // found
		    scSim = dynamic_cast<StatisticsCollector*> (*it);
		    break;
		}
	    }
	}
	//scSim = dynamic_cast<StatisticsCollector*> (*(this->_statsCountersSimulation->find((*it))));
	assert(scSim != nullptr);
	scSim->getStatistics()->getCollector()->addValue(sc->getStatistics()->average());
    }
    Counter *cnt, *cntSim;
    List<ModelElement*>* counters = _model->getElementManager()->getElements(Util::TypeOf<Counter>());
    for (std::list<ModelElement*>::iterator it = counters->getList()->begin(); it != counters->getList()->end(); it++) {
	cnt = dynamic_cast<Counter*> ((*it));
	cntSim = nullptr;
	for (std::list<ModelElement*>::iterator it = _statsCountersSimulation->getList()->begin(); it != _statsCountersSimulation->getList()->end(); it++) {
	    if ((*it)->getTypename() == UtilTypeOfCounter) {
		if ((*it)->getName() == _cte_stCountSimulNamePrefix + cnt->getName() && dynamic_cast<Counter*> (*it)->getParent() == cnt->getParent()) {
		    // found
		    cntSim = dynamic_cast<Counter*> (*it);
		    break;
		}
	    }
	}
	//cntSim = dynamic_cast<Counter*> (*(this->_statsCountersSimulation->find((*it))));
	assert(cntSim != nullptr);
	cntSim->incCountValue(cnt->getCountValue());
    }
}

void ModelSimulation::_showSimulationHeader() {
    TraceManager* tm = _model->getTraceManager();
    tm->traceReport(Util::TraceLevel::simulation, "\n-----------------------------------------------------");
    // simulator infos
    tm->traceReport(Util::TraceLevel::simulation, _model->getParent()->getName());
    tm->traceReport(Util::TraceLevel::simulation, _model->getParent()->getLicenceManager()->showLicence());
    tm->traceReport(Util::TraceLevel::simulation, _model->getParent()->getLicenceManager()->showLimits());
    // model infos
    tm->traceReport(Util::TraceLevel::simulation, "Analyst Name: " + _info->getAnalystName());
    tm->traceReport(Util::TraceLevel::simulation, "Project Title: " + _info->getProjectTitle());
    tm->traceReport(Util::TraceLevel::simulation, "Number of Replications: " + std::to_string(_info->getNumberOfReplications()));
    tm->traceReport(Util::TraceLevel::simulation, "Replication Length: " + std::to_string(_info->getReplicationLength())+ " " + Util::StrTimeUnit(_info->getReplicationLengthTimeUnit()));
    //tm->traceReport(Util::TraceLevel::simulation, "");
    // model controls and responses
    std::string controls;
    for(std::list<SimulationControl*>::iterator it = _model->getControls()->getList()->begin(); it!= _model->getControls()->getList()->end(); it++) {
	controls+=(*it)->getName()+"("+(*it)->getType()+"), ";
    }
    tm->traceReport(Util::TraceLevel::simulation, "Simulation controls: "+controls);
    std::string responses;
    for(std::list<SimulationResponse*>::iterator it = _model->getResponses()->getList()->begin(); it!= _model->getResponses()->getList()->end(); it++) {
	responses+=(*it)->getName()+"("+(*it)->getType()+"), ";
    }
    tm->traceReport(Util::TraceLevel::simulation, "Simulation responses: "+responses);
}

/*!
 * Initialize once for all replications
 */
void ModelSimulation::_initSimulation() {
    _showSimulationHeader();
    _model->getTraceManager()->trace(Util::TraceLevel::simulation, "Simulation of model \"" + _info->getName() + "\" is starting.");
    // copy all CStats and Counters (used in a replication) to CStats and counters for the whole simulation
    this->_statsCountersSimulation->clear();
    StatisticsCollector* cstat;
    List<ModelElement*>* cstats = _model->getElementManager()->getElements(Util::TypeOf<StatisticsCollector>());
    for (std::list<ModelElement*>::iterator it = cstats->getList()->begin(); it != cstats->getList()->end(); it++) {
	cstat = dynamic_cast<StatisticsCollector*> ((*it));
	StatisticsCollector* newCStatSimul = new StatisticsCollector(_cte_stCountSimulNamePrefix + cstat->getName(), cstat->getParent());
	this->_statsCountersSimulation->insert(newCStatSimul);
    }
    // copy all Counters (used in a replication) to Counters for the whole simulation
    Counter* counter;
    List<ModelElement*>* counters = _model->getElementManager()->getElements(Util::TypeOf<Counter>());
    for (std::list<ModelElement*>::iterator it = counters->getList()->begin(); it != counters->getList()->end(); it++) {
	counter = dynamic_cast<Counter*> ((*it));
	Counter* newCountSimul = new Counter(_cte_stCountSimulNamePrefix + counter->getName(), counter->getParent());
	this->_statsCountersSimulation->insert(newCountSimul);
    }
}

void ModelSimulation::_initReplication() {
    TraceManager* tm = _model->getTraceManager();
    tm->traceReport(Util::TraceLevel::simulation, "");
    tm->traceReport(Util::TraceLevel::simulation, "Replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_info->getNumberOfReplications()) + " is starting.");

    _model->getEvents()->clear();
    _simulatedTime = 0.0;
    _pauseRequested = false;

    //if (_currentReplicationNumber > 1) { // init all components between replications
    for (std::list<ModelComponent*>::iterator it = _model->getComponentManager()->begin(); it != _model->getComponentManager()->end(); it++) {
	ModelComponent::InitBetweenReplications((*it));
    }
    //}
    Util::ResetIdOfType(Util::TypeOf<Entity>());
    Util::ResetIdOfType(Util::TypeOf<Event>());

    // insert first creation events
    SourceModelComponent *source;
    Entity *newEntity;
    Event *newEvent;
    double creationTime;
    unsigned int numToCreate;
    //std::list<ModelComponent*>* list = _model->getComponents()->getList();
    for (std::list<ModelComponent*>::iterator it = _model->getComponentManager()->begin(); it != _model->getComponentManager()->end(); it++) {
	source = dynamic_cast<SourceModelComponent*> (*it);
	if (source != nullptr) {
	    creationTime = source->getFirstCreation();
	    numToCreate = source->getEntitiesPerCreation();
	    for (unsigned int i = 1; i <= numToCreate; i++) {
		newEntity = new Entity(_model->getElementManager());
		newEntity->setEntityType(source->getEntityType());
		newEvent = new Event(creationTime, newEntity, (*it));
		_model->getEvents()->insert(newEvent);
	    }
	}
    }

    if (this->_initializeStatisticsBetweenReplications) {
	_initStatistics();
    }
}

void ModelSimulation::_initStatistics() {
    StatisticsCollector* cstat;
    List<ModelElement*>* list = _model->getElementManager()->getElements(Util::TypeOf<StatisticsCollector>());
    for (std::list<ModelElement*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
	cstat = (StatisticsCollector*) (*it);
	cstat->getStatistics()->getCollector()->clear();
    }
    Counter* counter;
    list = _model->getElementManager()->getElements(Util::TypeOf<Counter>());
    for (std::list<ModelElement*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
	counter = (Counter*) (*it);
	counter->clear();
    }

}

void ModelSimulation::_stepSimulation() {
    // process one single event
    Event* nextEvent;
    nextEvent = _model->getEvents()->front();
    double warmupTime = Util::TimeUnitConvert(_model->getInfos()->getWarmUpPeriodTimeUnit(), _model->getInfos()->getReplicationLengthTimeUnit());
    warmupTime *= _model->getInfos()->getWarmUpPeriod();
    if (warmupTime>0.0 && _model->getSimulation()->getSimulatedTime() <= warmupTime && nextEvent->getTime() > warmupTime) {// warmuTime. Time to initStats
	_model->getTraceManager()->trace(Util::TraceLevel::simulation, "Warmup time reached. Statistics are being reseted.");
	_initStatistics();
    }
    if (nextEvent->getTime() <= _info->getReplicationLength()) {
	_model->getEvents()->pop_front();
	_model->getOnEventManager()->NotifyReplicationStepHandlers(new SimulationEvent(_currentReplicationNumber, nullptr));
	_processEvent(nextEvent);
    } else {
	this->_simulatedTime = _model->getInfos()->getReplicationLength(); ////nextEvent->getTime(); // just to advance time to beyond simulatedTime
    }
}

void ModelSimulation::_processEvent(Event* event) {
    //_model->getTraceManager()->trace(Util::TraceLevel::simulation, "");
    _model->getTraceManager()->trace(Util::TraceLevel::simulation, "Processing event=(" + event->show() + ")");
    _model->getTraceManager()->trace(Util::TraceLevel::blockInternal, "Current Entity: " + event->getEntity()->show());
    this->_currentEntity = event->getEntity();
    this->_currentComponent = event->getComponent();
    this->_currentInputNumber = event->getComponentInputNumber();
    _simulatedTime = event->getTime();
    _model->getOnEventManager()->NotifyProcessEventHandlers(new SimulationEvent(_currentReplicationNumber, event));
    Util::IncIndent();
    try {
	//event->getComponent()->Execute(event->getEntity(), event->getComponent()); // Execute is static
	ModelComponent::Execute(event->getEntity(), event->getComponent(), event->getComponentInputNumber());
    } catch (std::exception *e) {
	_model->getTraceManager()->traceError(*e, "Error on processing event (" + event->show() + ")");
    }
    Util::DecIndent();
}

void ModelSimulation::pauseSimulation() {
}

void ModelSimulation::stepSimulation() {
    if (_simulationIsInitiated && _replicationIsInitiaded) {
	if (!_isReplicationEndCondition()) {
	    try {
		this->_stepSimulation();
	    } catch (std::exception *e) {
		_model->getTraceManager()->traceError((*e), "Error on simulation step");
	    }
	}
    }

}

void ModelSimulation::stopSimulation() {
}

void ModelSimulation::restartSimulation() {
}

void ModelSimulation::setPauseOnEvent(bool _pauseOnEvent) {
    this->_pauseOnEvent = _pauseOnEvent;
}

bool ModelSimulation::isPauseOnEvent() const {
    return _pauseOnEvent;
}

void ModelSimulation::setInitializeStatistics(bool _initializeStatistics) {
    this->_initializeStatisticsBetweenReplications = _initializeStatistics;
}

bool ModelSimulation::isInitializeStatistics() const {
    return _initializeStatisticsBetweenReplications;
}

void ModelSimulation::setInitializeSystem(bool _initializeSystem) {
    this->_initializeSystem = _initializeSystem;
}

bool ModelSimulation::isInitializeSystem() const {
    return _initializeSystem;
}

void ModelSimulation::setStepByStep(bool _stepByStep) {
    this->_stepByStep = _stepByStep;
}

bool ModelSimulation::isStepByStep() const {
    return _stepByStep;
}

void ModelSimulation::setPauseOnReplication(bool _pauseOnReplication) {
    this->_pauseOnReplication = _pauseOnReplication;
}

bool ModelSimulation::isPauseOnReplication() const {
    return _pauseOnReplication;
}

double ModelSimulation::getSimulatedTime() const {
    return _simulatedTime;
}

bool ModelSimulation::isRunning() const {
    return _running;
}

unsigned int ModelSimulation::getCurrentReplicationNumber() const {
    return _currentReplicationNumber;
}

ModelComponent* ModelSimulation::getCurrentComponent() const {
    return _currentComponent;
}

Entity* ModelSimulation::getCurrentEntity() const {
    return _currentEntity;
}

SimulationReporter_if* ModelSimulation::getSimulationReporter() const {
    return _simulationReporter;
}

unsigned int ModelSimulation::getCurrentInputNumber() const {
    return _currentInputNumber;
}
