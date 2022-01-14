/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Smart_Plugin.cpp
 * Author: rlcancian
 * 
 * Created on 13 de janeiro de 2022, 17:47
 */

#include "Smart_Plugin.h"

#include "../../kernel/simulator/Simulator.h"

Smart_Plugin::Smart_Plugin() {
}

int Smart_Plugin::main(int argc, char** argv) {
	Simulator* simulator = new Simulator();
	this->insertFakePluginsByHand(simulator);
	for (unsigned int i = 0; i < simulator->getPlugins()->size(); i++) {
		std::cout << std::endl << simulator->getPlugins()->getAtRank(i)->show() << std::endl;
	}
	/*
		m->getPersistence()->setOption(ModelPersistence_if::Options::SAVEDEFAULTS, true);
		Plugin* plugin;
		PluginInformation* info;
		ModelElement* elem;
		ModelComponent* comp;
		std::string text;
		std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
		for (unsigned int i = 0; i < plugins->size(); i++) {
			plugin = plugins->getAtRank(i);
			info = plugin->getPluginInfo();
			fields->clear();
			if (info->isComponent()) {
				comp = dynamic_cast<ModelComponent*> (plugin->loadNew(m, fields));
				fields = comp->SaveInstance(comp);
			} else {
				elem = plugin->loadNew(m, fields);
				fields = elem->SaveInstance(elem);
			}
			text = "\n" + info->getPluginTypename() + " Fields: ";
			for (std::pair<std::string, std::string> field : *fields) {
				text += " " + field.first + "=" + field.second + ", ";
			}
			std::cout << text << std::endl;
		}
	 */
}
