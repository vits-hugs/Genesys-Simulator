/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/cppsimpletest.cc to edit this template
 */

/* 
 * File:   testProbabilityDistribution.cpp
 * Author: rlcancian
 *
 * Created on 23 de novembro de 2021, 18:30
 */

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

#include "../source/tools/ProbabilityDistribution.h"
#include "../source/tools/solver_if.h"
#include "../source/tools/SolverDefaultImpl1.h"
#include "../source/kernel/statistics/SamplerDefaultImpl1.h"
#include "../source/kernel/statistics/CollectorDatafileDefaultImpl1.h"
#include "../source/kernel/statistics/StatisticsDataFileDefaultImpl.h"
#include "../source/tools/TraitsTools.h"
#include "../source/tools/HypothesisTester_if.h"

void pd_test1() {
	//std::cout << "testProbabilityDistribution test 1" << std::endl;

	Sampler_if* sampler = new SamplerDefaultImpl1();
	StatisticsDatafile_if *stat = new StatisticsDatafileDefaultImpl1();
	CollectorDatafile_if *collector = static_cast<CollectorDatafile_if*> (stat->getCollector());
	collector->setDataFilename("./datafile.txt");
	double x;
	for (unsigned short i = 0; i < 5e3; i++) {
		x = sampler->sampleNormal(100, 20);
		collector->addValue(x);
	}
	std::cout << "min: " << stat->min() << std::endl;
	std::cout << "max: " << stat->max() << std::endl;
	std::cout << "avg: " << stat->average() << std::endl;
	std::cout << "std: " << stat->stddeviation() << std::endl;
	std::cout << "e0: " << stat->halfWidthConfidenceInterval() << std::endl;
	std::cout << "med: " << stat->mediane() << std::endl;
	std::cout << "mod: " << stat->mode() << std::endl;
	for (unsigned short i = 1; i <= 4; i++) {
		std::cout << "qrt" << i << ": " << stat->quartil(i) << std::endl;
	}
	for (unsigned short i = 1; i <= 10; i++) {
		std::cout << "dec" << i << ": " << stat->decil(i) << std::endl;
	}
}

void pd_test2() {
	//std::cout << "testProbabilityDistribution test 2" << std::endl;
	//std::cout << "%TEST_FAILED% time=0 testname=test2 (testProbabilityDistribution) message=error message sample" << std::endl;
	Solver_if* integr = new SolverDefaultImpl1(1e-6, 1e3);
	double x = integr->integrate(0.0, 0.5, &ProbabilityDistribution::beta, 4.0, 2.0);
	std::cout << x << std::endl;
}

void pd_test3() {
	double x = ProbabilityDistribution::inverseNormal(0.975, 0.0, 1.0);
	std::cout << x << std::endl;
	x = ProbabilityDistribution::inverseTStudent(0.975, 0.0, 1.0, 18);
	x = ProbabilityDistribution::inverseTStudent(0.975, 0.0, 1.0, 18);
	std::cout << x << std::endl;
	x = ProbabilityDistribution::inverseFFisherSnedecor(0.975, 2.0, 1.0);
	std::cout << x << std::endl;
	x = ProbabilityDistribution::inverseChi2(0.975, 5);
	std::cout << x << std::endl;
}

void tpd_est4() {
	HypothesisTester_if* ht = new TraitsTools<HypothesisTester_if>::Implementation();
	HypothesisTester_if::ConfidenceInterval ic = ht->averageConfidenceInterval(100, 10, 200, 0.95);
	double x;
	x = ProbabilityDistribution::inverseFFisherSnedecor(0.05, 7, 16);
	x = ProbabilityDistribution::inverseFFisherSnedecor(0.025, 7, 16);
	x = ProbabilityDistribution::inverseFFisherSnedecor(1.0 - 0.05, 16, 7);
	x = ProbabilityDistribution::inverseFFisherSnedecor(1.0 - 0.025, 16, 7);
	ic = ht->varianceRatioConfidenceInterval(46.5, 8, 23.4, 17, 0.95);
	std::cout << "[" << ic.inferiorLimit() << "," << ic.superiorLimit() << "]" << std::endl;
}

void pd_test5() {
	HypothesisTester_if* ht = new TraitsTools<HypothesisTester_if>::Implementation();
	HypothesisTester_if::TestResult result = ht->testAverage(90.0, 10.0, 25, 84.0, 0.95, HypothesisTester_if::H1Comparition::LESS_THAN);
	std::cout << result.acceptanceInferiorLimit() << result.acceptanceSuperiorLimit() << result.pValue() << result.rejectH0() << std::endl;
}

int pd_main(int argc, char** argv) {
	std::cout << "%SUITE_STARTING% testProbabilityDistribution" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	//pd_test1();
	//pd_test2();
	//pd_test3();
	//pd_test4();
	pd_test5();
	// std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	return (EXIT_SUCCESS);
}

