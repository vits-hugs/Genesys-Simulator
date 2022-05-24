/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ModelCheckerDefaultImpl1.cpp
 * Author: rafael.luiz.cancian
 *
 * Created on 8 de Agosto de 2018, 18:44
 */

#include "ModelCheckerDefaultImpl1.h"
#include "SourceModelComponent.h"
#include "SinkModelComponent.h"
#include "ComponentManager.h"
#include "Simulator.h"

#include <assert.h>

//using namespace GenesysKernel;

ModelCheckerDefaultImpl1::ModelCheckerDefaultImpl1(Model* model) {
	_model = model;
}

bool ModelCheckerDefaultImpl1::checkAll() {
	bool res = true;
	res &= checkSymbols();
	//if (res)
	//   res &= checkAndAddInternalLiterals();
	//if (res)
	//   res &= checkActivationCode();
	if (res)
		res &= checkLimits();
	if (res)
		res &= checkConnected();
	return res;
}

//bool ModelCheckerDefaultImpl1::checkAndAddInternalLiterals() {
//    /*  @TODO: +-: not implemented yet */
//    return true;
//}

void ModelCheckerDefaultImpl1::_recursiveConnectedTo(PluginManager* pluginManager, ModelComponent* comp, List<ModelComponent*>* visited, List<ModelComponent*>* unconnected, bool* drenoFound) {
	visited->insert(comp);
	_model->getTracer()->trace(Util::TraceLevel::L8_detailed, "Connected to component \"" + comp->getName() + "\"");
	Plugin* plugin = pluginManager->find(comp->getClassname());
	assert(plugin != nullptr);
	if (plugin->getPluginInfo()->isSink() || (plugin->getPluginInfo()->isSendTransfer() && comp->getConnections()->size() == 0)) {//(dynamic_cast<SinkModelComponent*> (comp) != nullptr) {
		// it is a sink OR it can send entities throught a transfer and has no nextConnections
		*drenoFound = true;
	} else { // it is not a sink
		if (comp->getConnections()->size() == 0) {
			unconnected->insert(comp);
			_model->getTracer()->traceError(Util::TraceLevel::L1_errorFatal, "Component \"" + comp->getName() + "\" is unconnected (not a sink with no next componentes connected to)");
			*drenoFound = false;
		} else {
			ModelComponent* nextComp;
			for (std::map<unsigned int, Connection*>::iterator it = comp->getConnections()->connections()->begin(); it != comp->getConnections()->connections()->end(); it++) {
				nextComp = (*it).second->component;
				if (visited->find(nextComp) == visited->list()->end()) { // not visited yet
					*drenoFound = false;
					Util::IncIndent();
					this->_recursiveConnectedTo(pluginManager, nextComp, visited, unconnected, drenoFound);
					Util::DecIndent();
				} else {
					Util::IncIndent();
					_model->getTracer()->trace(Util::TraceLevel::L8_detailed, "Connected to " + nextComp->getName());
					Util::DecIndent();
					*drenoFound = true;
				}
			}
		}
	}
}

bool ModelCheckerDefaultImpl1::checkConnected() {
	/*  @TODO: +-: not implemented yet */
	_model->getTracer()->trace(Util::TraceLevel::L7_internal, "Checking connected");
	bool resultAll = true;
	PluginManager* pluginManager = this->_model->getParentSimulator()->getPlugins();
	Plugin* plugin;
	Util::IncIndent();
	{
		List<ModelComponent*>* visited = new List<ModelComponent*>();
		List<ModelComponent*>* unconnected = new List<ModelComponent*>();
		ModelComponent* comp;
		for (std::list<ModelComponent*>::iterator it = _model->getComponents()->begin(); it != _model->getComponents()->end(); it++) {
			comp = (*it);
			plugin = pluginManager->find(comp->getClassname());
			assert(plugin != nullptr);
			if (plugin->getPluginInfo()->isSource() || plugin->getPluginInfo()->isReceiveTransfer()) { //(dynamic_cast<SourceModelComponent*> (comp) != nullptr) {
				// it is a source component OR it can receive enetities from transfer
				bool drenoFound = false;
				_recursiveConnectedTo(pluginManager, comp, visited, unconnected, &drenoFound);
			}
		}
		// check if any component remais unconnected
		for (std::list<ModelComponent*>::iterator it = _model->getComponents()->begin(); it != _model->getComponents()->end(); it++) {
			comp = (*it);
			if (visited->find(comp) == visited->list()->end()) { //not found
				resultAll = false;
				_model->getTracer()->traceError(Util::TraceLevel::L1_errorFatal, "Component \"" + comp->getName() + "\" is unconnected.");
			}
		}

	}
	Util::DecIndent();
	return resultAll;
}

