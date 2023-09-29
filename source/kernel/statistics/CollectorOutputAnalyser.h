//
// Created by vitorh on 16/11/23.
//

#ifndef COLLECTOROUTPUTANALYSER_H
#define COLLECTOROUTPUTANALYSER_H

#include "CollectorDatafile_if.h"
#include<vector>
class CollectorOutputAnalyser : public CollectorDatafile_if{
public:
    struct Data {
        double value;
        double time;
        bool operator<(const Data& other) const { return value < other.value; }
    };
public:
    double getValue(unsigned int rank) override;

    double getSize();

    void seekFirstValue() override;

    double getNextValue() override;

    std::string getDataFilename() override;

    void setDataFilename(std::string filename) override;

    void clear() override;

    void addValue(double value, double weight) override;

    double getLastValue() override;

    unsigned long numElements() override;

    void setAddValueHandler(CollectorAddValueHandler addValueHandler) override;

    void setClearHandler(CollectorClearHandler clearHandler) override;

    void setReplicationNumber(int replicationNumber);

    std::vector<CollectorOutputAnalyser::Data>::iterator end();

    std::vector<CollectorOutputAnalyser::Data>::iterator begin();

    CollectorDatafile_if *clone() const override;

    std::string toString() const;

    void sort();
private:
    std::string _filename;
    std::vector<Data> _datavector;
    unsigned int _readPos;
    int _replicationNumber=1;
    int _firstLine;
    CollectorAddValueHandler _addValueHandler = nullptr;
    CollectorClearHandler _clearHandler = nullptr;


};


#endif //GENESYS_SIMULATOR_COLLECTOROUTPUTANALYSER_H
