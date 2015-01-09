LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := sqlite
LOCAL_CFLAGS := -fvisibility=hidden -DNDEBUG=1 -D_NDEBUG=1
LOCAL_CPPFLAGS := -std=c++11 -fvisibility=hidden -mfpu=neon -DNDEBUG=1 -D_NDEBUG=1
LOCAL_CPP_FEATURES := rtti exceptions
LOCAL_CPP_EXTENSION := .cxx .cpp
LOCAL_ARM_NEON := true

LOCAL_C_INCLUDES := $(LOCAL_PATH)/sqlite
LOCAL_SRC_FILES := sqlite/sqlite3.c

include $(BUILD_STATIC_LIBRARY)
