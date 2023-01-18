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
	virtual std::string getValueText() const;
protected:
	typename Getter<T>::Member _getter;
	const std::string _type = Util::TypeOf<T>();
};
template<class T> std::string ReadOnlyPropertyG<T>::getValueText() const {return std::to_string(_getter());}
template<> std::string ReadOnlyPropertyG<std::string>::getValueText() const {return _getter();}
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


// -------------------------

class PropertyBaseG {
public:
	typedef std::pair<std::string, void*> PropertyAttribute;
public:
	PropertyBaseG(std::string propertyName, std::string propertyTypeName, int propertyType, bool writable, bool hasValue, void* propertyG, std::string className, std::string parentName, std::string displayText, std::string statusTip, std::string toolTip, std::string whatIsThis) {
		_propertyName=propertyName;
		_propertyTypeName=propertyTypeName;
		_propertyType=propertyType;
		_writable=writable;
		_hasValue=hasValue;
		_propertyG=propertyG;
		_className=className;
		_parentName=parentName;
		_displayText=displayText;
		_statusTip=statusTip;
		_toolTip=toolTip;
		_whatIsThis=whatIsThis;
	}
	PropertyBaseG(std::string className, std::string propertyName, std::string propertyType, std::string parentName = "") {
		_className = className;
		_propertyName = propertyName;
		_propertyTypeName = propertyType;
		_parentName = parentName;
	}
	PropertyBaseG(std::string propertyType, std::string propertyName){
		_propertyTypeName = propertyType;
		_propertyName = propertyName;
	}
	PropertyBaseG(int propertyType, std::string propertyName){
		_propertyType = propertyType;
		_propertyName = propertyName;
	}
public: //virtual
	virtual std::string show(){
		std::string message = " type="+_propertyTypeName+" ("+std::to_string(_propertyType)+"), name="+_propertyName+", class="+_className+", writable="+std::to_string(_writable);
		return message;
	}
public: // gets & sets
	void* getAttributeValue(const std::string attribute) const {
		for (PropertyAttribute attrib: *_attributes->list()) {
			if (attrib.first == attribute) {
				return attrib.second;
			}
		}
		return nullptr;
	}
	int getPropertyType() const{ return _propertyType; }
	void setAttribute(std::string attribute, void* value){
		for (PropertyAttribute attrib: *_attributes->list()) {
			if (attrib.first == attribute) {
				attrib.second = value;
			}
		}
		_attributes->insert({attribute, value});
	}
	void setValue(void* value){
		// todo
	}
	void* getValue() const{
		// todo
	}
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
	std::string getValueText() const{
		// todo (virtual?)
	}
	bool getWritable() const{ return _writable; }
	void setWritable(bool writable) { _writable = writable; }
	//template<class T>
	//void setGetterMethod(typename Getter<T>::Member getter){ _getter = getter; }
	//template<class T>
	//typename Getter<T>::Member getGetterMethod() const{ return _getter; }
	//template<class T>
	//void setSetterMethod(typename Setter<T>::Member setter){ _setter = setter; }
	//template<class T>
	//typename Setter<T>::Member getSetterMethod() const{ return _setter; }
	template<class T>
	void setValue(T value){
		// todo
	}
	template<class T>
	T getValue() const{
		// todo
	}
protected:
	std::string _propertyName;
	std::string _propertyTypeName;
	int _propertyType;
	bool _writable;
	bool _hasValue;
	//void* _getter;
	//void* _setter;
	void* _propertyG = nullptr;
	std::string _className;
	std::string _parentName;
	std::string _displayText;
	std::string _statusTip;
	std::string _toolTip;
	std::string _whatIsThis;
	//template<class T>
	//typename Getter<T>::Member getter<T>;
	//template<class T>
	//typename Setter<T>::Member _setter<T>;
	List<PropertyBaseG*>* _subProperties = new List<PropertyBaseG*>();
	List<PropertyAttribute>* _attributes = new List<PropertyAttribute>();
};


// -------------------------



#define ADD_PROPERTY_G(propertyName, propertyType, propertyTypeInt, hasValue, className, getter, setter, parentName, displayText, statusTip, toolTip, whatIsThis)\
	_addPropertyG( \
		new PropertyBaseG(propertyName, "propertyType", propertyTypeInt, true, hasValue, \
				new PropertyG<propertyType>( \
					DefineGetter<className, propertyType>(this, &className::getter), \
					DefineSetter<className, propertyType>(this, &className::setter) \
				), \
				"className", parentName, displayText, statusTip, toolTip, whatIsThis \
		) \
	);

#define ADD_READYONLY_PROPERTY_G(propertyName, propertyType, propertyTypeInt, hasValue, className, getter, setter, parentName, displayText, statusTip, toolTip, whatIsThis)\
	_addPropertyG( \
		new PropertyBaseG(propertyName, "propertyType", propertyTypeInt, false, hasValue, \
				new ReadOnlyPropertyG<propertyType>( \
					DefineGetter<className, propertyType>(this, &className::getter) \
				), \
				"className", parentName, displayText, statusTip, toolTip, whatIsThis \
		) \
	);


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

