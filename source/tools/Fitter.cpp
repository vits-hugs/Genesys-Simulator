/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fitter.cpp
 * Author: Tulio
 *
 * Created on 24 de Novembro de 2023, 14:24
 */
#include <iostream>
#include "Fitter.h"

Solver_if* Fitter::integrator = new SolverDefaultImpl1(1e-5, 1e2);

Fitter::Fitter(CollectorOutputAnalyser& collector, StatisticsDatafile_if* statistic) : _collector(collector),
                                                                            _statistic(statistic) {
    _confidenceLevel = 0.95;                                                 
}

void Fitter::fitUniform(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result,
                    HypothesisTester_if::TestResult *ksResult, 
                    double *min, double *max) {

    fitGeneric(histogramClasses,
            [min, max](BasicAnalysisResult res) {
                *min = res.min;
                *max = res.max;
                
                return res;
            },
            [histogramClasses](double li, double ls) {
                return 1.0 / histogramClasses;
            },
            chi2Result,
            ksResult
	   );

}

void Fitter::fitTriangular(unsigned int histogramClasses,
                        HypothesisTester_if::TestResult *chi2Result,
                        HypothesisTester_if::TestResult *ksResult,
                        double *min, double *mo, double *max) { 

        std::map<double, int> frequency;
        for (int i = 0; i < _collector.getSize(); i++) {
            frequency[_collector.getValue(i)]++;
        }
        double mode = _collector.getValue(0);
        int maxFrequency = frequency[mode];

        for (const auto& peer : frequency) {
            if (peer.second > maxFrequency) {
                mode = peer.first;
                maxFrequency = peer.second;
            }
        }
        *mo = mode;

	    fitGeneric(histogramClasses,
	        [min, mo, max](BasicAnalysisResult res) {
	            *min = res.min;
	            *max = res.max;
	            
	            return res;
	        },
	        [this, min, mo, max](double li, double ls) {
	            return integrator->integrate(li, ls, ProbabilityDistribution::triangular,  *min, *mo, *max);
	        },
	        chi2Result,
	        ksResult
	    );
}

void Fitter::fitNormal(unsigned int histogramClasses,
                    HypothesisTester_if::TestResult *chi2Result,
                    HypothesisTester_if::TestResult *ksResult,
                    double *avg, double *stddev) {

    fitGeneric(histogramClasses,
        [this, avg, stddev](BasicAnalysisResult res) {
            *avg = _statistic->average();
            *stddev = _statistic->stddeviation();
            return res;
        },
        [this, avg, stddev](double li, double ls) {
            return integrator->integrate(li, ls, ProbabilityDistribution::normal, *avg, *stddev);
        },
        chi2Result,
        ksResult
    );

}

void Fitter::fitExpo(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *avg1) {

    fitGeneric(histogramClasses,
        [this, avg1](BasicAnalysisResult res) {
            *avg1 = _statistic->average();
            return res;
        },
        [this, avg1](double li, double ls) {
            return integrator->integrate(li, ls, ProbabilityDistribution::exponential, *avg1);
        },
        chi2Result,
        ksResult
	);
}

void Fitter::fitErlang(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *avg, double *m) {

    double mean = _statistic->average();
    double var = _statistic->variance();

    *m = mean / var;
    *avg = floor(mean * (*m));

    if (*avg > 0 && *m > 0 ) {
        fitGeneric(histogramClasses,
            [this, avg, m](BasicAnalysisResult res) {
                
                return res;
            },
            [this, avg, m](double li, double ls) {
                return integrator->integrate(li, ls, ProbabilityDistribution::erlang, *avg, *m);
            },
            chi2Result,
            ksResult
        );
    }
}

void Fitter::fitBeta(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *alpha, double *beta, 
                    double *infLimit, double *supLimit) {
    
    fitGeneric(histogramClasses,
        [this, alpha, beta](BasicAnalysisResult res) {
            double mean = _statistic->average();
            double variance = _statistic->variance();            
            *alpha = mean * ((mean * (1-mean) / variance) - 1);
            *beta = (1 - mean) * ((mean * (1-mean) / variance) - 1);
            
            return res;
        },
        [this, alpha, beta](double li, double ls) {
            return integrator->integrate(li, ls, ProbabilityDistribution::beta, *alpha, *beta);
        },
        chi2Result,
        ksResult
    );

}

