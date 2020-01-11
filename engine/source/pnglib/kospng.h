/* KallistiOS ##version##

   png.h
   (c)2002 Jeffrey McBeth
*/

#ifndef __PNG_READPNG_H
#define __PNG_READPNG_H

#include <sys/cdefs.h>
__BEGIN_DECLS

#include <kos/img.h>

#define PNG_NO_ALPHA 0
#define PNG_MASK_ALPHA 1
#define PNG_FULL_ALPHA 2

#ifdef _arch_dreamcast
	#include <dc/pvr.h>

	/* Load a PNG file, allocating a texture, and returning the size of the file */
	int png_load_texture(const char *filename, pvr_ptr_t *tex, uint32 alpha, uint32 *w, uint32 *h);

	/* Load a PNG file into a texture; returns 0 for success, -1 for failure. */
	int png_to_texture(const char * filename, pvr_ptr_t tex, uint32 alpha);
#endif

/* Load a PNG to a KOS Platform Independent Image */
int png_to_img(const char * filename, uint32 mask, kos_img_t *rv);

#ifndef BUILD_LIBPNG
/* libpng has its own private png_write_data function, so we had to rename the
   one from writepng.c. This makes it so existing code will still work. */
#define png_write_data png_write_file
#endif

/* Write out a PNG file */
int png_write_file(const char *filename, uint8 *data, uint32 width, uint32 height);

__END_DECLS

#endif	/* __PNG_PNG_H */
