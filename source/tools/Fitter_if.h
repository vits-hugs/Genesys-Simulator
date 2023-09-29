/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fitter_if.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 14:05
 */

#ifndef FITTER_IF_H
#define FITTER_IF_H

#include <string>
#include "HypothesisTesterDefaultImpl1.h"
#include "../kernel/statistics/CollectorOutputAnalyser.h"

class Fitter_if {
public:
	virtual void fitUniform(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result,
                    HypothesisTester_if::TestResult *ksResult, 
                    double *min, double *max) = 0;

    virtual void fitTriangular(unsigned int histogramClasses,
                        HypothesisTester_if::TestResult *chi2Result,
                        HypothesisTester_if::TestResult *ksResult,
                        double *min, double *mo, double *max) = 0;

    virtual void fitNormal(unsigned int histogramClasses,
                    HypothesisTester_if::TestResult *chi2Result,
                    HypothesisTester_if::TestResult *ksResult,
                    double *avg, double *stddev) = 0;

    virtual void fitExpo(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *avg1) = 0;
    
    virtual void fitErlang(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *avg, double *m) = 0;

    virtual void fitBeta(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *alpha, double *beta, 
                    double *infLimit, double *supLimit) = 0;

    virtual void fitWeibull(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *alpha, double *scale) = 0;

    virtual void fitAll(unsigned int histogramClasses, 
                HypothesisTester_if::TestResult *chi2Result, 
                HypothesisTester_if::TestResult *ksResult, 
                std::string *name) = 0;

    virtual void setStatistics(StatisticsDatafile_if* statistic) = 0;
    virtual void setCollector(CollectorOutputAnalyser& collector) = 0;
};

#endif /* FITTER_IF_H */

