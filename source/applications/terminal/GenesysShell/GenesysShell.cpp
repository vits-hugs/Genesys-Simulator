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
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <chrono>
#include <thread>


using namespace std;
//#include "ProbDistribDefaultImpl1.h"

GenesysShell::GenesysShell() { 
	this->setDefaultTraceHandlers(simulator->getTracer());
}

void GenesysShell::Trace(string message) {
	cout<<message<<endl;
}

/*int i;
const char progress[] = "|/-\\";

for (i = 0; i < 100; i += 10) {
  printf("Processing: %3d%%\r",i); /* \r returns the caret to the line start //
  fflush(stdout);
  //sleep(1);
}
printf("\n"); /* goes to the next line //
fflush(stdout);

printf("Processing: ");
for (i = 0; i < 100; i += 10) {
  printf("%c\b", progress[(i/10)%sizeof(progress)]); /* \b goes one back //
  fflush(stdout);
  //sleep(1);
}
printf("\n"); /* goes to the next line //
fflush(stdout);
return 0;*/

void GenesysShell::run(List<string>* commandlineArgs) {
	simulator->getPlugins()->autoInsertPlugins("autoloadplugins.txt");
	_history->resize(100);
	Trace("Genesys Shell is running. Type your command. For help, type the command \"help\".");
	string inputText, historyText; //, shortPrefix, longPrefix, separator; //,longPrefix, separator;
	char c, c1, c2, c3;
	unsigned short historyPosition = 0;
	while (!_exitRequested) {
		if (!commandlineArgs->empty()) {
			inputText = commandlineArgs->front();
			commandlineArgs->pop_front();
			_history->push_back(inputText);
			tryExecuteCommand(inputText, "-", "--", "=");
		} else {
			cout<<_prompt<<" ";
			//getline(cin, inputText);
			std::cin>>std::noskipws; //don't skip whitespaces
			inputText = "";
			//std::basic_ios::sync_with_stdio(false);
			while (c=getchar()) {
				if (c=='\n')
					break;
				//cout << int(c)<<','<<flush;//<<int(c1)<<','<<int(c2)<<endl;
				if ((c==65||c==66) && c1==91 && c2==27) { // Up or down pressed. Show history
					printf("\b\b\b%c%c%c\b\b\b", ' ',' ',' '); 
					fflush(stdout);
					if (_history->size()>0) {
						historyText = _history->at(historyPosition);
						if (c == 65) {
							historyPosition++;
						} else {
							historyPosition--;
						}
						if (historyPosition>_history->size())
							historyPosition = 0;
						inputText = historyText;
						cout << inputText;
					}
				} else { // normal key. Add to the text being typed
					inputText.push_back(c);
				}
				//c3 = c2;
				c2 = c1;
				c1 = c;
			}
			if (inputText!="") {
				_history->push_back(inputText);
				tryExecuteCommand(inputText, "", "", " ");
			}
		}
	}
}

void GenesysShell::tryExecuteCommand(string inputText, string shortPrefix, string longPrefix, string separator) {
	regex regex{R"([\s]+)"}; // split on space R"([\s]+)"
	sregex_token_iterator it{inputText.begin(), inputText.end(), regex, -1};
	vector<string> fields{it,{}};
	string typedCommandStr = fields[0];
	bool found = false;
	_typedWords->clear();
	for (string w : fields) {
		_typedWords->insert(_typedWords->end(), w);
	}
	transform(typedCommandStr.begin(), typedCommandStr.end(), typedCommandStr.begin(), ::tolower);
	if (typedCommandStr.substr(0, 1)!="#") {
		for (ShellCommand *cmd : *_commands->list()) {
			if (cmd->longname==typedCommandStr) {
				found = true;
				cmd->executer();
			}
		}
		if (!found) {
			Trace("Command \""+typedCommandStr+"\" not found. Type \"h\" or \"help\" for help.");
		}
	}

}

int GenesysShell::main(int argc, char** argv) {
	List<string>* commandlineArgs = new List<string>();
	for (unsigned short i = 1; i<argc; i++) {
		string arg = argv[i];
		commandlineArgs->insert(arg);
	}
	defineCommands();
	this->run(commandlineArgs);
	delete commandlineArgs;
	return 0;
}

void GenesysShell::defineCommands() {
	_commands->insert(new ShellCommand("", "help", "", "Show the list of commands", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdHelp)));
	_commands->insert(new ShellCommand("", "quit", "[-y|--yes]", "Exit the simulator", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdQuit)));
	_commands->insert(new ShellCommand("", "script", "<script filename>", "Execute commands in a script file", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdScript)));
	_commands->insert(new ShellCommand("", "tracelevel", "<level>", "Set the trace level", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdTraceLevel)));
	_commands->insert(new ShellCommand("", "pluginlist", "", "List installed plugins", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdPluginList)));
	_commands->insert(new ShellCommand("", "plugininfo", "<plugin name>", "Show infos about a plugin", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdPluginInfo)));
	//_commands->insert(new ShellCommand("", "pluginadd", "<plugin filename>", "", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdPluginAdd)));
	//_commands->insert(new ShellCommand("", "pluginremove", "<classname>", "", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdPluginRemove)));
	_commands->insert(new ShellCommand("", "start", "", "Start simulation", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdSimulationStart)));
	_commands->insert(new ShellCommand("", "step", "", "Step simulation", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdSimulationStep)));
	_commands->insert(new ShellCommand("", "stop", "", "Stop simulation", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdSimulationStop)));
	_commands->insert(new ShellCommand("", "simulinfo", "", "Show simulation info", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdSimulationInfo)));
	_commands->insert(new ShellCommand("", "showreport", "", "Show simulation report", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdShowReport)));
	_commands->insert(new ShellCommand("", "show", "", "Show the model structure", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdModelShow)));
	_commands->insert(new ShellCommand("", "check", "", "Check the odel", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdModelCheck)));
	_commands->insert(new ShellCommand("", "load", "<filename>", "Load a model from a file", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdModelLoad)));
	_commands->insert(new ShellCommand("", "save", "<filename>", "Save a model to a file", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdModelSave)));

}

