#pragma once

#include <jni.h>

/**
 * Throws a new exception using the given exception class
 * and exception message.
 *
 * @param env JNIEnv interface.
 * @param className class name.
 * @param message exception message.
 */
void ThrowException(
		JNIEnv* env,
		const char* className,
		const char* message);

