/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Route.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:15
 */

#include <cassert>
#include "Route.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Attribute.h"
#include "../../kernel/simulator/Simulator.h"
#include "../data/Sequence.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Route::GetPluginInformation;
}
#endif

ModelDataDefinition* Route::NewInstance(Model* model, std::string name) {
	return new Route(model, name);
}

Route::Route(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Route>(), name) {
}

std::string Route::show() {
	std::string msg = ModelComponent::show() +
			",destinationType=" + std::to_string(static_cast<int> (this->_routeDestinationType)) +
			",timeExpression=" + this->_routeTimeExpression + " " + Util::StrTimeUnitShort(this->_routeTimeTimeUnit);
	if (_station != nullptr)
		msg += ",station=" + this->_station->getName();
	return msg;
}

ModelComponent* Route::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Route* newComponent = new Route(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Route::setStation(Station* _station) {
	this->_station = _station;
}

void Route::setStationName(std::string stationName) {
	ModelDataDefinition* data = _parentModel->getDataManager()->getDataDefinition(Util::TypeOf<Station>(), stationName);
	if (data != nullptr) {
		_station = dynamic_cast<Station*> (data);
	} else {
		_station = _parentModel->getParentSimulator()->getPlugins()->newInstance<Station>(_parentModel, stationName);
	}
}

Station* Route::getStation() const {
	return _station;
}

void Route::setRouteTimeExpression(std::string _routeTimeExpression) {
	this->_routeTimeExpression = _routeTimeExpression;
}

std::string Route::getRouteTimeExpression() const {
	return _routeTimeExpression;
}

void Route::setRouteTimeTimeUnit(Util::TimeUnit _routeTimeTimeUnit) {
	this->_routeTimeTimeUnit = _routeTimeTimeUnit;
}

Util::TimeUnit Route::getRouteTimeTimeUnit() const {
	return _routeTimeTimeUnit;
}

void Route::setRouteDestinationType(DestinationType _routeDestinationType) {
	this->_routeDestinationType = _routeDestinationType;
}

Route::DestinationType Route::getRouteDestinationType() const {
	return _routeDestinationType;
}

void Route::_onDispatchEvent(Entity* entity) {
	Station* destinyStation = _station;
	if (_routeDestinationType == Route::DestinationType::BySequence) {
		unsigned int sequenceId = static_cast<unsigned int> (entity->getAttributeValue("Entity.Sequence"));
		unsigned int step = static_cast<unsigned int> (entity->getAttributeValue("Entity.SequenceStep"));
		Sequence* sequence = static_cast<Sequence*> (_parentModel->getDataManager()->getDataDefinition(Util::TypeOf<Sequence>(), sequenceId));
		SequenceStep* seqStep = sequence->getSteps()->getAtRank(step);
		if (seqStep == nullptr) {
			step = 0;
			seqStep = sequence->getSteps()->getAtRank(step);
			assert(seqStep != nullptr);
		}
		destinyStation = seqStep->getStation();
		for (SequenceStep::Assignment* assignment : *seqStep->getAssignments()) {
			_parentModel->parseExpression(assignment->getDestination() + "=" + assignment->getExpression());
		}
		entity->setAttributeValue("Entity.SequenceStep", step + 1.0);
	}
	if (_reportStatistics)
		_numberIn->incCountValue();
	// adds the route time to the TransferTime statistics / attribute related to the Entitys
	double routeTime = _parentModel->parseExpression(_routeTimeExpression) * Util::TimeUnitConvert(_routeTimeTimeUnit, _parentModel->getSimulation()->getReplicationBaseTimeUnit());
	if (entity->getEntityType()->isReportStatistics())
		entity->getEntityType()->addGetStatisticsCollector(entity->getEntityTypeName() + ".TransferTime")->getStatistics()->getCollector()->addValue(routeTime);
	entity->setAttributeValue("Entity.TotalTransferTime", entity->getAttributeValue("Entity.TotalTransferTime") + routeTime);
	if (routeTime > 0.0) {
		// calculates when this Entity will reach the end of this route and schedule this Event
		double routeEndTime = _parentModel->getSimulation()->getSimulatedTime() + routeTime;
		Event* newEvent = new Event(routeEndTime, entity, destinyStation->getEnterIntoStationComponent());
		_parentModel->getFutureEvents()->insert(newEvent);
		_parentModel->getTracer()->traceSimulation(this, "End of route of "/*entity " + std::to_string(entity->entityNumber())*/ + entity->getName() + " to the component \"" + destinyStation->getEnterIntoStationComponent()->getName() + "\" was scheduled to time " + std::to_string(routeEndTime));
	} else {
		// send without delay
		_parentModel->sendEntityToComponent(entity, destinyStation->getEnterIntoStationComponent(), 0.0);
	}
}

bool Route::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		this->_routeTimeExpression = LoadField(fields, "routeTimeExpression", DEFAULT.routeTimeExpression);
		this->_routeTimeTimeUnit = LoadField(fields, "routeTimeTimeUnit", DEFAULT.routeTimeTimeUnit);
		this->_routeDestinationType = static_cast<Route::DestinationType> (LoadField(fields, "destinationType", static_cast<int> (DEFAULT.routeDestinationType)));
		if (_routeDestinationType == DestinationType::Station) {
			std::string stationName = LoadField(fields, "station", "");
			Station* station = dynamic_cast<Station*> (_parentModel->getDataManager()->getDataDefinition(Util::TypeOf<Station>(), stationName));
			this->_station = station;
		}
	}
	return res;
}

