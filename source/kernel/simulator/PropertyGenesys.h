#ifndef PROPERTY_H
#define PROPERTY_H

/*
#include "../util/Util.h"
//#include "../util/List.h"
#include <string>
#include <functional>

//class SeizableItem;
//class QueueableItem;

//---------------------------------------------------------------------------

class PropertyBase {
public:

	PropertyBase(std::string classname, std::string name, std::string parentName = "") {
		_classename = classname;
		_name = name;
		_parentname = parentName;
	}
	virtual ~PropertyBase() = default;
public:

	std::string show() const {
		return "classname=" + _classename + ", name=" + _name + ", parentname=" + _parentname;
	};

	std::string getClassname() const {
		return _classename;
	};

	std::string getParentName() const {
		return _parentname;
	};

	std::string getName() const {
		return _name;
	};

	std::string getType() const {
		return _type;
	};

	void setName(const std::string&name) {
		_name = name;
	}
public: // TODO: I hate this

	virtual double getValue() const {
		return -99.99;
	};

	virtual std::string getValueText() const {
		return "-99.99";
	};

	void setValue(double value) {
	};
	//virtual std::string getStringValue() const=0;
protected:
	std::string _name;
	std::string _parentname;
	std::string _classename;
	std::string _type = "none";
};

template<typename T>
struct Getter {
	typedef std::function<T() > Member;
};

template<typename Class, typename T>
typename Getter<T>::Member DefineGetter(Class * object, T(Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class, typename T>
typename Getter<T>::Member DefineGetter(Class * object, T(Class::*function)()) {
	return std::bind(function, object);
}

template<typename T>
struct Setter {
	typedef std::function<void(T) > Member;
};

template<typename Class, typename T>
typename Setter<T>::Member DefineSetter(Class * object, void (Class::*function)(T)) {
	return std::bind(function, object, std::placeholders::_1);
}

template<typename T>
class PropertyT : public PropertyBase {
public:

	PropertyT(std::string classname, std::string name, typename Getter<T>::Member getter, typename Setter<T>::Member setter, std::string parentName = "") : PropertyBase(classname, name, parentName) {
		_getter = getter;
		_setter = setter;
	};
public:

	T getValue() {
		return _getter();
	};
	void setValue(T value);
	//virtual std::string getStringValue() const override;
protected:
	typename Getter<T>::Member _getter;
	typename Setter<T>::Member _setter;
	const std::string _type = Util::TypeOf<T>();
};

//template<typename T> std::string PropertyT<T>::getStringValue() const {return std::to_string(_getter());}
//template<> std::string PropertyT<std::string>::getStringValue() const {return _getter();}
//template<> std::string PropertyT<Util::TimeUnit>::getStringValue() const {return Util::StrTimeUnitLong(_getter());}
//template<> std::string PropertyT<List<SeizableItem*>>::getStringValue() const {return "[]size:"+std::to_string(_getter().size());}
//template<> std::string PropertyT<List<QueueableItem*>>::getStringValue() const {return "[]size:"+std::to_string(_getter().size());}

/*
template<>
class PropertyT<std::string>: public PropertyBase {
public:
	PropertyT(std::string classname, std::string name, typename Getter<std::string>::Member getter, typename Setter<std::string>::Member setter, std::string parentName=""):PropertyBase(classname,name, parentName) {
		_getter = getter;
		_setter = setter;
	};
public:
	std::string getValue() {return _getter();};
	void setValue(std::string value){_setter(value);};
	virtual std::string getStringValue() const {return _getter();};
protected:
	typename Getter<std::string>::Member _getter;
	typename Setter<std::string>::Member _setter;
	const std::string _type = Util::TypeOf<std::string>();
};
template<>
class PropertyT<Util::TimeUnit>: public PropertyBase {
public:
	PropertyT(std::string classname, std::string name, typename Getter<Util::TimeUnit>::Member getter, typename Setter<Util::TimeUnit>::Member setter, std::string parentName=""):PropertyBase(classname,name, parentName) {
		_getter = getter;
		_setter = setter;
	};
public:
	Util::TimeUnit getValue() {return _getter();};
	void setValue(Util::TimeUnit value){_setter(value);};
	virtual std::string getStringValue() const {return Util::StrTimeUnitLong(_getter()); };
protected:
	typename Getter<Util::TimeUnit>::Member _getter;
	typename Setter<Util::TimeUnit>::Member _setter;
	const std::string _type = Util::TypeOf<Util::TimeUnit>();
};
 */
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

