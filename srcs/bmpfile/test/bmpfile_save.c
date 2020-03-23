#include "bmpfile.h"
#include <stdio.h>
#include <math.h>
#define HEIGHT 2
#define WIDTH 1

int main()
{
	char *filename = "red.bmp";
	typedef unsigned char t_pixel[3];
	typedef t_pixel t_screen[WIDTH][HEIGHT];
	t_screen screen;
	int cur_width, cur_height;
	t_bmpfile_info info;

	cur_width = 0;
	while (cur_width < WIDTH)
	{
		cur_height = 0;
		while (cur_height < HEIGHT)
		{
			screen[cur_width][cur_height][0] = 255;
			screen[cur_width][cur_height][1] = 255;
			screen[cur_width][cur_height][2] = 255;
			cur_height++;
		}
		cur_width++;
	}
	info.screen = (unsigned char *)screen;
	info.width = WIDTH;
	info.height = HEIGHT;
	if (bmpfile_save(filename, &info) == bmpfile_ok)
		printf("File %s successfully created.\n", filename);
	else
		printf("ERROR creating file %s.\n", filename);
	return (0);
}
