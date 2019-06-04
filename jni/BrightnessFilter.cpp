#include "BrightnessFilter.h"


static void genericBrightnessFilter(
		unsigned short* pixels,
		long count,
		unsigned char brightness)
{
	const unsigned char MAX_RB = 0xF8;
	const unsigned char MAX_G = 0xFC;

	unsigned short r, g, b;

	for (long i = 0; i < count; i++)
	{
		// Decompose colors
		r = (pixels[i] >> 8) & MAX_RB;
		g = (pixels[i] >> 3) & MAX_G;
		b = (pixels[i] << 3) & MAX_RB;

		// Brightness increment
		r += brightness;
		g += brightness;
		b += brightness;

		// Make sure that components are in range
		r = (r > MAX_RB) ? MAX_RB : r;
		g = (g > MAX_G) ? MAX_G : g;
		b = (b > MAX_RB) ? MAX_RB : b;

		// Set pixel
		pixels[i] = (r << 8);
		pixels[i] |= (g << 3);
		pixels[i] |= (b >> 3);
	}
}

void BrightnessFilter(
		unsigned short* pixels,
		long count,
		unsigned char brightness)
{
		//Invoke the generic brightness filter
		genericBrightnessFilter(pixels, count, brightness);
}

