// MyClass.h (Header File)

#ifndef OUTPUT_ANALYSER_H
#define OUTPUT_ANALYSER_H

#include "../Fitter.h"
#include "Correlogram.h"
#include "../DataAnalyser_if.h"
#include "../../kernel/statistics/CollectorOutputAnalyser.h"
#include "../../kernel/statistics/StatisticsDataFile_if.h"

class OutputAnalyser : public DataAnalyser_if {
public:
    // Constructor
    OutputAnalyser(std::string filename);
    ~OutputAnalyser();

    // Interface
	virtual bool loadDataSet(std::string datafilename) override;
	virtual bool saveDataSet(std::string datasetname) override;
	virtual void newDataSet(std::string datasetname, std::string datafilename) override;
	virtual Fitter_if* fitter() override;
	virtual Sampler_if* sampler() override;
	virtual ExperimentManager_if* experimenter() override;
	virtual HypothesisTester_if* tester() override;
    virtual StatisticsDatafile_if* statisticsDataFile() const override;
    CollectorOutputAnalyser* collector();
    Correlogram getCorrelogram(double start, double end, double timestep=1, int lag=10);
    void setReplication(int replicationNumber);

private:
    void _resetDependencies();

    CollectorOutputAnalyser _collector;
    StatisticsDatafile_if* _statisticsDataFile;
    Fitter_if* _fitter;
    Sampler_if* _sampler;
    ExperimentManager_if* _experimentManager;
    HypothesisTester_if* _hypothesisTester;
};

#endif
