#ifndef Y60_CAIRO_SETTING_INCLUDED
#define Y60_CAIRO_SETTING_INCLUDED

#include <asl/base/settings.h>

#ifdef Cairo_EXPORTS
#   define Y60_CAIRO_EXPORT AC_DLL_EXPORT
#else
#   define Y60_CAIRO_EXPORT AC_DLL_IMPORT
#endif

#endif // Y60_CAIRO_SETTING_INCLUDED