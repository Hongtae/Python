LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := zlib
LOCAL_CFLAGS := -fvisibility=hidden -DNDEBUG=1 -D_NDEBUG=1
LOCAL_CPPFLAGS := -std=c++11 -fvisibility=hidden -mfpu=neon -DNDEBUG=1 -D_NDEBUG=1
LOCAL_CPP_FEATURES := rtti exceptions
LOCAL_CPP_EXTENSION := .cxx .cpp
LOCAL_ARM_NEON := true

LOCAL_C_INCLUDES := $(LOCAL_PATH)/src

LOCAL_SRC_FILES := \
	src/adler32.c \
	src/compress.c \
	src/crc32.c \
	src/deflate.c \
	src/gzclose.c \
	src/gzlib.c \
	src/gzread.c \
	src/gzwrite.c \
	src/infback.c \
	src/inffast.c \
	src/inflate.c \
	src/inftrees.c \
	src/trees.c \
	src/uncompr.c \
	src/zutil.c


include $(BUILD_STATIC_LIBRARY)
