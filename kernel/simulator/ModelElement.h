/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelElement.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 19:40
 */

#ifndef MODELELEMENT_H
#define MODELELEMENT_H

#include <string>
#include <list>
#include <vector>
#include <map>
#include "../util/Util.h"

#include "ParserChangesInformation.h"
#include "PersistentObject_base.h"

//namespace GenesysKernel {
class Model;

/*!
 * This class is the basis for any element of the model (such as Queue, Resource, Variable, etc.) and also for any component of the model. 
 * It has the infrastructure to read and write on file and to verify symbols.
 */
class ModelElement : PersistentObject_base {
public:
	ModelElement(Model* model, std::string elementTypename, std::string name = "", bool insertIntoModel = true);
	//ModelElement(Model* model, std::string elementTypename, std::string name = "", bool insertIntoModel = true);
	//ModelElement(const ModelElement &orig);
	virtual ~ModelElement();

public: // get & set
	Util::identification getId() const;
	void setName(std::string name);
	std::string getName() const;
	std::string getClassname() const;
	/*! Return true if this ModelElement generates statics for simulation reports*/
	bool isReportStatistics() const;
	/*! Defnes if this ModelElement generates statics for simulation reports*/
	void setReportStatistics(bool reportStatistics);
public: // static
	/*! This class method receives a map of fields readed from a file (or somewhere else) creates an instace of the ModelElements and inokes the protected method _loadInstance() of that instance, whch fills the field values. The instance can be automatticaly inserted into the simulation model if required*/
	static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields, bool insertIntoModel); // \todo: return ModelComponent* ?
	/*! This class method takes an instance of a ModelElement, invokes the protected method _saveInstance() of that instance and retorns a map of filds (name=value) that can be saved on a file (or somewhere else)*/
	static std::map<std::string, std::string>* SaveInstance(ModelElement* element);
	/*! This class method takes an instance of a ModelElement and invokes the private method_check() method of that instance, which checks itself */
	static bool Check(ModelElement* element, std::string* errorMessage);
	/*! This class method is responsible for invoking the protected method _check() of the instance element, which creates any internal ModelElement (such as childrenElements) or even other external needed ModelElements, such as attributes or variables */
	static void CreateInternalElements(ModelElement* element);
	/* This class methood is responsible for invoking the protected method _initBetweenReplication(), which clears all statistics, attributes, counters and other stuff before starting a new repliction */
	static void InitBetweenReplications(ModelElement* element);
public:
	virtual std::string show();
	/*! Returns a list of keys (names) of internal ModelElements, cuch as Counters, StatisticsCollectors and others. ChildrenElements are ModelElements used by this ModelElement thar are needed before model checking */
	std::list<std::string>* getChildrenElementKeys() const;
	ModelElement* getChildElement(std::string key) const;
	bool hasChanged() const;
protected:
	void _setChildElement(std::string key, ModelElement* child);
	void _removeChildrenElements();
	void _removeChildElement(std::string key);
protected: // must be overriden by derived classes
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance();
protected: // could be overriden by derived classes
	virtual bool _check(std::string* errorMessage);
	/*! This method returns all changes in the parser that are needed by plugins of this ModelElements. When connecting a new plugin, ParserChangesInformation are used to change parser source code, whch is after compiled and dinamically linked to to simulator kernel to reflect the changes */
	virtual ParserChangesInformation* _getParserChangesInformation();
	virtual void _initBetweenReplications();
	/*! This method is necessary only for those components that instantiate internal elements that must exist before simulation starts and even before model checking. That's the case of components that have internal StatisticsCollectors, since others components may refer to them as expressions (as in "TVAG(ThisCSTAT)") and therefore the element must exist before checking such expression */
	virtual void _createInternalElements();
private:
	void _build(Model* model, std::string thistypename, bool insertIntoModel);
private: // name is now private. So changes in name must be throught setName, wich gives oportunity to rename childrenElements, SimulationControls and SimulationResponses
	std::string _name;
protected:
	Util::identification _id;
	std::string _typename;
	bool _reportStatistics;
	bool _hasChanged;
	Model* _parentModel;
protected:
	std::map<std::string, ModelElement*>* _childrenElements = new std::map<std::string, ModelElement*>();
};
//namespace\\}

#endif /* MODELELEMENT_H */

