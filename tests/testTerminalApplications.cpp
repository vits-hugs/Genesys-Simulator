/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   testTerminalApplications.cpp
 * Author: rlcancian
 *
 * Created on 24 de maio de 2022, 21:13
 */

#include <cstdlib>

#include "../source/applications/terminal/examples/smarts/Smart_AssignWriteSeizes.h"
#include "../source/applications/terminal/examples/smarts/Smart_BatchSeparate.h"
#include "../source/applications/terminal/examples/smarts/Smart_CellularAutomata1.h"
#include "../source/applications/terminal/examples/smarts/Smart_CppForG.h"
#include "../source/applications/terminal/examples/smarts/Smart_Delay.h"
#include "../source/applications/terminal/examples/smarts/Smart_Dummy.h"
#include "../source/applications/terminal/examples/smarts/Smart_WaitSignal.h"
#include "../source/applications/terminal/examples/smarts/Smart_ModelInfoModelSimulation.h"
#include "../source/applications/terminal/examples/smarts/Smart_ODE.h"
#include "../source/applications/terminal/examples/smarts/Smart_OnEvent.h"
#include "../source/applications/terminal/examples/smarts/Smart_Parser.h"
#include "../source/applications/terminal/examples/smarts/Smart_ParserModelFunctions.h"
#include "../source/applications/terminal/examples/smarts/Smart_Plugin.h"
#include "../source/applications/terminal/examples/smarts/Smart_Process.h"
#include "../source/applications/terminal/examples/smarts/Smart_ProcessSet.h"
#include "../source/applications/terminal/examples/smarts/Smart_RouteStation.h"
#include "../source/applications/terminal/examples/smarts/Smart_SeizeDelayRelease.h"
#include "../source/applications/terminal/examples/smarts/Smart_SeizeDelayReleaseMany.h"
#include "../source/applications/terminal/examples/smarts/Smart_SeizeDelayReleaseNoDataDefs.h"
#include "../source/applications/terminal/examples/smarts/Smart_Sequence.h"

using namespace std;

/*
 * 
 */
//int maintestTerminalApplications(int argc, char** argv) {

int __main(int argc, char** argv) {
	GenesysApplication_if* app;
	app = new Smart_AssignWriteSeizes();
	app->main(argc, argv);
	app = new Smart_BatchSeparate();
	app->main(argc, argv);
	//app = new Smart_CellularAutomata1();
	//app->main(argc, argv);
	app = new Smart_CppForG();
	app->main(argc, argv);
	app = new Smart_Delay();
	app->main(argc, argv);
	app = new Smart_Dummy();
	app->main(argc, argv);
	app = new Smart_WaitSignal();
	app->main(argc, argv);
	app = new Smart_ModelInfoModelSimulation();
	app->main(argc, argv);
	app = new Smart_ODE();
	app->main(argc, argv);
	app = new Smart_OnEvent();
	app->main(argc, argv);
	app = new Smart_Parser();
	app->main(argc, argv);
	app = new Smart_ParserModelFunctions();
	app->main(argc, argv);
	app = new Smart_Plugin();
	app->main(argc, argv);
	app = new Smart_Process();
	app->main(argc, argv);
	app = new Smart_ProcessSet();
	app->main(argc, argv);
	app = new Smart_RouteStation();
	app->main(argc, argv);
	app = new Smart_SeizeDelayRelease();
	app->main(argc, argv);
	app = new Smart_SeizeDelayReleaseMany();
	app->main(argc, argv);
	app = new Smart_SeizeDelayReleaseNoDataDefs();
	app->main(argc, argv);
	app = new Smart_Sequence();
	app->main(argc, argv);
	return 0;
}

