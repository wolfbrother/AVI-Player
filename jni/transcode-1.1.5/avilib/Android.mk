


LOCAL_PATH :=$(call my-dir)

MY_AVILIB_SRC_FILES := avilib.c platform_posix.c
MY_AVILIB_C_INCLUDES := $(LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE :=avilib_shared
LOCAL_MODULE_FILENAME:=libavilib_shared
LOCAL_SRC_FILES := $(MY_AVILIB_SRC_FILES)

LOCAL_EXPORT_C_INCLUDES := $(MY_AVILIB_C_INCLUDES)

include $(BUILD_STATIC_LIBRARY)


