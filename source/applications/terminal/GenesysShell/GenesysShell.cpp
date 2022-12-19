/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysShell.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 23 de Maio de 2019, 13:02
 */

#include "GenesysShell.h"
#include "../../../kernel/simulator/Simulator.h"
#include <regex>
#include <fstream>
#include <assert.h>

//#include "ProbDistribDefaultImpl1.h"

GenesysShell::GenesysShell() {
}

void GenesysShell::Trace(std::string message) {
	std::cout << message << std::endl;
}

void GenesysShell::run(List<std::string>* commandlineArgs) {
	Trace("Genesys Shell is running. Type your command. For help, type the command \"help\".");
	this->insertFakePluginsByHand(_simulator);
	std::string inputText; //, shortPrefix, longPrefix, separator; //,longPrefix, separator;
	while (true) {
		if (!commandlineArgs->empty()) {
			inputText = commandlineArgs->front();
			commandlineArgs->pop_front();
			tryExecuteCommand(inputText, "-", "--", "=");
		} else {
			std::cout << _prompt << " ";
			std::getline(std::cin, inputText);
			tryExecuteCommand(inputText, "", "", " ");
		}
	}
}

void GenesysShell::tryExecuteCommand(std::string inputText, std::string shortPrefix, std::string longPrefix, std::string separator) {
	std::regex regex{R"([\s]+)"}; // split on space R"([\s]+)"
	std::sregex_token_iterator it{inputText.begin(), inputText.end(), regex, -1};
	std::vector<std::string> fields{it,{}};
	std::string typedCommandStr = fields[0];
	if (fields.size() > 1) { // its a command and a paramater in the form command parameter
		assert(fields.size() == 2);
		_parameter = fields[1];
	} else {
		_parameter = "";
	}
	std::transform(typedCommandStr.begin(), typedCommandStr.end(), typedCommandStr.begin(), ::tolower);
	if (typedCommandStr.substr(0, 1) != "#") {
		//if (!found) {
		//	Trace("Command \"" + typedCommandStr + "\" not found. Type \"h\" or \"help\" for help.");
		//}
	}

}

int GenesysShell::main(int argc, char** argv) {
	List<std::string>* commandlineArgs = new List<std::string>();
	for (unsigned short i = 1; i < argc; i++) {
		std::string arg = argv[i];
		commandlineArgs->insert(arg);
	}
	this->run(commandlineArgs);
	delete commandlineArgs;
	return 0;
}