/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationReporterDefaultImpl1.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 8 de Agosto de 2018, 10:59
 */

#include "SimulationReporterDefaultImpl1.h"
#include <assert.h>
#include <iomanip>
#include <iostream>
#include "Counter.h"

//using namespace GenesysKernel;

SimulationReporterDefaultImpl1::SimulationReporterDefaultImpl1(ModelSimulation* simulation, Model* model, List<ModelData*>* statsCountersSimulation) {
	_simulation = simulation;
	_model = model;
	_statsCountersSimulation = statsCountersSimulation;
}

void SimulationReporterDefaultImpl1::showSimulationControls() {
	_model->getTracer()->traceReport("Simulation Controls:");
	Util::IncIndent();
	{
		for (std::list<SimulationControl*>::iterator it = _model->getControls()->list()->begin(); it != _model->getControls()->list()->end(); it++) {
			SimulationControl* control = (*it);
			_model->getTracer()->traceReport(control->getName() + ": " + std::to_string(control->getValue()));
		}
	}
	Util::DecIndent();
}

void SimulationReporterDefaultImpl1::showReplicationStatistics() {
	_model->getTracer()->traceReport("");
	_model->getTracer()->traceReport("Begin of Report for replication " + std::to_string(_simulation->getCurrentReplicationNumber()) + " of " + std::to_string(_model->getSimulation()->getNumberOfReplications()));
	/* @TODO: StatisticsCollector and Counter should NOT be special classes. It should iterate classes looking for classes that can generate reports.
	 StatisticsCollector and Counter should ovveride an inherited attribute from ModelData to specify they generate report information
	 look for _generateReportInformation = true;  using bool generateReportInformation() const;
	 */
	const std::string UtilTypeOfStatisticsCollector = Util::TypeOf<StatisticsCollector>();
	const std::string UtilTypeOfCounter = Util::TypeOf<Counter>();
	// runs over all elements and list the statistics for each one, and then the statistics with no parent
	Util::IncIndent();
	if (_simulation->isShowSimulationControlsInReport())
		this->showSimulationControls();
	// copy the ist of statistics and counters into a single new list
	std::list<ModelData*>* statisticsAndCounters = new std::list<ModelData*>(*(_model->getData()->getElementList(UtilTypeOfStatisticsCollector)->list()));
	std::list<ModelData*>* counters = new std::list<ModelData*>(*(_model->getData()->getElementList(UtilTypeOfCounter)->list()));
	statisticsAndCounters->merge(*counters);
	// organizes statistics into a map of maps
	std::map< std::string, std::map<std::string, std::list<ModelData*>*>* >* mapMapTypeStat = new std::map<std::string, std::map<std::string, std::list<ModelData*>*>*>();

	for (std::list<ModelData*>::iterator it = statisticsAndCounters->begin(); it != statisticsAndCounters->end(); it++) {
		std::string parentName, parentTypename;
		ModelData* statOrCnt = (*it);
		//std::cout << statOrCnt->getName() << ": " << statOrCnt->getTypename() << std::endl;
		if ((*it)->getClassname() == UtilTypeOfStatisticsCollector) {
			StatisticsCollector* stat = dynamic_cast<StatisticsCollector*> (statOrCnt);
			parentName = stat->getParent()->getName();
			parentTypename = stat->getParent()->getClassname();
		} else {
			if ((*it)->getClassname() == UtilTypeOfCounter) {
				Counter* cnt = dynamic_cast<Counter*> (statOrCnt);
				parentName = cnt->getParent()->getName();
				parentTypename = cnt->getParent()->getClassname();

			}
		}
		// look for key=parentTypename
		std::map<std::string, std::map<std::string, std::list<ModelData*>*>*>::iterator mapMapIt = mapMapTypeStat->find(parentTypename);
		if (mapMapIt == mapMapTypeStat->end()) { // parentTypename does not exists in map. Include it.
			std::pair< std::string, std::map<std::string, std::list<ModelData*>*>* >* newPair = new std::pair<std::string, std::map<std::string, std::list<ModelData*>*>*>(parentTypename, new std::map<std::string, std::list<ModelData*>*>());
			mapMapTypeStat->insert(*newPair);
			mapMapIt = mapMapTypeStat->find(parentTypename); // find again. Now it will.
		}
		//assert(mapMapIt != mapMapTypeStat->end());
		std::map<std::string, std::list<ModelData*>*>* mapTypeStat = (*mapMapIt).second;
		assert(mapTypeStat != nullptr);
		// look for key=parentName
		std::map<std::string, std::list<ModelData*>*>::iterator mapIt = mapTypeStat->find(parentName);
		if (mapIt == mapTypeStat->end()) { // parentTypename does not exists in map. Include it.
			std::pair< std::string, std::list<ModelData*>* >* newPair = new std::pair<std::string, std::list<ModelData*>*>(parentName, new std::list<ModelData*>());
			mapTypeStat->insert(*newPair);
			mapIt = mapTypeStat->find(parentName); // find again. Now it will.
		}
		// get the list and insert the stat in that list
		std::list<ModelData*>* listStatAndCount = (*mapIt).second;
		assert(listStatAndCount != nullptr);
		listStatAndCount->insert(listStatAndCount->end(), statOrCnt);
		//_model->getTraceManager()->traceReport(parentTypename + " -> " + parentName + " -> " + stat->show());
	}
	// now runs over that map of maps showing the statistics
	Util::IncIndent();
	Util::IncIndent();
	_model->getTracer()->traceReport(Util::SetW("name", _nameW) + Util::SetW("elems", _w) + Util::SetW("min", _w) + Util::SetW("max", _w) + Util::SetW("average", _w) + Util::SetW("variance", _w) + Util::SetW("stddev", _w) + Util::SetW("varCoef", _w) + Util::SetW("confInterv", _w) + Util::SetW("confLevel", _w));
	Util::DecIndent();
	Util::DecIndent();
	for (auto const mapmapItem : *mapMapTypeStat) {
		_model->getTracer()->traceReport("Statistics for " + mapmapItem.first + ":");
		Util::IncIndent();
		{
			for (auto const mapItem : *(mapmapItem.second)) {
				_model->getTracer()->traceReport(mapItem.first + ":");
				Util::IncIndent();
				{
					//					_model->getTracer()->traceReport(Util::SetW("name", _nameW) + Util::SetW("elems", _w) + Util::SetW("min", _w) + Util::SetW("max", _w) + Util::SetW("average", _w) + Util::SetW("variance", _w) + Util::SetW("stddev", _w) + Util::SetW("varCoef", _w) + Util::SetW("confInterv", _w) + Util::SetW("confLevel", _w));
					for (ModelData * const item : *(mapItem.second)) {
						if (item->getClassname() == UtilTypeOfStatisticsCollector) {
							Statistics_if* stat = dynamic_cast<StatisticsCollector*> (item)->getStatistics();
							_model->getTracer()->traceReport(Util::TraceLevel::L2_results,
									Util::SetW(item->getName() + std::string(_nameW, '.'), _nameW - 1) + " " +
									Util::SetW(std::to_string(stat->numElements()), _w) +
									Util::SetW(std::to_string(stat->min()), _w) +
									Util::SetW(std::to_string(stat->max()), _w) +
									Util::SetW(std::to_string(stat->average()), _w) +
									Util::SetW(std::to_string(stat->variance()), _w) +
									Util::SetW(std::to_string(stat->stddeviation()), _w) +
									Util::SetW(std::to_string(stat->variationCoef()), _w) +
									Util::SetW(std::to_string(stat->halfWidthConfidenceInterval()), _w) +
									Util::SetW(std::to_string(stat->getConfidenceLevel()), _w)
									);
						} else {
							if (item->getClassname() == UtilTypeOfCounter) {
								Counter* count = dynamic_cast<Counter*> (item);
								_model->getTracer()->traceReport(Util::TraceLevel::L2_results,
										Util::SetW(count->getName() + std::string(_nameW, '.'), _nameW - 1) + " " +
										Util::SetW(std::to_string(count->getCountValue()), _w)
										);
							}
						}
					}
				}
				Util::DecIndent();
			}
		}
		Util::DecIndent();
	}
	if (_simulation->isShowSimulationResposesInReport())
		this->showSimulationResponses();
	Util::DecIndent();
	_model->getTracer()->traceReport("End of Report for replication " + std::to_string(_simulation->getCurrentReplicationNumber()) + " of " + std::to_string(_model->getSimulation()->getNumberOfReplications()));
	_model->getTracer()->traceReport("-------------------------------------");
}

