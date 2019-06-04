#pragma once

/**
 * Extract the interleaved components. RGB565 color
 * space has a total of 16-bits with 5-bits red,
 * 6-bits green, and 5-bits blue.
 */
void BrightnessFilter(
		unsigned short* pixels,
		long count,
		unsigned char brightness);