// -------------------------

// -------------------------

// -------------------------

// -------------------------

// -------------------------



// -------------------------

class PropertyBase {
public:
	typedef std::pair<std::string, void*> PropertyAttribute;
public:
	PropertyBase(std::string propertyName, std::string propertyTypeName, int propertyType, bool writable, bool hasValue,
				 std::string className,	std::string parentName,
				 std::string displayText, std::string statusTip, std::string toolTip, std::string whatIsThis) {
		_propertyName=propertyName;
		_propertyTypeName=propertyTypeName;
		_propertyType=propertyType;
		_writable=writable;
		_hasValue=hasValue;
		_className=className;
		_parentName=parentName;
		_displayText=displayText;
		_statusTip=statusTip;
		_toolTip=toolTip;
		_whatIsThis=whatIsThis;
	}
	PropertyBase(std::string className, std::string propertyName, std::string propertyType, std::string parentName = "") {
		_className = className;
		_propertyName = propertyName;
		_propertyTypeName = propertyType;
		_parentName = parentName;
	}
	PropertyBase(std::string propertyType, std::string propertyName){
		_propertyTypeName = propertyType;
		_propertyName = propertyName;
	}
	PropertyBase(int propertyType, std::string propertyName){
		_propertyType = propertyType;
		_propertyName = propertyName;
	}
public: //virtual
	virtual std::string show(){
		std::string message = " type="+_propertyTypeName+" ("+std::to_string(_propertyType)+"), name="+_propertyName+", class="+_className+", writable="+std::to_string(_writable);
		return message;
	}
public: // gets & sets
	void* getAttributeValue(const std::string attribute) const {
		for (PropertyAttribute attrib: *_attributes->list()) {
			if (attrib.first == attribute) {
				return attrib.second;
			}
		}
		return nullptr;
	}
	int getPropertyType() const{ return _propertyType; }
	void setAttribute(std::string attribute, void* value){
		for (PropertyAttribute attrib: *_attributes->list()) {
			if (attrib.first == attribute) {
				attrib.second = value;
			}
		}
		_attributes->insert({attribute, value});
	}
	void setValue(void* value){
		// todo
	}
	void* getValue() const{
		// todo
	}
	void addSubProperty(PropertyBase* property){ _subProperties->insert(property); }
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
	std::string getValueText() const{
		// todo (virtual?)
	}
	bool getWritable() const{ return _writable; }
	void setWritable(bool writable) { _writable = writable; }
	template<class T>
	void setGetterMethod(typename Getter<T>::Member getter){ _getter = getter; }
	template<class T>
	typename Getter<T>::Member getGetterMethod() const{ return _getter; }
	template<class T>
	void setSetterMethod(typename Setter<T>::Member setter){ _setter = setter; }
	template<class T>
	typename Setter<T>::Member getSetterMethod() const{ return _setter; }
	template<class T>
	void setValue(T value){
		// todo
	}
	template<class T>
	T getValue() const{
		// todo
	}
protected:
	std::string _propertyName;
	std::string _propertyTypeName;
	int _propertyType;
	bool _writable;
	bool _hasValue;
	void* _getter;
	void* _setter;
	std::string _className;
	std::string _parentName;
	std::string _displayText;
	std::string _statusTip;
	std::string _toolTip;
	std::string _whatIsThis;
	//template<class T>
	//typename Getter<T>::Member getter<T>;
	//template<class T>
	//typename Setter<T>::Member _setter<T>;
	List<PropertyBase*>* _subProperties = new List<PropertyBase*>();
	List<PropertyAttribute>* _attributes = new List<PropertyAttribute>();
};

class PropertyList {
public:
	PropertyList () {}
	void insert(PropertyBase* property) {
		_properties->insert(property);
	}
	PropertyBase* getProperty(std::string propertyName) {
		for (PropertyBase* prop: *_properties->list()) {
			if (prop->getPropertyName() == propertyName) {
				return prop;
			}
		}
		return nullptr;
	}
	std::list<PropertyBase*>* list() {
		_properties->list();
	}
private:
	List<PropertyBase*>* _properties = new List<PropertyBase*>();
};




template<class T>
class ReadOnlyPropertyT : public PropertyBase {
		public:
			ReadOnlyPropertyT(std::string classname, std::string name, typename Getter<T>::Member getter, std::string parentName = "") : PropertyBase(classname, name, parentName) {
				_getter = getter;
			};
		public:

			T getValue() {
				return _getter();
			};
			//virtual std::string getStringValue() const override;
		protected:
			typename Getter<T>::Member _getter;
			const std::string _type = Util::TypeOf<T>();
		};

// -------------------------

template<class T>
class PropertyT : public ReadOnlyPropertyT<T> {
public:

	PropertyT(std::string classname, std::string name, typename Getter<T>::Member getter, typename Setter<T>::Member setter, std::string parentName = "") : ReadOnlyPropertyT<T>(classname, name, getter, parentName) {
		_setter = setter;
	};
public:
	void setValue(T value);
	//virtual std::string getStringValue() const override;
protected:
	typename Setter<T>::Member _setter;
};



#endif
