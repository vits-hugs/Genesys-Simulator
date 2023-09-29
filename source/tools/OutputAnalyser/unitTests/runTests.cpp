#include <cassert>
#include <string>
#include <vector>
#include "../OutputAnalyser.h"
#include "test.h"

using namespace std;

int totalErrors;
int size;
StatisticsDatafile_if* ss;
HypothesisTester_if* tester;
CollectorOutputAnalyser* collector;
Fitter_if* fitter;

void ss_min() {
    totalErrors += TEST_EQUAL_FP(ss->min(), 25.51, "Mínimo");
}

void ss_max() {
    totalErrors += TEST_EQUAL_FP(ss->max(),  74.94, "Máximo");
}

void ss_average() {
    totalErrors += TEST_EQUAL_FP(ss->average(), 50.4078, "Média");
}

void ss_variance() {
    totalErrors += TEST_EQUAL_FP(ss->variance(), 87.7589, "Variância");
}

void ss_stddeviation() {
    totalErrors += TEST_EQUAL_FP(ss->stddeviation(), 9.3679, "Desvio padrão");
}

void ss_variationCoef() {
    totalErrors += TEST_EQUAL_FP(ss->variationCoef(), 0.1858, "Coeficiente de variância");
}

void ss_mode() {
    totalErrors += TEST_EQUAL_FP(ss->mode(), 40.07, "Moda");
}

void ss_mediane() {
    totalErrors += TEST_EQUAL_FP(ss->mediane(), 50.73, "Mediana");
}

void ss_quartil() {
    totalErrors += TEST_EQUAL_FP(ss->quartil(1), 43.58, "Quartil Q1");
    totalErrors += TEST_EQUAL_FP(ss->quartil(2), 50.67, "Quartil Q2");
    totalErrors += TEST_EQUAL_FP(ss->quartil(3), 56.13, "Quartil Q3");
}

void ss_averageInterval() {
    auto avgInterval = tester->averageConfidenceInterval(ss->average(), ss->stddeviation(), collector->numElements(), 0.95);
    totalErrors += TEST_EQUAL_FP(avgInterval.inferiorLimit(), 49.1015, "Intervalo de confiança da média: limite inferior");
    totalErrors += TEST_EQUAL_FP(avgInterval.superiorLimit(), 51.7141, "Intervalo de confiança da média: limite superior");
}

void ss_varianceInterval() {
    auto varInterval = tester->varianceConfidenceInterval(ss->variance(), collector->numElements(), 0.95);
    totalErrors += TEST_EQUAL_FP(varInterval.inferiorLimit(), 72.7790, "Intervalo de confiança da variância: limite inferior");
    totalErrors += TEST_EQUAL_FP(varInterval.superiorLimit(), 107.9184, "Intervalo de confiança da variância: limite superior");
}

void ss_proportionInterval() {
    auto propInterval = tester->proportionConfidenceInterval(0.6, collector->numElements(), 0.95);
    totalErrors += TEST_EQUAL_FP(propInterval.inferiorLimit(), 0.5316, "Intervalo de confiança da proporção: limite inferior");
    totalErrors += TEST_EQUAL_FP(propInterval.superiorLimit(), 0.6683, "Intervalo de confiança da proporção: limite superior");
}

void ss_averageDifferenceConfidenceInterval() {
    // Valores iguais aos utilizados nos testes dos trabalhos disponibilizados.
    auto ci = tester->averageDifferenceConfidenceInterval(-50.0, 5, 30, -55, 5.5, 60, 0.95);
    totalErrors += TEST_EQUAL_FP(ci.inferiorLimit(), 2.6268777282956, "Intervalo de confiança da diferença da média: limite inferior");
    totalErrors += TEST_EQUAL_FP(ci.superiorLimit(), 7.3731222717044, "Intervalo de confiança da diferença da média: limite superior");

    ci = tester->averageDifferenceConfidenceInterval(-150.0, 15, 80, -180, 30, 65, 0.80);
    totalErrors += TEST_EQUAL_FP(ci.inferiorLimit(), 24.7315108021291, "Intervalo de confiança da diferença da média: limite inferior");
    totalErrors += TEST_EQUAL_FP(ci.superiorLimit(), 35.2684891978709, "Intervalo de confiança da diferença da média: limite superior");
}

