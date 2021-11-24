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

class ProbabilityDistribution {
public:
    static double beta(double x, double alpha, double beta);
    static double chi2(double x, double m);
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
    static double inverseChi2(double cumulativeProbability, double m);
    static double inverseFFisherSnedecor(double cumulativeProbability, double d1, double d2);
    static double inverseNormal(double cumulativeProbability, double mean, double stddev);
    static double inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom);
private:
    static double _gammaFunction(double x);
    static double _betaFunction(double x, double y);
    static double _factorial(double x);
};

#endif /* PROBABILITYDISTRIBUTION_H */