//void Route::_initBetweenReplications() {}

std::map<std::string, std::string>* Route::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues);
	if (_routeDestinationType == DestinationType::Station) {
		std::string text = "";
		if (_station != nullptr) {
			text = _station->getName();
		}
		SaveField(fields, "station", text);
	}
	SaveField(fields, "routeTimeExpression", _routeTimeExpression, DEFAULT.routeTimeExpression, saveDefaultValues);
	SaveField(fields, "routeTimeTimeUnit", _routeTimeTimeUnit, DEFAULT.routeTimeTimeUnit, saveDefaultValues);
	SaveField(fields, "destinationType", static_cast<int> (_routeDestinationType), static_cast<int> (DEFAULT.routeDestinationType), saveDefaultValues);
	return fields;
}

bool Route::_check(std::string* errorMessage) {
	//include attributes needed
	ModelDataManager* elements = _parentModel->getDataManager();
	std::vector<std::string> neededNames = {"Entity.TotalTransferTime", "Entity.Station"};
	std::string neededName;
	for (unsigned int i = 0; i < neededNames.size(); i++) {
		neededName = neededNames[i];
		if (elements->getDataDefinition(Util::TypeOf<Attribute>(), neededName) == nullptr) {
			Attribute* attr1 = new Attribute(_parentModel, neededName);
			elements->insert(attr1);
		}
	}
	// include StatisticsCollector needed in EntityType
	std::list<ModelDataDefinition*>* enttypes = elements->getDataDefinitionList(Util::TypeOf<EntityType>())->list();
	for (ModelDataDefinition* modeldatum : *enttypes) {
		if (modeldatum->isReportStatistics())
			static_cast<EntityType*> (modeldatum)->addGetStatisticsCollector(modeldatum->getName() + ".TransferTime"); // force create this CStat before simulation starts
	}
	bool resultAll = true;
	resultAll &= _parentModel->checkExpression(_routeTimeExpression, "Route time expression", errorMessage);
	if (this->_routeDestinationType == Route::DestinationType::Station) {
		resultAll &= _parentModel->getDataManager()->check(Util::TypeOf<Station>(), _station, "Station", errorMessage);
		if (resultAll) {
			resultAll &= _station->getEnterIntoStationComponent() != nullptr;
			if (!resultAll) {
				errorMessage->append("Station has no component to enter into it");
			}
		}
	}
	//_model->getParent()->getPluginManager()->
	return resultAll;
}

PluginInformation* Route::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Route>(), &Route::LoadInstance, &Route::NewInstance);
	info->setSendTransfer(true);
	info->setCategory("Material Handling");
	info->insertDynamicLibFileDependence("station.so");
	std::string help = "The Route module transfers an entity to a specified station or the next station in the station visitation sequence defined for the entity.";
	help += " A delay time to transfer to the next station may be defined.";
	help += " When an entity enters the Route module, its Station attribute (Entity.Station) is set to the destination station.";
	help += " The entity is then sent to the destination station, using the route time specified.";
	help += " If the station destination is entered as By Sequence, the next station is determined by the entity’s sequence and step within the set (defined by special-purpose attributes Entity.Sequence and Entity.Jobstep, respectively).";
	help += " TYPICAL USES: (1) Send a part to its next processing station based on its routing slip;";
	help += " (2) Send an account balance call to an account agent; (3) Send restaurant customers to a specific table";
	info->setDescriptionHelp(help);
	return info;
}

void Route::_createInternalData() {
	if (_parentModel->isAutomaticallyCreatesModelDataDefinitions()) {
		if (_station == nullptr) {
			_station = _parentModel->getParentSimulator()->getPlugins()->newInstance<Station>(_parentModel);
		}
	}
	if (_reportStatistics) {
		if (_numberIn == nullptr) {
			_numberIn = new Counter(_parentModel, getName() + "." + "CountNumberIn", this);
			_internalData->insert({"CountNumberIn", _numberIn});
		}
	} else
		if (_numberIn != nullptr) {
		_removeInternalDatas();
	}
}
