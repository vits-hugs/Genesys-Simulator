/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   DummyElement.h
 * Author: rlcancian
 *
 * Created on 11 de janeiro de 2022, 22:26
 */

#ifndef DUMMYELEMENT_H
#define DUMMYELEMENT_H

#include "../../kernel/simulator/ModelElement.h"

class DummyElement : public ModelElement {
public:
	DummyElement(Model* model, std::string name = "");
	virtual ~DummyElement() = default;
public: // static
	static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields, bool insertIntoModel); // \todo: return ModelComponent* ?
	static std::map<std::string, std::string>* SaveInstance(ModelElement* element);
	static bool Check(ModelElement* element, std::string* errorMessage);
	static void CreateInternalElements(ModelElement* element);
	static void InitBetweenReplications(ModelElement* element);
public:
	virtual std::string show();
protected: // must be overriden by derived classes
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance();
protected: // could be overriden by derived classes
	virtual bool _check(std::string* errorMessage);
	virtual ParserChangesInformation* _getParserChangesInformation();
	virtual void _initBetweenReplications();
	virtual void _createInternalElements();
private:
};

#endif /* DUMMYELEMENT_H */