void ss_estimateSampleSize() {
    // Valores iguais aos utilizados nos testes dos trabalhos disponibilizados.
    unsigned int n = tester->estimateSampleSize(10.0, 5.0, 30, 1.0, 0.95);
    totalErrors += TEST_EQUAL<unsigned int>(n, 105, "Tamanho estimado da amostra");
}

void ss_movingAverage() {
    // Read expected results
    ifstream expectedResultsFile("../../../source/tools/OutputAnalyser/Files/movingAverage");
    std::vector<double> expectedResults;
    double value;
    while (expectedResultsFile >> value) 
        expectedResults.push_back(value);
    
    auto results = ss->movingAverage(5);

    std::cout << " -------------- Testes de média móvel --------------" << "\n";
    for (size_t i = 0; i < results.size(); i++)  {
        std::string description = "Index " + to_string(i);
        totalErrors += TEST_EQUAL_FP(results[i], expectedResults[i], description);
    }
    cout << "\n";

    expectedResultsFile.close();
}

void testChi2() {
    cout << "-------------- TEST CHI2 --------------" << endl;
    std::vector<double> observedFreq = {10, 20, 30, 40, 30, 20, 10};
    std::vector<double> expectedFreq = {07, 25, 35, 35, 40, 22, 8};
    HypothesisTester_if::TestResult tr = HypothesisTesterDefaultImpl1::testChiSquare(observedFreq, expectedFreq, 0.8, 0);
    totalErrors += TEST_EQUAL_FP(tr.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.pValue(), 0.330562489132277, "p-value");
    totalErrors += TEST_EQUAL_FP(tr.testStat(), 6.8961038961039, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceInferiorLimit(), std::numeric_limits<double>::min(), "limite inferior da região de aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceSuperiorLimit(), 8.55805972025067, "limite superior da região de aceitação de H0");
    observedFreq = {320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320};
    expectedFreq = {300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300};
    tr = HypothesisTesterDefaultImpl1::testChiSquare(observedFreq, expectedFreq, 0.85, 0);
    totalErrors += TEST_EQUAL_FP(tr.acceptH0(), false, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.pValue(), 0.137482779951782, "p-value");
    totalErrors += TEST_EQUAL_FP(tr.testStat(), 17.3333333333333, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceInferiorLimit(), std::numeric_limits<double>::min(), "limite inferior da região de aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceSuperiorLimit(), 16.9893066811649, "limite superior da região de aceitação de H0");
}

void testKolmogorovSmirnov() {
    cout << "-------------- TEST KOLMOGOROV SMIRNOV --------------" << endl;
    std::vector<double> accumF1 = {0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
    std::vector<double> accumF2 = {3.39767312473006E-06, 3.167124183312E-05, 0.000232629079035526, 0.0013498980316301, 0.00620966532577614, 0.0227501319481792, 0.0668072012688581, 0.158655253931457, 0.308537538725987, 0.5, 0.691462461274013, 0.841344746068543, 0.933192798731142, 0.977249868051821, 0.993790334674224, 0.99865010196837, 0.999767370920964, 0.999968328758167, 0.999996602326875, 0.999999713348428, 0.999999981010438};
    HypothesisTester_if::TestResult tr = HypothesisTesterDefaultImpl1::testKolmogorovSmirnov(accumF1, accumF2, 0.8);
    totalErrors += TEST_EQUAL_FP(tr.acceptH0(), false, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.testStat(), 0.333192798731142, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceInferiorLimit(), std::numeric_limits<double>::min(), "limite inferior da região de aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceSuperiorLimit(), 0.331129746761285, "limite superior da região de aceitação de H0");
    accumF1 = {0.000122866389965152, 0.000429060333196837, 0.0013498980316301, 0.00383038056758974, 0.00981532862864534, 0.0227501319481792, 0.0477903522728147, 0.0912112197258679, 0.158655253931457, 0.252492537546923, 0.369441340181764, 0.5, 0.630558659818236, 0.747507462453077, 0.841344746068543, 0.908788780274132, 0.952209647727185, 0.977249868051821, 0.990184671371355, 0.99616961943241, 0.99865010196837, 0.999570939666803, 0.999877133610035, 0.999968328758167, 0.999992656576163};
    accumF2 = {0.000369078454275068, 0.000889025299108434, 0.002020137489946, 0.00433244836301256, 0.00877447509573837, 0.0167933064484488, 0.0303963617652614, 0.0520812794152196, 0.0845657223513357, 0.130294517136809, 0.190786952852511, 0.265985529048701, 0.353830233327276, 0.450261775169887, 0.549738224830113, 0.646169766672724, 0.734014470951299, 0.809213047147489, 0.869705482863191, 0.915434277648664, 0.94791872058478, 0.969603638234739, 0.983206693551551, 0.991225524904262, 0.995667551636987};
    tr = HypothesisTesterDefaultImpl1::testKolmogorovSmirnov(accumF1, accumF2, 0.85);
    totalErrors += TEST_EQUAL_FP(tr.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.testStat(), 0.29724568728319, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceInferiorLimit(), std::numeric_limits<double>::min(), "limite inferior da região de aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceSuperiorLimit(), 0.321886139213594, "limite superior da região de aceitação de H0");
}

void testAverage() {
    cout << "-------------- TEST AVERAGE --------------" << endl;
    HypothesisTester_if::TestResult tr = tester->testAverage(5000.0, 200.0, 35u, 5100.0, 400.0, 25u, 0.8, HypothesisTester_if::H1Comparition::DIFFERENT);
    totalErrors += TEST_EQUAL_FP(tr.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.pValue(), 0.128917821318511, "p-value");
    totalErrors += TEST_EQUAL_FP(tr.testStat(), -1.1514154661796, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceInferiorLimit(), -1.30773712445088, "limite inferior da região de aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceSuperiorLimit(), 1.30773712445088, "limite superior da região de aceitação de H0");
    tr = tester->testAverage(20.0, 2.44948974278318, 4u, 21.0, 2.23606797749979, 5u, 0.95, HypothesisTester_if::H1Comparition::DIFFERENT);
    totalErrors += TEST_EQUAL_FP(tr.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.pValue(), 0.271330573334733, "p-value");
    totalErrors += TEST_EQUAL_FP(tr.testStat(), -0.639809913291595, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceInferiorLimit(), -2.36462425159279, "limite inferior da região de aceitação de H0");
}

void testVariance() {
    cout << "-------------- TEST VARIANCE --------------" << endl;
    HypothesisTester_if::TestResult tr = tester->testVariance(72.25, 15u, 100.0, 0.95, HypothesisTester_if::H1Comparition::DIFFERENT);
    totalErrors += TEST_EQUAL<bool>(tr.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.pValue(), 0.246271764239943, "p-value");
    totalErrors += TEST_EQUAL_FP(tr.testStat(), 10.115, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceInferiorLimit(), 5.62872610303973, "limite inferior da região de aceitação de H0");
    totalErrors += TEST_EQUAL_FP(tr.acceptanceSuperiorLimit(), 26.1189480450374, "limite superior da região de aceitação de H0");
}

void fitUniform(Fitter_if * fitter) {
    cout << "-------------- FIT UNIFORM --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double min;
    double max;
    unsigned int k = 11;
    fitter->fitUniform(k, &chi2Result, &ksResult, &min, &max); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 0.50444775796095, "p-value");
    totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 9.294, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptanceInferiorLimit(), 0.0, "limite inferior da região de aceitação de H0");
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptanceSuperiorLimit(), 18.3070380532751, "limite superior da região de aceitação de H0");
    totalErrors += TEST_EQUAL_FP(min, 0.00041851500103784467, "parâmetro 'min' da distribuição");
    totalErrors += TEST_EQUAL_FP(max, 0.9998463710771078, "parâmetro 'max' da distribuição");
    totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.0213636, "estatistica de teste");
    totalErrors += TEST_EQUAL_FP(ksResult.acceptanceSuperiorLimit(), 0.579096432079081, "limite superior da região de aceitação de H0");
}

void fitNormal(Fitter_if * fitter) {
    cout << "-------------- FIT NORMAL --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double avg;
    double stddev;
    unsigned int k = 11;
    fitter->fitNormal(k, &chi2Result, &ksResult, &avg, &stddev); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 0.840640613971903, "p-value");
    totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 5.6895009312752, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.00746128209322899, "estatistica de teste");
    totalErrors += TEST_EQUAL_FP(avg, -0.0308207338485601, "parâmetro 'avg' da distribuição");
    totalErrors += TEST_EQUAL_FP(stddev, 1.0063006022762142, "parâmetro 'stddev' da distribuição");
}

