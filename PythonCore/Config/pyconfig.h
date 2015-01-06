
/* 2013-02-05 by tiff */
#ifdef _WIN32
#include "config/pyconfig_win32.h"
#elif defined(__APPLE__) && defined(__MACH__)
#include "config/pyconfig_osx.h"
#elif defined(__ANDROID__)
#include "config/pyconfig_android.h"
#else
#error "Unknown platform. run Configure to generate pyconfig.h"
#endif
