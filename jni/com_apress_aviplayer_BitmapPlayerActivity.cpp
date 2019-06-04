extern "C" {
#include <avilib.h>
}

#include <android/bitmap.h>

#include "BrightnessFilter.h"
#include "Common.h"
#include "com_apress_aviplayer_BitmapPlayerActivity.h"


jboolean Java_com_apress_aviplayer_BitmapPlayerActivity_render(
		JNIEnv* env,
		jclass clazz,
		jlong avi,
		jobject bitmap)
{
	jboolean isFrameRead = JNI_FALSE;

	char* frameBuffer = 0;
	long frameSize = 0;
	int keyFrame = 0;

	// Lock bitmap and get the raw bytes
	if (0 > AndroidBitmap_lockPixels(env, bitmap, (void**) &frameBuffer))
	{
		ThrowException(env, "java/io/IOException", "Unable to lock pixels.");
		goto exit;
	}

	// Read AVI frame bytes to bitmap
	frameSize = AVI_read_frame((avi_t*) avi, frameBuffer, &keyFrame);

	// Apply the brigthness filter
	BrightnessFilter((unsigned short*) frameBuffer, frameSize/2, (unsigned char)1);

	// Unlock bitmap
	if (0 > AndroidBitmap_unlockPixels(env, bitmap))
	{
		ThrowException(env, "java/io/IOException", "Unable to unlock pixels.");
		goto exit;
	}

	// Check if frame is successfully read
	if (0 < frameSize)
	{
		isFrameRead = JNI_TRUE;
	}

exit:
	return isFrameRead;
}

