/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PluginConnectorDummyImpl1.cpp
 * Author: rlcancian
 * 
 * Created on 9 de Setembro de 2019, 19:24
 */

#include "PluginConnectorDummyImpl1.h"

// Model Components

#include "../../plugins/components/Create.h"
#include "../../plugins/components/Delay.h"
#include "../../plugins/components/Dispose.h"
#include "../../plugins/components/Seize.h"
#include "../../plugins/components/Release.h"
#include "../../plugins/components/Assign.h"
#include "../../plugins/components/Record.h"
#include "../../plugins/components/Decide.h"
//#include "Dummy.h"
#include "../../plugins/components/Route.h"
#include "../../plugins/components/Enter.h"
#include "../../plugins/components/Leave.h"
#include "../../plugins/components/Write.h"
#include "../../plugins/components/Hold.h"
// #include "DropOff.h"
// #include "Schedule.h"
#include "../../plugins/components/Batch.h"
#include "../../plugins/components/Separate.h"
//#include "Submodel.h"
#include "../../plugins/components/Match.h"
// #include "PickUp.h"
// #include "Remove.h"
// #include "Search.h"
// #include "Signal.h"
#include "../../plugins/components/Store.h"
// #include "PickStation.h"
//#include "Sequence.h"
// #include "Start.h"
// #include "Stop.h"
#include "../../plugins/components/Unstore.h"
// #include "Failure.h"
// #include "File.h"
// #include "Storage.h"
// #include "Access.h"
// #include "Exit.h"

// Model elements
#include "../../plugins/elements/Variable.h"
//#include "ProbDistribDefaultImpl1.h"
#include "../../plugins/elements/EntityGroup.h"
#include "../../plugins/elements/Station.h"
//#include "Formula.h"
#include "../../plugins/elements/Set.h"
#include "../../plugins/elements/Storage.h"
#include "../../plugins/elements/Sequence.h"
//# include "OLD_ODEelement.h"

#include "../util/Util.h"

//namespace GenesysKernel {

PluginConnectorDummyImpl1::PluginConnectorDummyImpl1() {
}

Plugin* PluginConnectorDummyImpl1::check(const std::string dynamicLibraryFilename) {
    // \todo: not implemented yet!
    //dynamicLibraryFilename = ""; // just to use it
    return nullptr; /**@ \todo:To implement */
}

