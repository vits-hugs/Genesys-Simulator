/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ProbabilityDistribution.cpp
 * Author: rlcancian
 * 
 * Created on 22 de novembro de 2021, 17:24
 */

#include "ProbabilityDistribution.h"
#include "../Traits.h"
#include <math.h> 
#include <cassert>

std::map<std::string, double>* ProbabilityDistribution::memory = new std::map<std::string, double>();
Solver_if* ProbabilityDistribution::integrator = new Traits<Solver_if>::Implementation(Traits<Solver_if>::Precision, Traits<Solver_if>::MaxSteps);

double ProbabilityDistribution::beta(double x, double alpha, double beta) {
	double x1 = _gammaFunction(alpha + beta) / (_gammaFunction(alpha) * _gammaFunction(beta));
	//double x1 = 1/_betaFunction(alpha,beta);
	double x2 = pow(x, alpha - 1) * pow(1 - x, beta - 1);
	return x1*x2;
}

double ProbabilityDistribution::chi2(double x, double degreeFreedom) {
	if (x >= 0) {
		double x1 = pow(x, degreeFreedom / 2 - 1) * pow(M_E, -x / 2);
		double x2 = pow(2, degreeFreedom / 2) * _gammaFunction(degreeFreedom / 2);
		return x1 / x2;
	} else
		return 0.0;
}

double ProbabilityDistribution::erlang(double x, double shape, double scale) {
	assert(x >= 0.0 && scale >= 0.0);
	double x1 = pow(x, shape - 1) * pow(M_E, -x / scale);
	double x2 = pow(scale, shape)*(shape - 1);
	return x1 / x2;
} // int M

double ProbabilityDistribution::exponential(double x, double mean) {
	if (x >= 0) {
		return mean * pow(M_E, -mean * x);
	} else
		return 0.0;
}

double ProbabilityDistribution::fisherSnedecor(double x, double d1, double d2) {
	assert(x >= 0);
	double x1 = 1 / _betaFunction(d1 / 2, d2 / 2);
	double x2 = pow(d1 / d2, d1 / 2) * pow(x, d1 / 2 - 1);
	double x3 = pow(1 + (d1 / d2) * x, -(d1 + d2) / 2);
	return x1 * x2 * x3;
}

double ProbabilityDistribution::gamma(double x, double shape, double scale) {
	double x1 = pow(x, shape - 1) * pow(M_E, -x / scale);
	double x2 = pow(scale, shape) * _gammaFunction(shape);
	return x1 / x2;
}

double ProbabilityDistribution::logNormal(double x, double mean, double stddev) {
	double x1 = 1 / (x * stddev * sqrt(2 * M_PI));
	double x2 = exp(-pow(log(x) - mean, 2) / (2 * stddev * stddev));
	return x1 * x2;
}

double ProbabilityDistribution::normal(double x, double mean, double stddev) {
	double x1 = 1 / (stddev * sqrt(2 * M_PI));
	double x2 = -0.5 * pow((x - mean) / stddev, 2);
	return x1 * pow(M_E, x2);
}

double ProbabilityDistribution::poisson(double x, double mean) {
	assert((x - trunc(x)) == 0);
	double x1 = pow(mean, x) * pow(M_E, -mean);
	double x2 = _factorial(x);
	return x1 / x2;
}

double ProbabilityDistribution::triangular(double x, double min, double mode, double max) {
	if (x < min || x > max)
		return 0.0;
	else if (x < mode)
		return 2 * (x - min) / ((max - min)*(mode - min));
	else if (x == mode)
		return 2 / (max - min);
	else
		return 1 - pow(max - x, 2) / ((max - min)*(max - mode));
}

double ProbabilityDistribution::tStudent(double x, double mean, double stddev, double degreeFreedom) {
	double x1 = _gammaFunction((degreeFreedom + 1) / 2) / (sqrt(degreeFreedom * M_PI) * _gammaFunction(degreeFreedom / 2));
	double x2 = pow(1 + (x * x) / degreeFreedom, -(degreeFreedom + 1) / 2);
	return x1*x2;
}

double ProbabilityDistribution::uniform(double x, double min, double max) {
	return 1.0 / (max - min);
}

