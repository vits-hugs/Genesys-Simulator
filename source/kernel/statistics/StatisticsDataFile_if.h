/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsDataFile.h
 * Author: rafael.luiz.cancian
 *
 * Created on 22 de Novembro de 2018, 01:16
 */

#ifndef STATISTICSDATAFILE_IF_H
#define STATISTICSDATAFILE_IF_H

#include "CollectorDatafile_if.h"
#include "Statistics_if.h"
#include <vector>

class StatisticsDatafile_if : public Statistics_if {
	//public:
	//    virtual CollectorDatafile_if* getCollector() = 0;
	//    virtual void setCollector(Collector_if* collector) = 0;
public:
	virtual double mode() = 0;
	virtual double mediane() = 0;
	virtual double quartil(unsigned short num) = 0;
	virtual double decil(unsigned short num) = 0;
	virtual double centil(unsigned short num) = 0;
	virtual void setHistogramNumClasses(unsigned short num) = 0;
	virtual unsigned short histogramNumClasses() = 0;
	virtual double histogramClassLowerLimit(unsigned short classNum) = 0;
	virtual unsigned int histogramClassFrequency(unsigned short classNum) = 0;
	virtual std::vector<double> movingAverage(int dataPoints) = 0;
	virtual int sturges() = 0;
	virtual int squareRoot() = 0;
	virtual void clearCache() = 0;
};

#endif /* STATISTICSDATAFILE_IF_H */

