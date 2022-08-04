/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/*
 * File:   Tests.h
 * Author: rlcancian
 *
 * Created on 28 de junho de 2022, 20:00
 */

#ifndef TESTS_H
#define TESTS_H

#include <stdlib.h>
#include <iostream>

#include "../applications/BaseGenesysTerminalApplication.h"
#include "../kernel/statistics/StatisticsDataFile_if.h"
#include "../kernel/statistics/StatisticsDataFileDefaultImpl.h"
#include "../kernel/statistics/Sampler_if.h"
#include "../kernel/statistics/SamplerDefaultImpl1.h"

class Tests : public BaseGenesysTerminalApplication {
public:

	Tests() {
	}
	virtual ~Tests() = default;

	void testTools() {
		std::cout << "Start testTools" << std::endl;
		testDataAnalyser();
		testProbabilityDistribution();
	}

	void testDataAnalyser() {
		std::cout << "Start testDataAnalyser" << std::endl;
		testSampler();
	}

	void testProbabilityDistribution() {

	}

	void testSampler() {
		std::cout << "Start testSampler" << std::endl;
		testSamplerRandom();
	}

	void testSamplerRandom() {
		std::cout << "Start testSamplerRandom" << std::endl;
		//double error = 1.0;
		Sampler_if* sampler = new SamplerDefaultImpl1();
		StatisticsDatafile_if *stat = new StatisticsDatafileDefaultImpl1();
		CollectorDatafile_if *collector = static_cast<CollectorDatafile_if*> (stat->getCollector());
		collector->setDataFilename("./datafile_random.txt");
		double x;
		for (unsigned short i = 0; i < 5e3; i++) {
			x = sampler->random();
			std::cout << x << std::endl;
			collector->addValue(x);
		}
		//cassert(abs(stat->average()-100)<error);
	}

	virtual int main(int argc, char** argv) {
		std::cout << "Start TestSuite" << std::endl;
		//testTools();
		testProbabilityDistribution();
		return 0;
	}

private:

};

#endif /* TESTS_H */

