/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueableItem.h
 * Author: rlcancian
 *
 * Created on 23 de abril de 2021, 15:09
 */

#ifndef QUEUEABLEITEM_H
#define QUEUEABLEITEM_H

#include "../elements/Queue.h"
#include "../elements/Set.h"
#include "../../kernel/simulator/ElementManager.h"

// \todo should inhere from a common base to SeizeableItem

class QueueableItem {
public:

    enum class QueueableType : int {
        QUEUE = 1, SET = 2//, HOLD = 3
    };

public:
    QueueableItem(ModelElement* queueOrSet, QueueableItem::QueueableType queueableType = QueueableItem::QueueableType::QUEUE, std::string index = "0");
public:
    //virtual bool _loadInstance(std::map<std::string, std::string>* fields, unsigned int parentIndex);
    //virtual std::map<std::string, std::string>* _saveInstance(unsigned int parentIndex);
    bool loadInstance(std::map<std::string, std::string>* fields);
    std::map<std::string, std::string>* saveInstance();
public:
    std::string show();
    void setIndex(std::string index);
    std::string getIndex() const;
    std::string getQueueableName() const;
    void setQueue(Queue* resource);
    Queue* getQueue() const;
    void setSet(Set* set);
    Set* getSet() const;
    //
    void setQueueableType(QueueableType queueableType);
    QueueableType getQueueableType() const;
    ModelElement* getQueueable() const;
    void setElementManager(ElementManager* _elementManager);
    //void setComponentManager(ComponentManager* _componentManager);

private:

    const struct DEFAULT_VALUES {
        const std::string quantityExpression = "1";
        const QueueableItem::QueueableType queueableType = QueueableItem::QueueableType::QUEUE;
        const std::string saveAttribute = "";
        const std::string index = "0";
    } DEFAULT;

    QueueableType _queueableType;
    ModelElement* _queueOrSet;
    std::string _queueableName;
    std::string _index;
private:
    //ComponentManager* _componentManager;
    ElementManager* _elementManager;
};


#endif /* QUEUEABLEITEM_H */