/*
 Essa função não realiza o cálculo do alpha e scale, sendo portanto necessário passar esses parâmetros.
*/
void Fitter::fitWeibull(unsigned int histogramClasses, 
                    HypothesisTester_if::TestResult *chi2Result, 
                    HypothesisTester_if::TestResult *ksResult, 
                    double *alpha, double *scale) {

    _collector.sort();

    fitGeneric(histogramClasses,
        [this, alpha, scale](BasicAnalysisResult res) {
            // *alpha = _statistic->average();
            // *scale = 0;
            
            // double p = log(2);

            // for (int i = 0; i < _collector.getSize(); i++) {
            //     *scale += pow(_collector.getValue(i) / *alpha, p);
            // }
            
            // *scale = pow(*scale / _collector.getSize(), 1 / p);
            
            return res;
        },
        [this, alpha, scale](double li, double ls) {
            return integrator->integrate(li, ls, ProbabilityDistribution::weibull, *alpha, *scale);
        },
        chi2Result,
        ksResult
    );
}

void Fitter::fitGeneric(unsigned int histogramClasses, 
                        std::function<BasicAnalysisResult(BasicAnalysisResult)> gatherStats, 
                        std::function<double(double, double)> integrate, 
                        HypothesisTester_if::TestResult *chi2Result,
                        HypothesisTester_if::TestResult *ksResult) { 

    BasicAnalysisResult analysis = basicAnalysis(histogramClasses);

    analysis = gatherStats(analysis);
    
    std::vector<double> expectedFrequencies;
    std::vector<double> observedFrequencies;
    
    std::vector<double> accumf1;
    std::vector<double> accumf2;
    
    double cumulativeProbability = 0;
    double cumulativeObservedFrequence = 0;

    for (int i = 0; i < analysis.classes.size(); i++) {
        double li = analysis.min + analysis.rangePerClass * i;
        double ls = analysis.min + analysis.rangePerClass * (i + 1);
        
        double classProbability = integrate(li, ls);
        cumulativeProbability += classProbability;

        double expectedFreq = classProbability * _collector.getSize();
        double observedFreq = analysis.classes[i].size();
        
        expectedFrequencies.push_back(expectedFreq);
        observedFrequencies.push_back(observedFreq);

        cumulativeObservedFrequence += observedFreq / (double)_collector.getSize();
        accumf1.push_back(cumulativeProbability);
        accumf2.push_back(cumulativeObservedFrequence);
    }

    // for (int i = 0; i < observedFrequencies.size(); ++i) {
    //     std::cout << observedFrequencies[i] << std::endl;
    // }
    // std::cout << "----------------" << std::endl;
    // for (int i = 0; i < expectedFrequencies.size(); ++i) {
    //     std::cout << expectedFrequencies[i] << std::endl;
    // }

    // std::cout << "Cumulative observed ----------------" << std::endl;
    // for (int i = 0; i < accumf2.size(); ++i) {
    //     std::cout << accumf2[i] << std::endl;
    // }

    // std::cout << "Cumulative Expected ----------------" << std::endl;
    // for (int i = 0; i < accumf1.size(); ++i) {
    //     std::cout << accumf1[i] << std::endl;
    // }

    *chi2Result = HypothesisTesterDefaultImpl1::testChiSquare(observedFrequencies, expectedFrequencies, _confidenceLevel, 0);
    *ksResult = HypothesisTesterDefaultImpl1::testKolmogorovSmirnov(accumf1, accumf2, _confidenceLevel);
    
}

Fitter::BasicAnalysisResult Fitter::basicAnalysis(unsigned int histogramClasses) {
    BasicAnalysisResult result;        

    _collector.sort();
    
    result.min = _collector.getValue(0);
    result.max = _collector.getLastValue();
    
    result.amplitude = result.max - result.min;
    result.rangePerClass = result.amplitude / histogramClasses;
    
    result.classes = gatherClasses(histogramClasses);
    
    return result;
}

std::vector<std::vector<double>> Fitter::gatherClasses(unsigned int numberOfClasses) {
    _collector.sort();

    double min = _collector.getValue(0);
    double max = _collector.getLastValue();
    
    double amplitude = max - min;
    double rangePerClass = amplitude / numberOfClasses;
    
    std::vector<std::vector<double>> classes;
    double classStart = min;
    std::vector<double> currClass;

    for (int i = 0; i < _collector.getSize(); i++) {
        double currElement = _collector.getValue(i);
        
        if (i == _collector.getSize() - 1) {
            currClass.push_back(currElement);
            classes.push_back(currClass);
            continue;
        }
        
        if (currElement < classStart + rangePerClass) {
            currClass.push_back(currElement);
            continue;
        }
        
        classes.push_back(currClass);
        classStart += rangePerClass;
        currClass.clear();
        currClass.push_back(currElement);
    }

    return classes;
}