Plugin* PluginConnectorDummyImpl1::connect(const std::string dynamicLibraryFilename) {
    std::string fn = getFileName(dynamicLibraryFilename);
    StaticGetPluginInformation GetInfo = nullptr;
    Plugin* pluginResult = nullptr;
    // ODO: Remove this mostruosity and and trully dynamically loaded libraries    
    
    // model elements


    //if (fn == "attribute.so")
    //    GetInfo = &Attribute::GetPluginInformation;
    if (fn == "assign.so")
        GetInfo = &Assign::GetPluginInformation;
        //else if (fn == "counter.so")
        //    GetInfo = &Counter::GetPluginInformation;
    else if (fn == "entitygroup.so")
        GetInfo = &EntityGroup::GetPluginInformation;
        //else if (fn == "entitytype.so")
        //    GetInfo = &EntityType::GetPluginInformation;
        //else if (fn == "formula.so")
        //    GetInfo = &Formula::GetPluginInformation;
        //	else if (fn == "ode.so")
        //		GetInfo = &OLD_ODEelement::GetPluginInformation;
    else if (fn == "queue.so")
        GetInfo = &Queue::GetPluginInformation;
    else if (fn == "resource.so")
        GetInfo = &Resource::GetPluginInformation;
    else if (fn == "set.so")
        GetInfo = &Set::GetPluginInformation;
        //else if (fn == "statisticscollector.so")
        //    GetInfo = &StatisticsCollector::GetPluginInformation;
    else if (fn == "station.so")
        GetInfo = &Station::GetPluginInformation;
    else if (fn == "variable.so")
        GetInfo = &Variable::GetPluginInformation;
        // model components
    else if (fn == "create.so")
        GetInfo = &Create::GetPluginInformation;
    else if (fn == "write.so")
        GetInfo = &Write::GetPluginInformation;
    else if (fn == "decide.so")
        GetInfo = &Decide::GetPluginInformation;
    else if (fn == "delay.so")
        GetInfo = &Delay::GetPluginInformation;
    else if (fn == "dispose.so")
        GetInfo = &Dispose::GetPluginInformation;
        //else if (fn == "dummy.so")
        //    GetInfo = &Dummy::GetPluginInformation;
    else if (fn == "record.so")
        GetInfo = &Record::GetPluginInformation;
    else if (fn == "release.so")
        GetInfo = &Release::GetPluginInformation;
    else if (fn == "seize.so")
        GetInfo = &Seize::GetPluginInformation;
    else if (fn == "route.so")
        GetInfo = &Route::GetPluginInformation;
    else if (fn == "enter.so")
        GetInfo = &Enter::GetPluginInformation;
    else if (fn == "leave.so")
        GetInfo = &Leave::GetPluginInformation;
        //	else if (fn == "lsode.so")
        //		GetInfo = &LSODE::GetPluginInformation;
        //	else if (fn == "markovchain.so")
        //		GetInfo = &MarkovChain::GetPluginInformation;
    else if (fn == "hold.so")
        GetInfo = &Hold::GetPluginInformation;
        //	else if (fn == "schedule.so")
        //		GetInfo = &Schedule::GetPluginInformation;
        //	else if (fn == "dropoff.so")
        //		GetInfo = &DropOff::GetPluginInformation;
    else if (fn == "batch.so")
        GetInfo = &Batch::GetPluginInformation;
    else if (fn == "separate.so")
        GetInfo = &Separate::GetPluginInformation;
        //else if (fn == "submodel.so")
        //    GetInfo = &Submodel::GetPluginInformation;
    else if (fn == "match.so")
        GetInfo = &Match::GetPluginInformation;
    //	else if (fn == "pickup.so")
    //		GetInfo = &PickUp::GetPluginInformation;
        //else if (fn == "read.so")
        //	GetInfo = &Read::GetPluginInformation;
    //	else if (fn == "remove.so")
    //		GetInfo = &Remove::GetPluginInformation;
    //	else if (fn == "search.so")
    //		GetInfo = &Search::GetPluginInformation;
    //	else if (fn == "signal.so")
    //		GetInfo = &Signal::GetPluginInformation;
    else if (fn == "store.so")
        GetInfo = &Store::GetPluginInformation;
    else if (fn == "unstore.so")
        GetInfo = &Unstore::GetPluginInformation;
        //else if (fn == "expression.so")
        //	GetInfo = &Expression::GetPluginInformation;
    //	else if (fn == "failure.so")
    //		GetInfo = &Failure::GetPluginInformation;
    //	else if (fn == "file.so")
    //		GetInfo = &File::GetPluginInformation;
    else if (fn == "storage.so")
        GetInfo = &Storage::GetPluginInformation;
    //	else if (fn == "pickstation.so")
    //		GetInfo = &PickStation::GetPluginInformation;
    else if (fn == "sequence.so")
        GetInfo = &Sequence::GetPluginInformation;
    //	else if (fn == "access.so")
    //		GetInfo = &Access::GetPluginInformation;
    //	else if (fn == "exit.so")
    //		GetInfo = &Exit::GetPluginInformation;
    //	else if (fn == "start.so")
    //		GetInfo = &Start::GetPluginInformation;
    //	else if (fn == "stop.so")
    //		GetInfo = &Stop::GetPluginInformation;
    //else if (fn == "conveyour.so")
    //	GetInfo = &Conveyour::GetPluginInformation;
    //else if (fn == "segment.so")
    //	GetInfo = &Segment::GetPluginInformation;

    //else if (fn=="")
    
    if (GetInfo != nullptr) {
        pluginResult = new Plugin(GetInfo);
    }
    return pluginResult;
}

bool PluginConnectorDummyImpl1::disconnect(const std::string dynamicLibraryFilename) {
    // \TODO: To implement!
    //dynamicLibraryFilename = ""; // just to use ut
    return true;
}

bool PluginConnectorDummyImpl1::disconnect(Plugin* plugin) {
    // \TODO: To implement!
    return true;
}

//namespace\\}