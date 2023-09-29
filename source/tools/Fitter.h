/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fitter.h
 * Author: Tulio
 *
 * Created on 24 de Novembro de 2023, 14:24
 */

#ifndef FITTER_H
#define FITTER_H

#include <string>
#include <limits>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cassert>
#include <vector>

#include "ProbabilityDistribution.h"
#include "Fitter_if.h"

class Fitter : public Fitter_if {
public:
	Fitter(CollectorOutputAnalyser& collector, StatisticsDatafile_if* statistic);
	~Fitter();
public:
    virtual void fitUniform(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result,
                    HypothesisTester_if::TestResult *ksResult, 
                    double *min, double *max);

    virtual void fitTriangular(unsigned int histogramClasses,
                    HypothesisTester_if::TestResult *chi2Result,
                    HypothesisTester_if::TestResult *ksResult,
                    double *min, double *mo, double *max);

    virtual void fitNormal(unsigned int histogramClasses,
                    HypothesisTester_if::TestResult *chi2Result,
                    HypothesisTester_if::TestResult *ksResult,
                    double *avg, double *stddev);

    virtual void fitExpo(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *avg1);
    
    virtual void fitErlang(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *avg, double *m);

    virtual void fitBeta(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *alpha, double *beta, 
                    double *infLimit, double *supLimit);

    virtual void fitWeibull(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *alpha, double *scale);

    virtual void fitAll(unsigned int histogramClasses, 
                HypothesisTester_if::TestResult *chi2Result, 
                HypothesisTester_if::TestResult *ksResult, 
                std::string *name);
    
    virtual void setStatistics(StatisticsDatafile_if* statistic);
    virtual void setCollector(CollectorOutputAnalyser& collector);
    void setConfidenceLevel(double confidenceLevel);
    double getConfidenceLevel();

private:
    static Solver_if* integrator;
    CollectorOutputAnalyser& _collector;
    StatisticsDatafile_if* _statistic;
    double _confidenceLevel;

    struct FitResult {
	    HypothesisTester_if::TestResult *chi2Result;
	    HypothesisTester_if::TestResult *ksResult;
	};

    struct BasicAnalysisResult {
        double min;
        double max;
        double amplitude;
        double rangePerClass;
        std::vector<std::vector<double>> classes;
    };

    std::vector<std::vector<double>> gatherClasses(unsigned int numberOfClasses);
    BasicAnalysisResult basicAnalysis(unsigned int histogramClasses);
    void fitGeneric(unsigned int histogramClasses, 
                    std::function<BasicAnalysisResult(BasicAnalysisResult)> gatherStats, 
                    std::function<double(double, double)> integrate,
                    HypothesisTester_if::TestResult *chi2Result,
                    HypothesisTester_if::TestResult *ksResult);

};

#endif /* FITTER_H */

