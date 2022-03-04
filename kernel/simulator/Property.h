#ifndef PROPERTY_H
#define PROPERTY_H

#include "../util/Util.h"
#include <string>
#include <functional>

class PropertyGetterBase {
public:
	PropertyGetterBase(std::string classname, std::string name, std::string parentName="");
public:
	std::string show() const;
	std::string getType() const;
	std::string getParentName() const;
	std::string getName() const;
	void setName(const std::string &name);
public:
	double getValue();
protected:
	std::string _name;
	std::string _parentname;
	std::string _classename;
};

class PropertySetterBase: public PropertyGetterBase {
public:
	PropertySetterBase(std::string classname, std::string name, std::string parentName="");
public:
	void setValue(double value);
};

//
// unsigned int
//
typedef std::function<unsigned int()> GetterUInt;
template<typename Class>
GetterUInt DefineGetterUInt(Class * object, unsigned int (Class::*function)() const) {
	return std::bind(function, object);
}
class PropertyGetterUInt: public PropertyGetterBase {
public:
	PropertyGetterUInt(std::string classname, std::string name, GetterUInt getter, std::string parentName="");
public:
	unsigned int getValue();
protected:
	GetterUInt _getter;
};

typedef std::function<void(unsigned int) > SetterUInt;
template<typename Class>
SetterUInt DefineSetterUInt(Class * object, void (Class::*function)(unsigned int)) {
	return std::bind(function, object, std::placeholders::_1);
}
class PropertySetterUInt: public PropertyGetterUInt {
public:
	PropertySetterUInt(std::string classname, std::string name, GetterUInt getter, SetterUInt setter, std::string parentName="");
public:
	void setValue(unsigned int value);
protected:
	SetterUInt _setter;
};

//
// double
//
typedef std::function<double()> GetterDouble;
template<typename Class>
GetterDouble DefineGetterDouble(Class * object, double (Class::*function)() const) {
	return std::bind(function, object);
}
class PropertyGetterDouble: public PropertyGetterBase {
public:
	PropertyGetterDouble(std::string classname, std::string name, GetterDouble getter, std::string parentName="");
public:
	double getValue();
protected:
	GetterDouble _getter;
};

typedef std::function<void(double) > SetterDouble;
template<typename Class>
SetterDouble DefineSetterDouble(Class * object, void (Class::*function)(double)) {
	return std::bind(function, object, std::placeholders::_1);
}
class PropertySetterDouble: public PropertyGetterDouble {
public:
	PropertySetterDouble(std::string classname, std::string name, GetterDouble getter, SetterDouble setter, std::string parentName="");
public:
	void setValue(double value);
protected:
	SetterDouble _setter;
};


//
// string
//
typedef std::function<std::string()> GetterString;
template<typename Class>
GetterString DefineGetterString(Class * object, std::string (Class::*function)() const) {
	return std::bind(function, object);
}
class PropertyGetterString: public PropertyGetterBase {
public:
	PropertyGetterString(std::string classname, std::string name, GetterString getter, std::string parentName="");
public:
	std::string getValue();
protected:
	GetterString _getter;
};

typedef std::function<void(std::string) > SetterString;
template<typename Class>
SetterString DefineSetterString(Class * object, void (Class::*function)(std::string)) {
	return std::bind(function, object, std::placeholders::_1);
}
class PropertySetterString: public PropertyGetterString {
public:
	PropertySetterString(std::string classname, std::string name, GetterString getter, SetterString setter, std::string parentName="");
public:
	void setValue(std::string value);
protected:
	SetterString _setter;
};



//
// time unit
//
typedef std::function<Util::TimeUnit()> GetterTimeUnit;
template<typename Class>
GetterTimeUnit DefineGetterTimeUnit(Class * object, Util::TimeUnit (Class::*function)() const) {
	return std::bind(function, object);
}
class PropertyGetterTimeUnit: public PropertyGetterBase {
public:
	PropertyGetterTimeUnit(std::string classname, std::string name, GetterTimeUnit getter, std::string parentName="");
public:
	Util::TimeUnit getValue();
protected:
	GetterTimeUnit _getter;
};

typedef std::function<void(Util::TimeUnit) > SetterTimeUnit;
template<typename Class>
SetterTimeUnit DefineSetterTimeUnit(Class * object, void (Class::*function)(Util::TimeUnit)) {
	return std::bind(function, object, std::placeholders::_1);
}
class PropertySetterTimeUnit: public PropertyGetterTimeUnit {
public:
	PropertySetterTimeUnit(std::string classname, std::string name, GetterTimeUnit getter, SetterTimeUnit setter, std::string parentName="");
public:
	void setValue(Util::TimeUnit value);
protected:
	SetterTimeUnit _setter;
};




//
// bool
//
typedef std::function<bool()> GetterBool;
template<typename Class>
GetterBool DefineGetterBool(Class * object, bool (Class::*function)() const) {
	return std::bind(function, object);
}
class PropertyGetterBool: public PropertyGetterBase {
public:
	PropertyGetterBool(std::string classname, std::string name, GetterBool getter, std::string parentName="");
public:
	bool getValue();
protected:
	GetterBool _getter;
};

typedef std::function<void(bool) > SetterBool;
template<typename Class>
SetterBool DefineSetterBool(Class * object, void (Class::*function)(bool)) {
	return std::bind(function, object, std::placeholders::_1);
}
class PropertySetterBool: public PropertyGetterBool {
public:
	PropertySetterBool(std::string classname, std::string name, GetterBool getter, SetterBool setter, std::string parentName="");
public:
	void setValue(bool value);
protected:
	SetterBool _setter;
};



#endif // PROPERTY_H
