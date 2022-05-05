/*
 * The MIT License
 *
 * Copyright 2022 rlcancian.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * File:   testtestHyphotesisTester.cpp
 * Author: rlcancian
 *
 * Created on 21 de março de 2022, 19:13
 */

#include <stdlib.h>
#include <iostream>
#include "../tools/HypothesisTesterDefaultImpl1.h"
#include "../tools/HypothesisTester_if.h"
#include "../kernel/statistics/SamplerDefaultImpl1.h"
#include "../kernel/statistics/Sampler_if.h"

/*
 * Simple C++ Test Suite
 */

HypothesisTester_if* ht = new HypothesisTesterDefaultImpl1();
Sampler_if* rnd = new SamplerDefaultImpl1();

void testAvgIConf() {
	double avg, stddev, n, cl;
	for (unsigned int i =0; i<10; i++) {
		avg = 100;//rnd->sampleUniform(10,1000);
		stddev = 10;//avg * rnd->sampleUniform(0.01,1);
		n = (int)rnd->sampleUniform(5,500);
		cl = rnd->sampleUniform(0.7,0.999);
		HypothesisTester_if::ConfidenceInterval ci = ht->averageConfidenceInterval(avg, stddev, n, cl);
		std::cout <<"Avg=" << std::to_string(avg) << ", stddev=" << std::to_string(stddev) <<", n=" << std::to_string(n) << ", 1-a=" << std::to_string(cl) << " ==> ci=[" << ci.inferiorLimit() << ", " << ci.superiorLimit() << "], e0=" << std::to_string(ci.halfWidth()) << std::endl;
	}
}

void testPropIConf() {
}

void testVarIConf(){
}

void testVarRationIConf(){
}

void testAvgDiffIConf() {
}

void testPropDiffIConf() {
}

void testVarDiffIConf(){
}

void testAvgHypothesis() {
}

void testPropHypothesis() {
}

void testVarHypothesis(){
}


int mainTestHyphotesisTester(int argc, char** argv) {
	std::cout << "%SUITE_STARTING% testHyphotesisTester" << std::endl;
	testAvgIConf();
	testPropIConf();
	testVarIConf();
	testVarRationIConf();
	testAvgDiffIConf();
	testPropDiffIConf();
	testVarDiffIConf();
	testAvgHypothesis();
	testPropHypothesis();
	testVarHypothesis();
	std::cout << "%SUITE_FINISHED%" << std::endl;
	return (EXIT_SUCCESS);
}