double ProbabilityDistribution::weibull(double x, double shape, double scale) {
	assert(shape >= 0 && scale >= 0);
	if (x > 0) {
		double x1 = (shape / scale) * pow(x / scale, shape - 1);
		double x2 = pow(M_E, -pow(x / scale, shape));
		return x1 * x2;
	} else
		return 0.0;
}
// inverse

double ProbabilityDistribution::_findInverseChi2(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double degreeFreedom) {
	double x = ((cumulativeProbability - fa) / (fb - fa)) * (b - a) + a;
	double fx = fa + integrator->integrate(a, x, ProbabilityDistribution::chi2, degreeFreedom);
	++recursions;
	if ((recursions == integrator->getMaxSteps()) || (abs(fx - cumulativeProbability) <= integrator->getPrecision())) {
		return x;
	} else if (fx < cumulativeProbability) {
		return ProbabilityDistribution::_findInverseChi2(x, fx, b, fb, recursions, cumulativeProbability, degreeFreedom);
	} else {
		return ProbabilityDistribution::_findInverseChi2(a, fa, x, fx, recursions, cumulativeProbability, degreeFreedom);
	}
}

double ProbabilityDistribution::inverseChi2(double cumulativeProbability, double m) {
	std::string key = "chi2(" + std::to_string(m) + ")" + std::to_string(cumulativeProbability);
	auto search = ProbabilityDistribution::memory->find(key);
	if (search != ProbabilityDistribution::memory->end()) { //found
		return search->second;
	} else {
		double a, fa;
		double b, fb;
		a = 0.0;
		fa = 0.0;
		b = 1000.0; ///TODO: Is there a way to better determine the upper limit?
		unsigned int savedSteps = integrator->getMaxSteps();
		integrator->setMaxSteps(1e3);
		fb = integrator->integrate(a, b, ProbabilityDistribution::chi2, m);
		//integrator->setMaxSteps(1e3);
		double inv = ProbabilityDistribution::_findInverseChi2(a, fa, b, fb, 0, cumulativeProbability, m);
		integrator->setMaxSteps(savedSteps);
		std::pair<std::string, double> pair = std::pair<std::string, double>(key, inv);
		ProbabilityDistribution::memory->insert(pair);
		return inv;
	}
}

double ProbabilityDistribution::_findInverseFFisherSnedecor(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double d1, double d2) {
	double x = ((cumulativeProbability - fa) / (fb - fa)) * (b - a) + a;
	double fx = fa + integrator->integrate(a, x, ProbabilityDistribution::fisherSnedecor, d1, d2);
	++recursions;
	if ((recursions == integrator->getMaxSteps()) || (abs(fx - cumulativeProbability) <= integrator->getPrecision())) {
		return x;
	} else if (fx < cumulativeProbability) {
		return ProbabilityDistribution::_findInverseFFisherSnedecor(x, fx, b, fb, recursions, cumulativeProbability, d1, d2);
	} else {
		return ProbabilityDistribution::_findInverseFFisherSnedecor(a, fa, x, fx, recursions, cumulativeProbability, d1, d2);
	}
}

double ProbabilityDistribution::inverseFFisherSnedecor(double cumulativeProbability, double d1, double d2) {
	std::string key = "fisher(" + std::to_string(d1) + "," + std::to_string(d2) + ")" + std::to_string(cumulativeProbability);
	auto search = ProbabilityDistribution::memory->find(key);
	if (search != ProbabilityDistribution::memory->end()) { //found
		return search->second;
	} else {
		double a, fa;
		double b, fb;
		a = 0.0;
		fa = 0.0;
		b = 10000.0; ///TODO: Is there a way to better determine the upper limit?
		unsigned int savedSteps = integrator->getMaxSteps();
		integrator->setMaxSteps(1e4);
		fb = integrator->integrate(a, b, ProbabilityDistribution::fisherSnedecor, d1, d2);
		//integrator->setMaxSteps(1e3);
		double inv = ProbabilityDistribution::_findInverseFFisherSnedecor(a, fa, b, fb, 0, cumulativeProbability, d1, d2);
		integrator->setMaxSteps(savedSteps);
		std::pair<std::string, double> pair = std::pair<std::string, double>(key, inv);
		ProbabilityDistribution::memory->insert(pair);
		return inv;
	}
}

