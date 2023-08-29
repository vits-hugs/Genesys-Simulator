#ifndef PROPERTY_GENESYS_H
#define PROPERTY_GENESYS_H

#include <functional>
#include "../util/Util.h"


/*
template<typename T>
struct GetterMemberT {
	typedef std::function<T()> Getter; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
};
template<typename T>
struct SetterMemberT {
	typedef std::function<void(T)> Setter; //!< Pointer to a setter function that sets a <T>. Used to set values to Simulationresponse
};

template<class Class, typename T>
typename GetterMemberT<T>::Getter DefineGetterMember(Class * object, T (Class::*function)()) {
	return std::bind(function, object);
}
template<class Class, typename T>
typename GetterMemberT<T>::Getter DefineGetterMember(Class * object, T (Class::*function)() const) {
	return std::bind(function, object);
}
template<typename Class, typename T>
typename SetterMemberT<T>::Setter DefineSetterMember(Class * object, void (Class::*function)(T)) {
	return std::bind(function, object, std::placeholders::_1);
}

//
// specific types
//

//
// void*
//
typedef std::function<void*()>GetterMemberVoidPtr; //!< Pointer to a getter function that return a double. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(void*) > SetterMemberVoidPtr; //!< Pointer to a setter function that sets a double. Used to set values to Simulationresponse

template<typename Class>
GetterMemberVoidPtr DefineGetterMember(Class * object, void* (Class::*function)()) {
	return std::bind(function, object);
}
template<typename Class>
GetterMemberVoidPtr DefineGetterMember(Class * object, void* (Class::*function)() const) {
	return std::bind(function, object);
}
template<typename Class>
SetterMemberVoidPtr DefineSetterMember(Class * object, void (Class::*function)(void*)) {
	return std::bind(function, object, std::placeholders::_1);
}


//
// double
//
typedef std::function<double()>GetterMemberDouble; //!< Pointer to a getter function that return a double. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(double) > SetterMemberDouble; //!< Pointer to a setter function that sets a double. Used to set values to Simulationresponse

template<typename Class>
GetterMemberDouble DefineGetterMember(Class * object, double (Class::*function)()) {
	return std::bind(function, object);
}
template<typename Class>
GetterMemberDouble DefineGetterMember(Class * object, double (Class::*function)() const) {
	return std::bind(function, object);
}
template<typename Class>
SetterMemberDouble DefineSetterMember(Class * object, void (Class::*function)(double)) {
	return std::bind(function, object, std::placeholders::_1);
}

//
// unsigned int
//
typedef std::function<unsigned int()>GetterMemberUInt; //!< Pointer to a getter function that return a uint. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(unsigned int) > SetterMemberUInt; //!< Pointer to a setter function that sets a uint. Used to set values to Simulationresponse

template<typename Class>
GetterMemberUInt DefineGetterMember(Class * object, unsigned int (Class::*function)()) {
	return std::bind(function, object);
}
template<typename Class>
GetterMemberUInt DefineGetterMember(Class * object, unsigned int (Class::*function)() const) {
	return std::bind(function, object);
}
template<typename Class>
SetterMemberUInt DefineSetterMember(Class * object, void (Class::*function)(unsigned int)) {
	return std::bind(function, object, std::placeholders::_1);
}


//
// unsigned long
//
typedef std::function<long()>GetterMemberLong; //!< Pointer to a getter function that return a long. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(long) > SetterMemberLong; //!< Pointer to a setter function that sets a long. Used to set values to Simulationresponse

template<typename Class>
GetterMemberLong DefineGetterMember(Class * object, unsigned long (Class::*function)()) {
	return std::bind(function, object);
}
template<typename Class>
GetterMemberLong DefineGetterMember(Class * object, unsigned long (Class::*function)() const) {
	return std::bind(function, object);
}
template<typename Class>
SetterMemberLong DefineSetterMember(Class * object, void (Class::*function)(unsigned long)) {
	return std::bind(function, object, std::placeholders::_1);
}

//
// bool
//
typedef std::function<bool()>GetterMemberBool; //!< Pointer to a getter function that return a bool. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(bool)>SetterMemberBool; //!< Pointer to a setter function that sets a bool. Used to set values to Simulationresponse

template<typename Class>
GetterMemberBool DefineGetterMember(Class * object, bool (Class::*function)()) {
	return std::bind(function, object);
}
template<typename Class>
GetterMemberBool DefineGetterMember(Class * object, bool (Class::*function)() const) {
	return std::bind(function, object);
}
template<typename Class>
SetterMemberBool DefineSetterMember(Class * object, void (Class::*function)(bool)) {
	return std::bind(function, object, std::placeholders::_1);
}

//
// int
//
typedef std::function<int()>GetterMemberInt; //!< Pointer to a getter function that return a uint. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(int) > SetterMemberInt; //!< Pointer to a setter function that sets a uint. Used to set values to Simulationresponse

template<typename Class>
GetterMemberInt DefineGetterMember(Class * object, int (Class::*function)()) {
	return std::bind(function, object);
}
template<typename Class>
GetterMemberInt DefineGetterMember(Class * object, int (Class::*function)() const) {
	return std::bind(function, object);
}
template<typename Class>
SetterMemberInt DefineSetterMember(Class * object, void (Class::*function)(int)) {
	return std::bind(function, object, std::placeholders::_1);
}

//
//std::string
//
typedef std::function<std::string()>GetterMemberString; //!< Pointer to a getter function that return a string. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(std::string)>SetterMemberString; //!< Pointer to a setter function that sets a string. Used to set values to Simulationresponse

template<typename Class>
GetterMemberString DefineGetterMember(Class * object, std::string(Class::*function)() const) {
	return std::bind(function, object);
}
template<typename Class>
SetterMemberString DefineSetterMember(Class * object, void (Class::*function)(std::string) const) {
	return std::bind(function, object, std::placeholders::_1);
}

//
// Util::TimeUnit
//
typedef std::function<Util::TimeUnit()>GetterMemberTimeUnit; //!< Pointer to a getter function that return a TimeUnit. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(Util::TimeUnit)>SetterMemberTimeUnit; //!< Pointer to a setter function that sets a TimeUnit. Used to set values to Simulationresponse

template<typename Class>
GetterMemberTimeUnit DefineGetterMember(Class * object, Util::TimeUnit(Class::*function)() const) {
	return std::bind(function, object);
}
template<typename Class>
GetterMemberTimeUnit DefineGetterMember(Class * object, Util::TimeUnit(Class::*function)()) {
	return std::bind(function, object);
}
template<typename Class>
SetterMemberTimeUnit DefineSetterMember(Class * object, void (Class::*function)(Util::TimeUnit)) {
	return std::bind(function, object, std::placeholders::_1);
}

*/










#endif

