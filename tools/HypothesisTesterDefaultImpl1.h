/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   HypothesisTesterDefaultImpl1.h
 * Author: rlcancian
 *
 * Created on 24 de novembro de 2021, 02:52
 */

#ifndef HYPOTHESISTESTERDEFAULTIMPL1_H
#define HYPOTHESISTESTERDEFAULTIMPL1_H

#include "HypothesisTester_if.h"

class HypothesisTesterDefaultImpl1 : public HypothesisTester_if {
public:
    HypothesisTesterDefaultImpl1();
    virtual ~HypothesisTesterDefaultImpl1() = default;
public:
    // confidence intervals
    virtual double averageConfidenceInterval(double avg, double stddev, unsigned int n, double confidenceLevel);
    virtual double proportionConfidenceInterval(double prop, unsigned int n, double confidenceLevel, H1Comparition comp);
    virtual double varianceConfidenceInterval(double var, unsigned int n, double confidenceLevel, H1Comparition comp);
    // confidence intervals based on datafile
    virtual double averageConfidenceInterval(std::string sampleDataFilename, double confidenceLevel, H1Comparition comp);
    virtual double proportionConfidenceInterval(std::string sampleDataFilename, checkProportionFunction function, double confidenceLevel, H1Comparition comp);
    virtual double varianceConfidenceInterval(std::string sampleDataFilename, double confidenceLevel, H1Comparition comp);
    // parametric tests
    // one population
    virtual double testAverage(double avg, unsigned int n, double avgtest, H1Comparition comp);
    virtual double testProportion(double prop, unsigned int n, double proptest, H1Comparition comp);
    virtual double testVariance(double var, unsigned int n, double vartest, H1Comparition comp);
    // two populations
    virtual double testAverage(double avg1, unsigned int n1, double avg2, unsigned int n2, H1Comparition comp);
    virtual double testProportion(double prop1, unsigned int n1, double prop2, unsigned int n2, H1Comparition comp);
    virtual double testVariance(double var1, unsigned int n1, double var2, unsigned int n2, H1Comparition comp);
    // one population based on datafile
    virtual double testAverage(std::string sampleDataFilename, double avgtest, H1Comparition comp);
    virtual double testProportion(std::string sampleDataFilename, checkProportionFunction function, double proptest, H1Comparition comp);
    virtual double testVariance(std::string sampleDataFilename, double vartest, H1Comparition comp);
    // two populations based on datafile
    virtual double testAverage(std::string firstSampleDataFilename, std::string secondSampleDataFilename, H1Comparition comp);
    virtual double testProportion(std::string firstSampleDataFilename, std::string secondSampleDataFilename, checkProportionFunction function, H1Comparition comp);
    virtual double testVariance(std::string firstSampleDataFilename, std::string secondSampleDataFilename, H1Comparition comp);
    // @TODO: Add interface for non-parametrical tests, such as chi-square (based on values and on datafile)
private:

};

#endif /* HYPOTHESISTESTERDEFAULTIMPL1_H */