void fitTriangular(Fitter_if * fitter) {
    cout << "-------------- FIT Triangular --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double mo;
    double min;
    double max;
    unsigned int k = 11;
    fitter->fitTriangular(k, &chi2Result, &ksResult, &min, &mo, &max); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 0.16797377, "p-value");
    totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 14.11133072, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.021338309784058, "estatistica de teste");
    totalErrors += TEST_EQUAL_FP(min, 0.21, "estatistica de teste");
    totalErrors += TEST_EQUAL_FP(max, 9.79, "estatistica de teste");
    totalErrors += TEST_EQUAL_FP(mo, 5.17, "estatistica de teste");
}

void fitExpo(Fitter_if * fitter) {
    cout << "-------------- FIT EXPO --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double avg;
    unsigned int k = 11;
    fitter->fitExpo(k, &chi2Result, &ksResult, &avg); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 0.0795165016440853, "p-value");
    totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 16.7740115996267, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.04112703078706, "estatistica de teste");
    totalErrors += TEST_EQUAL_FP(avg, 0.9572135795102974, "parâmetro 'avg' da distribuição");
}

void fitErlang(Fitter_if * fitter) {
    cout << "-------------- FIT ERLANG --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double shape;
    double rate;
    unsigned int k = 11;
    fitter->fitErlang(k, &chi2Result, &ksResult, &shape, &rate); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 0.135246837806501, "p-value");
    totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 12.3748351366633, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.029777845685511, "estatistica de teste");
    totalErrors += TEST_EQUAL_FP(shape, 2, "parâmetro 'shape' da distribuição");
    totalErrors += TEST_EQUAL_FP(rate, 0.9989044994306325, "parâmetro 'rate' da distribuição");
}

