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

#include "../kernel/util/Util.h"
// TERMINAL USER INTERFACES
#include "terminal/GenesysTerminalApp.h"
//
// EXAMPLES
//
// book
#include "../examples/book/Book_Cap02_Example01.h"
// smarts
#include "../examples/smarts/Smart_AssignWriteSeizes.h"
#include "../examples/smarts/Smart_BatchSeparate.h"
#include "../examples/smarts/Smart_Delay.h"
#include "../examples/smarts/Smart_Dummy.h"
#include "../examples/smarts/Smart_HoldSignal.h"
#include "../examples/smarts/Smart_ModelInfoModelSimulation.h"
#include "../examples/smarts/Smart_ODE.h"
#include "../examples/smarts/Smart_OnEvent.h"
#include "../examples/smarts/Smart_Parser.h"
#include "../examples/smarts/Smart_ParserModelFunctions.h"
#include "../examples/smarts/Smart_Plugin.h"
#include "../examples/smarts/Smart_Process.h"
#include "../examples/smarts/Smart_ProcessSet.h"
#include "../examples/smarts/Smart_RouteStation.h"
#include "../examples/smarts/Smart_SeizeDelayRelease.h"
#include "../examples/smarts/Smart_SeizeDelayReleaseMany.h"
#include "../examples/smarts/Smart_Sequence.h"
#include "../examples/smarts/Smart_CppForG.h"
// teachng
#include "../examples/teaching/AnElectronicAssemblyAndTestSystem.h"
#include "../examples/teaching/OperatingSystem02.h"
#include "../examples/teaching/OperatingSystem03.h"

template <typename T>
struct TraitsApp {
};
/*!
 *  Configure the Genesys Application to be compiled and executed
 */
template <> struct TraitsApp<GenesysApplication_if> {
	static const Util::TraceLevel traceLevel = Util::TraceLevel::L6_arrival;

	//// SMART SMART_S SORTED
	//typedef Smart_AssignWriteSeizes Application;
	//typedef Smart_BatchSeparate Application;
	//typedef Smart_Delay Application;
	//typedef Smart_Dummy Application;
	//typedef Smart_HoldSignal Application;
	//typedef Smart_ModelInfoModelSimulation Application;
	//typedef Smart_ODE Application;
	//typedef Smart_OnEvent Application;
	//typedef Smart_Parser Application;
	typedef Smart_ParserModelFunctions Application;
	//typedef Smart_Plugin Application;
	//typedef Smart_Process Application;
	//typedef Smart_ProcessSet Application;
	//typedef Smart_RouteStation Application;
	//typedef Smart_SeizeDelayRelease Application;
	//typedef Smart_SeizeDelayReleaseMany Application; 
	//typedef Smart_Sequence Application;
	//typedef Smart_CppForG Application;

	//// TEACHING
	//typedef AnElectronicAssemblyAndTestSystem Application;
	//typedef OperatingSystem02 Application;
	////	typedef OperatingSystem03 Application;

	//// TERMINAL APPLICATIONS
	//typedef GenesysTerminalApp Application;
};

#endif /* TRAITS_H */

