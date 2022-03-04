/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Statistics_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 14 de Agosto de 2018, 13:47
 */

#ifndef STATISTICS_IF_H
#define STATISTICS_IF_H

#include <string>
#include "Collector_if.h"

/*!
 * Interface for statisct synthesis of a stochastic variable collected by a Collector_if. The statistics generated may be updated based only on the previous statistics and the single newest added value or they may be updated based on a datafile, depending on the Collector implementation.
 */
class Statistics_if {
public:
    virtual Collector_if* getCollector() = 0;
    virtual void setCollector(Collector_if* collector) = 0;
public:
    virtual unsigned int numElements() = 0;
    virtual double min() const = 0;
    virtual double max() const = 0;
    virtual double average() const = 0;
    virtual double variance() const = 0;
    virtual double stddeviation() const = 0;
    virtual double variationCoef() const = 0;
    virtual double halfWidthConfidenceInterval() const = 0;
    virtual unsigned int newSampleSize(double halfWidth) = 0;
    virtual double getConfidenceLevel() const = 0;
    virtual void setConfidenceLevel(double confidencelevel) = 0;
};

#endif /* STATISTICS_IF_H */

