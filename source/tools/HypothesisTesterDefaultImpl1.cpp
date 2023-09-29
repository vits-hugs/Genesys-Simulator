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
#include "../kernel/statistics/StatisticsDataFile_if.h"
#include "../kernel/TraitsKernel.h"
#include <cmath>
#include <math.h>

HypothesisTesterDefaultImpl1::HypothesisTesterDefaultImpl1() {
}

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::averageConfidenceInterval(double avg, double stddev, unsigned int n, double confidenceLevel) {
	double correctConf = (1.0 - confidenceLevel) / 2.0;
	double critic = -ProbabilityDistribution::inverseTStudent(correctConf, 0.0, 1.0, n - 1);
	double e0 = critic * stddev / sqrt(n);
	return HypothesisTester_if::ConfidenceInterval(avg - e0, avg + e0, e0);
}

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::proportionConfidenceInterval(double prop, unsigned int n, double confidenceLevel) {
	double correctConf = (1.0 - confidenceLevel) / 2.0;
	double critic = -ProbabilityDistribution::inverseTStudent(correctConf, 0.0, 1.0, n - 1);
	double e0 = critic * sqrt(prop * (1 - prop) / n);
	return HypothesisTester_if::ConfidenceInterval(prop - e0, prop + e0, e0);
}

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::proportionConfidenceInterval(double prop, unsigned int n, int N, double confidenceLevel) {
	double correctConf = (1.0 - confidenceLevel) / 2.0;
	double critic = -ProbabilityDistribution::inverseTStudent(correctConf, 0.0, 1.0, n - 1);
	double e0 = critic * sqrt(prop * (1 - prop) / n) * sqrt((N - n) / (N - 1));
	return HypothesisTester_if::ConfidenceInterval(prop - e0, prop + e0, e0);
}

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::varianceConfidenceInterval(double var, unsigned int n, double confidenceLevel) {
	double a = 1 - confidenceLevel;
	double il = (n - 1) * var / ProbabilityDistribution::inverseChi2(1 - a / 2.0, n - 1);
	double sl = (n - 1) * var / ProbabilityDistribution::inverseChi2(a / 2.0, n - 1);
	double e0 = (sl - il) / 2.0;
	return HypothesisTester_if::ConfidenceInterval(il, sl, e0);
}

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::averageDifferenceConfidenceInterval(double avg1, double stddev1, unsigned int n1, double avg2, double stddev2, unsigned int n2, double confidenceLevel) { 
	double e0;
	double halfA = (1 - confidenceLevel) / 2;
	double var1 = stddev1 * stddev1;
	double var2 = stddev2 * stddev2;

	auto varIC = varianceRatioConfidenceInterval(pow(stddev1, 2), n1, pow(stddev2, 2), n2, confidenceLevel);

	if ((varIC.inferiorLimit() <= 1.0 && varIC.superiorLimit() >= 1.0) || (varIC.inferiorLimit() >= 1.0 && varIC.superiorLimit() <= 1.0)) {
		double criticalTValue = ProbabilityDistribution::inverseTStudent(1-halfA, 0.0, 1.0, n1 + n2 - 2);
		double varP = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2);
		e0 = criticalTValue * sqrt(varP * ((1 / (double)n1) + (1 / (double)n2)));
	} else {
		double var1ByN = var1 / n1;
		double var2ByN = var2 / n2;
		
		double varP = ((var1ByN+var2ByN) * (var1ByN+var2ByN)) / (var1ByN * var1ByN / (n1 - 1) + var2ByN * var2ByN / (n2 - 1));
		double criticalTValue = ProbabilityDistribution::inverseTStudent(1-halfA, 0.0, 1.0, round(varP));
		e0 = criticalTValue * sqrt(var1ByN + var2ByN);
	}
	
	double inferiorLimit = avg1 - avg2 - e0;
	double superiorLimit = avg1 - avg2 + e0;
	
	return ConfidenceInterval(inferiorLimit, superiorLimit, e0);
}

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::proportionDifferenceConfidenceInterval(double p1, unsigned int n1, double p2, unsigned int n2, double confidenceLevel) {
	double e0 = p2 - p1;
	double criticalValueZ = ProbabilityDistribution::inverseNormal(confidenceLevel, 0.0, 1.0);

	double p1Fraction = (p1 * (1 - p1)) / n1;
	double p2Fraction = (p2 * (1 - p2)) / n2;
	double errorMargin = criticalValueZ * sqrt(p1Fraction - p2Fraction);

	return ConfidenceInterval(e0 - errorMargin, e0 + errorMargin, e0);
}

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::varianceRatioConfidenceInterval(double var1, unsigned int n1, double var2, unsigned int n2, double confidenceLevel) {
	double ratio = var1 / var2;
	double il = 1 / ProbabilityDistribution::inverseFFisherSnedecor((1.0 - confidenceLevel) / 2.0, n2 - 1, n1 - 1);
	il *= ratio;
	double sl = ProbabilityDistribution::inverseFFisherSnedecor(confidenceLevel / 2.0, n1 - 1, n2 - 1);
	sl *= ratio;
	double e0 = (sl - il) / 2.0;
	return HypothesisTester_if::ConfidenceInterval(il, sl, e0);
}


