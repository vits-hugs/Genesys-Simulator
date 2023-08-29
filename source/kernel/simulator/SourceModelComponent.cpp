/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SourceModelCOmponent.cpp
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 19:50
 */

#include "SourceModelComponent.h"
#include "Model.h"
#include "PropertyGenesys.h"

//using namespace GenesysKernel;

SourceModelComponent::SourceModelComponent(Model* model, std::string componentTypename, std::string name) : ModelComponent(model, componentTypename, name) {
/*	_addSimulationControl(new SimulationControl("SourceModelComponent", "First Creation",
			DefineGetterMember<SourceModelComponent>(this, &SourceModelComponent::getFirstCreation),
			DefineSetterMember<SourceModelComponent>(this, &SourceModelComponent::setFirstCreation)) );

	_addSimulationControl(new SimulationControl("SourceModelComponent", "Entities Per Creation",
			DefineGetterMember<SourceModelComponent>(this, &SourceModelComponent::getEntitiesPerCreation),
			DefineSetterMember<SourceModelComponent>(this, &SourceModelComponent::setEntitiesPerCreation)) );

	_addSimulationControl(new SimulationControl("SourceModelComponent", "Time Unit",
			DefineGetterMember<SourceModelComponent,Util::TimeUnit>(this, &SourceModelComponent::getTimeUnit),
			DefineSetterMember<SourceModelComponent,Util::TimeUnit>(this, &SourceModelComponent::setTimeUnit)) );

	_addSimulationControl(new SimulationControl("SourceModelComponent", "Time Between Creations Expression",
			DefineGetterMember<SourceModelComponent>(this, &SourceModelComponent::getTimeBetweenCreationsExpression),
			DefineSetterMember<SourceModelComponent>(this, &SourceModelComponent::setTimeBetweenCreationsExpression)) );
*/
	/*
	GetterMemberDouble getterFirstCreation = DefineGetterMember<SourceModelComponent, double>(this, &SourceModelComponent::getFirstCreation);
	SetterMemberDouble setterFirstCreation = DefineSetterMember<SourceModelComponent, double>(this, &SourceModelComponent::setFirstCreation);
	SimulationControl* controlFirstCreation = new SimulationControl("double", "First Creation", getterFirstCreation, setterFirstCreation, this->getName());
	_addSimulationControl(controlFirstCreation);
	GetterMemberUInt getterEntitiesPerCreation = DefineGetterMember<SourceModelComponent, unsigned int>(this, &SourceModelComponent::getEntitiesPerCreation);
	SetterMemberUInt setterEntitiesPerCreation = DefineSetterMember<SourceModelComponent, unsigned int>(this, &SourceModelComponent::setEntitiesPerCreation);
	SimulationControl* controlEntitiesPerCreation = new SimulationControl("uint", "Entities Per Creation", getterEntitiesPerCreation, setterEntitiesPerCreation, this->getName());
	_addSimulationControl(controlFirstCreation);
	GetterMemberTimeUnit getterTimeUnit = DefineGetterMember<SourceModelComponent, Util::TimeUnit>(this, &SourceModelComponent::getTimeUnit);
	SetterMemberTimeUnit setterTimeUnit = DefineSetterMember<SourceModelComponent, Util::TimeUnit>(this, &SourceModelComponent::setTimeUnit);
	SimulationControl* controlTimeUnit = new SimulationControl("uint", "Time Unit", getterTimeUnit, setterTimeUnit, this->getName());
	_addSimulationControl(controlFirstCreation);
	GetterMemberString getterTimeBetweenCreationsExpression = DefineGetterMember<SourceModelComponent, std::string>(this, &SourceModelComponent::getTimeBetweenCreationsExpression);
	SetterMemberString setterTimeBetweenCreationsExpression = DefineSetterMember<SourceModelComponent, std::string>(this, &SourceModelComponent::setTimeBetweenCreationsExpression);
	SimulationControl* controlTimeBetweenCreationsExpression = new SimulationControl("std::string", "TimeBetweenCreationsExpression", getterTimeBetweenCreationsExpression, setterTimeBetweenCreationsExpression, this->getName());
	_addSimulationControl(controlFirstCreation);
	*/

// -----------------  MESSY STUFF ---------------------
	// ADD_PROPERTY(double, SourceModelComponent, "First Creation", getFirstCreation, setFirstCreation)
	// ADD_PROPERTY(unsigned int, SourceModelComponent, "Entities Per Creation", getEntitiesPerCreation, setEntitiesPerCreation)
	// ADD_PROPERTY(std::string, SourceModelComponent, "Max Creations", getMaxCreations, setMaxCreations)
	// ADD_PROPERTY(std::string, SourceModelComponent, "Time Between Creations", getTimeBetweenCreationsExpression, setTimeBetweenCreationsExpression)
	// ADD_PROPERTY(Util::TimeUnit, SourceModelComponent, "Time Unit", getTimeUnit, setTimeUnit)
	// ADD_PROPERTY(EntityType*, SourceModelComponent, "Entity Type", getEntityType, setEntityType)

	// properties//
//	Property_double *propertyD = new Property_double();
//	propertyD->setGetter(DefineGetterMember<SourceModelComponent, double>(this, &SourceModelComponent::getFirstCreation));
//	propertyD->setSetter(DefineSetterMember<SourceModelComponent, double>(this, &SourceModelComponent::setFirstCreation));
/// TODO PProperties ///	propertyD->setClassName(_typename);
/// TODO PProperties ///	propertyD->setPropertyName("First Creation");
/// TODO PProperties ///	_addPropertyG(propertyD);
//	//
//	Property_unsigned_int *propertyI = new Property_unsigned_int();
//	propertyI->setGetter(DefineGetterMember<SourceModelComponent, unsigned int>(this, &SourceModelComponent::getEntitiesPerCreation));
//	propertyI->setSetter(DefineSetterMember<SourceModelComponent, unsigned int>(this, &SourceModelComponent::setEntitiesPerCreation));
/// TODO PProperties ///	propertyI->setClassName(_typename);
/// TODO PProperties ///	propertyI->setPropertyName("Entities Per Creation");
/// TODO PProperties ///	_addPropertyG(propertyI);


	//model->getControls()->insert(_properties->getProperty("First Creation"));
	//model->getControls()->insert(_properties->getProperty("Entities Per Creation"));
	//model->getControls()->insert(_properties->getProperty("Max Creations"));
	//model->getControls()->insert(_properties->getProperty("Time Between Creations"));
	//model->getControls()->insert(_properties->getProperty("Time Unit"));
	// todo continue

}

