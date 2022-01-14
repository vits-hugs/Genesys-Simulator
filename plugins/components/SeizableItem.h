/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SeizableItem.h
 * Author: rlcancian
 *
 * Created on 10 de abril de 2021, 08:45
 */

#ifndef SEIZABLEITEM_H
#define SEIZABLEITEM_H

#include "../elements/Resource.h"
#include "../elements/Set.h"
#include "../../kernel/simulator/ElementManager.h"

// @TODO should inhere from a common base to QueueableItem

class SeizableItem {
public:

	enum class SelectionRule : int {
		CYCLICAL = 1, RANDOM = 2, SPECIFICMEMBER = 3, LARGESTREMAININGCAPACITY = 4, SMALLESTNUMBERBUSY = 5
	};

	enum class SeizableType : int {
		RESOURCE = 1, SET = 2
	};

public:
	SeizableItem(ModelElement* resourceOrSet, std::string quantityExpression = "1", SeizableItem::SelectionRule selectionRule = SeizableItem::SelectionRule::LARGESTREMAININGCAPACITY, std::string saveAttribute = "", std::string index = "0");

public:
	bool loadInstance(std::map<std::string, std::string>* fields, unsigned int parentIndex);
	std::map<std::string, std::string>* saveInstance(unsigned int parentIndex, bool saveDefault);
	bool loadInstance(std::map<std::string, std::string>* fields);
	std::map<std::string, std::string>* saveInstance(bool saveDefaults);
public:
	std::string show();
	void setIndex(std::string index);
	std::string getIndex() const;
	void setSaveAttribute(std::string saveAttribute);
	std::string getSaveAttribute() const;
	void setSelectionRule(SelectionRule selectionRule);
	SelectionRule getSelectionRule() const;
	void setQuantityExpression(std::string quantityExpression);
	std::string getQuantityExpression() const;
	std::string getResourceName() const;
	void setResource(Resource* resource);
	Resource* getResource() const;
	void setSet(Set* set);
	Set* getSet() const;
	void setSeizableType(SeizableType resourceType);
	SeizableType getSeizableType() const;
	void setLastMemberSeized(unsigned int lastMemberSeized);
	unsigned int getLastMemberSeized() const;
	ModelElement* getSeizable() const;
	void setElementManager(ElementManager* _elementManager);
	//void setComponentManager(ComponentManager* _componentManager);

private:

	const struct DEFAULT_VALUES {
		const std::string quantityExpression = "1";
		const SeizableItem::SeizableType seizableType = SeizableItem::SeizableType::RESOURCE;
		const SeizableItem::SelectionRule selectionRule = SeizableItem::SelectionRule::LARGESTREMAININGCAPACITY;
		const std::string saveAttribute = "";
		const std::string index = "0";
	} DEFAULT;

	SeizableType _seizableType = DEFAULT.seizableType;
	SelectionRule _selectionRule = DEFAULT.selectionRule;
	std::string _saveAttribute = DEFAULT.saveAttribute;
	std::string _index = DEFAULT.index;
	ModelElement* _resourceOrSet;
	std::string _seizableName;
	std::string _quantityExpression;
	unsigned int _lastMemberSeized = 0;
private:
	//ComponentManager* _componentManager;
	ElementManager* _elementManager;
};

#endif /* SEIZABLEITEM_H */