void SimulationReporterDefaultImpl1::showSimulationResponses() {
	_model->getTracer()->traceReport("Simulation Responses:");
	Util::IncIndent();
	{
		for (std::list<SimulationResponse*>::iterator it = _model->getResponses()->list()->begin(); it != _model->getResponses()->list()->end(); it++) {
			SimulationResponse* response = (*it);
			_model->getTracer()->traceReport(response->getName() + ": " + std::to_string(response->getValue()));
		}
	}
	Util::DecIndent();
}

void SimulationReporterDefaultImpl1::showSimulationStatistics() {//List<StatisticsCollector*>* cstatsSimulation) {
	_model->getTracer()->traceReport("");
	_model->getTracer()->traceReport("Begin of Report for Simulation (based on " + std::to_string(_model->getSimulation()->getNumberOfReplications()) + " replications)");
	const std::string UtilTypeOfStatisticsCollector = Util::TypeOf<StatisticsCollector>();
	const std::string UtilTypeOfCounter = Util::TypeOf<Counter>();
	// runs over all elements and list the statistics for each one, and then the statistics with no parent
	Util::IncIndent();
	// COPY the list of statistics and counters into a single new list
	//std::list<ModelData*>* statisticsAndCounters = //new std::list<ModelData*>(*(this->_statsCountersSimulation->list()));
	// organizes statistics into a map of maps
	std::map< std::string, std::map<std::string, std::list<ModelData*>*>* >* mapMapTypeStat = new std::map<std::string, std::map<std::string, std::list<ModelData*>*>*>();

	for (std::list<ModelData*>::iterator it = _statsCountersSimulation->list()->begin(); it != _statsCountersSimulation->list()->end(); it++) {
		std::string parentName, parentTypename;
		ModelData* statOrCnt = (*it);
		//std::cout << statOrCnt->getName() << ": " << statOrCnt->getTypename() << std::endl;
		if ((*it)->getClassname() == UtilTypeOfStatisticsCollector) {
			StatisticsCollector* stat = dynamic_cast<StatisticsCollector*> (statOrCnt);
			parentName = stat->getParent()->getName();
			parentTypename = stat->getParent()->getClassname();
		} else {
			if ((*it)->getClassname() == UtilTypeOfCounter) {
				Counter* cnt = dynamic_cast<Counter*> (statOrCnt);
				parentName = cnt->getParent()->getName();
				parentTypename = cnt->getParent()->getClassname();

			}
		}
		// look for key=parentTypename
		std::map<std::string, std::map<std::string, std::list<ModelData*>*>*>::iterator mapMapIt = mapMapTypeStat->find(parentTypename);
		if (mapMapIt == mapMapTypeStat->end()) { // parentTypename does not exists in map. Include it.
			std::pair< std::string, std::map<std::string, std::list<ModelData*>*>* >* newPair = new std::pair<std::string, std::map<std::string, std::list<ModelData*>*>*>(parentTypename, new std::map<std::string, std::list<ModelData*>*>());
			mapMapTypeStat->insert(*newPair);
			mapMapIt = mapMapTypeStat->find(parentTypename); // find again. Now it will.
		}
		assert(mapMapIt != mapMapTypeStat->end());
		std::map<std::string, std::list<ModelData*>*>* mapTypeStat = (*mapMapIt).second;
		assert(mapTypeStat != nullptr);
		// look for key=parentName
		std::map<std::string, std::list<ModelData*>*>::iterator mapIt = mapTypeStat->find(parentName);
		if (mapIt == mapTypeStat->end()) { // parentTypename does not exists in map. Include it.
			std::pair< std::string, std::list<ModelData*>* >* newPair = new std::pair<std::string, std::list<ModelData*>*>(parentName, new std::list<ModelData*>());
			mapTypeStat->insert(*newPair);
			mapIt = mapTypeStat->find(parentName); // find again. Now it will.
		}
		// get the list and insert the stat in that list
		std::list<ModelData*>* listStat = (*mapIt).second;
		listStat->insert(listStat->end(), statOrCnt);
		//_model->getTraceManager()->traceReport(parentTypename + " -> " + parentName + " -> " + stat->show());
	}
	// now runs over that map of maps showing the statistics
	//int w = 12;
	Util::IncIndent();
	Util::IncIndent();
	_model->getTracer()->traceReport(Util::SetW("name", _nameW) + Util::SetW("elems", _w) + Util::SetW("min", _w) + Util::SetW("max", _w) + Util::SetW("average", _w) + Util::SetW("variance", _w) + Util::SetW("stddev", _w) + Util::SetW("varCoef", _w) + Util::SetW("confInterv", _w) + Util::SetW("confLevel", _w));
	Util::DecIndent();
	Util::DecIndent();
	/// TODO: USE REFERENCE TO MAPITEM TO AVOID COPY
	for (auto const mapmapItem : *mapMapTypeStat) {
		_model->getTracer()->traceReport("Statistics for " + mapmapItem.first + ":");
		Util::IncIndent();
		{
			for (auto const mapItem : *(mapmapItem.second)) {
				_model->getTracer()->traceReport(mapItem.first + ":");
				Util::IncIndent();
				{
					for (ModelData * const item : *(mapItem.second)) {
						if (item->getClassname() == UtilTypeOfStatisticsCollector) {
							Statistics_if* stat = dynamic_cast<StatisticsCollector*> (item)->getStatistics();
							_model->getTracer()->traceReport(Util::TraceLevel::L2_results,
									Util::SetW(item->getName() + std::string(_nameW, '.'), _nameW - 1) + " " +
									Util::SetW(std::to_string(stat->numElements()), _w) +
									Util::SetW(std::to_string(stat->min()), _w) +
									Util::SetW(std::to_string(stat->max()), _w) +
									Util::SetW(std::to_string(stat->average()), _w) +
									Util::SetW(std::to_string(stat->variance()), _w) +
									Util::SetW(std::to_string(stat->stddeviation()), _w) +
									Util::SetW(std::to_string(stat->variationCoef()), _w) +
									Util::SetW(std::to_string(stat->halfWidthConfidenceInterval()), _w) +
									Util::SetW(std::to_string(stat->getConfidenceLevel()), _w)
									);
						} else {
							if (item->getClassname() == UtilTypeOfCounter) {
								Counter* cnt = dynamic_cast<Counter*> (item);
								_model->getTracer()->traceReport(Util::TraceLevel::L2_results,
										Util::SetW(cnt->getName() + std::string(_nameW, '.'), _nameW - 1) + " " +
										Util::SetW(std::to_string(cnt->getCountValue()), _w)
										);
							}
						}
					}
				}
				Util::DecIndent();
			}
		}
		Util::DecIndent();
	}

	Util::DecIndent();
	_model->getTracer()->traceReport("End of Report for Simulation");
}
