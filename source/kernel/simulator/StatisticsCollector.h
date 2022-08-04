/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   StatisticsCollector.h
 * Author: rafael.luiz.cancian
 *
 * Created on 30 de Agosto de 2018, 17:24
 */

#ifndef STATISTICSCOLLECTOR_H
#define STATISTICSCOLLECTOR_H

#include "ModelDataDefinition.h"
#include "../statistics/Statistics_if.h"
#include "ModelDataManager.h"
#include "Plugin.h"

//namespace GenesysKernel {

/*!
 The StatisticsCollector is the ModelDataDefinition responsible for collecting data from the model (using the Collector) and simultaneouly keeping statistics updated (using the Statistics)
 */
class StatisticsCollector : public ModelDataDefinition {//, public Statistics_if {
public:
    StatisticsCollector(Model* model, std::string name = "", ModelDataDefinition* parent = nullptr, bool insertIntoModel = true);
    virtual ~StatisticsCollector() = default;
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelDataDefinition* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
    static ModelDataDefinition* NewInstance(Model* model, std::string name = "");
public:
    ModelDataDefinition* getParent() const;
    Statistics_if* getStatistics() const;

protected:
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance(bool saveDefaultValues);
    virtual bool _check(std::string* errorMessage);
private:
    void _initStaticsAndCollector();
private:
    ModelDataDefinition* _parent;
    Statistics_if* _statistics;
};
//namespace\\}
#endif /* STATISTICSCOLLECTOR_H */

