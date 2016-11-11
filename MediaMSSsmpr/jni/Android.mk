LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := mylib
LOCAL_SRC_FILES := lib/libMSS_MSPR_Android.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := media_ns 
					
LOCAL_SRC_FILES := MediaNS.c\
					
										
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog
LOCAL_CFLAGS := -O2 -g3 -Wall
LOCAL_CFLAGS := -D__STDC_CONSTANT_MACROS
LOCAL_CXXFLAGS := -std=c++11 
LOCAL_DEFAULT_CPP_EXTENSION := '.c' '.cc'
LOCAL_STATIC_LIBRARIES := mylib

include $(BUILD_SHARED_LIBRARY)