double ProbabilityDistribution::_findInverseNormal(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double mean, double stddev) {
	double x = ((cumulativeProbability - fa) / (fb - fa)) * (b - a) + a;
	double fx = fa + integrator->integrate(a, x, ProbabilityDistribution::normal, mean, stddev);
	++recursions;
	if ((recursions == integrator->getMaxSteps()) || (abs(fx - cumulativeProbability) <= integrator->getPrecision())) {
		return x;
	} else if (fx < cumulativeProbability) {
		return ProbabilityDistribution::_findInverseNormal(x, fx, b, fb, recursions, cumulativeProbability, mean, stddev);
	} else {
		return ProbabilityDistribution::_findInverseNormal(a, fa, x, fx, recursions, cumulativeProbability, mean, stddev);
	}
}

double ProbabilityDistribution::inverseNormal(double cumulativeProbability, double mean, double stddev) {
	std::string key = "normal(" + std::to_string(mean) + "," + std::to_string(stddev) + ")" + std::to_string(cumulativeProbability);
	auto search = ProbabilityDistribution::memory->find(key);
	if (search != ProbabilityDistribution::memory->end()) { //found
		return search->second;
	} else {
		double a, fa;
		double b, fb;
		if (cumulativeProbability <= 0.5) { ///TODO: Could be better (separate into 1,2,3xstddev)
			a = mean - stddev * 5.0;
			fa = 0.0;
			b = mean;
			fb = 0.5;
		} else {
			a = mean;
			fa = 0.5;
			b = mean + stddev * 5.0;
			fb = 1.0;
		}
		double inv = ProbabilityDistribution::_findInverseNormal(a, fa, b, fb, 0, cumulativeProbability, mean, stddev);
		std::pair<std::string, double> pair = std::pair<std::string, double>(key, inv);
		ProbabilityDistribution::memory->insert(pair);
		return inv;
	}
}

double ProbabilityDistribution::_findInverseTStudent(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double mean, double stddev, double degreeFreedom) {
	double x = ((cumulativeProbability - fa) / (fb - fa)) * (b - a) + a;
	double fx = fa + integrator->integrate(a, x, ProbabilityDistribution::tStudent, mean, stddev, degreeFreedom);
	++recursions;
	if ((recursions == integrator->getMaxSteps()) || (abs(fx - cumulativeProbability) <= integrator->getPrecision())) {
		return x;
	} else if (fx < cumulativeProbability) {
		return ProbabilityDistribution::_findInverseTStudent(x, fx, b, fb, recursions, cumulativeProbability, mean, stddev, degreeFreedom);
	} else {
		return ProbabilityDistribution::_findInverseTStudent(a, fa, x, fx, recursions, cumulativeProbability, mean, stddev, degreeFreedom);
	}
}

double ProbabilityDistribution::inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom) {
	std::string key = "tstudent(" + std::to_string(mean) + "," + std::to_string(stddev) + "," + std::to_string(degreeFreedom) + ")" + std::to_string(cumulativeProbability);
	auto search = ProbabilityDistribution::memory->find(key);
	if (search != ProbabilityDistribution::memory->end()) { //found
		return search->second;
	} else {
		double a, fa;
		double b, fb;
		if (cumulativeProbability <= 0.5) { ///TODO: Could be better
			a = mean - stddev * 5.0;
			fa = 0.0;
			b = mean;
			fb = 0.5;
		} else {
			a = mean;
			fa = 0.5;
			b = mean + stddev * 5.0;
			fb = 1.0;
		}
		double inv = ProbabilityDistribution::_findInverseTStudent(a, fa, b, fb, 0, cumulativeProbability, mean, stddev, degreeFreedom);
		std::pair<std::string, double> pair = std::pair<std::string, double>(key, inv);
		ProbabilityDistribution::memory->insert(pair);
		return inv;
	}
}

//************************

double ProbabilityDistribution::_gammaFunction(double x) {
	return tgamma(x); ///TODO: Implement by myself
}

double ProbabilityDistribution::_betaFunction(double x, double y) {
	return std::beta(x, y); ///TODO: Implement by myself
}

double ProbabilityDistribution::_factorial(double x) {
	if (x > 1)
		return x * _factorial(x - 1);
	else
		return 1;
}