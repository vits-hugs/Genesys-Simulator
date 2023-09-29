#include<iostream>
#include <cmath>
#include"Correlogram.h"
#include <sstream>

using namespace std;

Correlogram::Correlogram(CollectorOutputAnalyser &collector, double start, double end, double timestep, int lag) {
    _timestep = timestep;
    getTimeVector(collector);
    if (end == -1 || end > int(_timeVector.size()) * _timestep) {
        end = _timeVector.size()*timestep + _startTime;
    }
    if (start < _startTime) {
        start = _startTime;
    }

    auto begin = _timeVector.begin() + int((start - _startTime)/ timestep);
    auto endF = _timeVector.begin() +  int((end - _startTime)/timestep);

    int size = 0;
    double mean = getMean(begin,endF,size);
    double var = getVarWithMean(begin,endF,mean);


    _autocorrelation = std::vector<double>();
    double c = 1;
    for (int t = 0; t < lag; t ++)
    {

        if (t>0) {
            double sum = 0;

            for (int i = 0; i < size-t; ++i) {
                double first = *(begin+t+i) - mean;
                double second = *(begin+i) - mean;
                sum += first * second;
            }
            c = sum/size/var;

        }
        _autocorrelation.push_back(c);
    }
}

std::string Correlogram::toString() const {
    std::stringstream oss;
    std::stringstream line;
    line << "[ ";
    for (auto &&i : _autocorrelation)
    {
        line << i << " ";
    }
    line << "]" << std::endl;
    oss << line.str();
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Correlogram& o) {
    os << o.toString();
    return os;
}

std::vector<CollectorOutputAnalyser::Data>::iterator Correlogram::getBeginPosition(std::vector<CollectorOutputAnalyser::Data>::iterator begin, std::vector<CollectorOutputAnalyser::Data>::iterator end, int start) {
    auto i = begin;
    auto last = i;
    while(i!=end) {
        CollectorOutputAnalyser::Data data =  CollectorOutputAnalyser::Data(*i);
    
        if (data.time >= start) {
            break;
        }
        last = i++;
    }

    return last;
}

std::vector<CollectorOutputAnalyser::Data>::iterator Correlogram::getEndTimePosition(std::vector<CollectorOutputAnalyser::Data>::iterator begin, std::vector<CollectorOutputAnalyser::Data>::iterator end, int endtime) {
    auto i = begin;
    auto last = i;
    while(i!=end) {
        CollectorOutputAnalyser::Data data =  CollectorOutputAnalyser::Data(*i);
    
        if (data.time >= endtime) {
            break;
        }
        last = i++;
    }

    return last;
}

void Correlogram::getTimeVector(CollectorOutputAnalyser& reader) {
    auto it = reader.begin();
    _startTime = (*it).time;
    CollectorOutputAnalyser::Data last;
    double time = 0;
    while(it != reader.end()) {
        CollectorOutputAnalyser::Data data = CollectorOutputAnalyser::Data(*it);
        it++;
        for (int i = 0; i < (data.time - time)/_timestep; i++)
        {
            _timeVector.push_back(last.value);

        }
        last = data;
        time = data.time;
    }
    _timeVector.push_back(last.value);

}

double Correlogram::getVarWithMean(std::vector<double>::iterator begin, std::vector<double>::iterator end, double mean) {
    double sum = 0;
    int size = 0;
    for(auto it= begin;it!=end;it++) {
        sum += pow(*(it) - mean,2.0);
        size++;
    }
    return sum/size;
}

double Correlogram::getMean(std::vector<double>::iterator begin, std::vector<double>::iterator end, int &size) {
    double sum = 0;
    size = 0;
    for(auto it= begin;it!=end;it++) {
        sum += *it;
        size++;
    }
    return sum/size;
}
