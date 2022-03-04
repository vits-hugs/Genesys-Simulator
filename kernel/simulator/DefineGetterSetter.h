/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DefineGetterSetter.h
 * Author: rafael.luiz.cancian
 *
 * Created on 5 de Agosto de 2018, 13:52
 */

#ifndef DEFINEGETTERSETTER_H
#define DEFINEGETTERSETTER_H

#include <functional>
#include "../util/Util.h"
/*

// Metaproggramed version (Best one, but does not work since demands templated data members)
template<typename T>
struct GetterT {
    typedef std::function<T()> Member; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
};
template<typename T>
struct SetterT {
    typedef std::function<void(T)> Member; //!< Pointer to a setter function that sets a <T>. Used to set values to Simulationresponse
};
template<class Class, typename T>
typename GetterT<T>::Member DefineGetterMemberT(Class * object, T (Class::*function)()) {
    return std::bind(function, object);
}
template<class Class, typename T>
typename GetterT<T>::Member DefineGetterMemberT(Class * object, T (Class::*function)() const) {
    return std::bind(function, object);
}
template<typename Class, typename T>
typename SetterT<T>::Member DefineSetterMemberT(Class * object, void (Class::*function)(T)) {
    return std::bind(function, object, std::placeholders::_1);
}


//
//
//



template<typename T>
struct GetterMember {
    typedef std::function<T()> Getter; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
};
template<typename T>
struct SetterMember {
    typedef std::function<void(T)> Setter; //!< Pointer to a setter function that sets a <T>. Used to set values to Simulationresponse
};

//
// specific types with hierarchy (Third try, mixing the first and metaprogrammed versions)
//
struct SGetterSuper {
    typedef std::function<double()> Getter; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
    typedef std::function<double() const> GetterCte; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
};
struct SSetterSuper {
    typedef std::function<void(double)> Setter; //!< Pointer to a setter function that sets a <T>. Used to set values to Simulationresponse
};
//
struct SGetterDouble: SGetterSuper  {
    typedef std::function<double()> Getter; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
    typedef std::function<double() const> GetterCte; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
};
struct SSetterDouble: SGetterSuper {
    typedef std::function<void(double)> Setter; //!< Pointer to a setter function that sets a <T>. Used to set values to Simulationresponse
};
//
struct SGetterBool: SGetterSuper {
    typedef std::function<bool()> Getter; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
    typedef std::function<bool() const> GetterCte; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
};
struct SSetterBool: SSetterSuper {
    typedef std::function<void(bool)> Setter; //!< Pointer to a setter function that sets a <T>. Used to set values to Simulationresponse
};
//
struct SGetterString: SGetterSuper {
    typedef std::function<std::string()> Getter; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
    typedef std::function<std::string() const> GetterCte; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
};
struct SSetterString: SSetterSuper {
    typedef std::function<void(std::string)> Setter; //!< Pointer to a setter function that sets a <T>. Used to set values to Simulationresponse
};
//
struct SGetterUInt: SGetterSuper {
    typedef std::function<unsigned int() const> Getter; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
};
struct SSetterUInt: SSetterSuper {
    typedef std::function<void(unsigned int)> Setter; //!< Pointer to a setter function that sets a <T>. Used to set values to Simulationresponse
};
//
struct SGetterTimeUnit: SGetterSuper {
    typedef std::function<Util::TimeUnit() const> Getter; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
};
struct SSetterTimeUnit: SSetterSuper {
    typedef std::function<void(Util::TimeUnit)> Setter; //!< Pointer to a setter function that sets a <T>. Used to set values to Simulationresponse
};
//
struct SGetterLong: SGetterSuper {
    typedef std::function<long() const> Getter; //!< Pointer to a getter function that return a <T>. Used to get values from SimulationControl and Simulationresponse
};
struct SSetterLong: SSetterSuper {
    typedef std::function<void(long)> Setter; //!< Pointer to a setter function that sets a <T>. Used to set values to Simulationresponse
};

template<class Class, typename T>
auto DefineSGetterMember(Class * object, T(Class::*function)() const) {
    return std::bind(function, object);
}
template<class Class, typename T>
auto DefineSGetterMember(Class * object, T(Class::*function)() ) {
    return std::bind(function, object);
}
template<class Class, typename T>
auto DefineSSetterMember(Class * object, void (Class::*function)(T)) {
    return std::bind(function, object, std::placeholders::_1);
}


//
// specific types without hierarchy (FIRST TRY)
//

typedef std::function<double() > GetterMemberDouble; //!< Pointer to a getter function that return a double. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(double) > SetterMemberDouble; //!< Pointer to a setter function that sets a double. Used to set values to Simulationresponse

typedef std::function<std::string() > GetterMemberString; //!< Pointer to a getter function that return a string. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(std::string) > SetterMemberString; //!< Pointer to a setter function that sets a string. Used to set values to Simulationresponse

typedef std::function<bool() > GetterMemberBool; //!< Pointer to a getter function that return a bool. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(bool) > SetterMemberBool; //!< Pointer to a setter function that sets a bool. Used to set values to Simulationresponse

typedef std::function<unsigned int() > GetterMemberUInt; //!< Pointer to a getter function that return a uint. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(unsigned int) > SetterMemberUInt; //!< Pointer to a setter function that sets a uint. Used to set values to Simulationresponse

typedef std::function<long() > GetterMemberLong; //!< Pointer to a getter function that return a long. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(long) > SetterMemberLong; //!< Pointer to a setter function that sets a long. Used to set values to Simulationresponse

typedef std::function<Util::TimeUnit() > GetterMemberTimeUnit; //!< Pointer to a getter function that return a long. Used to get values from SimulationControl and Simulationresponse
typedef std::function<void(Util::TimeUnit) > SetterMemberTimeUnit; //!< Pointer to a setter function that sets a long. Used to set values to Simulationresponse

// double
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

// unsigned int
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


// unsigned long
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

// bool
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

//std::string
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
GetterMemberTimeUnit DefineGetterMember(Class * object, Util::TimeUnit(Class::*function)() const) {
    return std::bind(function, object);
}
template<typename Class>
SetterMemberTimeUnit DefineSetterMember(Class * object, void (Class::*function)(Util::TimeUnit)) {
    return std::bind(function, object, std::placeholders::_1);
}
*/

#endif /* DEFINEGETTERSETTER_H */

