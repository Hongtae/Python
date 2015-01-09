PYTHON_ROOT_PATH := $(call my-dir)

include $(PYTHON_ROOT_PATH)/sqlite/Android.mk
include $(PYTHON_ROOT_PATH)/bzip2/Android.mk
include $(PYTHON_ROOT_PATH)/zlib/Android.mk
include $(PYTHON_ROOT_PATH)/OpenSSL/Android.mk
include $(PYTHON_ROOT_PATH)/PythonCore/Android.mk
