/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CelularAutomata.h
 * Author: rlcancian
 *
 * Created on 03 de Junho de 2019, 15:14
 */

#ifndef CELULARAUTOMATA_H
#define CELULARAUTOMATA_H

#include <string>
#include "../../kernel/simulator/ModelComponent.h"
#include "../../kernel/simulator/Entity.h"

class CelularAutomata : public ModelComponent {
public: // constructors
	CelularAutomata(Model* model, std::string name = "");
	virtual ~CelularAutomata() = default;
public: // virtual
	virtual std::string show();
public: // static
	static PluginInformation* GetPluginInformation();
	static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
protected: // virtual
	virtual void _onDispatchEvent(Entity* entity);
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance(bool saveDefaultValues);
protected: // virtual
	//virtual void _initBetweenReplications();
	virtual bool _check(std::string* errorMessage);
private: // methods
private: // attributes 1:1
private: // attributes 1:n
};
#endif /* CELULARAUTOMATA_H */

