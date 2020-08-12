
/* 2015-01-06 by tiff */
#ifdef _WIN32
#include "pyconfig_win32.h"
#elif defined(__APPLE__) && defined(__MACH__)
#include "pyconfig_osx.h"
#elif defined(__ANDROID__)
#include "pyconfig_android.h"
#else
#error "Unknown platform. run Configure to generate pyconfig.h"
#endif


/* framework name */
#define _PYTHONFRAMEWORK ""

