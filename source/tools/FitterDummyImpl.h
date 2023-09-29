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

#ifndef FITTERDUMMYIMPL_H
#define FITTERDUMMYIMPL_H

#include <string>
#include "Fitter_if.h"

class FitterDummyImpl : public Fitter_if {
public:
	FitterDummyImpl();
	~FitterDummyImpl();
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
};

#endif /* FITTERDUMMYIMPL_H */