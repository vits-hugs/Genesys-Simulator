/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Schedule.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:16
 */

#include "Schedule.h"

Schedule::Schedule(Model* model, std::string name) : ModelData(model, Util::TypeOf<Schedule>(), name) {
}

std::string Schedule::show() {
}

PluginInformation* Schedule::GetPluginInformation() {
}

ModelData* Schedule::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
}

bool Schedule::_loadInstance(std::map<std::string, std::string>* fields) {
}

std::map<std::string, std::string>* Schedule::_saveInstance(bool saveDefaultValues) {
}

bool Schedule::_check(std::string* errorMessage) {
	*errorMessage += "";
	return true;
}

