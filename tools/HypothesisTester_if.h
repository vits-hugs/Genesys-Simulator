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

    class ConfidenceInterval {
    public:

        ConfidenceInterval(double inferiorLimit, double superiorLimit) {
            _infLim = inferiorLimit;
            _supLim = superiorLimit;
        }

        double inferiorLimit() {
            return _infLim;
        }

        double superiorLimit() {
            return _supLim;
        }

    private:
        double _infLim, _supLim;
    };

    enum H1Comparition {
        DIFFERENT = 1,
        LESS_THAN = 2,
        GREATER_THAN = 3
    };

    class TestResult {
    public:

        TestResult(double errorTypeI, double pvalue, bool rejectH0, double rejectionThreshold, double testStat) {
            _errorTypeI = errorTypeI;
            _pvalue = pvalue;
            _rejectH0 = rejectH0;
            _rejectionThreshold = rejectionThreshold;
            _testStat = testStat;
        }

        bool rejectH0() {
            return _rejectH0;
        }

        double pValue() {
            return _pvalue;
        }

        double errorTypeI() {
            return _errorTypeI;
        }

        double rejectionThreshold() {
            return _rejectionThreshold;
        }

        double testStat() {
            return _testStat;
        }

    private:
        double _pvalue, _confidenceLevel, _errorTypeI, _rejectionThreshold, _testStat;
        bool _rejectH0;
    };
public:
    // confidence intervals
    virtual HypothesisTester_if::ConfidenceInterval averageConfidenceInterval(double avg, double stddev, unsigned int n, double confidenceLevel) = 0;
    virtual HypothesisTester_if::ConfidenceInterval proportionConfidenceInterval(double prop, unsigned int n, double confidenceLevel) = 0;
    virtual HypothesisTester_if::ConfidenceInterval varianceConfidenceInterval(double var, unsigned int n, double confidenceLevel) = 0;
    virtual HypothesisTester_if::ConfidenceInterval averageDifferenceConfidenceInterval(double avg1, double stddev1, unsigned int n1, double avg2, double stddev2, unsigned int n2, double confidenceLevel) = 0;
    virtual HypothesisTester_if::ConfidenceInterval varianceRatioConfidenceInterval(double var1, unsigned int n1, double var2, unsigned int n2, double confidenceLevel) = 0;
    // confidence intervals based on datafile
    virtual HypothesisTester_if::ConfidenceInterval averageConfidenceInterval(std::string sampleDataFilename, double confidenceLevel) = 0;
    virtual HypothesisTester_if::ConfidenceInterval proportionConfidenceInterval(std::string sampleDataFilename, checkProportionFunction function, double confidenceLevel) = 0;
    virtual HypothesisTester_if::ConfidenceInterval varianceConfidenceInterval(std::string sampleDataFilename, double confidenceLevel) = 0;
    // parametric tests
    // one population
    virtual HypothesisTester_if::TestResult testAverage(double avg, double stddev, unsigned int n, double avgSample, double confidenceLevel, HypothesisTester_if::H1Comparition comp) = 0;
    virtual HypothesisTester_if::TestResult testProportion(double prop, unsigned int n, double proptest, HypothesisTester_if::H1Comparition comp) = 0;
    virtual HypothesisTester_if::TestResult testVariance(double var, unsigned int n, double vartest, HypothesisTester_if::H1Comparition comp) = 0;
    // two populations
    virtual HypothesisTester_if::TestResult testAverage(double avg1, unsigned int n1, double avg2, unsigned int n2, HypothesisTester_if::H1Comparition comp) = 0;
    virtual HypothesisTester_if::TestResult testProportion(double prop1, unsigned int n1, double prop2, unsigned int n2, HypothesisTester_if::H1Comparition comp) = 0;
    virtual HypothesisTester_if::TestResult testVariance(double var1, unsigned int n1, double var2, unsigned int n2, HypothesisTester_if::H1Comparition comp) = 0;
    // one population based on datafile
    virtual HypothesisTester_if::TestResult testAverage(std::string sampleDataFilename, double avgSample, HypothesisTester_if::H1Comparition comp) = 0;
    virtual HypothesisTester_if::TestResult testProportion(std::string sampleDataFilename, checkProportionFunction function, double proptest, HypothesisTester_if::H1Comparition comp) = 0;
    virtual HypothesisTester_if::TestResult testVariance(std::string sampleDataFilename, double vartest, HypothesisTester_if::H1Comparition comp) = 0;
    // two populations based on datafile
    virtual HypothesisTester_if::TestResult testAverage(std::string firstSampleDataFilename, std::string secondSampleDataFilename, HypothesisTester_if::H1Comparition comp) = 0;
    virtual HypothesisTester_if::TestResult testProportion(std::string firstSampleDataFilename, std::string secondSampleDataFilename, checkProportionFunction function, HypothesisTester_if::H1Comparition comp) = 0;
    virtual HypothesisTester_if::TestResult testVariance(std::string firstSampleDataFilename, std::string secondSampleDataFilename, HypothesisTester_if::H1Comparition comp) = 0;
    // @TODO: Add interface for non-parametrical tests, such as chi-square (based on values and on datafile)
};

#endif /* HYPOTHESISTESTER_IF_H */

