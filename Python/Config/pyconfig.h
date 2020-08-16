
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


#if defined(__APPLE__)
     #include "TargetConditionals.h"
     #if TARGET_OS_IOS || TARGET_OS_WATCH || TARGET_OS_TV
         #define system(s) ((s)==NULL ? 0 : -1)
     #endif
#elif defined(__ANDROID__)
     #define system(s) ((s)==NULL ? 0 : -1)
#endif
