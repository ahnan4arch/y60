//=============================================================================
// Copyright (C) 1993-2005, ART+COM AG Berlin
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of ART+COM AG Berlin, and
// are copy protected by law. They may not be disclosed to third parties
// or copied or duplicated in any form, in whole or in part, without the
// specific, prior written permission of ART+COM AG Berlin.
//=============================================================================
//
//   $RCSfile: JSCellRendererText.cpp,v $
//   $Author: martin $
//   $Revision: 1.2 $
//   $Date: 2005/04/13 10:38:06 $
//
//
//=============================================================================

#include "JSCellRendererText.h"
#include "JSSignalProxy2.h"
#include "JSWindow.h"
#include "JSRenderArea.h"
#include "jsgtk.h"
#include <y60/JScppUtils.h>
#include <iostream>

using namespace std;
using namespace asl;

namespace jslib {

static JSBool
toString(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval) {
    DOC_BEGIN("");
    DOC_END;
    std::string myStringRep = std::string("GtkCellRendererText@") + as_string(obj);
    *rval = as_jsval(cx, myStringRep);
    return JS_TRUE;
}

JSFunctionSpec *
JSCellRendererText::Functions() {
    IF_REG(cerr << "Registering class '"<<ClassName()<<"'"<<endl);
    static JSFunctionSpec myFunctions[] = {
        // name                  native                   nargs
        {"toString",             toString,                0},
        {0}
    };
    return myFunctions;
}


JSPropertySpec *
JSCellRendererText::Properties() {
    static JSPropertySpec myProperties[] = {
        {"signal_edited", PROP_signal_edited, JSPROP_ENUMERATE | JSPROP_ENUMERATE},
        {0}
    };
    return myProperties;
}
// getproperty handling
JSBool
JSCellRendererText::getPropertySwitch(NATIVE & theNative, unsigned long theID,
        JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
    switch (theID) {
        case PROP_signal_edited:
            try {
                typedef JSSignalProxy2<void, const Glib::ustring &, const Glib::ustring &> SignalEditedT;
                SignalEditedT::OWNERPTR mySignal( new SignalEditedT::NATIVE(theNative.signal_edited()));
                *vp = jslib::as_jsval(cx, mySignal);
                return JS_TRUE;
            } HANDLE_CPP_EXCEPTION
        default:
            JS_ReportError(cx,"JSCellRendererText::getProperty: index %d out of range", theID);
            return JS_FALSE;
    }
}

JSBool
JSCellRendererText::getPropertySwitch(unsigned long theID, JSContext *cx, JSObject *obj, jsval id, jsval *vp) {
    JSClassTraits<NATIVE>::ScopedNativeRef myObj(cx, obj);
    return getPropertySwitch(myObj.getNative(), theID, cx, obj, id, vp);
}

// setproperty handling
JSBool
JSCellRendererText::setPropertySwitch(NATIVE & theNative, unsigned long theID,
        JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
    switch (theID) {
        case 0:
        default:
            JS_ReportError(cx,"JSCellRendererText::setProperty: index %d out of range", theID);
            return JS_FALSE;
    }
}

JSBool
JSCellRendererText::setPropertySwitch(unsigned long theID, JSContext *cx, JSObject *obj, jsval id, jsval *vp) {
    JSClassTraits<NATIVE>::ScopedNativeRef myObj(cx, obj);
    return setPropertySwitch(myObj.getNative(), theID, cx, obj, id, vp);
}

JSBool
JSCellRendererText::Constructor(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval) {
    DOC_BEGIN("");
    DOC_END;
    if (JSA_GetClass(cx,obj) != Class()) {
        JS_ReportError(cx,"Constructor for %s  bad object; did you forget a 'new'?",ClassName());
        return JS_FALSE;
    }

    NATIVE * newNative = 0;

    JSCellRendererText * myNewObject = 0;

    if (argc == 0) {
        newNative = new Gtk::CellRendererText();
        myNewObject = new JSCellRendererText(OWNERPTR(newNative), newNative);
    } else {
        JS_ReportError(cx,"Constructor for %s: bad number of arguments: expected none () %d",ClassName(), argc);
        return JS_FALSE;
    }

    if (myNewObject) {
        JS_SetPrivate(cx,obj,myNewObject);
        return JS_TRUE;
    }
    JS_ReportError(cx,"JSButton::Constructor: bad parameters");
    return JS_FALSE;
}

void
JSCellRendererText::addClassProperties(JSContext * cx, JSObject * theClassProto) {
    JSA_AddFunctions(cx, theClassProto, Functions());
    JSA_AddProperties(cx, theClassProto, Properties());
    createClassModuleDocumentation("gtk", ClassName(), Properties(), Functions(), 0, 0, 0);
}

/*
JSConstIntPropertySpec *
JSCellRendererText::ConstIntProperties() {

    static JSConstIntPropertySpec myProperties[] = {
            "TEXT",              PROP_CELL_RENDERER_TEXT,     PROP_CELL_RENDERER_TEXT,
            "PIXBUF",            PROP_CELL_RENDERER_PIXBUF,   PROP_CELL_RENDERER_PIXBUF,
            //"PROGRESS",          PROP_CELL_RENDERER_PROGRESS, PROP_CELL_RENDERER_PROGRESS,
            "TOGGLE",            PROP_CELL_RENDERER_TOGGLE,   PROP_CELL_RENDERER_TOGGLE,
            //"COMBO",             PROP_CELL_RENDERER_COMBO,    PROP_CELL_RENDERER_COMBO,
        {0}
    };
    return myProperties;
};
*/

JSObject *
JSCellRendererText::initClass(JSContext *cx, JSObject *theGlobalObject) {
    JSObject * myClassObject = Base::initClass(cx, theGlobalObject, ClassName(), Constructor, 0, 0);
    if (myClassObject) {
        addClassProperties(cx, myClassObject);
    }
    jsval myConstructorFuncObjVal;
    if (JS_GetProperty(cx, theGlobalObject, ClassName(), &myConstructorFuncObjVal)) {
//        JSObject * myConstructorFuncObj = JSVAL_TO_OBJECT(myConstructorFuncObjVal);
//        JSA_DefineConstInts(cx, myConstructorFuncObj, ConstIntProperties());
    } else {
        cerr << "JSCellRendererText::initClass: constructor function object not found, could not initialize static members"<<endl;
    }
    return myClassObject;
}

jsval as_jsval(JSContext *cx, JSCellRendererText::NATIVE * theNative) {
    JSObject * myReturnObject = JSCellRendererText::Construct(cx, JSCellRendererText::OWNERPTR(0), theNative);
    return OBJECT_TO_JSVAL(myReturnObject);
}

}


