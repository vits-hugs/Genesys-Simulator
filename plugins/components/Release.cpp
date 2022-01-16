/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Release.cpp
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Agosto de 2018, 16:17
 */

#include "Release.h"
#include "../../kernel/simulator/Model.h"
#include "../data/Resource.h"
#include "../../kernel/simulator/Attribute.h"
#include <assert.h>
#include <cmath>

Release::Release(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Release>(), name) {
}

std::string Release::show() {
	std::string txt = ModelComponent::show() +
			"priority=" + std::to_string(_priority) +
			"releaseRequests={";
	unsigned short i = 0;
	for (SeizableItem* item : *_releaseRequests->list()) {
		txt += "request" + std::to_string(i++) + "=[" + item->show() + "],";
	}
	txt = txt.substr(0, txt.length() - 1) + "}";
	return txt;
}

void Release::setPriority(unsigned short _priority) {
	this->_priority = _priority;
}

unsigned short Release::priority() const {
	return _priority;
}

List<SeizableItem*>* Release::getReleaseRequests() const {
	return _releaseRequests;
}

//void Release::setResource(Resource* _resource) {
//	this->_resource = _resource;
//}

//Resource* Release::resource() const {
//	return _resource;
//}

void Release::_execute(Entity* entity) {
	for (SeizableItem* seizable : *_releaseRequests->list()) {
		Resource* resource;
		if (seizable->getSeizableType() == SeizableItem::SeizableType::RESOURCE) {
			resource = seizable->getResource();
		} else { // assume SET
			SeizableItem::SelectionRule rule = seizable->getSelectionRule();
			Set* set = seizable->getSet();
			unsigned int index = 0;
			switch (rule) { // @TODO: Rules for release are DIFFERENT (least and first member seized)
				case SeizableItem::SelectionRule::CYCLICAL:
					index = (seizable->getLastMemberSeized() + 1) % _releaseRequests->list()->size();
					break;
				case SeizableItem::SelectionRule::LARGESTREMAININGCAPACITY:
					// @TODO
					break;
				case SeizableItem::SelectionRule::RANDOM:
					index = trunc(rand() * _releaseRequests->list()->size());
					break;
				case SeizableItem::SelectionRule::SMALLESTNUMBERBUSY:
					// @TODO
					break;
				case SeizableItem::SelectionRule::SPECIFICMEMBER:
					index = _parentModel->parseExpression(seizable->getIndex());
					break;
			}
			_parentModel->getTracer()->traceSimulation(this, "Member of set " + set->getName() + " chosen index " + std::to_string(index), Util::TraceLevel::L8_detailed);
			resource = static_cast<Resource*> (set->getElementSet()->getAtRank(index));
			assert(resource != nullptr);
		}
		unsigned int quantity = _parentModel->parseExpression(seizable->getQuantityExpression());
		assert(resource->getNumberBusy() >= quantity); // 202104 ops. maybe not anymore
		_parentModel->getTracer()->traceSimulation(this, _parentModel->getSimulation()->getSimulatedTime(), entity, this, entity->getName() + " releases " + std::to_string(quantity) + " units of resource \"" + resource->getName() + "\" seized on time " + std::to_string(resource->getLastTimeSeized()));
		resource->release(quantity, _parentModel->getSimulation()->getSimulatedTime()); //{releases and sets the 'LastTimeSeized'property}
	}
	_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

void Release::_initBetweenReplications() {
	//for (SeizableItem* seizable : *_releaseRequests->list()) {
	//	if (seizable->getSeizableType() == SeizableItem::SeizableType::RESOURCE)
	//		seizable->getResource()->initBetweenReplications();
	//	else if (seizable->getSeizableType() == SeizableItem::SeizableType::SET)
	//		seizable->getSet()->initBetweenReplications();
	//}
}

bool Release::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		this->_priority = LoadField(fields, "priority", DEFAULT.priority);
		unsigned short numRequests = LoadField(fields, "resquestSize", DEFAULT.releaseRequestSize);
		for (unsigned short i = 0; i < numRequests; i++) {
			SeizableItem* Item = new SeizableItem(nullptr);
			Item->setElementManager(_parentModel->getData());
			Item->loadInstance(fields, i);
			//Resource* resource = static_cast<Resource*> (_parentModel->getData()->getData(Util::TypeOf<Resource>(), Item->getResourceName()));
			//Item->setResource(resource);
			//this->_releaseRequests->insert(Item);
		}
	}
	return res;
}

std::map<std::string, std::string>* Release::_saveInstance(bool saveDefaultValues) {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(saveDefaultValues); //Util::TypeOf<Release>());
	SaveField(fields, "priority", _priority, DEFAULT.priority, saveDefaultValues);
	SaveField(fields, "resquestSize", _releaseRequests->size(), DEFAULT.releaseRequestSize, saveDefaultValues);
	unsigned short i = 0;
	for (SeizableItem* request : *_releaseRequests->list()) {
		std::map<std::string, std::string>* seizablefields = request->saveInstance(i, saveDefaultValues);
		fields->insert(seizablefields->begin(), seizablefields->end());
		i++;
	}
	return fields;
}

bool Release::_check(std::string* errorMessage) {
	bool resultAll = true;

	for (SeizableItem* seizable : * _releaseRequests->list()) {
		resultAll &= _parentModel->checkExpression(seizable->getQuantityExpression(), "quantity", errorMessage);
		if (seizable->getSeizableType() == SeizableItem::SeizableType::RESOURCE) {
			resultAll &= _parentModel->getData()->check(Util::TypeOf<Resource>(), seizable->getResource(), "Resource", errorMessage);
		} else if (seizable->getSeizableType() == SeizableItem::SeizableType::SET) {
			resultAll &= _parentModel->getData()->check(Util::TypeOf<Set>(), seizable->getSet(), "Set", errorMessage);
		}
		// @TODO: Should be checking saveAttribute, index, etc
	}
	return resultAll;
}

//void Release::setResourceName(std::string resourceName) throw () {
//	ModelData* resource = _parentModel->elements()->modeldatum(Util::TypeOf<Resource>(), resourceName);
//	if (resource != nullptr) {
//		this->_resource = dynamic_cast<Resource*> (resource);
//	} else {
//		throw std::invalid_argument("Resource does not exist");
//	}
//}

//std::string Release::resourceName() const {
//	return _resource->name();
//}

PluginInformation* Release::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Release>(), &Release::LoadInstance);
	info->insertDynamicLibFileDependence("resource.so");
	std::string help = "The Release module is used to release units of a resource that an entity previously has seized.";
	help += " This module may be used to release individual resources or may be used to release resources within a set.";
	help += " For each resource to be released, the name and quantity to release are specified.";
	help += " When the entity enters the Release module, it gives up control of the specified resource(s).";
	help += " Any entities waiting in queues for those resources will gain control of the resources immediately.";
	help += " TYPICAL USES: (1) Finishing a customer order (release the operator); (2) Completing a tax return (release the accountant);";
	help += " (3) Leaving the hospital (release the doctor, nurse, hospital room)";
	info->setDescriptionHelp(help);
	return info;
}

ModelComponent* Release::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Release* newComponent = new Release(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;

}