// confidence intervals based on datafile

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::averageConfidenceInterval(std::string sampleDataFilename, double confidenceLevel) {
	StatisticsDatafile_if* stat = new TraitsKernel<StatisticsDatafile_if>::Implementation();
	static_cast<CollectorDatafile_if*> (stat->getCollector())->setDataFilename(sampleDataFilename);
	return averageConfidenceInterval(stat->average(), stat->stddeviation(), stat->numElements(), confidenceLevel);
}

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::proportionConfidenceInterval(std::string sampleDataFilename, checkProportionFunction function, double confidenceLevel) {
	StatisticsDatafile_if* stat = new TraitsKernel<StatisticsDatafile_if>::Implementation();
	static_cast<CollectorDatafile_if*> (stat->getCollector())->setDataFilename(sampleDataFilename);
	unsigned long count = 0;
	double value;
	for (unsigned long i = 0; i < stat->numElements(); i++) {
		value = static_cast<CollectorDatafile_if*> (stat->getCollector())->getValue(i);
		if (function(value))
			count++;
	}
	double prop = (double) count / stat->numElements();
	return proportionConfidenceInterval(prop, stat->numElements(), confidenceLevel);
}

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::proportionConfidenceInterval(std::string sampleDataFilename, checkProportionFunction function, double N, double confidenceLevel) {

}

HypothesisTester_if::ConfidenceInterval HypothesisTesterDefaultImpl1::varianceConfidenceInterval(std::string sampleDataFilename, double confidenceLevel) {
	StatisticsDatafile_if* stat = new TraitsKernel<StatisticsDatafile_if>::Implementation();
	static_cast<CollectorDatafile_if*> (stat->getCollector())->setDataFilename(sampleDataFilename);
	return varianceConfidenceInterval(stat->variance(), stat->numElements(), confidenceLevel);
}

unsigned int HypothesisTesterDefaultImpl1::estimateSampleSize(double avg, double stddev, unsigned int n, double desiredE0, double confidenceLevel) {
	double halfA = (1 - confidenceLevel) / 2;
	double criticalTValue = ProbabilityDistribution::inverseTStudent(1-halfA, 0.0, 1.0, n-1);
	double sqrtSampleSize = criticalTValue * stddev / desiredE0;
	
	return ceil(sqrtSampleSize * sqrtSampleSize);
}

