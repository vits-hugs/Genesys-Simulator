#pragma once

#include <string>
#include <functional>
#include <list>
#include "../util/Util.h"

//namespace GenesysKernel {


class PropertyGenesysBase {
public:
	PropertyGenesysBase(std::string className, std::string propertyName, std::string whatsThis="") {
		_className=className;
		_propertyName=propertyName;
		_whatsThis=whatsThis;
	}
	virtual ~PropertyGenesysBase() = default;
public:
	std::string whatsThis() const { return _whatsThis; }
	std::string getClassname() const { return _className; }
	std::string getName() const { return _propertyName; }
	std::string propertyType() const { return _propertyType; }
	void setWhatsThis(const std::string text);
	void setName(std::string name) { _propertyName = name; }
protected:
	std::string _className;
	std::string _propertyName;
	std::string _propertyType;
	std::string _whatsThis;
};

class PropertyGenesys: public PropertyGenesysBase {
public:
	PropertyGenesys(std::string className, std::string propertyName, std::string whatsThis="", std::string propertyId="", std::string toolTip="", std::string statusTip="")
		: PropertyGenesysBase(className, propertyName, whatsThis){
		_propertyId=propertyId;
		_toolTip=toolTip;
		_statusTip=statusTip;
	}
	virtual ~PropertyGenesys() = default;
public:
	std::list<PropertyGenesys *> subProperties() const { return _subProperties; };
	std::string toolTip() const { return _toolTip; }
	std::string statusTip() const { return _statusTip; }
	std::string propertyName() const { return _propertyName; }
	std::string propertyId() const { return _propertyId; }
	bool isEnabled() const { return _isEnabled; }
	bool isModified() const { return _isModified; }
	bool isSubProperty()const { return _isSubProperty; }
	bool hasValue() const { return _hasValue; }
	std::string valueText() const { return "?"; } // TODO
	void setToolTip(const std::string text);
	void setStatusTip(const std::string text);
	void setWhatsThis(const std::string text);
	void setPropertyName(const std::string text);
	void setPropertyId(const std::string text);
	void setEnabled(bool enable);
	void setModified(bool modified);
public:
	virtual bool compare(PropertyGenesys* otherProperty)const { return true; } // TODO
public:
	void addSubProperty(PropertyGenesys *property) {}
	void insertSubProperty(PropertyGenesys *property, PropertyGenesys *afterProperty) {}
	void removeSubProperty(PropertyGenesys *property) {}
protected:
	void propertyChanged() {}
protected:
	//friend class QtAbstractPropertyManager;
	std::string _className;
	std::string _propertyName;
	std::string _whatsThis;
	std::string _propertyId;
	std::string _toolTip;
	std::string _statusTip;
	std::list<PropertyGenesys*> _subProperties;
	bool _isEnabled;
	bool _isModified;
	bool _hasValue;
	bool _isSubProperty;
};

class SimulationControl: public PropertyGenesysBase {
public:
	SimulationControl(std::string className, std::string propertyName, std::string whatsThis="")
		: PropertyGenesysBase(className, propertyName, whatsThis){
	}
	std::string show() const { return "classname="+_className+ ",name="+_propertyName+", type="+_propertyType+", value="+this->getValue(); }
	bool isReadOnly() const { return _readonly; }
public:
	virtual std::string getValue() const  = 0;
	virtual void setValue(std::string value) = 0;
protected:
	bool _readonly;
};
typedef  SimulationControl SimulationResponse;

// -----------------------------------------------------------

typedef std::function<std::string()> GetterString;
typedef std::function<void(std::string)> SetterString;
class SimulationControlString: public SimulationControl {
public:
	SimulationControlString(GetterString getter, SetterString setter, std::string className, std::string propertyName, std::string whatsThis="") : SimulationControl(className, propertyName, whatsThis) {
		_getter= getter;
		_setter = setter;
		_readonly = setter == nullptr;
		_propertyType = Util::TypeOf<std::string>();
	}
public:
	virtual std::string getValue() const override { return _getter(); }
	virtual void setValue(std::string value) override { _setter(value); };
private:
	GetterString _getter;
	SetterString _setter;
};


// -----------------------------------------------------------

typedef std::function<double()> GetterDouble;
typedef std::function<void(double)> SetterDouble;
class SimulationControlDouble: public SimulationControl {
public:
	SimulationControlDouble(GetterDouble getter, SetterDouble setter, std::string className, std::string propertyName, std::string whatsThis="") : SimulationControl(className, propertyName, whatsThis){
		_getter= getter;
		_setter = setter;
		_readonly = setter == nullptr;
		_propertyType = Util::TypeOf<double>();
	}
public:
	virtual std::string getValue() const override { return std::to_string(_getter()); }
	virtual void setValue(std::string value) override { _setter(std::stod(value)); };
private:
	GetterDouble _getter;
	SetterDouble _setter;
};

// -----------------------------------------------------------

typedef std::function<bool()> GetterBool;
typedef std::function<void(bool)> SetterBool;
class SimulationControlBool: public SimulationControl {
public:
	SimulationControlBool(GetterBool getter, SetterBool setter, std::string className, std::string propertyName, std::string whatsThis="") : SimulationControl(className, propertyName, whatsThis){
		_getter= getter;
		_setter = setter;
		_readonly = setter == nullptr;
		_propertyType = Util::TypeOf<bool>();
	}
public:
	virtual std::string getValue() const override { return std::to_string(_getter()); }
	virtual void setValue(std::string value) override { _setter(std::stoi(value)); };
private:
	GetterBool _getter;
	SetterBool _setter;
};


// -----------------------------------------------------------

typedef std::function<unsigned int()> GetterUInt;
typedef std::function<void(unsigned int)> SetterUInt;
class SimulationControlUInt: public SimulationControl {
public:
	SimulationControlUInt(GetterUInt getter, SetterUInt setter, std::string className, std::string propertyName, std::string whatsThis="") : SimulationControl(className, propertyName, whatsThis){
		_getter= getter;
		_setter = setter;
		_readonly = setter == nullptr;
		_propertyType = Util::TypeOf<unsigned int>();
	}
public:
	virtual std::string getValue() const override { return std::to_string(_getter()); }
	virtual void setValue(std::string value) override { _setter(std::stoul(value)); };
private:
	GetterUInt _getter;
	SetterUInt _setter;
};


// -----------------------------------------------------------

typedef std::function<Util::TimeUnit()> GetterTimeUnit;
typedef std::function<void(Util::TimeUnit)> SetterTimeUnit;
class SimulationControlTimeUnit: public SimulationControl {
public:
	SimulationControlTimeUnit(GetterTimeUnit getter, SetterTimeUnit setter, std::string className, std::string propertyName, std::string whatsThis="") : SimulationControl(className, propertyName, whatsThis){
		_getter= getter;
		_setter = setter;
		_readonly = setter == nullptr;
		_propertyType = Util::TypeOf<Util::TimeUnit>();
	}
public:
	virtual std::string getValue() const override {
		int intVal = static_cast<int>(_getter());
		return std::to_string(intVal);
	}
	virtual void setValue(std::string value) override {
		int intVal = std::stoul(value);
		_setter(static_cast<Util::TimeUnit>(intVal));
	};
private:
	GetterTimeUnit _getter;
	SetterTimeUnit _setter;
};


typedef SimulationControl PropertyBase;


//namespace\\}
