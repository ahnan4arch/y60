/* __ ___ ____ _____ ______ _______ ________ _______ ______ _____ ____ ___ __
//
// Copyright (C) 1993-2008, ART+COM AG Berlin, Germany <www.artcom.de>
//
// These coded instructions, statements, and computer programs contain
// proprietary information of ART+COM AG Berlin, and are copy protected
// by law. They may be used, modified and redistributed under the terms
// of GNU General Public License referenced below. 
//    
// Alternative licensing without the obligations of the GPL is
// available upon request.
//
// GPL v3 Licensing:
//
// This file is part of the ART+COM Y60 Platform.
//
// ART+COM Y60 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// ART+COM Y60 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with ART+COM Y60.  If not, see <http://www.gnu.org/licenses/>.
// __ ___ ____ _____ ______ _______ ________ _______ ______ _____ ____ ___ __
//
// Description: TODO  
//
// Last Review: NEVER, NOONE
//
//  review status report: (perfect, ok, fair, poor, disaster, notapplicable, unknown)
//    usefullness            : unknown
//    formatting             : unknown
//    documentation          : unknown
//    test coverage          : unknown
//    names                  : unknown
//    style guide conformance: unknown
//    technical soundness    : unknown
//    dead code              : unknown
//    readability            : unknown
//    understandabilty       : unknown
//    interfaces             : unknown
//    confidence             : unknown
//    integration            : unknown
//    dependencies           : unknown
//    cheesyness             : unknown
//
//    overall review status  : unknown
//
//    recommendations: 
//       - unknown
// __ ___ ____ _____ ______ _______ ________ _______ ______ _____ ____ ___ __
*/

#include "NetAsync.h"

namespace y60 {
    
static JSClass Package = {
    "Package",
    JSCLASS_HAS_PRIVATE,
    JS_PropertyStub, JS_PropertyStub,
    JS_PropertyStub, JS_PropertyStub,
    JS_EnumerateStub, JS_ResolveStub,
    JS_ConvertStub, JS_FinalizeStub
};
    	
NetAsync::NetAsync(asl::DLHandle theDLHandle) : 
                asl::PlugInBase(theDLHandle),
                IRendererExtension(ClassName()) 
{
    _myAsioThread = AsioThreadPtr(new boost::thread( boost::bind( &NetAsync::run, this, 10) ) );
};

NetAsync::~NetAsync() {
    stop();
};

boost::asio::io_service & 
NetAsync::io_service() {
    return io;
};


void 
NetAsync::initClasses(JSContext * theContext, JSObject *theGlobalObject) {
    IScriptablePlugin::initClasses(theContext, theGlobalObject);
    // start javascript namespace
    JSObject *asyncNamespace = JS_DefineObject(theContext, theGlobalObject, "Async", &Package, NULL, JSPROP_PERMANENT | JSPROP_READONLY);
    JSHttpServer::initClass(theContext, asyncNamespace);
};

void
NetAsync::run(std::size_t thread_pool_size) {
    AC_DEBUG << "starting asio threads";
    
    // Create a pool of threads to run all of the io_services.
    std::vector<boost::shared_ptr<boost::thread> > threads;
    for (std::size_t i = 0; i < thread_pool_size; ++i)
    {
        boost::shared_ptr<boost::thread> thread(new boost::thread(
                    boost::bind(&boost::asio::io_service::run, &io)));
        threads.push_back(thread);
    }

    // Wait for all threads in the pool to exit.
    for (std::size_t i = 0; i < threads.size(); ++i)
        threads[i]->join();

    AC_DEBUG << "asio threads terminated";
};

void 
NetAsync::stop() {
    io.stop();
};

};

// static initializer
boost::asio::io_service y60::NetAsync::io;
boost::asio::io_service::work y60::NetAsync::keep_busy(io);

extern "C"
EXPORT asl::PlugInBase * NetAsync_instantiatePlugIn(asl::DLHandle myDLHandle) {
	return new y60::NetAsync(myDLHandle);
}
