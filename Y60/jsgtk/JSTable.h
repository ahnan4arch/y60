//=============================================================================
// Copyright (C) 2003, ART+COM AG Berlin
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of ART+COM AG Berlin, and
// are copy protected by law. They may not be disclosed to third parties
// or copied or duplicated in any form, in whole or in part, without the
// specific, prior written permission of ART+COM AG Berlin.
//=============================================================================
//
//   $RCSfile: JSTable.h,v $
//   $Author: martin $
//   $Revision: 1.1 $
//   $Date: 2005/01/20 11:40:37 $
//
//
//=============================================================================

#ifndef _Y60_ACGTKSHELL_JSTABLE_INCLUDED_
#define _Y60_ACGTKSHELL_JSTABLE_INCLUDED_

#include "JSContainer.h"

#include <y60/JSWrapper.h>
#include <gtkmm/table.h>

#include <asl/string_functions.h>

namespace jslib {

class JSTable : public JSWrapper<Gtk::Table, asl::Ptr<Gtk::Table>, StaticAccessProtocol> {
        JSTable();  // hide default constructor
        typedef JSContainer JSBASE;
    public:
        virtual ~JSTable() {
        }
        typedef Gtk::Table NATIVE;
        typedef asl::Ptr<Gtk::Table> OWNERPTR;
        typedef JSWrapper<NATIVE, OWNERPTR, StaticAccessProtocol> Base;

        static const char * ClassName() {
            return "Table";
        };
        static JSFunctionSpec * Functions();

        enum PropertyNumbers {
            PROP_END = JSBASE::PROP_END
        };

        static JSPropertySpec * Properties();

        virtual unsigned long length() const {
            return 1;
        }

        static JSBool getPropertySwitch(NATIVE & theNative, unsigned long theID,
                JSContext *cx, JSObject *obj, jsval id, jsval *vp);
        virtual JSBool getPropertySwitch(unsigned long theID, JSContext *cx, JSObject *obj, jsval id, jsval *vp);
        static JSBool setPropertySwitch(NATIVE & theNative, unsigned long theID, JSContext *cx,
                JSObject *obj, jsval id, jsval *vp);
        virtual JSBool setPropertySwitch(unsigned long theID, JSContext *cx, JSObject *obj, jsval id, jsval *vp);

        static JSBool
        Constructor(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);

        static
        JSObject * Construct(JSContext *cx, OWNERPTR theOwner, NATIVE * theNative) {
            return Base::Construct(cx, theOwner, theNative);
        }

        JSTable(OWNERPTR theOwner, NATIVE * theNative)
            : Base(theOwner, theNative)
        { }

        static JSConstIntPropertySpec * ConstIntProperties();
        static JSObject * initClass(JSContext *cx, JSObject *theGlobalObject);
        static void addClassProperties(JSContext * cx, JSObject * theClassProto);

        static JSTable & getObject(JSContext *cx, JSObject * obj) {
            return dynamic_cast<JSTable &>(JSTable::getJSWrapper(cx,obj));
        }

    private:
};

template <>
struct JSClassTraits<JSTable::NATIVE>
    : public JSClassTraitsWrapper<JSTable::NATIVE, JSTable> {};

jsval as_jsval(JSContext *cx, JSTable::OWNERPTR theOwner, JSTable::NATIVE * theBin);

} // namespace

#endif