// parametric tests
// one population

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testAverage(double avg, double stddev, unsigned int n, double avgSample, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double significanceLevel = (1.0 - confidenceLevel);
	double cumulative;
	if (comp == HypothesisTester_if::H1Comparition::LESS_THAN) {
		cumulative = significanceLevel;
	} else if (comp == HypothesisTester_if::H1Comparition::GREATER_THAN) {
		cumulative = confidenceLevel;
	} else {
		cumulative = confidenceLevel + significanceLevel / 2.0;
	}
	double acceptInfLimit = ProbabilityDistribution::inverseTStudent(cumulative, 0.0, 1.0, n - 1);
	double acceptSupLimit = ProbabilityDistribution::inverseTStudent(cumulative, 0.0, 1.0, n - 1);
	double testStat = (avgSample - avg) / (stddev / sqrt(n));
	double pvalue = ProbabilityDistribution::tStudent(avgSample, avg, stddev, n - 1);
	return HypothesisTester_if::TestResult(pvalue, pvalue<significanceLevel, acceptInfLimit, acceptSupLimit, testStat);
}

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testProportion(double prop, unsigned int n, double proptest, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue, rejectH0, acceptInfLim, acceptSupLim, testStat;
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptInfLim, acceptSupLim, testStat); ///@TODO: not implemented yet
}

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testVariance(double var, unsigned int n, double vartest, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue;
	bool rejectH0;
	double acceptanceInferiorLimit = std::numeric_limits<double>::min();
	double acceptanceSuperiorLimit = std::numeric_limits<double>::max();
	double testStat;
	
	double halfA = comp == H1Comparition::DIFFERENT
		? (1 - confidenceLevel) / 2
		: 1 - confidenceLevel;
	double df = n - 1;
	
	testStat = df * var / vartest;
	
	if (comp != H1Comparition::GREATER_THAN) {
		acceptanceInferiorLimit = ProbabilityDistribution::inverseChi2(halfA, df);
	}
	
	if (comp != H1Comparition::LESS_THAN) {
		acceptanceSuperiorLimit = ProbabilityDistribution::inverseChi2(1 - halfA, df);
	}
	
	rejectH0 = testStat < acceptanceInferiorLimit || testStat > acceptanceSuperiorLimit;
	double pValue1 = ProbabilityDistribution::getIntegrator()->integrate(std::numeric_limits<double>::min(), testStat, ProbabilityDistribution::chi2, df);
	double pValue2 = 1 - pValue1;
	pValue = std::min(pValue1, pValue2);
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptanceInferiorLimit, acceptanceSuperiorLimit, testStat); ///@TODO: not implemented yet
}
// two populations

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testAverage(double avg1, double stddev1, unsigned int n1, double avg2, double stddev2, unsigned int n2, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue;
	bool rejectH0;
	double acceptanceInferiorLimit = std::numeric_limits<double>::min();
	double acceptanceSuperiorLimit = std::numeric_limits<double>::max();
	double testStat;
	
	double halfA = comp == H1Comparition::DIFFERENT
		? (1 - confidenceLevel) / 2
		: 1 - confidenceLevel;
		
	double var1 = stddev1 * stddev1;
	double var2 = stddev2 * stddev2;
	
	auto varRatioInterval = varianceRatioConfidenceInterval(var1, n1, var2, n2, confidenceLevel);
	double areVariancesEqual = 1 >= varRatioInterval.inferiorLimit() && 1 <= varRatioInterval.superiorLimit();
	double tCrit;
	double v;
	
	if (!areVariancesEqual) {
		double var1ByN = var1 / n1;
		double var2ByN = var2 / n2;
	
		v = (var1ByN + var2ByN) * (var1ByN + var2ByN) / ((var1ByN * var1ByN / (n1 + 1)) + (var2ByN * var2ByN / (n2 + 1)));
		tCrit = ProbabilityDistribution::inverseTStudent(halfA, 0, 1, round(v));
		testStat = (avg1 - avg2) / sqrt(var1ByN + var2ByN);
	} else {
		v = n1 + n2 - 2;
		double varP = ((n1-1) * var1 + (n2-1) * var2)/ v;
		
		tCrit = -ProbabilityDistribution::inverseTStudent(1-halfA, 0, 1, v);
		testStat = (avg1 - avg2) / sqrt(varP * (1.0/n1 + 1.0/n2));
	}
	
	acceptanceInferiorLimit = comp == H1Comparition::GREATER_THAN
			? std::numeric_limits<double>::min()
			: tCrit;
		
	acceptanceSuperiorLimit = comp == H1Comparition::LESS_THAN
		? std::numeric_limits<double>::max()
		: -tCrit;
	
	rejectH0 = testStat < acceptanceInferiorLimit || testStat > acceptanceSuperiorLimit;
	    
	// Integrar a partir de std::numeric_limits<double>::min() (-infinito) não dá o resultado correto
	pValue = ProbabilityDistribution::getIntegrator()->integrate(-10, testStat, ProbabilityDistribution::tStudent, 0, 1, round(v));
	
	if (testStat >= 0) {
		pValue = 1 - pValue;
	}
	   
    	    
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptanceInferiorLimit, acceptanceSuperiorLimit, testStat);
}

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testProportion(double prop1, unsigned int n1, double prop2, unsigned int n2, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue, rejectH0, acceptInfLim, acceptSupLim, testStat;
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptInfLim, acceptSupLim, testStat); ///@TODO: not implemented yet
}

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testVariance(double var1, unsigned int n1, double var2, unsigned int n2, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue, rejectH0, acceptInfLim, acceptSupLim, testStat;
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptInfLim, acceptSupLim, testStat); ///@TODO: not implemented yet
}
// one population based on datafile

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testAverage(std::string sampleDataFilename, double avgSample, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue, rejectH0, acceptInfLim, acceptSupLim, testStat;
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptInfLim, acceptSupLim, testStat); ///@TODO: not implemented yet
}

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testProportion(std::string sampleDataFilename, checkProportionFunction function, double proptest, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue, rejectH0, acceptInfLim, acceptSupLim, testStat;
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptInfLim, acceptSupLim, testStat); ///@TODO: not implemented yet
}

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testVariance(std::string sampleDataFilename, double vartest, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue, rejectH0, acceptInfLim, acceptSupLim, testStat;
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptInfLim, acceptSupLim, testStat); ///@TODO: not implemented yet
}
// two populations based on datafile

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testAverage(std::string firstSampleDataFilename, std::string secondSampleDataFilename, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue, rejectH0, acceptInfLim, acceptSupLim, testStat;
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptInfLim, acceptSupLim, testStat); ///@TODO: not implemented yet
}

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testProportion(std::string firstSampleDataFilename, std::string secondSampleDataFilename, checkProportionFunction function, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue, rejectH0, acceptInfLim, acceptSupLim, testStat;
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptInfLim, acceptSupLim, testStat); ///@TODO: not implemented yet
}

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testVariance(std::string firstSampleDataFilename, std::string secondSampleDataFilename, double confidenceLevel, HypothesisTester_if::H1Comparition comp) {
	double pValue, rejectH0, acceptInfLim, acceptSupLim, testStat;
	return HypothesisTester_if::TestResult(pValue, rejectH0, acceptInfLim, acceptSupLim, testStat); ///@TODO: not implemented yet
}
// @TODO: Add interface for non-parametrical tests, such as chi-square (based on values and on datafile)

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testChiSquare(std::vector<double> observedFreq, std::vector<double> expectedFreq, double confidenceLevel, double minimumExpectedFrequency=5) {
	double pvalue;
	double freedomDegree;
	bool rejectH0;
	double acceptanceInferiorLimit = std::numeric_limits<double>::min();
	double acceptanceSuperiorLimit = std::numeric_limits<double>::max();
	double testStat = 0;
	double currExpectedFreq = 0;
	double currObservedFreq = 0;

	for (int i = 0; i < observedFreq.size(); i++) {
		currExpectedFreq += expectedFreq[i];
		currObservedFreq += observedFreq[i];
		
		if (currExpectedFreq < minimumExpectedFrequency) {
			continue;
		}
		
		double freqDiff = currExpectedFreq - currObservedFreq;
		testStat += freqDiff * freqDiff / currExpectedFreq;

		currExpectedFreq = 0;
		currObservedFreq = 0;
	}

	freedomDegree = observedFreq.size() - 1;

	acceptanceSuperiorLimit = ProbabilityDistribution::inverseChi2(confidenceLevel, freedomDegree);
	pvalue = 1 - ProbabilityDistribution::getIntegrator()->integrate(0, testStat, ProbabilityDistribution::chi2, freedomDegree);

	rejectH0 = testStat < acceptanceInferiorLimit || testStat > acceptanceSuperiorLimit;
	
	return HypothesisTester_if::TestResult(pvalue, rejectH0, acceptanceInferiorLimit, acceptanceSuperiorLimit, testStat);
}

HypothesisTester_if::TestResult HypothesisTesterDefaultImpl1::testKolmogorovSmirnov(std::vector<double> accumf1, std::vector<double> accumf2, double confidenceLevel) {
	double pvalue = std::numeric_limits<double>::min();
	bool rejectH0;
	double acceptanceInferiorLimit = std::numeric_limits<double>::min();
	double acceptanceSuperiorLimit = std::numeric_limits<double>::max();
	double maxDiff = std::numeric_limits<double>::min();
	double testStat;
	
	double n = accumf1.size();
	
	for (int i = 0; i < n; i++) {
		double diff = abs(accumf1[i] - accumf2[i]);
		maxDiff = std::max(diff, maxDiff);
	}
	
	double c = sqrt(-0.5 * std::log((1 - confidenceLevel) / 2));
	acceptanceSuperiorLimit = c * sqrt((n + n) / (n * n));
	testStat = maxDiff;
	
	rejectH0 = testStat > acceptanceSuperiorLimit;
	
	return HypothesisTester_if::TestResult(pvalue, rejectH0, acceptanceInferiorLimit, acceptanceSuperiorLimit, testStat);
}
