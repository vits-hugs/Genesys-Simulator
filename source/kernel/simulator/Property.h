#ifndef PROPERTY_GENESYS_H
#define PROPERTY_GENESYS_H

#include "../util/List.h"

#include <string>
#include <functional>
#include <unordered_map>
#include <typeinfo>
#include <iostream>
#include <cstdlib>
#include <new>
#include <cassert>

// https://doc.qt.io/qt-6/properties.html

// -------------------------

template<class T>
struct Getter {
	typedef std::function<T() > Member;
};

template<class Class, class T>
typename Getter<T>::Member DefineGetter(Class * object, T(Class::*function)() const) {
	return std::bind(function, object);
}

template<class Class, class T>
typename Getter<T>::Member DefineGetter(Class * object, T(Class::*function)()) {
	return std::bind(function, object);
}

template<class T>
struct Setter {
	typedef std::function<void(T) > Member;
};

template<class Class, class T>
typename Setter<T>::Member DefineSetter(Class * object, void (Class::*function)(T)) {
	return std::bind(function, object, std::placeholders::_1);
}

// -----------------

/*
template<class T>
class ReadOnlyPropertyG {
public:
	ReadOnlyPropertyG(typename Getter<T>::Member getter) {
		_getter = getter;
	};
public:

	T getValue() {
		return _getter();
	};
	std::string getValueText() const;
protected:
	typename Getter<T>::Member _getter;
	const std::string _type = Util::TypeOf<T>();
};

template<class T> std::string ReadOnlyPropertyG<T>::getValueText() const {return std::to_string(_getter());}
//template<> std::string ReadOnlyPropertyG<std::string>::getValueText() const {return _getter();}
//template<class T> std::string PropertyT<T>::getStringValue() const {return std::to_string(_getter());}
//template<> std::string PropertyT<std::string>::getStringValue() const {return _getter();}
//template<> std::string PropertyT<List<SeizableItem*>>::getStringValue() const {return "[]size:"+std::to_string(_getter().size());}
//template<> std::string PropertyT<List<QueueableItem*>>::getStringValue() const {return "[]size:"+std::to_string(_getter().size());}


template<class T>
class PropertyG : public ReadOnlyPropertyG<T> {
public:

	PropertyG(typename Getter<T>::Member getter, typename Setter<T>::Member setter) : ReadOnlyPropertyG<T>(getter) {
		_setter = setter;
	};
public:
	void setValue(T value);
protected:
	typename Setter<T>::Member _setter;
};

template<class T> void PropertyG<T>::setValue(T value) {_setter(value);}

*/

/*
class PropertyG_basevalue {
protected:
	bool _value;
	std::string _type = Util::TypeOf<decltype(_value)>();
	Getter<decltype(_value)>::Member _getter;
	Setter<decltype(_value)>::Member _setter;
public:
	PropertyG_basevalue() {}
	std::string getType() {return _type;}
	virtual void setGetter(Getter<decltype(_value)>::Member getter) {_getter=getter;}
	virtual void setSetter(Setter<decltype(_value)>::Member setter) {_setter=setter;}
	virtual auto getValue() -> decltype(_value) {return _getter();}
	virtual void setValue(decltype(_value) value) {_setter(value);}
	virtual std::string getValueText() const {return std::to_string(_getter());}
};

class PropertyG_bool: public PropertyG_basevalue {
};

class PropertyG_string: public PropertyG_basevalue {
protected:
	std::string _value;
public:
	virtual std::string getValueText() const {return _value;}
};


class PropertyG_int: public PropertyG_basevalue {
protected:
	int _value;
};

class PropertyG_unsigned_int: public PropertyG_basevalue {
protected:
	unsigned int _value;
};

class PropertyG_double: public PropertyG_basevalue {
protected:
	double _value;
};

*/

// -------------------------