void Fitter::fitAll(unsigned int histogramClasses, 
                HypothesisTester_if::TestResult *chi2Result, 
                HypothesisTester_if::TestResult *ksResult, 
                std::string *name) {
    std::map<std::string, FitResult> fitResults;

    HypothesisTester_if::TestResult uniformChi2Result;
    HypothesisTester_if::TestResult uniformKsResult;
    double uniformMin;
    double uniformMax;
    fitUniform(histogramClasses, &uniformChi2Result, &uniformKsResult, &uniformMin, &uniformMax);
    FitResult uniformResult;
    uniformResult.chi2Result = &uniformChi2Result;
    uniformResult.ksResult = &uniformKsResult;
    fitResults["Uniform"] = uniformResult;
    
    HypothesisTester_if::TestResult triangularChi2Result;
    HypothesisTester_if::TestResult triangularKsResult;
    double triangularMin;
    double triangularMo;
    double triangularMax;
    fitTriangular(histogramClasses, &triangularChi2Result, &triangularKsResult, &triangularMin, &triangularMo, &triangularMax);
    FitResult triangularResult;
    triangularResult.chi2Result = &triangularChi2Result;
    triangularResult.ksResult = &triangularKsResult;
    fitResults["Triangular"] = triangularResult;
    
    HypothesisTester_if::TestResult normalChi2Result;
    HypothesisTester_if::TestResult normalKsResult;
    double normalAvg;
    double normalStddev;
    fitNormal(histogramClasses, &normalChi2Result, &normalKsResult, &normalAvg, &normalStddev);
    FitResult normalResult;
    normalResult.chi2Result = &normalChi2Result;
    normalResult.ksResult = &normalKsResult;
    fitResults["Normal"] = normalResult;
    
    HypothesisTester_if::TestResult expoChi2Result;
    HypothesisTester_if::TestResult expoKsResult;
    double expoAvg1;
    fitExpo(histogramClasses, &expoChi2Result, &expoKsResult, &expoAvg1);
    FitResult expoResult;
    expoResult.chi2Result = &expoChi2Result;
    expoResult.ksResult = &expoKsResult;
    fitResults["Expo"] = expoResult;
    
    HypothesisTester_if::TestResult erlangChi2Result;
    HypothesisTester_if::TestResult erlangKsResult;
    double erlangAvg;
    double erlangM;
    fitErlang(histogramClasses, &erlangChi2Result, &erlangKsResult, &erlangAvg, &erlangM);
    FitResult erlangResult;
    erlangResult.chi2Result = &erlangChi2Result;
    erlangResult.ksResult = &erlangKsResult;
    fitResults["Erlang"] = erlangResult;
    
    HypothesisTester_if::TestResult betaChi2Result;
    HypothesisTester_if::TestResult betaKsResult;
    double betaAlpha;
    double betaBeta;
    double betaInfLimit;
    double betaSupLimit;
    fitBeta(histogramClasses, &betaChi2Result, &betaKsResult, &betaAlpha, &betaBeta, &betaInfLimit, &betaSupLimit);
    FitResult betaResult;
    betaResult.chi2Result = &betaChi2Result;
    betaResult.ksResult = &betaKsResult;
    fitResults["Beta"] = betaResult;
    
    HypothesisTester_if::TestResult weibullChi2Result;
    HypothesisTester_if::TestResult weibullKsResult;
    double weibullAlpha;
    double weibullScale;
    fitWeibull(histogramClasses, &weibullChi2Result, &weibullKsResult, &weibullAlpha, &weibullScale);
    FitResult weibullResult;
    weibullResult.chi2Result = &weibullChi2Result;
    weibullResult.ksResult = &weibullKsResult;
    fitResults["Weibull"] = weibullResult;
    
    double bestPvalue = std::numeric_limits<double>::min();
    for (auto it = fitResults.begin(); it != fitResults.end(); ++it) {
        std::string method = it->first;
        FitResult result = it->second;

        double pValue = result.chi2Result->pValue();
        if (pValue > bestPvalue) {
            if (chi2Result->acceptH0() == 1) {
                if (result.chi2Result->acceptH0() == 1) {
                    bestPvalue = pValue;
                    *name = method;
                    *chi2Result = *result.chi2Result;
                    *ksResult = *result.ksResult;
                }
            } else {
                bestPvalue = pValue;
                *name = method;
                *chi2Result = *result.chi2Result;
                *ksResult = *result.ksResult;
            }
        }
    }
}

void Fitter::setStatistics(StatisticsDatafile_if* statistic) {
    _statistic = statistic;
}

void Fitter::setCollector(CollectorOutputAnalyser& collector) {
    _collector = collector;
}

void Fitter::setConfidenceLevel(double confidenceLevel) {
    _confidenceLevel = confidenceLevel;
}

double Fitter::getConfidenceLevel() {
    return _confidenceLevel;
}