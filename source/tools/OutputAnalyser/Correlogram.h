// MyClass.h (Header File)

#ifndef CORRELOGRAM_H
#define CORRELOGRAM_H
#include <vector>
#include <algorithm>
#include <numeric>
#include "../../kernel/statistics/CollectorOutputAnalyser.h"

class Correlogram {
   public:
    // Constructor
    Correlogram(CollectorOutputAnalyser &collector, double start, double end, double timestep=1, int lag=10);
    ~Correlogram()=default;
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Correlogram& o);
    std::vector<double> getAutoCorrelation() {return _autocorrelation;}

   private:
    double getMean(std::vector<double>::iterator begin,std::vector<double>::iterator  end, int &size);
    double getVarWithMean(std::vector<double>::iterator begin,std::vector<double>::iterator  end,double mean);
    void getTimeVector(CollectorOutputAnalyser& reader);
    std::vector<CollectorOutputAnalyser::Data>::iterator getBeginPosition(std::vector<CollectorOutputAnalyser::Data>::iterator begin, std::vector<CollectorOutputAnalyser::Data>::iterator end, int start);
    std::vector<CollectorOutputAnalyser::Data>::iterator getEndTimePosition(std::vector<CollectorOutputAnalyser::Data>::iterator begin, std::vector<CollectorOutputAnalyser::Data>::iterator, int endtime);
    std::vector<double> _timeVector;
    std::vector<double> _autocorrelation;
    double _timestep;
    int _startTime;
};

#endif
