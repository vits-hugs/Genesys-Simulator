/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Resource.cpp
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Agosto de 2018, 16:52
 */

#include "Resource.h"
#include "../../kernel/simulator/Counter.h"
#include "../../kernel/simulator/Model.h"
#include "Schedule.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Resource::GetPluginInformation;
}
#endif

ModelDataDefinition* Resource::NewInstance(Model* model, std::string name) {
	return new Resource(model, name);
}

Resource::Resource(Model* model, std::string name) : ModelDataDefinition(model, Util::TypeOf<Resource>(), name) {
	_resourceEventHandlers->setSortFunc([](const SortedResourceEventHandler* a, const SortedResourceEventHandler * b) {
		return a->second < b->second; /// Handlers are sorted by priority
	});
	// OLD
	//GetterMemberDouble getter = DefineGetterMember<Resource>(this, &Resource::getCapacity);
	//SetterMemberDouble setter = DefineSetterMember<Resource>(this, &Resource::setCapacity);
	//model->getControls()->insert(new SimulationControl(Util::TypeOf<Resource>(), getName() + ".Capacity", getter, setter));
	//GetterMemberDouble getter2 = DefineGetterMember<Resource>(this, &Resource::getCostPerUse);
	//SetterMemberDouble setter2 = DefineSetterMember<Resource>(this, &Resource::setCostPerUse);
	//model->getControls()->insert(new SimulationControl(Util::TypeOf<Resource>(), getName() + ".CostPerUse", getter2, setter2));
	// ...
	PropertyT<unsigned int>* prop1 = new PropertyT<unsigned int>(Util::TypeOf<Resource>(), "Capacity",
			DefineGetter<Resource, unsigned int>(this, &Resource::getCapacity),
			DefineSetter<Resource, unsigned int>(this, &Resource::setCapacity));
	_parentModel->getControls()->insert(prop1);
	_addProperty(prop1);
}

std::string Resource::show() {
	return ModelDataDefinition::show() +
			",capacity=" + Util::StrTruncIfInt(std::to_string(_capacity)) +
			",costBusyByour=" + Util::StrTruncIfInt(std::to_string(_costBusyHour)) +
			",costIdleByour=" + Util::StrTruncIfInt(std::to_string(_costIdleHour)) +
			",costPerUse=" + Util::StrTruncIfInt(std::to_string(_costPerUse)) +
			",state=" + Util::StrTruncIfInt(std::to_string(static_cast<int> (_resourceState)));
}

bool Resource::seize(unsigned int quantity, double priority) {
	bool canSeize = (getCapacity() - _numberBusy) >= quantity;
	if (canSeize) {
		_numberBusy += quantity;
		if (_reportStatistics)
			_counterNumSeizes->incCountValue(quantity);
		_lastTimeSeized = _parentModel->getSimulation()->getSimulatedTime(); // instant when seized
		_lastTimeAnythingNumberBusy = _numberBusy; 
		_resourceState = Resource::ResourceState::BUSY;
	}
	// @TODO implement costs
	return canSeize;
}

void Resource::release(unsigned int quantity) {
	if (_numberBusy >= quantity) {
		_numberBusy -= quantity;
	} else {
		_numberBusy = 0;
	}
	if (_numberBusy == 0) {
		_resourceState = Resource::ResourceState::IDLE;
	}
	_lastTimeReleased = _parentModel->getSimulation()->getSimulatedTime();
	_lastTimeAnythingNumberBusy = _numberBusy;
	double timeSeized = _lastTimeReleased - _lastTimeSeized;
	if (_reportStatistics) {
		_counterNumReleases->incCountValue(quantity);
		_cstatTimeSeized->getStatistics()->getCollector()->addValue(timeSeized);
		_counterTotalTimeSeized->incCountValue(timeSeized);
	}
	_notifyReleaseEventHandlers();
	_checkFailByCount();
}

void Resource::_fail() {
	_originalCapacity = _capacity;
	_lastTimeFailed = _parentModel->getSimulation()->getSimulatedTime();
	_capacity = 0;
	_isActive = false;
	_resourceState = ResourceState::FAILED;
	_parentModel->getTracer()->traceSimulation(this, "Resource \"" + this->getName() + "\" has failed. Capacity " + std::to_string(_originalCapacity) + " changed to 0");
}

