/*
 * TransparentBlt.c
 *
 *  Created on: Sep 1, 2016
 *      Author: xinsu
 *
 Write a function that performs
 a transparent "blit" (block
 transfer) of one bitmap onto
 another at a specified
 coordinate in the destination
 bitmap.
 Assume that both bitmaps are
 8-bit (that is, one byte per
 pixel).
 Assume that bitmap data is
 stored in memory buffers
 contiguously in row-major
 order.
 Write efficient code. Blitters need to
 be fast.
 For example, if the destination
 bitmap is a 5x3 image...
 d d d d d
 d d d d d
 d d d d d
 ...and the source bitmap is a 3x3 imag...
 sss
 sTT
 sss
 ...The destination is (1, 0). After applying the source bitmap to the destination
 the result is...
 dsssd
 dsTTd
 dsssd
 *
 */

typedef unsigned char byte;
typedef struct {
	unsigned width;
	unsigned height;
	byte * data;
} Bitmap;

byte TRANSPARENT_COLOR = 0;

void TransparentBlt(unsigned destX, unsigned destY, Bitmap * dest,
		const Bitmap source) {

	unsigned source_n = source.height;
	unsigned source_m = source.width;

	//check destX, destY availability
	if (destX + source_m >= dest->width)
		source_m = dest->width - destX;
	if (destY + source_n >= dest->height)
		source_n = dest->height - destY;
	if (source_n <= 0 || source_m <= 0)
		return;

	//init offset to begining of the needed line
	long i, j, source_offset = 0, destY_offset = destY * dest->width;

	for (i = 0; i < source_n; i++) {
		for (j = 0; j < source_m; j++) {
			if (source.data[source_offset + j] != TRANSPARENT_COLOR) {
				//need to copy
				dest->data[destY_offset + destX + j] = source.data[source_offset
						+ j];
			}
		}
		source_offset += source.width;
		destY_offset += dest->width;
	}

	int x = 0;

	for (x = 0; x < source.height * source.width; x++) {
		printf("%d", source.data[x]);
	}

	printf("\n");

	for (x = 0; x < dest->height * dest->width; x++) {
		printf("%d", dest->data[x]);
	}
}

int main() {
	unsigned destX = 3;
	unsigned destY = 0;

	Bitmap dest;
	dest.width = 5;
	dest.height = 5;
	dest.data = (byte *) calloc(dest.width * dest.height, sizeof(byte));
	for (int i = 0; i < dest.width * dest.height; i++) {
		dest.data[i] = 8;
	}

	Bitmap source;
	source.width = 3;
	source.height = 3;
	source.data = (byte *) calloc(dest.width * dest.height, sizeof(byte));
	for (int i = 0; i < source.width * source.height; i++) {
		source.data[i] = 5;
	}

	source.data[1] = 1;
	source.data[4] = 1;
	source.data[7] = 1;

	TransparentBlt(destX, destY, &dest, source);
}
