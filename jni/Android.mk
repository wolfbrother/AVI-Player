LOCAL_PATH := $(call my-dir)
$(call import-add-path,$(LOCAL_PATH))
include $(CLEAR_VARS)

LOCAL_MODULE    := AVIPlayer
LOCAL_SRC_FILES := \
	Common.cpp \
	com_apress_aviplayer_AbstractPlayerActivity.cpp \
	com_apress_aviplayer_BitmapPlayerActivity.cpp \
    BrightnessFilter.cpp

#LOCAL_SRC_FILES += BrightnessFilter.cpp

# Use AVILib static library 
LOCAL_SHARED_LIBRARIES += avilib_shared


# Link with JNI graphics
LOCAL_LDLIBS += -ljnigraphics

include $(BUILD_SHARED_LIBRARY)

# Import AVILib library module
$(call import-module, transcode-1.1.5/avilib)