void Resource::_active() {
	_capacity = _originalCapacity;
	if (_reportStatistics) {
		double failureTime = _parentModel->getSimulation()->getSimulatedTime() - _lastTimeFailed;
		_counterTotalTimeFailed->incCountValue(failureTime);
		_cstatTimeFailed->getStatistics()->getCollector()->addValue(failureTime);
	}
	_isActive = true;
	if (_numberBusy == 0)
		_resourceState = ResourceState::IDLE;
	else
		_resourceState = ResourceState::BUSY;
	_parentModel->getTracer()->traceSimulation(this, "Resource \"" + this->getName() + "\" has been activated. Capacity set back to " + std::to_string(_capacity));
}


void Resource::_checkFailByCount() {
	for (Failure* failure : *_failures->list()) {
		if (failure->getFailureType() == Failure::FailureType::COUNT) {
			failure->checkIsGoingToFailByCount(this);
		}
	}
}

// 
void Resource::_initBetweenReplications() {
	ModelDataDefinition::_initBetweenReplications();
	_lastTimeSeized = 0.0;
	_lastTimeReleased = 0.0;
	_lastTimeFailed = 0.0;
	_lastTimeAnythingNumberBusy = 0.0;
	_sumNumberBusyOverTime = 0.0;
	_sumCapacityOverTime = 0.0;
	_numberBusy = 0;
	_isActive = true;
}

void Resource::setResourceState(ResourceState _resourceState) {
	this->_resourceState = _resourceState;
}

Resource::ResourceState Resource::getResourceState() const {
	return _resourceState;
}

void Resource::setCapacity(unsigned int _capacity) {
	this->_capacity = _capacity;
}

unsigned int Resource::getCapacity() const {
	if (this->_capacitySchedule == nullptr || _parentModel == nullptr || !_isActive)
		return _capacity;
	else
		return _parentModel->parseExpression(_capacitySchedule->getExpression());
}

void Resource::setCostBusyHour(double _costBusyHour) {
	this->_costBusyHour = _costBusyHour;
}

double Resource::getCostBusyHour() const {
	return _costBusyHour;
}

void Resource::setCostIdleHour(double _costIdleHour) {
	this->_costIdleHour = _costIdleHour;
}

double Resource::getCostIdleHour() const {
	return _costIdleHour;
}

void Resource::setCostPerUse(double _costPerUse) {
	this->_costPerUse = _costPerUse;
}

double Resource::getCostPerUse() const {
	return _costPerUse;
}

unsigned int Resource::getNumberBusy() const {
	return _numberBusy;
}

void Resource::addReleaseResourceEventHandler(ResourceEventHandler eventHandler, ModelComponent* component, unsigned int priority) {
	ModelComponent* compHandler;
	for (SortedResourceEventHandler* sreh : * this->_resourceEventHandlers->list()) {
		compHandler = sreh->first.second;
		if (compHandler == component) {
			return; // already exists. Do not insert again
		}
	}
	SortedResourceEventHandler* sortedEventHandler = new SortedResourceEventHandler({
		{eventHandler, component}, priority
	});
	_resourceEventHandlers->insert(sortedEventHandler);
}

double Resource::getLastTimeSeized() const {
	return _lastTimeSeized;
}
double Resource::getInstantCapacityUtilization() const {
	double capacity = getCapacity();
	if (capacity == 0)
		return 0.0;
	else 
		return _numberBusy/capacity;
}

double Resource::getCapacityUtilization() const {
	if (_parentModel != nullptr && _parentModel->getSimulation()->getSimulatedTime() > 0)
		return this->_sumNumberBusyOverTime / (this->_sumCapacityOverTime * _parentModel->getSimulation()->getSimulatedTime());
	else
		return 0.0;
}

double Resource::getSeizedUtilization() const {
	if (_parentModel != nullptr && _parentModel->getSimulation()->getSimulatedTime() > 0)
		return _counterTotalTimeSeized->getCountValue() / _parentModel->getSimulation()->getSimulatedTime();
	else
		return 0.0;
}

void Resource::insertFailure(Failure* failure) {
	_failures->insert(failure);
	failure->falingResources()->insert(this);
}

void Resource::removeFailure(Failure* failure) {
	_failures->remove(failure);
	failure->falingResources()->remove(this);
}

void Resource::setCapacitySchedule(Schedule* _capacitySchedule) {
	this->_capacitySchedule = _capacitySchedule;
}

Schedule* Resource::getCapacitySchedule() const {
	return _capacitySchedule;
}

//List<Failure*>* Resource::getFailures() const {
//    return _failures;
//}