void fitBeta(Fitter_if * fitter) {
    cout << "-------------- FIT BETA --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double alpha;
    double beta;
    double infLim;
    double supLim;
    unsigned int k = 11;
    fitter->fitBeta(k, &chi2Result, &ksResult, &alpha, &beta, &infLim, &supLim); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 0.795178034543125, "p-value");
    totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 6.234657415, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.01259551791, "estatistica de teste");
    totalErrors += TEST_EQUAL_FP(alpha, 1.9481060508976555, "parâmetro 'alpha' da distribuição");
    totalErrors += TEST_EQUAL_FP(beta, 4.725406639825216, "parâmetro 'beta' da distribuição");
}

void fitWeibull(Fitter_if * fitter) {
    cout << "-------------- FIT WEIBULL --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double alpha = 2.0;
    double scale = 1.0;
    unsigned int k = 11;
    fitter->fitWeibull(k, &chi2Result, &ksResult, &alpha, &scale); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 0.511478019891339, "p-value");
    totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 8.22663717694809, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.026543272048204, "estatistica de teste");
}

void fitAll(Fitter_if * fitter) {
    cout << "-------------- FIT ALL --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    unsigned int k = 11;
    string name;
    fitter->fitAll(k, &chi2Result, &ksResult, &name);
    totalErrors += TEST_EQUAL<string>(name, "Normal", "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 0.840640613971903, "p-value");
    totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 5.6895009312752, "estatística de teste");
    totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.00746128209322899, "estatistica de teste");
}

