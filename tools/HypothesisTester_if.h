/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTester_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Agosto de 2018, 19:04
 */

#ifndef HYPOTHESISTESTER_IF_H
#define HYPOTHESISTESTER_IF_H

#include <string>

typedef bool (*checkProportionFunction)(double value);

/**
 * Interface for parametric hypothesis tests based on a datafile or parameters.
 * All tests are suposed to be based on samples with unknown population parameters
 */
class HypothesisTester_if {
public:

    enum H1Comparition {
        DIFFERENT = 1,
        LESS_THAN = 2,
        GREATER_THAN = 3
    };
public:
    // confidence intervals
    virtual double averageConfidenceInterval(double avg, unsigned int n, double confidenceLevel, H1Comparition comp) = 0;
    virtual double proportionConfidenceInterval(double prop, unsigned int n, double confidenceLevel, H1Comparition comp) = 0;
    virtual double varianceConfidenceInterval(double var, unsigned int n, double confidenceLevel, H1Comparition comp) = 0;
    // confidence intervals based on datafile
    virtual double averageConfidenceInterval(std::string sampleDataFilename, double confidenceLevel, H1Comparition comp) = 0;
    virtual double proportionConfidenceInterval(std::string sampleDataFilename, checkProportionFunction function, double confidenceLevel, H1Comparition comp) = 0;
    virtual double varianceConfidenceInterval(std::string sampleDataFilename, double confidenceLevel, H1Comparition comp) = 0;
    // parametric tests
    // one population
    virtual double testAverage(double avg, unsigned int n, double avgtest, H1Comparition comp) = 0;
    virtual double testProportion(double prop, unsigned int n, double proptest, H1Comparition comp) = 0;
    virtual double testVariance(double var, unsigned int n, double vartest, H1Comparition comp) = 0;
    // two populations
    virtual double testAverage(double avg1, unsigned int n1, double avg2, unsigned int n2, H1Comparition comp) = 0;
    virtual double testProportion(double prop1, unsigned int n1, double prop2, unsigned int n2, H1Comparition comp) = 0;
    virtual double testVariance(double var1, unsigned int n1, double var2, unsigned int n2, H1Comparition comp) = 0;
    // one population based on datafile
    virtual double testAverage(std::string sampleDataFilename, double avgtest, H1Comparition comp) = 0;
    virtual double testProportion(std::string sampleDataFilename, checkProportionFunction function, double proptest, H1Comparition comp) = 0;
    virtual double testVariance(std::string sampleDataFilename, double vartest, H1Comparition comp) = 0;
    // two populations based on datafile
    virtual double testAverage(std::string firstSampleDataFilename, std::string secondSampleDataFilename, H1Comparition comp) = 0;
    virtual double testProportion(std::string firstSampleDataFilename, std::string secondSampleDataFilename, checkProportionFunction function, H1Comparition comp) = 0;
    virtual double testVariance(std::string firstSampleDataFilename, std::string secondSampleDataFilename, H1Comparition comp) = 0;
    // @TODO: Add interface for non-parametrical tests, such as chi-square (based on values and on datafile)
};

#endif /* HYPOTHESISTESTER_IF_H */

