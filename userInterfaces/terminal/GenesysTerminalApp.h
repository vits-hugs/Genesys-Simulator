/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysTerminalApp.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Maio de 2019, 13:02
 */

#ifndef GENESYSTERMINALAPP_H
#define GENESYSTERMINALAPP_H

#include "../BaseConsoleGenesysApplication.h"
#include "../../kernel/simulator/Simulator.h"
#include "../../kernel/util/List.h"

class GenesysTerminalApp : public BaseConsoleGenesysApplication {
	class ShellCommand {
	public:
		ShellCommand(std::string longname, std::string parameters, std::string descrition, unsigned short numParameters=0) {
			this->descrition = descrition;
			this->longname = longname;
			this->parameters = parameters;
            this->numParameters = numParameters;
		}
		std::string longname;
		std::string parameters;
		std::string descrition;
        unsigned short numParameters;
	};
public:
	GenesysTerminalApp();
	virtual ~GenesysTerminalApp() = default;
public:
	virtual int main(int argc, char** argv);
private:
	void run(List<std::string>* arguments);
	void Trace(std::string message);
	void tryExecuteCommand(std::string inputText, std::string longPrefix, std::string separator);
private:
	Simulator* _simulator = new Simulator();
	std::string _prompt = "$ReGenesys> ";
    std::string _parameter;
};

#endif /* GENESYSTERMINALAPP_H */

