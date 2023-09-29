#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

#include "OutputAnalyser.h"

using namespace std;

int main() {
    // ------------------------------
    // ---- Output Analyser ----
    // ------------------------------
    OutputAnalyser outputAnalyser("../../source/tools/OutputAnalyser/Files/UniformDist.txt");
    outputAnalyser.setReplication(1);

    // ------------------------------
    // ---- Statistical Analysis ----
    // ------------------------------
    auto ss = outputAnalyser.statisticsDataFile();
    int size = ss->getCollector()->numElements();

    double min = ss->min();
    double max = ss->max();
    double avg = ss->average();
    double stdDev = ss->stddeviation();
    double varCoef = ss->variationCoef();
    auto movingAverage = ss->movingAverage(5);
    double var = ss->variance();
    double mode = ss->mode();
    double median = ss->mediane();
    double Q1 = ss->quartil(1);
    double Q2 = ss->quartil(2);
    double Q3 = ss->quartil(3);
    double decil = ss->decil(1);
    double centil = ss->centil(1);

    cout << "------- Statistics -------" << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Avg: " << avg << endl;
    cout << "Var: " << var << endl;

    cout << "Moving average: " << endl;
    for (const auto& element : movingAverage) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    cout << "StdDev: " << stdDev << endl;
    cout << "VarCoef: " << varCoef << endl;
    cout << "Mode: " << mode << endl;
    cout << "Median: " << median << endl;
    cout << "Quartil Q1: " << Q1 << endl;
    cout << "Quartil Q2: " << Q2 << endl;
    cout << "Quartil Q3: " << Q3 << endl;
    cout << "Decil: " << decil << endl;
    cout << "Centil: " << centil << endl;


    auto tester = outputAnalyser.tester();
    auto avgInterval = tester->averageConfidenceInterval(avg, stdDev, size, 0.95);
    auto varInterval = tester->varianceConfidenceInterval(var, size, 0.95);
    auto propInterval = tester->proportionConfidenceInterval(0.6, 400, 0.95);

    cout << endl << "------- Hypothesis Tester -------" << endl;
    cout << "AverageInterval " << avgInterval.inferiorLimit() << " " << avgInterval.superiorLimit() << endl;
    cout << "VarianceInterval " << varInterval.inferiorLimit() << " " << varInterval.superiorLimit() << endl;
    cout << "ProportionInterval (60% pro, 95% confidence) " << propInterval.inferiorLimit() << " " << propInterval.superiorLimit() << endl;

    // // -----------------------------
    // // --------- Histogram ---------
    // // -----------------------------

    int numClasses = ss->sturges();
    ss->setHistogramNumClasses(numClasses);

    std::stringstream histogram;
    histogram << std::fixed << std::setprecision(3);
    for (int i = 0; i < numClasses - 1; i++) 
        histogram << "( " << ss->histogramClassLowerLimit(i) << " - " << ss->histogramClassLowerLimit(i + 1) << " )" << "->" << ss->histogramClassFrequency(i) << std::endl;
    histogram << "( " << ss->histogramClassLowerLimit(numClasses - 1) << " - " << ss->max() << " )" << "->" << ss->histogramClassFrequency(numClasses - 1) << std::endl;
    cout << histogram.str() << endl;

    // // // ------------------------------
    // // // ----------- Fitter -----------
    // // // ------------------------------
    auto fitter = outputAnalyser.fitter();
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double stddev;

    std::stringstream fitterStream;

    fitter->fitUniform(11, &chi2Result, &ksResult, &avg, &stddev);
    fitterStream << "Teste FitUniform --------------------" << std::endl;
    fitterStream << "Chi Aceitação de H0: " << chi2Result.acceptH0() << std::endl;
    fitterStream << "Chi p-value: " << chi2Result.pValue() << std::endl;
    fitterStream << "Chi Estatística de teste: " << chi2Result.testStat() << std::endl;
    fitterStream << "Ks Aceitação de H0: " << ksResult.acceptH0() << std::endl;
    fitterStream << "Ks Estatística de teste: " << ksResult.testStat() << std::endl;

    std::string name;
    fitter->fitAll(11, &chi2Result, &ksResult, &name);
    fitterStream << "Teste FitAll --------------------" << std::endl;
    fitterStream << "Teste Melhor: " << name << std::endl;
    fitterStream << "Chi Aceitação de H0: " << chi2Result.acceptH0() << std::endl;
    fitterStream << "Chi p-value: " << chi2Result.pValue() << std::endl;
    fitterStream << "Chi Estatística de teste: " << chi2Result.testStat() << std::endl;
    fitterStream << "Ks Aceitação de H0: " << ksResult.acceptH0() << std::endl;
    fitterStream << "Ks Estatística de teste: " << ksResult.testStat() << std::endl;
    cout << fitterStream.str() << endl;

    // // // -----------------------------
    // // // -------- Correlogram --------
    // // // -----------------------------

    // // auto correlogram = outputAnalyser.getCorrelogram(0, -1);
    // // cout << "Correlogram: " << endl
    // //      << correlogram << endl;
}
