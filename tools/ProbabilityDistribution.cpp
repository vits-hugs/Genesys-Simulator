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

#include <math.h> 
#include <cassert>

double ProbabilityDistribution::beta(double x, double alpha, double beta) {
    double x1 = _gammaFunction(alpha + beta) / (_gammaFunction(alpha) * _gammaFunction(beta));
    //double x1 = 1/_betaFunction(alpha,beta);
    double x2 = pow(x, alpha - 1) * pow(1 - x, beta - 1);
    return x1*x2;
}

double ProbabilityDistribution::chi2(double x, double m) {
    if (x >= 0) {
        double x1 = pow(x, m / 2 - 1) * pow(M_E, -x / 2);
        double x2 = pow(2, m / 2) * _gammaFunction(m / 2);
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

double ProbabilityDistribution::inverseChi2(double cumulativeProbability, double m) {
    return 0.0;
}

double ProbabilityDistribution::inverseFFisherSnedecor(double cumulativeProbability, double d1, double d2) {
    return 0.0;
}

double ProbabilityDistribution::inverseNormal(double cumulativeProbability, double mean, double stddev) {
    return 0.0;
}

double ProbabilityDistribution::inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom) {
    return 0.0;
}

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