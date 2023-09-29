/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FitterDummyImpl.cpp
 * Author: cancian
 * 
 * Created on 23 de Agosto de 2018, 15:36
 */

#include "FitterDummyImpl.h"

FitterDummyImpl::FitterDummyImpl() {

}

void FitterDummyImpl::fitUniform(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result,
                    HypothesisTester_if::TestResult *ksResult, 
                    double *min, double *max) {

}

void FitterDummyImpl::fitTriangular(unsigned int histogramClasses,
                    HypothesisTester_if::TestResult *chi2Result,
                    HypothesisTester_if::TestResult *ksResult,
                    double *min, double *mo, double *max) {

}

void FitterDummyImpl::fitNormal(unsigned int histogramClasses,
                HypothesisTester_if::TestResult *chi2Result,
                HypothesisTester_if::TestResult *ksResult,
                double *avg, double *stddev) {

}

void FitterDummyImpl::fitExpo(unsigned int histogramClasses, 
                HypothesisTester_if::TestResult *chi2Result, 
                HypothesisTester_if::TestResult *ksResult, 
                double *avg1) {

}

void FitterDummyImpl::fitErlang(unsigned int histogramClasses, 
                HypothesisTester_if::TestResult *chi2Result, 
                HypothesisTester_if::TestResult *ksResult, 
                double *avg, double *m) {

}

void FitterDummyImpl::fitBeta(unsigned int histogramClasses, 
                HypothesisTester_if::TestResult *chi2Result, 
                HypothesisTester_if::TestResult *ksResult, 
                double *alpha, double *beta, 
                double *infLimit, double *supLimit) {

}

void FitterDummyImpl::fitWeibull(unsigned int histogramClasses, 
                HypothesisTester_if::TestResult *chi2Result, 
                HypothesisTester_if::TestResult *ksResult, 
                double *alpha, double *scale) {

}

void FitterDummyImpl::fitAll(unsigned int histogramClasses, 
            HypothesisTester_if::TestResult *chi2Result, 
            HypothesisTester_if::TestResult *ksResult, 
            std::string *name) {

}

void FitterDummyImpl::setStatistics(StatisticsDatafile_if* statistic) {

}

void FitterDummyImpl::setCollector(CollectorOutputAnalyser& collector) {
    
}
