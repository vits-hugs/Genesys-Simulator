/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Traits.h
 * Author: rafael.luiz.cancian
 *
 * Created on 14 de Agosto de 2018, 19:36
 */

#ifndef TRAITS_H
#define TRAITS_H

#include "kernel/util/Util.h"
// USER INTERFACES
#include "userInterfaces/terminal/GenesysTerminalApp.h"
#include "userInterfaces/gui/qt/GenesysQtGUI.h"
// BOOK
#include "userInterfaces/examples/book/Book_Cap02_Example01.h"
// SMARTS
#include "userInterfaces/examples/Example_Dummy.h"
#include "userInterfaces/examples/Example_Delay.h"
#include "userInterfaces/examples/Example_ModelInfoModelSimulation.h"
#include "userInterfaces/examples/Example_Process.h"
#include "userInterfaces/examples/Example_ProcessSet.h"
#include "userInterfaces/examples/Example_SeizeDelayRelease.h"
#include "userInterfaces/examples/Example_SeizeDelayReleaseMany.h"
#include "userInterfaces/examples/Example_RouteStation.h"
#include "userInterfaces/examples/Example_Sequence.h"
#include "userInterfaces/examples/Example_HoldSignal.h"
// TEACHING
#include "userInterfaces/examples/AnElectronicAssemblyAndTestSystem.h"
//#include "userInterfaces/examples/Example_SistemaOperacional03.h"

#include "tools/SolverDefaultImpl1.h"
#include "tools/HypothesisTesterDefaultImpl1.h"
#include "tools/HypothesisTester_if.h"

template <typename T>
struct Traits {
};

/*
 *  Genesys Application
 */

template <> struct Traits<GenesysApplication_if> {
	static const Util::TraceLevel traceLevel = Util::TraceLevel::L6_arrival;
	//// SMART EXAMPLES SORTED
	//typedef Example_Delay Application;
	//typedef Example_ModelInfoModelSimulation Application;
	//typedef Example_Process Application;
	//typedef Example_ProcessSet Application;
	//typedef Example_SeizeDelayRelease Application;
	//typedef Example_SeizeDelayReleaseMany Application;
	//typedef Example_RouteStation Application;
	//typedef Example_Sequence Application;
	typedef Example_HoldSignal Application;

	//// USER INTERFACES
	//typedef GenesysTerminalApp Application;
	//typedef GenesysQtGUI Application;

};

template <> struct Traits<Solver_if> {
	typedef SolverDefaultImpl1 Implementation;
	static constexpr double Precision = 1e-5;
	static constexpr unsigned int MaxSteps = 1e2;
};

template <> struct Traits<HypothesisTester_if> {
	typedef HypothesisTesterDefaultImpl1 Implementation;
	static constexpr unsigned int ConfidenceLevel = 95;
};
#endif /* TRAITS_H */

