/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsDataFileDummyImpl.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 22 de Novembro de 2018, 01:24
 */

#include "StatisticsDataFileDefaultImpl.h"

#include "../TraitsKernel.h"

StatisticsDataFileDummyImpl::StatisticsDataFileDummyImpl() {
    _collector = new TraitsKernel<Statistics_if>::CollectorImplementation();
}

unsigned int StatisticsDataFileDummyImpl::numElements() {
    return 0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::min() {
    return 0.0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::max() {
    return 0.0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::average() {
    return 0.0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::mode() {
    return 0.0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::mediane() {
    return 0.0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::variance() {
    return 0.0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::stddeviation() {
    return 0.0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::variationCoef() {
    return 0.0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::halfWidthConfidenceInterval(double confidencelevel) {
    return 0.0; // \TODO: Not implemented yet
}

unsigned int StatisticsDataFileDummyImpl::newSampleSize(double confidencelevel, double halfWidth) {
    return 0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::quartil(unsigned short num) {
    return 0.0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::decil(unsigned short num) {
    return 0.0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::centil(unsigned short num) {
    return 0.0; // \TODO: Not implemented yet
}

void StatisticsDataFileDummyImpl::setHistogramNumClasses(unsigned short num) {
}

unsigned short StatisticsDataFileDummyImpl::histogramNumClasses() {
    return 0; // \TODO: Not implemented yet
}

double StatisticsDataFileDummyImpl::histogramClassLowerLimit(unsigned short classNum) {
    return 0.0; // \TODO: Not implemented yet
}

unsigned int StatisticsDataFileDummyImpl::histogramClassFrequency(unsigned short classNum) {
    return 0; // \TODO: Not implemented yet
}

Collector_if* StatisticsDataFileDummyImpl::getCollector() {
	return this->_collector;
}

void StatisticsDataFileDummyImpl::setCollector(Collector_if* collector) {

}