void GenesysShell::cmdHelp() {
	cout<<"List of commands:"<<endl;
	for (ShellCommand *command : *_commands->list()) {
		cout<<command->longname<<" "<<command->parameters<<" - "<<command->descrition<<endl;
	}
}

void GenesysShell::cmdQuit() {
	cout<<"Quiting. Bye."<<endl;
	_exitRequested = true;
}

void GenesysShell::cmdScript() { }

void GenesysShell::cmdTraceLevel() {
	if (_typedWords->size()!=2) {
		cout<<"Syntax error"<<endl;
		return;
	}
	int levelInt = stoi(_typedWords->at(1));
	if (levelInt>=1) {
		cout<<"Setting tracelevel to "<<levelInt<<endl;
		TraceManager::Level level = static_cast<TraceManager::Level> (levelInt);
		simulator->getTracer()->setTraceLevel(level);
	} else {
		cout<<"Error: "<<_typedWords->at(1)<<" is not a valid level"<<endl;
	}
}

void GenesysShell::cmdPluginList() {
	PluginInformation* p;
	cout<<"List of installed plugins:"<<endl;
	for (unsigned short i = 0; i<simulator->getPlugins()->size(); i++) {
		p = simulator->getPlugins()->getAtRank(i)->getPluginInfo();
		if (p->isSource())
			cout<<"Source ";
		if (p->isSink())
			cout<<"Sink ";
		if (p->isSendTransfer())
			cout<<"SendTransfer ";
		if (p->isSendTransfer())
			cout<<"ReceiveTransfer ";
		if (p->isGenerateReport())
			cout<<"GenerateReport ";
		if (p->isComponent())
			cout<<"Component ";
		else
			cout<<"DataElement ";
		cout<<p->getPluginTypename()<<" ("<<p->getCategory()<<")";
		cout<<endl;
	}
}
//void GenesysShell::cmdPluginAdd() {}

void GenesysShell::cmdPluginInfo() {
	if (_typedWords->size()!=2) {
		cout<<"Syntax error"<<endl;
		return;
	}
	std::string parameter = _typedWords->at(1);
	Plugin* p;
	for (unsigned short i = 0; i<simulator->getPlugins()->size(); i++) {
		p = simulator->getPlugins()->getAtRank(i);
		if (p->getPluginInfo()->getPluginTypename()==parameter) {
			cout<<"Information for plugin "<<parameter<<":"<<endl;
			cout<<p->show()<<endl;
			return;
		}
	}
	cout<<"Error: Could not find plugin of type "<<parameter<<endl;
}

void GenesysShell::cmdPluginRemove() { }

void GenesysShell::cmdSimulationStart() {
	if (model==nullptr) {
		cout<<"Error: There is no loaded model to simulate."<<endl;
		return;
	}
	model->getSimulation()->start();
}

void GenesysShell::cmdSimulationStep() {
	if (model==nullptr) {
		cout<<"Error: There is no loaded model to simulate."<<endl;
		return;
	}
	model->getSimulation()->step();
}

void GenesysShell::cmdSimulationStop() {
	if (model==nullptr) {
		cout<<"Error: There is no loaded model to simulate."<<endl;
		return;
	}
	model->getSimulation()->stop();
}

void GenesysShell::cmdSimulationInfo() {
	if (model==nullptr) {
		cout<<"Error: There is no loaded model to simulate."<<endl;
		return;
	}
	//model->getSimulation()->get;
}

void GenesysShell::cmdShowReport() {
	if (model==nullptr) {
		cout<<"Error: There is no loaded model to show report."<<endl;
		return;
	}
}

void GenesysShell::cmdModelLoad() { 
	if (_typedWords->size()!=2) {
		cout<<"Syntax error"<<endl;
		return;
	}
	std::string parameter = _typedWords->at(1);
	cout << "Loading model "<< parameter << endl;
	model = simulator->getModels()->loadModel(parameter);
	if (model==nullptr) {
		cout << "Error: Could not load the model" << endl;
	} else {
		cout << "Model loaded" << endl;
	}
}

void GenesysShell::cmdModelCheck() {
	if (model==nullptr) {
		cout<<"Error: There is no loaded model to check."<<endl;
		return;
	}
	model->check();
}

void GenesysShell::cmdModelSave() {
	if (model==nullptr) {
		cout<<"Error: There is no loaded model to save."<<endl;
		return;
	}
	if (_typedWords->size()!=2) {
		cout<<"Syntax error"<<endl;
		return;
	}
	std::string parameter = _typedWords->at(1);
	cout << "Saving model "<< parameter << endl;
	if (model->save(parameter)) {
		cout << "Model saved" << endl;
	} else {
		cout << "Error: Could not save the model" << endl;
	}
}

void GenesysShell::cmdModelShow() {
	if (model==nullptr) {
		cout<<"Error: There is no loaded model to show."<<endl;
		return;
	}
	model->show();
}
