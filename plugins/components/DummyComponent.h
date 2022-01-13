/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dummy.h
 * Author: rafael.luiz.cancian
 *
 * Created on 22 de Maio de 2019, 18:41
 */

#ifndef DUMMYCOMPONENT_H
#define DUMMYCOMPONENT_H

#include "../../kernel/simulator/ModelComponent.h"

/*!
 This component ...
 */
class DummyComponent : public ModelComponent {
public: // constructors
	DummyComponent(Model* model, std::string name = "");
	virtual ~DummyComponent() = default;
public: // virtual
	virtual std::string show();
public: // static
	static PluginInformation* GetPluginInformation();
	static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
protected: // virtual
	virtual void _execute(Entity* entity);
	virtual void _initBetweenReplications();
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance(bool saveDefaultValues=false);
	virtual bool _check(std::string* errorMessage);
	virtual void _createInternalElements();
private: // methods
private: // attributes 1:1
private: // attributes 1:n
};

#endif /* DUMMYCOMPONENT_H */

