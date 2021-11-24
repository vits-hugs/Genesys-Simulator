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

IntegratorDefaultImpl1::IntegratorDefaultImpl1(double precision, double steps) {
    _precision = precision;
    _steps = steps;
}

void IntegratorDefaultImpl1::setPrecision(double precision) {
    _precision = precision;
}

double IntegratorDefaultImpl1::getPrecision() {
    return _precision;
}

void IntegratorDefaultImpl1::setSteps(double steps) {
    _steps = steps;
}

double IntegratorDefaultImpl1::getSteps() {
    return _steps;
}

double IntegratorDefaultImpl1::integrate(double min, double max, double (*f)(double, double), double p2) {
    // Simpson's 1/3 rule

    double h = (max - min) / _steps; // distance between points
    double x, c; // x is the point being evaluated, c is the weight
    double sum = 0.0;
    for (int i = 0; i <= _steps; i++) {
        if (i == 0 || i == _steps)
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

    double h = (max - min) / _steps; // distance between points
    double x, c; // x is the point being evaluated, c is the weight
    double sum = 0.0;
    for (int i = 0; i <= _steps; i++) {
        if (i == 0 || i == _steps)
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

    double h = (max - min) / _steps; // distance between points
    double x, c; // x is the point being evaluated, c is the weight
    double sum = 0.0;
    for (int i = 0; i <= _steps; i++) {
        if (i == 0 || i == _steps)
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

    double h = (max - min) / _steps; // distance between points
    double x, c; // x is the point being evaluated, c is the weight
    double sum = 0.0;
    for (int i = 0; i <= _steps; i++) {
        if (i == 0 || i == _steps)
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