/*
class PropertyGetterBase {
public:
	PropertyGetterBase(std::string classname, std::string name, std::string parentName="");
public:
	std::string show() const;
	std::string getClassname() const;
	std::string getParentName() const;
	std::string getName() const;
	void setName(const std::string &name);
	std::string getType() const;
public:
	double getValue();
protected:
	std::string _name;
	std::string _parentname;
	std::string _classename;
	const std::string _type = "void";
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
	const std::string _type = "unsigned int";
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
	const std::string _type = "double";
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
	const std::string _type = "string";
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
	const std::string _type = "TimeUnit";
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
	const std::string _type = "bool";
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


















/*

#ifndef PROPERTY_GENESYS_H
#define PROPERTY_GENESYS_H

#include <functional>
#include <string>
#include "../util/Util.h"

//namespace GenesysKernel {


//-------------------------------------------------------------------------
//-------------------------------------------------------------------------


typedef std::function<double() > GetterMember;
typedef std::function<void(double) > SetterMember;

//
// trying to metaprogram it
//
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



//-------------------------------------------------------------------------
//-------------------------------------------------------------------------


/*!
 * Represents any possible response of a simulation. Any element or event the model can declare one of its own attribute as a simulation response. It just has to create a SimulationResponse object, passing the access to the method that gets the response value and including this SimulationResponse in the corresponding list of the model
 */
/*
class SimulationResponse {
public:
	SimulationResponse(std::string classname, std::string name, std::string description = "", std::string parent = "") {
		_classname = classname;
		_name = name;
		_description = description;
		_parent = parent;
	}
	virtual ~SimulationResponse() = default;
public:
	std::string show() {
		return "classname="+_classname+", name="+_name+", description=\""+_description+"\", parent="+_parent;
	}
public: // getters and setters
	std::string getName() const { return _name; }
	//void setName(std::string name) { _name = name; };
	std::string getClassname() const { return _classname; };
	//void setClassname(std::string classname) { _classname = classname; };
	std::string getParent() const { return _parent;};
	//void setParent(std::string parent) { _parent = parent; };
	std::string getDescription() const { return _description;};
	//void setDescription(std::string description) { _description = description; };
protected:
	std::string _classname;
	std::string _parent;
	std::string _name;
	std::string _description;
};


template<typename T>
class SimulationResponseT: public SimulationResponse {
public:
	SimulationResponseT(std::string classname, std::string name, GetterMemberT<T> getter, std::string description = "", std::string parent = "")
		: SimulationResponse(classname, name, description, parent){
		_getter = getter;
	}
	virtual ~SimulationResponse() = default;
public:
	T getValue() const { return _getter(); }
protected:
	GetterMemberT<T> _getter;
};

*/

/*

class PropertyGenesys {
public:
	PropertyGenesys(std::string classname, std::string name, std::string description = "", std::string parent = "") {
		_classname = classname;
		_name = name;
		_description = description;
		_parent = parent;
	}
	virtual ~PropertyGenesys() = default;
public:
	std::string show() {
		return "classname="+_classname+", name="+_name+", description=\""+_description+"\", parent="+_parent;
	}
public: // getters and setters
	std::string getName() const { return _name; }
	void setName(std::string name) { _name = name; };
	std::string getClassname() const { return _classname; };
	//void setClassname(std::string classname) { _classname = classname; };
	std::string getParent() const { return _parent;};
	//void setParent(std::string parent) { _parent = parent; };
	std::string getDescription() const { return _description;};
	//void setDescription(std::string description) { _description = description; };
public:
	//virtual double getValue() const =0;
	//virtual void setValue(double value) =0;
protected:
	std::string _classname;
	std::string _parent;
	std::string _name;
	std::string _description;
};


//typedef std::function<double() > GetterMember;
//typedef std::function<void(double) > SetterMember;


template<typename T>
class PropertyT: public PropertyGenesys {
public:
	PropertyT(std::string classname, std::string name, std::function<T()> getter, std::function<void(T)> setter = nullptr, std::string description = "", std::string parent = "")
		: PropertyGenesys(classname, name, description, parent){
		_getter = getter;
		_setter = setter;
	}
	virtual ~PropertyT() = default;
public:
	bool isReadOnly() { return _setter == nullptr; }
	virtual T getValue() const override { return _getter(); }
	virtual void setValue(T value) override { _setter(value); }
protected:
	std::function<T()> _getter;
	std::function<void(T)> _setter;
};

typedef PropertyGenesys SimulationResponse;
typedef PropertyGenesys SimulationControl;

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------



	/*!
	 * Represents any possible parameter or control for a simulation. Any element or event the model can declare one of its own attribute as a simulation control. It just have to create a SimulationControl object, passing the access to the methods that gets and sets the control value and including this SimulationControl in the corresponding list of the model
	 */
/*
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

	typedef SimulationControl PropertyGenesys;  // TODO Trying to solve that mess stuff
*/


//-------------------------------------------------------------------------
//-------------------------------------------------------------------------






//-------------------------------------------------------------------------
//-------------------------------------------------------------------------




//namespace\\}



// MESSY STUFF

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
