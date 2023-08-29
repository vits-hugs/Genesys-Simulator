
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SimulationControl.h
 * Author: rafael.luiz.cancian
 *
 * Created on 10 de Outubro de 2018, 18:01
 */

#ifndef MODELCONTROLANDRESPONSE_H
#define MODELCONTROLANDRESPONSE_H

//namespace GenesysKernel {

#include <string>
#include <functional>
#include "../util/Util.h"

typedef std::function<double() > GetterMember; //!< Pointer to a getter function that return a double. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(double) > SetterMember; //!< Pointer to a setter function that sets a double. Used to set values to Simulationresponse

typedef std::function<std::string() > GetterMemberString; //!< Pointer to a getter function that return a string. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(std::string) > SetterMemberString; //!< Pointer to a setter function that sets a string. Used to set values to Simulationresponse

typedef std::function<double() > GetterMemberBool; //!< Pointer to a getter function that return a bool. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(double) > SetterMemberBool; //!< Pointer to a setter function that sets a bool. Used to set values to Simulationresponse

// double

template<typename Class>
GetterMember DefineGetterMember(Class * object, double (Class::*function)()) {
	return std::bind(function, object);
}

template<typename Class>
GetterMember DefineGetterMember(Class * object, double (Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(double)) {
	return std::bind(function, object, std::placeholders::_1);
}

// unsigned int

template<typename Class>
GetterMember DefineGetterMember(Class * object, unsigned int (Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(unsigned int)) {
	return std::bind(function, object, std::placeholders::_1);
}


// unsigned long

template<typename Class>
GetterMember DefineGetterMember(Class * object, unsigned long (Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(unsigned long)) {
	return std::bind(function, object, std::placeholders::_1);
}

// bool

template<typename Class>
GetterMember DefineGetterMember(Class * object, bool (Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(bool)) {
	return std::bind(function, object, std::placeholders::_1);
}

//std::string

template<typename Class>
GetterMember DefineGetterMember(Class * object, std::string(Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(std::string) const) {
	return std::bind(function, object, std::placeholders::_1);
}

template<typename Class>
GetterMemberString DefineGetterMember(Class * object, std::string(Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetterMemberString DefineSetterMember(Class * object, void (Class::*function)(std::string) const) {
	return std::bind(function, object, std::placeholders::_1);
}


// Util::TimeUnit

template<typename Class>
GetterMember DefineGetterMember(Class * object, /*GenesysKernel::*/Util::TimeUnit(Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetterMember DefineSetterMember(Class * object, void (Class::*function)(/*GenesysKernel::*/Util::TimeUnit)) {
	return std::bind(function, object, std::placeholders::_1);
}

/*!
 * Represents any possible response of a simulation. Any element or event the model can declare one of its own attribute as a simulation response. It just has to create a SimulationResponse object, passing the access to the method that gets the response value and including this SimulationResponse in the corresponding list of the model
 */
class SimulationResponse {
public:
	SimulationResponse(std::string type, std::string name, GetterMember getterMember, std::string parent = "");
	virtual ~SimulationResponse() = default;
public:
	std::string show();
public:
	double getValue();
	std::string getName() const;
	void setName(std::string name);
	std::string getType() const;
	std::string getParent() const;
protected:
	std::string _type;
	std::string _parent;
	std::string _name;
	GetterMember _getterMember;
};


	/*!
	 * Represents any possible parameter or control for a simulation. Any element or event the model can declare one of its own attribute as a simulation control. It just have to create a SimulationControl object, passing the access to the methods that gets and sets the control value and including this SimulationControl in the corresponding list of the model
	 */
	class SimulationControl : public SimulationResponse {
	public:
		SimulationControl(std::string type, std::string name, GetterMember getterMember, SetterMember setterMember, std::string parent = "");
		virtual ~SimulationControl() = default;
	public:
		std::string show();
	public:
		void setValue(double value);
	private:
		SetterMember _setMemberFunction;
		//SetterMemberString  _setMemberStringFunction;
	};
//namespace\\}

#endif // MODELCONTROLANDRESPONSE_H
