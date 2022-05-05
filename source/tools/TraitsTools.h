/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   TraitsTools.h
 * Author: rlcancian
 *
 * Created on 3 de maio de 2022, 18:57
 */

#ifndef TRAITSTOOLS_H
#define TRAITSTOOLS_H

// TOOLS
#include "SolverDefaultImpl1.h"
#include "HypothesisTesterDefaultImpl1.h"
#include "HypothesisTester_if.h"

template <typename T>
struct Traits {
};

/*!
 *  Configure the Solver to be used
 */
template <> struct Traits<Solver_if> {
	typedef SolverDefaultImpl1 Implementation;
	static constexpr double Precision = 1e-5;
	static constexpr unsigned int MaxSteps = 1e2;
};

/*!
 *  Configure the Hypothesis Tester to be used
 */
template <> struct Traits<HypothesisTester_if> {
	typedef HypothesisTesterDefaultImpl1 Implementation;
	static constexpr unsigned int ConfidenceLevel = 95;
};

#endif /* TRAITSTOOLS_H */

