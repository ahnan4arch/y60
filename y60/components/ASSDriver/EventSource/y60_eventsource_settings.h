#ifndef Y60_EVENTSOURCE_SETTING_INCLUDED
#define Y60_EVENTSOURCE_SETTING_INCLUDED

#include <asl/base/settings.h>

#ifdef EventSource_EXPORTS
#   define Y60_EVENTSOURCE_EXPORT AC_DLL_EXPORT
#else
#   define Y60_EVENTSOURCE_EXPORT AC_DLL_IMPORT
#endif

#endif // Y60_EVENTSOURCE_SETTING_INCLUDED