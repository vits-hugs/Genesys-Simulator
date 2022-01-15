/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   CppCode.h
 * Author: rlcancian
 *
 * Created on 11 de janeiro de 2022, 22:24
 */

#ifndef CPPCODE_H
#define CPPCODE_H

#include "../../kernel/simulator/ModelElement.h"
//#include "../../kernel/simulator/ModelElement.h"

class CppCode : public ModelElement {
public:

	class CodeResult {
	public:
		CodeResult(bool success = true, std::string generalMessage = "", unsigned int lineNumber = 1) {
			this->success = success;
			this->generalMessage = generalMessage;
			this->lineNumber = lineNumber;
		}
		bool success;
		std::string generalMessage;
		unsigned int lineNumber;
	};

public:
	CppCode(Model* model, std::string name = "");
	virtual ~CppCode() = default;
public: // static
	static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
	static PluginInformation* GetPluginInformation();
public:
	virtual std::string show();
public: // gets & sets
	void setCode(std::string _code);
	std::string getCode() const;
	bool IsLibraryLoaded() const;
public: // new methods
	CodeResult compile();
	CodeResult loadLibrary();
	CodeResult unloadLibrary();
protected: // must be overriden by derived classes
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance(bool saveDefaultValues);
protected: // could be overriden by derived classes
	virtual bool _check(std::string* errorMessage);
	// virtual ParserChangesInformation* _getParserChangesInformation();
	//virtual void _initBetweenReplications();
	virtual void _createInternalElements();
private:

	const struct DEFAULT_VALUES {
		std::string code = "";
		std::string tempDir = ".temp/";
	} DEFAULT;
	std::string _code = DEFAULT.code;
	std::string _tempDir = DEFAULT.tempDir;
	bool libraryLoaded = false;
};

#endif /* CPPCODE_H */