std::string SourceModelComponent::show() {
	std::string text = ModelComponent::show();
	if (_entityType != nullptr)
		text += ",entityType=\"" + _entityType->getName() + "\"";
	else
		text += ",entityType=NULL";
	text += ",firstCreation=" + std::to_string(_firstCreation);
	return text;
}

bool SourceModelComponent::_loadInstance(PersistenceRecord *fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		this->_entitiesPerCreation = fields->loadField("entitiesPerCreation", DEFAULT.entitiesPerCreation);
		this->_firstCreation = fields->loadField("firstCreation", DEFAULT.firstCreation);
		this->_timeBetweenCreationsExpression = fields->loadField("timeBetweenCreations", DEFAULT.timeBetweenCreationsExpression);
		this->_timeBetweenCreationsTimeUnit = fields->loadField("timeBetweenCreationsTimeUnit", DEFAULT.timeBetweenCreationsTimeUnit);
		this->_maxCreationsExpression = fields->loadField("maxCreations", DEFAULT.maxCreationsExpression);
		std::string entityTypename = fields->loadField("entityType", DEFAULT.entityTypename);
		ModelDataDefinition* enttype = (_parentModel->getDataManager()->getDataDefinition(Util::TypeOf<EntityType>(), entityTypename));
		if (enttype != nullptr) {
			this->_entityType = dynamic_cast<EntityType*> (enttype);
		} else {
			this->_entityType = nullptr;
		}
	}
	return res;
}

void SourceModelComponent::_initBetweenReplications() {
	for (unsigned int i=0; i<this->_entitiesPerCreation; i++) {
		Entity* newEntity = _parentModel->createEntity(_entityType->getName() + "_%", false);
		newEntity->setEntityType(_entityType);
		Event* newEvent = new Event(_firstCreation, newEntity, this);
		_parentModel->getFutureEvents()->insert(newEvent);
	}
	_entitiesCreatedSoFar = _entitiesPerCreation;
}

void SourceModelComponent::_saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {
	ModelComponent::_saveInstance(fields, saveDefaultValues);
	fields->saveField("entitiesPerCreation", _entitiesPerCreation, DEFAULT.entitiesPerCreation, saveDefaultValues);
	fields->saveField("firstCreation", _firstCreation, DEFAULT.firstCreation, saveDefaultValues);
	fields->saveField("timeBetweenCreations", _timeBetweenCreationsExpression, DEFAULT.timeBetweenCreationsExpression, saveDefaultValues);
	fields->saveField("timeBetweenCreationsTimeUnit", _timeBetweenCreationsTimeUnit, DEFAULT.timeBetweenCreationsTimeUnit, saveDefaultValues);
	fields->saveField("maxCreations", _maxCreationsExpression, DEFAULT.maxCreationsExpression, saveDefaultValues);
	if (_entityType != nullptr) {
		fields->saveField("entityType", _entityType->getName());
	} else {
		fields->saveField("entityType", DEFAULT.entityTypename);
	}
}

