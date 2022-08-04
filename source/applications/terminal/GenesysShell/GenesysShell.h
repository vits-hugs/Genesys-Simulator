/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysTerminalAppApp.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Maio de 2019, 13:02
 */

#ifndef GENESYSSHELL_H
#define GENESYSSHELL_H

#include "../../BaseGenesysTerminalApplication.h"
#include "../../../kernel/simulator/Simulator.h"
#include "../../../kernel/util/List.h"
#include <regex>
#include <fstream>
#include <assert.h>

class GenesysShell : public BaseGenesysTerminalApplication {
private:
	typedef std::function<void() > ExecuterMember;
	template<typename Class>
	ExecuterMember DefineExecuterMember(Class * object, void (Class::*function)()) {
		return std::bind(function, object); //, std::placeholders::_1
	}

	class ShellCommand {
	public:
		ShellCommand(std::string shortname, std::string longname, std::string parameters, std::string descrition, ExecuterMember executer) {
			this->descrition = descrition;
			this->longname = longname;
			this->parameters = parameters;
			this->shortname = shortname;
			this->executer = executer;
		}
		std::string shortname;
		std::string longname;
		std::string parameters;
		std::string descrition;
		ExecuterMember executer;
	};
public:
	GenesysShell();
	GenesysShell(const GenesysShell& orig);
	virtual ~GenesysShell() = default;
public:
	virtual int main(int argc, char** argv);
public: // commands
	void cmdScript();
	void cmdHelp();
	void cmdQuit();
	void cmdModelLoad();
	void cmdModelCheck();
	void cmdStart();
	void cmdStep();
	void cmdStop();
	void cmdShowReport();
	void cmdModelSave();
	void cmdModelShow();
	void cmdVersion();
	void cmdTraceLevel();
private:
	void run(List<std::string>* arguments);
	void Trace(std::string message);
	//void tryExecuteCommand(std::string inputText, const char* shortPrefix, const char* longPrefix, std::string separator);
	void tryExecuteCommand(std::string inputText, std::string shortPrefix, std::string longPrefix, std::string separator);
private:
	Simulator* _simulator = new Simulator();
	std::string _parameter;
	List<ShellCommand*>* _commands = new List<ShellCommand*>();
	std::string _prompt = "$ReGenesys> ";
};
#endif /* GENESYSSHELL_H */

