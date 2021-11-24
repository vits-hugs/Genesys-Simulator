/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   HypothesisTesterDefaultImpl1.cpp
 * Author: rlcancian
 * 
 * Created on 24 de novembro de 2021, 02:52
 */

#include "HypothesisTesterDefaultImpl1.h"
#include "ProbabilityDistribution.h"
#include <math.h>

HypothesisTesterDefaultImpl1::HypothesisTesterDefaultImpl1() {
}

// confidence intervals

double HypothesisTesterDefaultImpl1::averageConfidenceInterval(double avg, double stddev, unsigned int n, double confidenceLevel) {
    double correctConf = confidenceLevel + (1.0 - confidenceLevel) / 2.0;
    double e0 = ProbabilityDistribution::inverseNormal(correctConf, avg, stddev) * stddev / sqrt(n);
    return e0;
}

double HypothesisTesterDefaultImpl1::proportionConfidenceInterval(double prop, unsigned int n, double confidenceLevel, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::varianceConfidenceInterval(double var, unsigned int n, double confidenceLevel, H1Comparition comp) {
}
// confidence intervals based on datafile

double HypothesisTesterDefaultImpl1::averageConfidenceInterval(std::string sampleDataFilename, double confidenceLevel, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::proportionConfidenceInterval(std::string sampleDataFilename, checkProportionFunction function, double confidenceLevel, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::varianceConfidenceInterval(std::string sampleDataFilename, double confidenceLevel, H1Comparition comp) {
}
// parametric tests
// one population

double HypothesisTesterDefaultImpl1::testAverage(double avg, unsigned int n, double avgtest, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::testProportion(double prop, unsigned int n, double proptest, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::testVariance(double var, unsigned int n, double vartest, H1Comparition comp) {
}
// two populations

double HypothesisTesterDefaultImpl1::testAverage(double avg1, unsigned int n1, double avg2, unsigned int n2, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::testProportion(double prop1, unsigned int n1, double prop2, unsigned int n2, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::testVariance(double var1, unsigned int n1, double var2, unsigned int n2, H1Comparition comp) {
}
// one population based on datafile

double HypothesisTesterDefaultImpl1::testAverage(std::string sampleDataFilename, double avgtest, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::testProportion(std::string sampleDataFilename, checkProportionFunction function, double proptest, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::testVariance(std::string sampleDataFilename, double vartest, H1Comparition comp) {
}
// two populations based on datafile

double HypothesisTesterDefaultImpl1::testAverage(std::string firstSampleDataFilename, std::string secondSampleDataFilename, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::testProportion(std::string firstSampleDataFilename, std::string secondSampleDataFilename, checkProportionFunction function, H1Comparition comp) {
}

double HypothesisTesterDefaultImpl1::testVariance(std::string firstSampleDataFilename, std::string secondSampleDataFilename, H1Comparition comp) {
}
// @TODO: Add interface for non-parametrical tests, such as chi-square (based on values and on datafile)
