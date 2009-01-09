
set(SOURCES
AssEventSchema.cpp
AxisEvent.cpp
ButtonEvent.cpp
DebugEventSink.cpp
Event.cpp
EventDispatcher.cpp
EventRecorder.cpp
GenericEvent.cpp
KeyEvent.cpp
MouseEvent.cpp
TouchEvent.cpp
WindowEvent.cpp
asseventxsd.cpp
)

set(HEADERS
AssEventSchema.h
AxisEvent.h
ButtonEvent.h
DebugEventSink.h
Event.h
EventDispatcher.h
EventRecorder.h
GenericEvent.h
IEventSink.h
IEventSource.h
KeyCodes.h
KeyEvent.h
MouseEvent.h
TouchEvent.h
WindowEvent.h
)

set(TESTS
EventDispatcher
)

ac_add_library(
    y60input y60/input
    SOURCES ${SOURCES}
    HEADERS ${HEADERS}
    DEPENDS aslbase aslmath asldom
    EXTERNS OPENEXR
    TESTS   ${TESTS}
)