bool SourceModelComponent::_check(std::string* errorMessage) {
	bool resultAll = true;
	resultAll &= _parentModel->getDataManager()->check(Util::TypeOf<EntityType>(), _entityType, "entitytype", errorMessage);
	resultAll &= _parentModel->checkExpression(this->_timeBetweenCreationsExpression, "time between creations", errorMessage);
	return resultAll;
}

void SourceModelComponent::_createInternalAndAttachedData() {
	_attachedAttributesInsert({"Entity.ArrivalTime", "Entity.Type"});
	if (_parentModel->isAutomaticallyCreatesModelDataDefinitions()) {
		if (this->_entityType == nullptr) {
			_entityType = new EntityType(_parentModel, DEFAULT.entityTypename);
		}
	}
	_attachedDataInsert("EntityType", _entityType);
}

double SourceModelComponent::propertyfirstCreation() const
{
	return _propertyfirstCreation;
}

void SourceModelComponent::setPropertyfirstCreation(double newPropertyfirstCreation)
{
	if (qFuzzyCompare(_propertyfirstCreation, newPropertyfirstCreation))
		return;
	_propertyfirstCreation = newPropertyfirstCreation;
	//emit propertyfirstCreationChanged();
}

void SourceModelComponent::setFirstCreation(double _firstCreation) {
	this->_firstCreation = _firstCreation;
}

double SourceModelComponent::getFirstCreation() const {
	return _firstCreation;
}

void SourceModelComponent::setEntityType(EntityType* entityType) {
	_entityType = entityType;
}

void SourceModelComponent::setEntityTypeName(std::string entityTypeName) {
	ModelDataDefinition* data = _parentModel->getDataManager()->getDataDefinition(Util::TypeOf<EntityType>(), entityTypeName);
	if (data != nullptr) {
		_entityType = dynamic_cast<EntityType*> (data);
	} else {
		_entityType = new EntityType(_parentModel, entityTypeName);
	}
}

EntityType* SourceModelComponent::getEntityType() const {
	return _entityType;
}

void SourceModelComponent::setTimeUnit(Util::TimeUnit _timeUnit) {
	this->_timeBetweenCreationsTimeUnit = _timeUnit;
}

Util::TimeUnit SourceModelComponent::getTimeUnit() const {
	return this->_timeBetweenCreationsTimeUnit;
}

void SourceModelComponent::setTimeBetweenCreationsExpression(std::string _timeBetweenCreations) {
	this->_timeBetweenCreationsExpression = _timeBetweenCreations;
}

void SourceModelComponent::setTimeBetweenCreationsExpression(std::string _timeBetweenCreations, Util::TimeUnit _timeUnit) {
	this->_timeBetweenCreationsExpression = _timeBetweenCreations;
	this->_timeBetweenCreationsTimeUnit = _timeUnit;
}

std::string SourceModelComponent::getTimeBetweenCreationsExpression() const {
	return _timeBetweenCreationsExpression;
}

void SourceModelComponent::setMaxCreations(std::string _maxCreationsExpression) {
	this->_maxCreationsExpression = _maxCreationsExpression;
}

void SourceModelComponent::setMaxCreations(unsigned long _maxCreations) {
	this->_maxCreationsExpression = std::to_string(_maxCreations);
}

std::string SourceModelComponent::getMaxCreations() const {
	return _maxCreationsExpression;
}

unsigned int SourceModelComponent::getEntitiesCreated() const {
	return _entitiesCreatedSoFar;
}

void SourceModelComponent::setEntitiesCreated(unsigned int _entitiesCreated) {
	this->_entitiesCreatedSoFar = _entitiesCreated;
}

void SourceModelComponent::setEntitiesPerCreation(unsigned int _entitiesPerCreation) {
	this->_entitiesPerCreation = _entitiesPerCreation;
	//this->_entitiesCreatedSoFar = _entitiesPerCreation; // that's because "entitiesPerCreation" entities are included in the future events list BEFORE replication starts (to initialize events list)
}

unsigned int SourceModelComponent::getEntitiesPerCreation() const {
	return _entitiesPerCreation;
}