bool ModelCheckerDefaultImpl1::checkSymbols() {
	bool res = true;
	_model->getTracer()->trace(Util::TraceLevel::L7_internal, "Checking symbols");
	Util::IncIndent();
	{
		// check components
		_model->getTracer()->trace(Util::TraceLevel::L8_detailed, "Components:");
		Util::IncIndent();
		{
			//List<ModelComponent*>* components = _model->getComponents();
			for (std::list<ModelComponent*>::iterator it = _model->getComponents()->begin(); it != _model->getComponents()->end(); it++) {
				res &= (*it)->Check((*it));
			}
		}
		Util::DecIndent();

		// check elements
		if (res) {
			_model->getTracer()->trace(Util::TraceLevel::L8_detailed, "Elements:");
			Util::IncIndent();
			{
				std::string elementType;
				bool result;
				ModelDataDefinition* modeldatum;
				std::string* errorMessage = new std::string();
				std::list<std::string>* elementTypes = _model->getDataManager()->getDataDefinitionClassnames();
				for (std::list<std::string>::iterator typeIt = elementTypes->begin(); typeIt != elementTypes->end(); typeIt++) {
					elementType = (*typeIt);
					List<ModelDataDefinition*>* elements = _model->getDataManager()->getDataDefinitionList(elementType);
					for (std::list<ModelDataDefinition*>::iterator it = elements->list()->begin(); it != elements->list()->end(); it++) {
						modeldatum = (*it);
						// copyed from modelCOmponent. It is not inside the ModelDataDefinition::Check because ModelDataDefinition has no access to Model to call Tracer
						_model->getTracer()->trace(Util::TraceLevel::L8_detailed, "Checking " + modeldatum->getClassname() + ": \"" + modeldatum->getName() + "\" (id " + std::to_string(modeldatum->getId()) + ")"); //std::to_string(component->_id));
						Util::IncIndent();
						{
							try {
								result = modeldatum->Check((*it), errorMessage);
								res &= result;
								if (!result) {
									_model->getTracer()->traceError(Util::TraceLevel::L1_errorFatal, "Error: Checking has failed with message '" + *errorMessage + "'");
								}
							} catch (const std::exception& e) {
								_model->getTracer()->traceError(e, "Error verifying component " + modeldatum->show());
							}
						}
						Util::DecIndent();
					}
				}
			}
			Util::DecIndent();
		}
	}
	Util::DecIndent();

	return res;
}

bool ModelCheckerDefaultImpl1::checkActivationCode() {
	/*  @TODO: +-: not implemented yet */
	_model->getTracer()->trace(Util::TraceLevel::L7_internal, "Checking activation code");
	Util::IncIndent();
	{

	}
	Util::DecIndent();
	return true;
}

bool ModelCheckerDefaultImpl1::checkLimits() {
	bool res = true;
	std::string text;
	unsigned int value, limit;
	LicenceManager *licence = _model->getParentSimulator()->getLicenceManager();
	_model->getTracer()->trace(Util::TraceLevel::L7_internal, "Checking model limits");
	Util::IncIndent();
	{
		value = _model->getComponents()->getNumberOfComponents();
		limit = licence->getModelComponentsLimit();
		res &= value <= limit;
		_model->getTracer()->trace("Model has " + std::to_string(value) + "/" + std::to_string(limit) + " components");
		if (!res) {
			text = "Model has " + std::to_string(_model->getComponents()->getNumberOfComponents()) + " components, exceding the limit of " + std::to_string(licence->getModelComponentsLimit()) + " components imposed by the current activation code";
			//_model->getTraceManager()->trace(Util::TraceLevel::errors, text);
		} else {
			value = _model->getDataManager()->getNumberOfDataDefinitions();
			limit = licence->getModelDatasLimit();
			res &= value <= limit;
			_model->getTracer()->trace("Model has " + std::to_string(value) + "/" + std::to_string(limit) + " elements");
			if (!res) {
				text = "Model has " + std::to_string(_model->getDataManager()->getNumberOfDataDefinitions()) + " elements, exceding the limit of " + std::to_string(licence->getModelDatasLimit()) + " elements imposed by the current activation code";
				//_model->getTraceManager()->trace(Util::TraceLevel::errors, text);
			}
		}
		if (!res) {
			_model->getTracer()->traceError(Util::TraceLevel::L1_errorFatal, "Error: Checking has failed with message '" + text + "'");
		}
	}
	Util::DecIndent();
	return res;
}

bool ModelCheckerDefaultImpl1::checkOrphaned() {
	_model->getTracer()->trace(Util::TraceLevel::L7_internal, "Checking orphaned DataDefinitions");
	Util::IncIndent();
	{
	}
}