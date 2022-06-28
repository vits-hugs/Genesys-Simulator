/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ProbabilityDistribution.h
 * Author: rlcancian
 *
 * Created on 22 de novembro de 2021, 17:24
 */

#ifndef PROBABILITYDISTRIBUTION_H
#define PROBABILITYDISTRIBUTION_H

#include "solver_if.h"
#include <string>
#include <map>

class ProbabilityDistribution {
public:
	static double beta(double x, double alpha, double beta);
	static double chi2(double x, double degreeFreedom);
	static double erlang(double x, double shape, double scale); // int M
	static double exponential(double x, double mean);
	static double fisherSnedecor(double x, double d1, double d2);
	static double gamma(double x, double shape, double scale);
	static double logNormal(double x, double mean, double stddev);
	static double normal(double x, double mean, double stddev);
	static double poisson(double x, double mean);
	static double triangular(double x, double min, double mode, double max);
	static double tStudent(double x, double mean, double stddev, double degreeFreedom);
	static double uniform(double x, double min, double max);
	static double weibull(double x, double shape, double scale);
	// inverse
	static double inverseChi2(double cumulativeProbability, double degreeFreedom);
	static double inverseFFisherSnedecor(double cumulativeProbability, double d1, double d2);
	static double inverseNormal(double cumulativeProbability, double mean, double stddev);
	static double inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom);
    static double inverseAnything(); //@TODO
private:
	static double _findInverseChi2(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double degreeFreedom);
	static double _findInverseFFisherSnedecor(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double d1, double d2);
	static double _findInverseNormal(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double mean, double stddev);
	static double _findInverseTStudent(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double mean, double stddev, double degreeFreedom);
private:
	static double _gammaFunction(double x);
	static double _betaFunction(double x, double y);
	static double _factorial(double x);
	//static double _inverseAnything(double x, double cumulative, double min, double max);
private:
	static std::map<std::string, double>* memory; // = std::map<std::string, double>();
	static Solver_if* integrator;
	//static IntegratorDefaultImpl1 _Integrator = IntegratorDefaultImpl1(); //Integrator_if _Integrator = Traits<Integrator_if>::Implementation(); //Traits<Integrator_if>::Precision, Traits<Integrator_if>::MaxSteps);
	//static constexpr Integrator_if* _Integrator = new Traits<Integrator_if>::Implementation(Traits<Integrator_if>::Precision, Traits<Integrator_if>::MaxSteps);
};
#endif /* PROBABILITYDISTRIBUTION_H */

