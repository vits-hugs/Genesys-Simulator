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
	virtual HypothesisTester_if::ConfidenceInterval averageConfidenceInterval(double avg, double stddev, unsigned int n, double confidenceLevel);
	virtual HypothesisTester_if::ConfidenceInterval proportionConfidenceInterval(double prop, unsigned int n, double confidenceLevel);
	virtual HypothesisTester_if::ConfidenceInterval varianceConfidenceInterval(double var, unsigned int n, double confidenceLevel);
	virtual HypothesisTester_if::ConfidenceInterval averageDifferenceConfidenceInterval(double avg1, double stddev1, unsigned int n1, double avg2, double stddev2, unsigned int n2, double confidenceLevel);
	virtual HypothesisTester_if::ConfidenceInterval varianceRatioConfidenceInterval(double var1, unsigned int n1, double var2, unsigned int n2, double confidenceLevel);

	// confidence intervals based on datafile
	virtual HypothesisTester_if::ConfidenceInterval averageConfidenceInterval(std::string sampleDataFilename, double confidenceLevel);
	virtual HypothesisTester_if::ConfidenceInterval proportionConfidenceInterval(std::string sampleDataFilename, checkProportionFunction function, double confidenceLevel);
	virtual HypothesisTester_if::ConfidenceInterval varianceConfidenceInterval(std::string sampleDataFilename, double confidenceLevel);
	// parametric tests
	// one population
	virtual HypothesisTester_if::TestResult testAverage(double avg, double stddev, unsigned int n, double avgSample, double confidenceLevel, HypothesisTester_if::H1Comparition comp);
	virtual HypothesisTester_if::TestResult testProportion(double prop, unsigned int n, double proptest, HypothesisTester_if::H1Comparition comp);
	virtual HypothesisTester_if::TestResult testVariance(double var, unsigned int n, double vartest, HypothesisTester_if::H1Comparition comp);
	// two populations
	virtual HypothesisTester_if::TestResult testAverage(double avg1, unsigned int n1, double avg2, unsigned int n2, HypothesisTester_if::H1Comparition comp);
	virtual HypothesisTester_if::TestResult testProportion(double prop1, unsigned int n1, double prop2, unsigned int n2, HypothesisTester_if::H1Comparition comp);
	virtual HypothesisTester_if::TestResult testVariance(double var1, unsigned int n1, double var2, unsigned int n2, HypothesisTester_if::H1Comparition comp);
	// one population based on datafile
	virtual HypothesisTester_if::TestResult testAverage(std::string sampleDataFilename, double avgSample, HypothesisTester_if::H1Comparition comp);
	virtual HypothesisTester_if::TestResult testProportion(std::string sampleDataFilename, checkProportionFunction function, double proptest, HypothesisTester_if::H1Comparition comp);
	virtual HypothesisTester_if::TestResult testVariance(std::string sampleDataFilename, double vartest, HypothesisTester_if::H1Comparition comp);
	// two populations based on datafile
	virtual HypothesisTester_if::TestResult testAverage(std::string firstSampleDataFilename, std::string secondSampleDataFilename, HypothesisTester_if::H1Comparition comp);
	virtual HypothesisTester_if::TestResult testProportion(std::string firstSampleDataFilename, std::string secondSampleDataFilename, checkProportionFunction function, HypothesisTester_if::H1Comparition comp);
	virtual HypothesisTester_if::TestResult testVariance(std::string firstSampleDataFilename, std::string secondSampleDataFilename, HypothesisTester_if::H1Comparition comp);
	// @TODO: Add interface for non-parametrical tests, such as chi-square (based on values and on datafile)
private:

};

#endif /* HYPOTHESISTESTERDEFAULTIMPL1_H */

