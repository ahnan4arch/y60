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
//   $RCSfile: JSTreeView.h,v $
//   $Author: martin $
//   $Revision: 1.3 $
//   $Date: 2004/11/27 16:22:00 $
//
//
//=============================================================================

#ifndef _Y60_ACGTKSHELL_JSTREEVIEW_INCLUDED_
#define _Y60_ACGTKSHELL_JSTREEVIEW_INCLUDED_

#include "JSContainer.h"

#include <y60/JSWrapper.h>
#include <gtkmm/treeview.h>

#include <asl/string_functions.h>

namespace jslib {

class JSTreeView : public JSWrapper<Gtk::TreeView, asl::Ptr<Gtk::TreeView>, StaticAccessProtocol> {
        JSTreeView();  // hide default constructor
        typedef JSContainer JSBASE;
    public:
        virtual ~JSTreeView() {
        }
        typedef Gtk::TreeView NATIVE;
        typedef asl::Ptr<Gtk::TreeView> OWNERPTR;
        typedef JSWrapper<NATIVE, OWNERPTR, StaticAccessProtocol> Base;

        static const char * ClassName() {
            return "TreeView";
        };
        static JSFunctionSpec * Functions();

        enum PropertyNumbers {
            PROP_column_count = JSBASE::PROP_END,
            PROP_selected_row,
            PROP_selected_row_values,
            PROP_headers_visible,
            PROP_signal_cursor_changed,
            PROP_END
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

        JSTreeView(OWNERPTR theOwner, NATIVE * theNative)
            : Base(theOwner, theNative)
        { }

        static JSConstIntPropertySpec * ConstIntProperties();
        static JSObject * initClass(JSContext *cx, JSObject *theGlobalObject);
        static void addClassProperties(JSContext * cx, JSObject * theClassProto);

        static JSTreeView & getObject(JSContext *cx, JSObject * obj) {
            return dynamic_cast<JSTreeView &>(JSTreeView::getJSWrapper(cx,obj));
        }

    private:
};

template <>
struct JSClassTraits<JSTreeView::NATIVE>
    : public JSClassTraitsWrapper<JSTreeView::NATIVE, JSTreeView> {};

jsval as_jsval(JSContext *cx, JSTreeView::OWNERPTR theOwner, JSTreeView::NATIVE * theTreeView);

} // namespace

#endif


