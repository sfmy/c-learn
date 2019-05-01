/*
 * png图片颜色处理 需要用到libpng库
 * 编译时请加上`pkg-config --cflags --libs libpng`
 */

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 

#include <png.h>  

#define PNG_BYTES_TO_CHECK 4  

int dealWithData (png_bytep *row_pointers, int width, int height) {
	int i, j;
	for (i = 0; i < height; ++i) {
		for (j = 0; j < width; ++j) {
			row_pointers[i][j*3] = 0;   /* red */
			/* row_pointers[i][j*3+1] = 0; [> green <] */
			/* row_pointers[i][j*3+2] = 0; [> blue <] */
		}
	}
}

int writePngImage (const char * file_write, png_bytep *row_pointers, int width, int height) {
	FILE *file;
	png_structp png_ptr;
	png_infop info_ptr;

	file = fopen(file_write, "wb");
	if (file == NULL) {
		printf("write file %s failed!\n", file_write);
		return 1;
	}

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	info_ptr = png_create_info_struct(png_ptr);
	if (setjmp(png_jmpbuf(png_ptr))) {
		fclose(file);
		png_destroy_write_struct(&png_ptr, &info_ptr);
		return 1;
	}
	png_init_io(png_ptr, file);
	png_set_IHDR(png_ptr, info_ptr, width, height,
			8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
	png_write_info(png_ptr, info_ptr);
	png_write_image(png_ptr, row_pointers);
	png_write_end(png_ptr, info_ptr);
	fclose(file);
	png_destroy_write_struct(&png_ptr, &info_ptr);
	return 0;
}

int transPngImage (const char *file_read, const char *file_write) {
	FILE *file;
	png_structp png_ptr;
	png_infop info_ptr;
	png_bytep *row_pointers;
	char buf[PNG_BYTES_TO_CHECK];
	int width, height, color_type;

	file = fopen(file_read, "rb");
	if (file == NULL) {
		printf("open file %s failed!\n", file_read);
		return 1;
	}

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
	info_ptr = png_create_info_struct(png_ptr);

	setjmp(png_jmpbuf(png_ptr));
	if (fread(buf, 1, PNG_BYTES_TO_CHECK, file) != PNG_BYTES_TO_CHECK) {
		fclose(file);
		png_destroy_read_struct(&png_ptr, &info_ptr, 0);
		printf("cann't read PNG_BYTES_TO_CHECK byte!");
		return 1;
	}
	
	if (png_sig_cmp((png_bytep)buf, 0, PNG_BYTES_TO_CHECK) != 0) {
		fclose(file);
		png_destroy_read_struct(&png_ptr, &info_ptr, 0);
		printf("%s not a png sign!", file_read);
		return 1;
	}

	rewind(file);
	png_init_io(png_ptr, file);
	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_EXPAND, 0);
	width = png_get_image_width(png_ptr, info_ptr);
	height = png_get_image_height(png_ptr, info_ptr);
	row_pointers = png_get_rows(png_ptr, info_ptr);

	dealWithData(row_pointers, width, height);
	writePngImage(file_write, row_pointers, width, height);

	fclose(file);
	png_destroy_read_struct(&png_ptr, &info_ptr, 0);
	return 0;
}

int main (int argc, char **argv) {
	if (argc == 3) {
		transPngImage(argv[1], argv[2]);
	}
	return 0;
}
