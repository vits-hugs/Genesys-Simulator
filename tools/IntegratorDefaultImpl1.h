/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   IntegratorDefaultImpl1.h
 * Author: rlcancian
 *
 * Created on 23 de novembro de 2021, 18:36
 */

#ifndef INTEGRATORDEFAULTIMPL1_H
#define INTEGRATORDEFAULTIMPL1_H

#include "Integrator_if.h"

class IntegratorDefaultImpl1 : public Integrator_if {
public:
    IntegratorDefaultImpl1(double precision = 1e-6, unsigned int steps = 1e3);
    virtual ~IntegratorDefaultImpl1() = default;
public:
    virtual void setPrecision(double e);
    virtual double getPrecision();
    virtual void setMaxSteps(double steps);
    virtual double getMaxSteps(); 
    virtual double integrate(double min, double max, double (*f)(double, double), double p2);
    virtual double integrate(double min, double max, double (*f)(double, double, double), double p2, double p3);
    virtual double integrate(double min, double max, double (*f)(double, double, double, double), double p2, double p3, double p4);
    virtual double integrate(double min, double max, double (*f)(double, double, double, double, double), double p2, double p3, double p4, double p5);
private:
    double _precision;
    unsigned int _steps;
};

#endif /* INTEGRATORDEFAULTIMPL1_H */