class PropertyBaseG {
protected:
	const std::string _myType;
	const std::string _propertyType = Util::TypeOf<decltype(_myType)>();
	Getter<decltype(_myType)>::Member _getter;
	Setter<decltype(_myType)>::Member _setter;
public:
	std::string getType() const {return _propertyType;}
	virtual void setGetter(Getter<decltype(_myType)>::Member getter) {_getter=getter;}
	virtual void setSetter(Setter<decltype(_myType)>::Member setter) {_setter=setter;}
	virtual auto getValue() -> decltype(_myType) const {return _getter();}
	virtual void setValue(decltype(_myType) value) {_setter(value);}
	virtual std::string getValueText() const {return (_getter());}
public:
	typedef std::pair<std::string, void*> PropertyAttribute;
public:
	PropertyBaseG() {} /* Getter<decltype(_myType)>::Member getter, Setter<decltype(_myType)>::Member setter, std::string className, std::string propertyName, std::string displayText="", std::string statusTip="", std::string toolTip="", std::string whatIsThis="", std::string parentName="") {
		_getter=getter;
		_setter=setter;
		_propertyName=propertyName;
		_propertyTypeInt=0; //propertyTypeInt;
		_writable=setter!=nullptr;
		_hasValue=true;
		_className=className;
		_parentName=parentName;
		if (displayText=="") displayText = propertyName;
		_displayText=displayText;
		if (displayText!= "" && statusTip=="") statusTip = displayText;
		_statusTip=statusTip;
		if (statusTip!="" && toolTip=="") toolTip = statusTip;
		_toolTip=toolTip;
		if (toolTip!="" && whatIsThis=="") whatIsThis = toolTip;
		_whatIsThis=whatIsThis;
	}
	*/
public: //virtual
	virtual std::string show(){
		std::string message = " type="+_propertyType+" ("+std::to_string(_propertyTypeInt)+"), name="+_propertyName+", class="+_className+", writable="+std::to_string(_writable);
		return message;
	}
public: // gets & sets
	int getPropertyTypeInt() const{ return _propertyTypeInt; }
	void addSubProperty(PropertyBaseG* property){ _subProperties->insert(property); }
	std::string getDisplayText() const{ return _displayText; }
	void setDisplayText(std::string displayText) { _displayText = displayText; }
	bool getHasValue() const{ return _hasValue; }
	void setHasValue(bool hasValue) { _hasValue = hasValue; }
	std::string getPropertyName() const{ return _propertyName; }
	void setPropertyName(std::string propertyName){ _propertyName = propertyName; }
	std::string getName() const{ return _propertyName; } // same as propertyName
	void setName(std::string propertyName){ _propertyName = propertyName; }
	std::string getClassName() const{ return _className; }
	void setClassName(std::string className){ _className = className; }
	std::string getParentName() const{ return _parentName; }
	void setParentName(std::string parentName){ _parentName = parentName; }
	std::string getStatusTip() const{ return _statusTip; }
	void setStatusTip(std::string statusTip){ _statusTip = statusTip; }
	std::string getToolTip() const{ return _toolTip; }
	void setToolTip(std::string toolTip){ _toolTip = toolTip; }
	std::string getWhatIsThis() const{ return _whatIsThis; }
	void setWhatIsThis(std::string whatIsThis){ _whatIsThis = whatIsThis; }
	bool getWritable() const{ return _writable; }
	void setWritable(bool writable) { _writable = writable; }
	void* getAttributeValue(const std::string attribute) const {
		for (PropertyAttribute attrib: *_attributes->list()) {
			if (attrib.first == attribute) {
				return attrib.second;
			}
		}
		return nullptr;
	}
	void setAttribute(std::string attribute, void* value){
		for (PropertyAttribute attrib: *_attributes->list()) {
			if (attrib.first == attribute) {
				attrib.second = value;
			}
		}
		_attributes->insert({attribute, value});
	}
protected:
	std::string _className;
	std::string _propertyName;
	int _propertyTypeInt;
	bool _writable = true;
	bool _hasValue = true;
	std::string _parentName;
	std::string _displayText;
	std::string _statusTip;
	std::string _toolTip;
	std::string _whatIsThis;
	List<PropertyBaseG*>* _subProperties = new List<PropertyBaseG*>();
	List<PropertyAttribute>* _attributes = new List<PropertyAttribute>();
};

class Property_bool: public PropertyBaseG{
protected:
	const bool _myType;
	const std::string _propertyType = Util::TypeOf<decltype(_myType)>();
	Getter<decltype(_myType)>::Member _getter;
	Setter<decltype(_myType)>::Member _setter;
public:
	std::string getType() const {return _propertyType;}
	virtual void setGetter(Getter<decltype(_myType)>::Member getter) {_getter=getter;}
	virtual void setSetter(Setter<decltype(_myType)>::Member setter) {_setter=setter;}
	virtual auto getValue() -> decltype(_myType) const {return _getter();}
	virtual void setValue(decltype(_myType) value) {_setter(value);}
	virtual std::string getValueText() const {return (_getter());}
};

class Property_string: public PropertyBaseG{
};

class Property_int: public PropertyBaseG{
protected:
	const std::string _myType;
	const std::string _propertyType = Util::TypeOf<decltype(_myType)>();
	Getter<decltype(_myType)>::Member _getter;
	Setter<decltype(_myType)>::Member _setter;
public:
	std::string getType() const {return _propertyType;}
	virtual void setGetter(Getter<decltype(_myType)>::Member getter) {_getter=getter;}
	virtual void setSetter(Setter<decltype(_myType)>::Member setter) {_setter=setter;}
	virtual auto getValue() -> decltype(_myType) const {return _getter();}
	virtual void setValue(decltype(_myType) value) {_setter(value);}
	virtual std::string getValueText() const {return (_getter());}
public:
};


// -------------------------

class PropertyListG {
public:
	PropertyListG () {}
	void insert(PropertyBaseG* property) {
		_properties->insert(property);
	}
	PropertyBaseG* getProperty(std::string propertyName) {
		for (PropertyBaseG* prop: *_properties->list()) {
			if (prop->getPropertyName() == propertyName) {
				return prop;
			}
		}
		return nullptr;
	}
	std::list<PropertyBaseG*>* list() {
		_properties->list();
	}
private:
	List<PropertyBaseG*>* _properties = new List<PropertyBaseG*>();
};

// -------------------------

#define ADD_PROPERTY_G(__propertyName, __propertyType, __propertyTypeInt, __hasValue, __className, __getter, __setter, __parentName, __displayText, __statusTip, __toolTip, __whatIsThis)\
	_addPropertyG( \
		new PropertyG___propertyType( \
			__propertyName, "__propertyType", __propertyTypeInt, true, __hasValue, "__className", __parentName,	__displayText, __statusTip, __toolTip, __whatIsThis) \
	);

#endif
