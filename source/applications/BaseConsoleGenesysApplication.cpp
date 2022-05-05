/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseConsoleGenesysApplication.cpp
 * Author: rlcancian
 * 
 * Created on 3 de Setembro de 2019, 16:25
 */

#include "BaseConsoleGenesysApplication.h"
#include <iostream>

#include "../kernel/simulator/Simulator.h"

BaseConsoleGenesysApplication::BaseConsoleGenesysApplication() {
}


// default Trace Handlers

void BaseConsoleGenesysApplication::traceHandler(TraceEvent e) {
	std::cout << e.getText() << std::endl;
}

void BaseConsoleGenesysApplication::traceErrorHandler(TraceErrorEvent e) {
	std::cout << e.getText() << std::endl;
}

void BaseConsoleGenesysApplication::traceReportHandler(TraceEvent e) {
	std::cout << "" << e.getText() << "" << std::endl;
}

void BaseConsoleGenesysApplication::traceSimulationHandler(TraceSimulationEvent e) {
	std::cout << e.getText() << std::endl;
}


// default Event Handlers

void BaseConsoleGenesysApplication::onBreakpointHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Breakpoint occured at time " << std::to_string(re->getSimulatedTime()) << std::endl;
}

void BaseConsoleGenesysApplication::onEntityCreateHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Entity " << re->getEntityCreated()->getName() << " was created." << std::endl;
}

void BaseConsoleGenesysApplication::onEntityMoveHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Entity " << re->getCurrentEvent()->getEntity()->getName() << " was moved to component" << re->getDestinationComponent()->getName() << std::endl;
}

void BaseConsoleGenesysApplication::onEntityRemoveHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Entity " << re->getCurrentEvent()->getEntity()->getName() << " was removed." << std::endl;
}

void BaseConsoleGenesysApplication::onProcessEventHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Processing event " << re->getCurrentEvent()->show() << std::endl;
}

void BaseConsoleGenesysApplication::onReplicationEndHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Replication " << re->getCurrentReplicationNumber() << " ending." << std::endl;
}

void BaseConsoleGenesysApplication::onReplicationStartHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Replication " << re->getCurrentReplicationNumber() << " starting." << std::endl;
}

void BaseConsoleGenesysApplication::onReplicationStepHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Replication step at time " << std::to_string(re->getSimulatedTime()) << std::endl;
}

void BaseConsoleGenesysApplication::onSimulationStartHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Simulation is starting" << std::endl;
}

void BaseConsoleGenesysApplication::onSimulationEndHandler(SimulationEvent* re) {
	std::cout << "Event (Handler) " << "Replication " << re->getCurrentReplicationNumber() << " ending." << std::endl;
}

void BaseConsoleGenesysApplication::onSimulationPausedHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Simulation was paused at time " << std::to_string(re->getSimulatedTime()) << std::endl;
}

void BaseConsoleGenesysApplication::onSimulationResumeHandler(SimulationEvent* re) {
	std::cout << "(Event Handler) " << "Simulation was resumed." << std::endl;
}

void BaseConsoleGenesysApplication::setDefaultEventHandlers(OnEventManager* oem) {
	oem->addOnBreakpointHandler(this, &BaseConsoleGenesysApplication::onBreakpointHandler);
	oem->addOnEntityCreateHandler(this, &BaseConsoleGenesysApplication::onEntityCreateHandler);
	oem->addOnEntityMoveHandler(this, &BaseConsoleGenesysApplication::onEntityMoveHandler);
	oem->addOnEntityRemoveHandler(this, &BaseConsoleGenesysApplication::onEntityRemoveHandler);
	oem->addOnProcessEventHandler(this, &BaseConsoleGenesysApplication::onProcessEventHandler);
	oem->addOnReplicationEndHandler(this, &BaseConsoleGenesysApplication::onReplicationEndHandler);
	oem->addOnReplicationStartHandler(this, &BaseConsoleGenesysApplication::onReplicationStartHandler);
	oem->addOnReplicationStepHandler(this, &BaseConsoleGenesysApplication::onReplicationStepHandler);
	oem->addOnSimulationEndHandler(this, &BaseConsoleGenesysApplication::onSimulationEndHandler);
	oem->addOnSimulationPausedHandler(this, &BaseConsoleGenesysApplication::onSimulationPausedHandler);
	oem->addOnSimulationResumeHandler(this, &BaseConsoleGenesysApplication::onSimulationResumeHandler);
	oem->addOnSimulationStartHandler(this, &BaseConsoleGenesysApplication::onSimulationStartHandler);
}

void BaseConsoleGenesysApplication::setDefaultTraceHandlers(TraceManager* tm) {
	tm->addTraceHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceHandler);
	tm->addTraceErrorHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceErrorHandler);
	tm->addTraceReportHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceReportHandler);
	tm->addTraceSimulationHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceSimulationHandler);
}

void BaseConsoleGenesysApplication::insertFakePluginsByHand(Simulator* simulator) {
	PluginManager* pm = simulator->getPlugins();
	// TRYING SOME NEW ORGANIZATION (BASED ON ARENA 16..20)

	// DISCRETE PROCESSING

	// GROUPING

	//INPUT/OUTPUT

	// MATERIAL HANDLING

	// CONTINUOS

	// DATA DEFINITION


	//-----------------------------------------------------

	// OLD ORGANIZATION 

	// model components
	// arena basic process
	pm->insert("create.so");
	pm->insert("dispose.so");
	pm->insert("decide.so");
	pm->insert("batch.so");
	pm->insert("separate.so");
	pm->insert("assign.so");
	pm->insert("record.so");
	pm->insert("process.so");
	pm->insert("submodel.so");
	pm->insert("entitygroup.so");
	pm->insert("queue.so");
	pm->insert("set.so");
	pm->insert("resource.so");
	pm->insert("variable.so");
	pm->insert("schedule.so");
	pm->insert("entitygroup.so");
	// arena advanced process
	pm->insert("delay.so");
	pm->insert("dropoff.so");
	pm->insert("hold.so");
	pm->insert("match.so");
	pm->insert("pickup.so");
	pm->insert("read.so");
	pm->insert("write.so");
	pm->insert("release.so");
	pm->insert("remove.so");
	pm->insert("seize.so");
	pm->insert("search.so");
	pm->insert("signal.so");
	pm->insert("store.so");
	pm->insert("unstore.so");
	pm->insert("expression.so");
	pm->insert("failure.so");
	pm->insert("file.so");
	pm->insert("storage.so");
	// arena transfer station
	pm->insert("enter.so");
	pm->insert("leave.so");
	pm->insert("pickstation.so");
	pm->insert("route.so");
	pm->insert("sequence.so");
	pm->insert("station.so");
	pm->insert("label.so");
	// arena transfer conveyour
	pm->insert("access.so");
	pm->insert("exit.so");
	pm->insert("start.so");
	pm->insert("stop.so");
	pm->insert("conveyour.so");
	pm->insert("segment.so");
	// arena transfer transport
	pm->insert("alocate.so");
	pm->insert("free.so");
	pm->insert("halt.so");
	pm->insert("move.so");
	pm->insert("request.so");
	pm->insert("transporter.so");
	pm->insert("distance.so");
	pm->insert("network.so");
	pm->insert("networklink.so");
	// others
	pm->insert("dummy.so");
	pm->insert("lsode.so");
	pm->insert("biochemical.so");
	pm->insert("markovchain.so");
	pm->insert("cellularautomata.so");
	pm->insert("cppforg.so");
	// now complete the information
	simulator->getPlugins()->completePluginsFieldsAndTemplates();
}