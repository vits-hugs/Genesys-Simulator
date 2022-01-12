/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   DummyElement.cpp
 * Author: rlcancian
 * 
 * Created on 11 de janeiro de 2022, 22:26
 */

#include "DummyElement.h"

DummyElement::DummyElement(Model* model, std::string name) : ModelElement(model, Util::TypeOf<DummyElement>(), name) {
}

// static 

ModelElement* DummyElement::LoadInstance(Model* model, std::map<std::string, std::string>* fields, bool insertIntoModel) {
}

std::map<std::string, std::string>* DummyElement::SaveInstance(ModelElement* element) {
}

bool DummyElement::Check(ModelElement* element, std::string* errorMessage) {
}

void DummyElement::CreateInternalElements(ModelElement* element) {
}

void DummyElement::InitBetweenReplications(ModelElement* element) {
}

//

std::string DummyElement::show() {
}
// must be overriden by derived classes

bool DummyElement::_loadInstance(std::map<std::string, std::string>* fields) {
}

std::map<std::string, std::string>* DummyElement::_saveInstance() {
}
// could be overriden by derived classes

bool DummyElement::_check(std::string* errorMessage) {
}

ParserChangesInformation* DummyElement::_getParserChangesInformation() {
}

void DummyElement::_initBetweenReplications() {
}

void DummyElement::_createInternalElements() {
}
