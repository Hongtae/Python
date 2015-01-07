
#if defined(__arm64__)
#include "ffitarget_arm64.h"
#elif defined(__arm__)
#include "ffitarget_armv7.h"
#elif defined(__i386__) || defined(__x86_64__)
#include "ffitarget_x86.h"
#else
#error "Unknown platform"
#endif

