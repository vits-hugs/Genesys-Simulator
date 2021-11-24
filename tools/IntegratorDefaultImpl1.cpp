/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   IntegratorDefaultImpl1.cpp
 * Author: rlcancian
 * 
 * Created on 23 de novembro de 2021, 18:36
 */

#include "IntegratorDefaultImpl1.h"
#include <math.h>

IntegratorDefaultImpl1::IntegratorDefaultImpl1(double precision, unsigned int steps) {
    _precision = precision;
    _steps = steps;
}

void IntegratorDefaultImpl1::setPrecision(double precision) {
    _precision = precision;
}

double IntegratorDefaultImpl1::getPrecision() {
    return _precision;
}

void IntegratorDefaultImpl1::setMaxSteps(double steps) {
    _steps = steps;
}

double IntegratorDefaultImpl1::getMaxSteps() {
    return _steps;
}

double IntegratorDefaultImpl1::integrate(double min, double max, double (*f)(double, double), double p2) {
    // Simpson's 1/3 rule
    double steps = _steps;
    double h = (max - min) / steps; // distance between points
    if (h < _precision) {
        steps = (max - min) / _precision;
        h = (max - min) / steps;
    }
    double x, c; // x is the point being evaluated, c is the weight
    double sum = 0.0;
    for (int i = 0; i <= steps; i++) {
        if (i == 0 || i == steps)
            c = 1;
        else if (i % 2 == 0)
            c = 2;
        else
            c = 4;
        x = min + i*h;
        sum += c * f(x, p2);
    }
    return (h / 3)*sum;
}

double IntegratorDefaultImpl1::integrate(double min, double max, double (*f)(double, double, double), double p2, double p3) {
    // Simpson's 1/3 rule

    unsigned int steps = _steps;
    double h = (max - min) / steps; // distance between points
    if (h < _precision) {
        steps = ceil((max - min) / _precision);
        h = (max - min) / steps;
    }
    double x, c; // x is the point being evaluated, c is the weight
    double sum = 0.0;
    for (int i = 0; i <= steps; i++) {
        if (i == 0 || i == steps)
            c = 1;
        else if (i % 2 == 0)
            c = 2;
        else
            c = 4;
        x = min + i*h;
        sum += c * f(x, p2, p3);
    }
    return (h / 3)*sum;
}

double IntegratorDefaultImpl1::integrate(double min, double max, double (*f)(double, double, double, double), double p2, double p3, double p4) {
    // Simpson's 1/3 rule
    double steps = _steps;
    double h = (max - min) / steps; // distance between points
    if (h < _precision) {
        steps = (max - min) / _precision;
        h = (max - min) / steps;
    }
    double x, c; // x is the point being evaluated, c is the weight
    double sum = 0.0;
    for (int i = 0; i <= steps; i++) {
        if (i == 0 || i == steps)
            c = 1;
        else if (i % 2 == 0)
            c = 2;
        else
            c = 4;
        x = min + i*h;
        sum += c * f(x, p2, p3, p4);
    }
    return (h / 3)*sum;
}

double IntegratorDefaultImpl1::integrate(double min, double max, double (*f)(double, double, double, double, double), double p2, double p3, double p4, double p5) {
    // Simpson's 1/3 rule
    double steps = _steps;
    double h = (max - min) / steps; // distance between points
    if (h < _precision) {
        steps = (max - min) / _precision;
        h = (max - min) / steps;
    }
    double x, c; // x is the point being evaluated, c is the weight
    double sum = 0.0;
    for (int i = 0; i <= steps; i++) {
        if (i == 0 || i == steps)
            c = 1;
        else if (i % 2 == 0)
            c = 2;
        else
            c = 4;
        x = min + i*h;
        sum += c * f(x, p2, p3, p4, p5);
    }
    return (h / 3)*sum;
}