void Resource::_notifyReleaseEventHandlers() {
	for (SortedResourceEventHandler* sortedHandler : *_resourceEventHandlers->list()) {
		ResourceEventHandler handler = sortedHandler->first.first;
		handler(this);
	}
}

PluginInformation* Resource::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Resource>(), &Resource::LoadInstance, &Resource::NewInstance);
	info->insertDynamicLibFileDependence("failure.so");
	info->insertDynamicLibFileDependence("schedule.so");
	//info->set...
	return info;
}

ModelDataDefinition* Resource::LoadInstance(Model* model, PersistenceRecord *fields) {
	Resource* newElement = new Resource(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

bool Resource::_loadInstance(PersistenceRecord *fields) {
	bool res = ModelDataDefinition::_loadInstance(fields);
	if (res) {
		_capacity = fields->loadField("capacity", DEFAULT.capacity);
		_costBusyHour = fields->loadField("costBusyHour", DEFAULT.cost);
		_costIdleHour = fields->loadField("costIdleHour", DEFAULT.cost);
		_costPerUse = fields->loadField("costPerUse", DEFAULT.cost);
		_resourceState = static_cast<Resource::ResourceState> (fields->loadField("resourceState", static_cast<int> (DEFAULT.resourceState)));
	}
	//@TODO: Save failures
	return res;
}

void Resource::_saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {
	ModelDataDefinition::_saveInstance(fields, saveDefaultValues);
	fields->saveField("capacity", _capacity, DEFAULT.capacity, saveDefaultValues);
	fields->saveField("costBusyHour", _costBusyHour, DEFAULT.cost, saveDefaultValues);
	fields->saveField("costIdleHour", _costIdleHour, DEFAULT.cost, saveDefaultValues);
	fields->saveField("costPerUse", _costPerUse, DEFAULT.cost, saveDefaultValues);
	fields->saveField("resourceState", static_cast<int> (_resourceState), static_cast<int> (DEFAULT.resourceState), saveDefaultValues);
	//@TODO: load failures
}

bool Resource::_check(std::string* errorMessage) {
	//@TODO CHECK!
	*errorMessage += "";
	return true;
}

void Resource::_onReplicationEnd(SimulationEvent* se) {
	double totalTime = se->getSimulatedTime();
	double seizedTime = _counterTotalTimeSeized->getCountValue();
	double finalProportionSeized = seizedTime / totalTime;
	_cstatProportionSeized->getStatistics()->getCollector()->addValue(finalProportionSeized); // final proportionSeized is just one more value to this cstat
}

void Resource::_createInternalAndAttachedData() {
	if (_reportStatistics && _cstatTimeSeized == nullptr) {
		_cstatProportionSeized = new StatisticsCollector(_parentModel, getName() + "." + "ProportionSeized", this);
		_cstatCapacityUtilization = new StatisticsCollector(_parentModel, getName() + "." + "CapacityUtilization", this);
		_cstatTimeSeized = new StatisticsCollector(_parentModel, getName() + "." + "TimeSeized", this);
		_cstatTimeFailed = new StatisticsCollector(_parentModel, getName() + "." + "TimeFailed", this);
		_counterTotalTimeSeized = new Counter(_parentModel, getName() + "." + "TotalTimeSeized", this);
		_counterTotalTimeFailed = new Counter(_parentModel, getName() + "." + "TotalTimeFailed", this);
		_counterNumSeizes = new Counter(_parentModel, getName() + "." + "Seizes", this);
		_counterNumReleases = new Counter(_parentModel, getName() + "." + "Releases", this);
		_internalDataInsert("ProportionSeized", _cstatProportionSeized);
		_internalDataInsert("CapacityUtilization", _cstatCapacityUtilization);
		_internalDataInsert("TimeSeized", _cstatTimeSeized);
		_internalDataInsert("TimeFailed", _cstatTimeFailed);
		_internalDataInsert("TotalTimeSeized", _counterTotalTimeSeized);
		_internalDataInsert("TotalTimeFailed", _counterTotalTimeFailed);
		_internalDataInsert("Seizes", _counterNumSeizes);
		_internalDataInsert("Releases", _counterNumReleases);
		_parentModel->getOnEvents()->addOnReplicationEndHandler(this, &Resource::_onReplicationEnd);
	} else if (!_reportStatistics && _cstatTimeSeized != nullptr) {
		_internalDataClear();
	}
	for (Failure* failure : *_failures->list()) {
		_attachedDataInsert(getName() + "." + failure->getName(), failure);
	}
}
