/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sequence.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:12
 */

#include "Sequence.h"
#include "../../kernel/simulator/Attribute.h"
#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Simulator.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &Sequence::GetPluginInformation;
}
#endif

ModelDataDefinition* Sequence::NewInstance(Model* model, std::string name) {
	return new Sequence(model, name);
}

Sequence::Sequence(Model* model, std::string name) : ModelDataDefinition(model, Util::TypeOf<Sequence>(), name) {
}

std::string Sequence::show() {
	std::string msg = ModelDataDefinition::show();
	return msg;
}

PluginInformation* Sequence::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Sequence>(), &Sequence::LoadInstance, &Sequence::NewInstance);
	return info;
}

ModelDataDefinition* Sequence::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Sequence* newElement = new Sequence(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

List<SequenceStep*>* Sequence::getSteps() const {
	return _steps;
}

bool Sequence::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelDataDefinition::_loadInstance(fields);
	if (res) {
		try {
			unsigned short numSteps = LoadField(fields, "steps", 0);
			for (unsigned short i = 0; i < numSteps; i++) {
				SequenceStep* step = new SequenceStep((Station*)nullptr);
				step->setElementManager(_parentModel->getDataManager());
				step->_loadInstance(fields, i);
				this->_steps->insert(step);
			}
		} catch (...) {
		}
	}
	return res;
}

std::map<std::string, std::string>* Sequence::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelDataDefinition::_saveInstance(saveDefaultValues); //Util::TypeOf<Sequence>());
	SaveField(fields, "steps", _steps->size(), 0u, saveDefaultValues);
	int i = 0;
	for (SequenceStep* step : *_steps->list()) {
		std::map<std::string, std::string>* stepfields = step->_saveInstance(i, saveDefaultValues);
		fields->insert(stepfields->begin(), stepfields->end());
		i++;
	}
	return fields;
}

bool Sequence::_check(std::string* errorMessage) {
	_insertNeededAttributes({"Entity.Sequence", "Entity.SequenceStep"});
	int i = 0;
	for (SequenceStep* step : *_steps->list()) {
		_setAttachedData("StepStation" + strIndex(i), step->getStation());
		_setAttachedData("StepLabel" + strIndex(i), step->getLabel());
		i++;
	}
	*errorMessage += "";
	return true;
}

SequenceStep::SequenceStep(Station* station, std::list<Assignment*>* assignments) {
	this->_station = station;
	if (assignments != nullptr)
		_assignments = assignments;
	else
		_assignments = new std::list<Assignment*>();
}

SequenceStep::SequenceStep(Label* label, std::list<Assignment*>* assignments) {
	this->_label = label;
	if (assignments != nullptr)
		_assignments = assignments;
	else
		_assignments = new std::list<Assignment*>();
}

SequenceStep::SequenceStep(Model* model, std::string stationOrLabelName, bool isStation, std::list<Assignment*>* assignments) {
	this->_modeldataManager = model->getDataManager();
	if (isStation) {
		Station* station;
		ModelDataDefinition* data = model->getDataManager()->getDataDefinition(Util::TypeOf<Station>(), stationOrLabelName);
		if (data != nullptr) {
			station = dynamic_cast<Station*> (data);
		} else {
			station = model->getParentSimulator()->getPlugins()->newInstance<Station>(model, stationOrLabelName);
		}
		this->_station = station;
	} else {//isLabel
		Label* label;
		ModelDataDefinition* data = model->getDataManager()->getDataDefinition(Util::TypeOf<Label>(), stationOrLabelName);
		if (data != nullptr) {
			label = dynamic_cast<Label*> (data);
		} else {
			label = model->getParentSimulator()->getPlugins()->newInstance<Label>(model, stationOrLabelName);
		}
		this->_label = label;
	}
	if (assignments != nullptr)
		_assignments = assignments;
	else
		_assignments = new std::list<Assignment*>();
}

bool SequenceStep::_loadInstance(std::map<std::string, std::string>* fields, unsigned int parentIndex) {
	bool res = true;
	std::string num = strIndex(parentIndex);
	std::string destination, expression;
	try {
		std::string stationName = LoadField(fields, "stepStation" + num, "");
		if (_modeldataManager != nullptr) {
			_station = static_cast<Station*> (_modeldataManager->getDataDefinition(Util::TypeOf<Station>(), stationName));
		}
		std::string labelName = LoadField(fields, "stepLabel" + num, "");
		if (_modeldataManager != nullptr) {
			_label = static_cast<Label*> (_modeldataManager->getDataDefinition(Util::TypeOf<Label>(), labelName));
		}
		unsigned int assignmentsSize = LoadField(fields, "stepAssignments" + num, DEFAULT.assignmentsSize);
		for (unsigned short i = 0; i < assignmentsSize; i++) {
			Assignment* assm = new Assignment("", "");
			assm->loadInstance(fields, i);
			_assignments->insert(_assignments->end(), assm);
		}
	} catch (...) {
		res = false;
	}
	return res;
}

std::map<std::string, std::string>* SequenceStep::_saveInstance(unsigned int parentIndex, bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
	std::string num = strIndex(parentIndex);
	if (_station != nullptr) {
		SaveField(fields, "stepStation" + num, _station->getName());
	}
	if (_label != nullptr) {
		SaveField(fields, "stepLabel" + num, _label->getName());
	}
	SaveField(fields, "stepAssignments" + num, _assignments->size(), DEFAULT.assignmentsSize);
	unsigned short i = 0;
	for (Assignment* assm : *_assignments) {
		std::map<std::string, std::string>* assmfields = assm->saveInstance(i, saveDefaultValues);
		fields->insert(assmfields->begin(), assmfields->end());
		i++;
	}
	return fields;
}

bool SequenceStep::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = true;
	try {
	} catch (...) {
		res = false;
	}
	return res;
}

std::map<std::string, std::string>* SequenceStep::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
	return fields;
}

std::list<Assignment*>* SequenceStep::getAssignments() const {
	return _assignments;
}

void SequenceStep::setStation(Station* _station) {
	this->_station = _station;
}

Station* SequenceStep::getStation() const {
	return _station;
}

void SequenceStep::setElementManager(ModelDataManager* _modeldataManager) {
	this->_modeldataManager = _modeldataManager;
}

void SequenceStep::setLabel(Label* _label) {
	this->_label = _label;
}

Label* SequenceStep::getLabel() const {
	return _label;
}
