/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Delay.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 19:49
 */

#include "Delay.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Attribute.h"

Delay::Delay(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Delay>(), name) {

	GetterMember getter = DefineGetterMember<Delay>(this, &Delay::delay);
	SetterMember setter = DefineSetterMember<Delay>(this, &Delay::setDelay);
	model->getControls()->insert(new SimulationControl(Util::TypeOf<Delay>(), getName() + ".Delay", getter, setter));

	//GetterMember getter2 = DefineGetterMember<Delay>(this, &Delay::delayTimeUnit);
	//SetterMember setter2 = DefineSetterMember<Delay>(this, &Delay::setDelayTimeUnit);
	//model->controls()->insert(new SimulationControl(Util::TypeOf<Delay>(), getName() + ".DelayTimeUnit", getter2, setter2));


}

void Delay::setDelay(double delay) {
	_delayExpression = std::to_string(delay);
}

double Delay::delay() const {
	return _parentModel->parseExpression(_delayExpression);
}

std::string Delay::show() {
	return ModelComponent::show() +
			",delayExpression=" + this->_delayExpression +
			",timeUnit=" + std::to_string(static_cast<int> (this->_delayTimeUnit));
}

ModelComponent* Delay::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Delay* newComponent = new Delay(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Delay::setDelayExpression(std::string _delayExpression) {
	this->_delayExpression = _delayExpression;
}

std::string Delay::delayExpression() const {
	return _delayExpression;
}

void Delay::setDelayTimeUnit(Util::TimeUnit _delayTimeUnit) {
	this->_delayTimeUnit = _delayTimeUnit;
}

Util::TimeUnit Delay::delayTimeUnit() const {
	return _delayTimeUnit;
}

void Delay::_execute(Entity* entity) {
	double waitTime = _parentModel->parseExpression(_delayExpression);
	Util::TimeUnit stu = _parentModel->getSimulation()->getReplicationBaseTimeUnit(); //getReplicationLengthTimeUnit();
	waitTime *= Util::TimeUnitConvert(_delayTimeUnit, stu);
	if (_reportStatistics) {
		_cstatWaitTime->getStatistics()->getCollector()->addValue(waitTime);
		if (entity->getEntityType()->isReportStatistics())
			entity->getEntityType()->addGetStatisticsCollector(entity->getEntityTypeName() + ".WaitTime")->getStatistics()->getCollector()->addValue(waitTime);
	}
	double totalWaitTime = entity->getAttributeValue("Entity.TotalWaitTime");
	entity->setAttributeValue("Entity.TotalWaitTime", totalWaitTime + waitTime);
	double delayEndTime = _parentModel->getSimulation()->getSimulatedTime() + waitTime;
	Event* newEvent = new Event(delayEndTime, entity, this->getConnections()->getFrontConnection());
	_parentModel->getFutureEvents()->insert(newEvent);
	_parentModel->getTracer()->traceSimulation("End of delay of "/*entity " + std::to_string(entity->entityNumber())*/ + entity->getName() + " scheduled to time " + std::to_string(delayEndTime) + Util::StrTimeUnitShort(stu) + " (wait time " + std::to_string(waitTime) + Util::StrTimeUnitShort(stu) + ") // " + _delayExpression);
}

bool Delay::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		this->_delayExpression = LoadField(fields, "delayExpression", DEFAULT.delayExpression);
		this->_delayTimeUnit = LoadField(fields, "delayExpressionTimeUnit", DEFAULT.delayTimeUnit);
	}
	return res;
}

//void Delay::_initBetweenReplications() {}

std::map<std::string, std::string>* Delay::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues); //Util::TypeOf<Delay>());
	SaveField(fields, "delayExpression", this->_delayExpression, DEFAULT.delayExpression, saveDefaultValues);
	SaveField(fields, "delayExpressionTimeUnit", _delayTimeUnit, DEFAULT.delayTimeUnit, saveDefaultValues);
	return fields;
}

bool Delay::_check(std::string* errorMessage) {
	//include attributes needed
	ElementManager* elements = _parentModel->getElements();
	std::vector<std::string> neededNames = {"Entity.TotalWaitTime"};
	std::string neededName;
	for (unsigned int i = 0; i < neededNames.size(); i++) {
		neededName = neededNames[i];
		if (elements->getElement(Util::TypeOf<Attribute>(), neededName) == nullptr) {
			Attribute* attr1 = new Attribute(_parentModel, neededName);
			elements->insert(attr1);
		}
	}
	return _parentModel->checkExpression(_delayExpression, "Delay expression", errorMessage);
}

void Delay::_createInternalElements() {
	if (_reportStatistics && _cstatWaitTime == nullptr) {
		_cstatWaitTime = new StatisticsCollector(_parentModel, getName() + "." + "WaitTime", this);
		_internalElements->insert({"WaitTime", _cstatWaitTime});
		// include StatisticsCollector needed in EntityType 
		ElementManager* elements = _parentModel->getElements();
		std::list<ModelElement*>* enttypes = elements->getElementList(Util::TypeOf<EntityType>())->list();
		for (ModelElement* element : *enttypes) {
			EntityType* enttype = static_cast<EntityType*> (element);
			if (element->isReportStatistics())
				enttype->addGetStatisticsCollector(enttype->getName() + ".WaitTime"); // force create this CStat before simulation starts
		}
	} else {
		_removeInternalElements();
		// @TODO remove StatisticsCollector needed in EntityType
	}
}

PluginInformation* Delay::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Delay>(), &Delay::LoadInstance);
	std::string text = "The Delay module delays an entity by a specified amount of time.";
	text += " When an entity arrives at a Delay module, the time delay expression is evaluated and the entity remains in the module for the resulting time.";
	text += " The time is then allocated to the entity’s value-added, non-value added, transfer, wait, or other time.";
	text += " Associated costs are calculated and allocated as well.";
	text += " TYPICAL USES: (1) Processing a check at a bank; (2) Performing a setup on a machine; (3) Transferring a document to another department";
	info->setDescriptionHelp(text);
	return info;
}
