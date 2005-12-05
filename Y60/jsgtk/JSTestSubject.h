//=============================================================================
// Copyright (C) 1993-2005, ART+COM AG Berlin
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of ART+COM AG Berlin, and
// are copy protected by law. They may not be disclosed to third parties
// or copied or duplicated in any form, in whole or in part, without the
// specific, prior written permission of ART+COM AG Berlin.
//=============================================================================

// Sample Test Subject for Subject-Observer Test

#ifndef __acgtkshell__test_subject
#define __acgtkshell__test_subject

#include "JSSignal0.h"

namespace jslib {

class TestSubject {
    public:
        void trigger() {
            test_signal.emit();
        };
        sigc::signal<void> test_signal;
};

class JSTestSubject : public JSWrapper<TestSubject, asl::Ptr<TestSubject>,
                                      StaticAccessProtocol>
{
        JSTestSubject();  // hide default constructor
    public:
        virtual ~JSTestSubject() { 
        }
        typedef TestSubject NATIVE;
        typedef asl::Ptr<TestSubject> OWNERPTR;
        typedef JSWrapper<NATIVE, OWNERPTR, StaticAccessProtocol> Base;

        static const char * ClassName() {
            return "TestSubject";
        }

        static JSFunctionSpec * Functions();

        
        enum PropertyNumbers {
            PROP_test_signal = -127,
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

        JSTestSubject(OWNERPTR theOwner, NATIVE * theNative)
            : Base(theOwner, theNative)
        {}

        static JSConstIntPropertySpec * ConstIntProperties();
        static JSObject * initClass(JSContext *cx, JSObject *theGlobalObject);
        static void addClassProperties(JSContext * cx, JSObject * theClassProto);

        static JSTestSubject & getObject(JSContext *cx, JSObject * obj) {
            return dynamic_cast<JSTestSubject &>(JSTestSubject::getJSWrapper(cx,obj));
        }

    private:
};

template <>
struct JSClassTraits<JSTestSubject::NATIVE> 
    : public JSClassTraitsWrapper<JSTestSubject::NATIVE, JSTestSubject> {};

jsval as_jsval(JSContext *cx, JSTestSubject::NATIVE * theWindow);
bool convertFrom(JSContext *cx, jsval theValue, asl::Ptr<TestSubject> & theTestSubject);
}

#endif
