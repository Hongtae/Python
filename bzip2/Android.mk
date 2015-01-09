LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := bzip2
LOCAL_CFLAGS := -fvisibility=hidden -DNDEBUG=1 -D_NDEBUG=1
LOCAL_CPPFLAGS := -std=c++11 -fvisibility=hidden -mfpu=neon -DNDEBUG=1 -D_NDEBUG=1
LOCAL_CPP_FEATURES := rtti exceptions
LOCAL_CPP_EXTENSION := .cxx .cpp
LOCAL_ARM_NEON := true

LOCAL_C_INCLUDES := $(LOCAL_PATH)/bzip2

LOCAL_SRC_FILES := \
	bzip2/blocksort.c \
	bzip2/bzlib.c \
	bzip2/compress.c \
	bzip2/crctable.c \
	bzip2/decompress.c \
	bzip2/huffman.c \
	bzip2/randtable.c

include $(BUILD_STATIC_LIBRARY)
