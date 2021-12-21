/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Process.h
 * Author: rafael.luiz.cancian
 *
 * Created on 22 de Maio de 2019, 18:41
 */

#ifndef PROCESS_H
#define PROCESS_H

#include "../../kernel/simulator/ModelComponent.h"
#include "Seize.h"
#include "Delay.h"
#include "Release.h"

/*!
 This component ...
 */
class Process : public ModelComponent {
public: // constructors
    Process(Model* model, std::string name = "");
    virtual ~Process() = default;
public: // virtual
    virtual std::string show();
public: // static
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);

public:

    void setPriority(unsigned short _priority);
    unsigned short getPriority() const;
    void setAllocationType(unsigned int _allocationType);
    unsigned int getAllocationType() const;
    List<SeizableItem*>* getSeizeRequests() const;
    void setQueueableItem(QueueableItem* _queueableItem);
    QueueableItem* getQueueableItem() const;
    void setSaveAttribute(std::string _saveAttribute);
    std::string getSaveAttribute() const;
    void setDelayExpression(std::string _delayExpression);
    std::string delayExpression() const;
    void setDelayTimeUnit(Util::TimeUnit _delayTimeUnit);
    Util::TimeUnit delayTimeUnit() const;



protected: // virtual
    virtual void _execute(Entity* entity);
    // virtual void _initBetweenReplications();
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
    virtual void _createInternalElements();
private: // methods
private: // attributes 1:1
    Seize* seize;
    Delay* delay;
    Release* release;
    ModelComponent* _nextComponent;
    unsigned int _nextInput;
private: // attributes 1:n
};

#endif /* PROCESS_H */