int runStatisticsTest() {
    cout << "-------------- Statistical Synthesis --------------" << endl;
    ss_min();
    ss_max();
    ss_average();
    ss_variance();
    ss_stddeviation();
    ss_variationCoef();
    ss_mode();
    ss_mediane();
    ss_quartil();
    ss_averageInterval();
    ss_varianceInterval();
    ss_proportionInterval();
    ss_averageDifferenceConfidenceInterval();
    ss_estimateSampleSize();
    ss_movingAverage();

    return 0;
}

int runHypotesesTest() {

    testChi2();
    testKolmogorovSmirnov();
    testAverage();
    testVariance();

    return 0;
}

int runFitterTest() {
    auto outputAnalyser = OutputAnalyser("../../../source/tools/OutputAnalyser/Files/UniformDist.txt");
    outputAnalyser.setReplication(1);
    fitter = outputAnalyser.fitter();

    fitUniform(fitter);

    outputAnalyser.loadDataSet("../../../source/tools/OutputAnalyser/Files/NormalDist.txt");
    fitNormal(fitter);

    outputAnalyser.loadDataSet("../../../source/tools/OutputAnalyser/Files/TriangularDist.txt");
    fitTriangular(fitter);

    outputAnalyser.loadDataSet("../../../source/tools/OutputAnalyser/Files/ExpoDist.txt");
    fitExpo(fitter);

    outputAnalyser.loadDataSet("../../../source/tools/OutputAnalyser/Files/ErlangDist.txt");
    fitErlang(fitter);

    outputAnalyser.loadDataSet("../../../source/tools/OutputAnalyser/Files/BetaDist.txt");
    fitBeta(fitter);

    /*
    O fitWeibul não funciona completamente, nele são necessários passar os parâmetros alpha e scale
    */
    outputAnalyser.loadDataSet("../../../source/tools/OutputAnalyser/Files/WeibullDist.txt");
    fitWeibull(fitter);

    outputAnalyser.loadDataSet("../../../source/tools/OutputAnalyser/Files/NormalDist.txt");
    fitAll(fitter);

    return 0;
}

void runCorrelogramTest() {
    cout << "-------------- AUTOCORRELOGRAM --------------" << endl;
    auto outputAnalyser = OutputAnalyser("../../../source/tools/OutputAnalyser/Files/CorrelogramTest.txt");
    outputAnalyser.setReplication(1);

    auto correlogram = outputAnalyser.getCorrelogram(0.0, -1, 1);

    std::vector<double> autocorrelation = correlogram.getAutoCorrelation();

    std::vector<double> generatedData = {1.0, 0.07327, 0.01341, -0.03866, 0.13065, -0.05907, -0.00449,
                                         0.08829, -0.0569, 0.03173, 0.07153, 0.05066, 0.0143, 0.07438,
                                         -0.01216, -0.1384, 0.00386, 0.02552, -0.11688, -0.00175, 0.06562,
                                         -0.02562, -0.08905, -0.10885, -0.1966, -0.016};
    for (int i = 0; i < autocorrelation.size(); ++i) {
        totalErrors += TEST_EQUAL_FP(autocorrelation[i],generatedData[i],"correlogram value",1e5);
    }
}

int main() {
    auto outputAnalyser = OutputAnalyser("../../../source/tools/OutputAnalyser/Files/normalDist_genesys");
    outputAnalyser.setReplication(1);

    ss = outputAnalyser.statisticsDataFile();
    tester = outputAnalyser.tester();
    collector = outputAnalyser.collector();

    runStatisticsTest();
    runHypotesesTest();
    runFitterTest();
    runCorrelogramTest();

    if (totalErrors == 0)
        cout << "Succesfully runned all unit tests" << endl;
    else
        cout << "Total errors: " << totalErrors << endl;
    return 0;
}
