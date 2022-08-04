/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SamplerDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 2 de Agosto de 2018, 01:10
 */

#ifndef SAMPLERDEFAULTIMPL1_H
#define SAMPLERDEFAULTIMPL1_H

#include "Sampler_if.h"
#include <stdint.h>

//namespace GenesysKernel {

class SamplerDefaultImpl1 : public Sampler_if {
public:

	struct DefaultImpl1RNG_Parameters : public RNG_Parameters {
		uint32_t seed = 16021974;
		uint32_t a = 279470273u; // multiplier
		uint32_t m = 0xfffffffb; // module
		uint32_t c = 0; // increment
		~DefaultImpl1RNG_Parameters() = default;
	};
public:
	SamplerDefaultImpl1();
	virtual ~SamplerDefaultImpl1() = default;
public: // RNG
	virtual double random();
public: // continuous probability distributions
	virtual double sampleBeta(double alpha, double beta, double infLimit, double supLimit);
	virtual double sampleBeta(double alpha, double beta);
	virtual double sampleErlang(double mean, int M, double offset = 0.0);
	virtual double sampleExponential(double mean, double offset = 0.0);
	//virtual double sampleGamma(double mean, double alpha, double offset=0.0);
	virtual double sampleGamma(double alpha, double beta, double offset = 0.0);
	virtual double sampleGumbell(double mode, double scale);
	virtual double sampleLogNormal(double mean, double stddev, double offset = 0.0);
	virtual double sampleNormal(double mean, double stddev);
	virtual double sampleTriangular(double min, double mode, double max);
	virtual double sampleUniform(double min, double max);
	virtual double sampleWeibull(double alpha, double scale);
public: // discrete probability distributions
	//TODO: Poisson, si vous plait!!!!
	virtual double sampleBinomial(int trials, double p);
	virtual double sampleBernoulli(double p);
	virtual double sampleDiscrete(double prob, double value, ...);
	virtual double sampleDiscrete(double *prob, double *value, int size);
	virtual double sampleGeometric(double p);
public:
	void reset(); ///< reinitialize seed and other parameters so (pseudo) random number sequence will be generated again.
public:
	virtual void setRNGparameters(RNG_Parameters* param);
	virtual RNG_Parameters* getRNGparameters() const;
private:
	RNG_Parameters* _param = new DefaultImpl1RNG_Parameters();
	uint32_t _xi;
	bool _normalflag;
	double _lastnormal;
};
//namespace\\}
#endif /* SAMPLERDEFAULTIMPL1_H */

