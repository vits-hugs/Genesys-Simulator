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
	std::cout << "(Event Handler) " << "Entity " << re->getCurrentEntity()->getName() << " was moved to component" << re->getDestinationComponent()->getName() << std::endl;
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
	// model components
	// arena basic process
	simulator->getPlugins()->insert("create.so");
	simulator->getPlugins()->insert("dispose.so");
	simulator->getPlugins()->insert("decide.so");
	simulator->getPlugins()->insert("batch.so");
	simulator->getPlugins()->insert("separate.so");
	simulator->getPlugins()->insert("assign.so");
	simulator->getPlugins()->insert("record.so");
	simulator->getPlugins()->insert("process.so");
	simulator->getPlugins()->insert("submodel.so");
	simulator->getPlugins()->insert("entitygroup.so");
	simulator->getPlugins()->insert("queue.so");
	simulator->getPlugins()->insert("set.so");
	simulator->getPlugins()->insert("resource.so");
	simulator->getPlugins()->insert("variable.so");
	simulator->getPlugins()->insert("schedule.so");
	simulator->getPlugins()->insert("entitygroup.so");
	// arena advanced process
	simulator->getPlugins()->insert("delay.so");
	simulator->getPlugins()->insert("dropoff.so");
	simulator->getPlugins()->insert("hold.so");
	simulator->getPlugins()->insert("match.so");
	simulator->getPlugins()->insert("pickup.so");
	simulator->getPlugins()->insert("read.so");
	simulator->getPlugins()->insert("write.so");
	simulator->getPlugins()->insert("release.so");
	simulator->getPlugins()->insert("remove.so");
	simulator->getPlugins()->insert("seize.so");
	simulator->getPlugins()->insert("search.so");
	simulator->getPlugins()->insert("signal.so");
	simulator->getPlugins()->insert("store.so");
	simulator->getPlugins()->insert("unstore.so");
	simulator->getPlugins()->insert("expression.so");
	simulator->getPlugins()->insert("failure.so");
	simulator->getPlugins()->insert("file.so");
	simulator->getPlugins()->insert("storage.so");
	// arena transfer station
	simulator->getPlugins()->insert("enter.so");
	simulator->getPlugins()->insert("leave.so");
	simulator->getPlugins()->insert("pickstation.so");
	simulator->getPlugins()->insert("route.so");
	simulator->getPlugins()->insert("sequence.so");
	simulator->getPlugins()->insert("station.so");
	// arena transfer conveyour
	simulator->getPlugins()->insert("access.so");
	simulator->getPlugins()->insert("exit.so");
	simulator->getPlugins()->insert("start.so");
	simulator->getPlugins()->insert("stop.so");
	simulator->getPlugins()->insert("conveyour.so");
	simulator->getPlugins()->insert("segment.so");
	// arena transfer transport
	simulator->getPlugins()->insert("alocate.so");
	simulator->getPlugins()->insert("free.so");
	simulator->getPlugins()->insert("halt.so");
	simulator->getPlugins()->insert("move.so");
	simulator->getPlugins()->insert("request.so");
	simulator->getPlugins()->insert("transporter.so");
	simulator->getPlugins()->insert("distance.so");
	simulator->getPlugins()->insert("network.so");
	simulator->getPlugins()->insert("networklink.so");
	// others
	simulator->getPlugins()->insert("dummy.so");
	simulator->getPlugins()->insert("lsode.so");
	simulator->getPlugins()->insert("biochemical.so");
	simulator->getPlugins()->insert("markovchain.so");
	simulator->getPlugins()->insert("cellularautomata.so");
	simulator->getPlugins()->insert("cppforgenesys.so");
}