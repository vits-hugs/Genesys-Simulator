/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Traits.h
 * Author: rafael.luiz.cancian
 *
 * Created on 14 de Agosto de 2018, 19:36
 */


#ifndef TRAITS_H
#define TRAITS_H


#include "simulator/ModelPersistenceDefaultImpl1.h"
#include "simulator/SimulationReporterDefaultImpl1.h"
#include "simulator/Counter.h"
#include "simulator/ModelCheckerDefaultImpl1.h"
#include "simulator/PluginConnectorDummyImpl1.h"
#include "simulator/ParserDefaultImpl2.h"

#include "statistics/CollectorDatafileDefaultImpl1.h"
#include "statistics/CollectorDefaultImpl1.h"
#include "statistics/StatisticsDefaultImpl1.h"
#include "statistics/SamplerDefaultImpl1.h"



//namespace GenesysKernel {

template <typename T>
struct TraitsKernel {
    static const Util::TraceLevel traceLevel = Util::TraceLevel::L2_results;
};

/*
 *  Simulation and Simulation Parts
 */

template <> struct TraitsKernel<SimulationReporter_if> {
    typedef SimulationReporterDefaultImpl1 Implementation;
    typedef Counter CounterImplementation;
    static const Util::TraceLevel traceLevel = Util::TraceLevel::L2_results;
};

template <> struct TraitsKernel<PluginConnector_if> {
    typedef PluginConnectorDummyImpl1 Implementation;
    static const Util::TraceLevel traceLevel = Util::TraceLevel::L4_warning;
};


template <> struct TraitsKernel<Parser_if> {
	typedef ParserDefaultImpl2 Implementation;
};

/*
 *  Model and Model Parts
 */

template <> struct TraitsKernel<Model> {
    static const Util::TraceLevel traceLevel = Util::TraceLevel::L4_warning;
};

template <> struct TraitsKernel<ModelComponent> {
	typedef StatisticsDefaultImpl1 StatisticsCollector_StatisticsImplementation;
	typedef CollectorDefaultImpl1 StatisticsCollector_CollectorImplementation;
	static constexpr bool reportStatistics = true;
	static const Util::TraceLevel traceLevel = Util::TraceLevel::L2_results;
};

template <> struct TraitsKernel<ModelElement> {
	static constexpr bool reportStatistics = true;
	static const Util::TraceLevel traceLevel = Util::TraceLevel::L2_results;
};

template <> struct TraitsKernel<ModelChecker_if> {
    typedef ModelCheckerDefaultImpl1 Implementation;
    static const Util::TraceLevel traceLevel = Util::TraceLevel::L2_results;
};


template <> struct TraitsKernel<ModelPersistence_if> {
    typedef ModelPersistenceDefaultImpl1 Implementation;
    static const Util::TraceLevel traceLevel = Util::TraceLevel::L2_results;
};

/*
 *  Statistics
 */
template <> struct TraitsKernel<Statistics_if> {
    typedef StatisticsDefaultImpl1 Implementation;
    typedef CollectorDefaultImpl1 CollectorImplementation;
    static constexpr double SignificanceLevel = 0.05;
};

template <> struct TraitsKernel<Sampler_if> {
    typedef SamplerDefaultImpl1 Implementation;
    typedef SamplerDefaultImpl1::DefaultImpl1RNG_Parameters Parameters;
};


template <> struct TraitsKernel<Collector_if> {
    typedef CollectorDatafileDefaultImpl1 Implementation;
};
//namespace\\}

#endif /* TRAITS_H */

