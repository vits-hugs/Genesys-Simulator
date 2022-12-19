/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExperimentManager.cpp
 * Author: rlcancian
 * 
 * Created on 4 de maio de 2021, 11:43
 */

#include "ExperimentManager.h"
#include "Simulator.h"

ExperimentManager::ExperimentManager(Simulator* simulator) {
	_simulator = simulator;
	_currentSimulationExperiment = nullptr;
}

List<SimulationExperiment*>* ExperimentManager::getExperiments() const {
	return _experiments;
}

SimulationExperiment* ExperimentManager::newSimulationExperiment() {
	_currentSimulationExperiment = new SimulationExperiment(); //_simulator
	return _currentSimulationExperiment;
}

void ExperimentManager::insert(SimulationExperiment* experiment) {
	_experiments->insert(experiment);
	this->_currentSimulationExperiment = experiment;
	_simulator->getTracer()->trace(TraceManager::Level::L2_results, "Experiment successfully inserted");
}

void ExperimentManager::remove(SimulationExperiment* experiment) {
	_experiments->remove(experiment);
	if (_currentSimulationExperiment == experiment) {
		_currentSimulationExperiment = this->front();
	}
	delete experiment; //->~SimulationExperiment();
	_simulator->getTracer()->trace(TraceManager::Level::L2_results, "Experiment successfully removed");
}

unsigned int ExperimentManager::size() {
	return _experiments->size();
}

bool ExperimentManager::saveSimulationExperiment(std::string filename) {
	// @TODO: implement
	if (_currentSimulationExperiment != nullptr) {
		filename = ""; // just to avoid not using it
		//return _currentSimulationExperiment->save(filename);
	}
	return false;
}

bool ExperimentManager::loadSimulationExperiment(std::string filename) {
	SimulationExperiment* experiment = new SimulationExperiment(); //_simulator);
	// @TODO: not implemented yet!
	filename = ""; // jut to avoid not using it
	bool res = false; // = experiment->load(filename);
	if (res) {
		this->insert(experiment);
		_simulator->getTracer()->trace(TraceManager::Level::L2_results, "Experiment successfully loaded");
	} else {
		delete experiment; //->~SimulationExperiment();
		_simulator->getTracer()->trace(TraceManager::Level::L2_results, "Experiment coud not be loaded");
	}
	return res;
}

void ExperimentManager::setCurrent(SimulationExperiment* experiment) {
	this->_currentSimulationExperiment = experiment;
}

SimulationExperiment* ExperimentManager::current() {
	return _currentSimulationExperiment;
}

SimulationExperiment* ExperimentManager::front() {
	return _experiments->front();
}

SimulationExperiment* ExperimentManager::next() {
	return _experiments->next();
}

