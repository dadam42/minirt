#include "bmpfile.h"
#include <stdio.h>
#include <math.h>
#define HEIGHT 800
#define WIDTH  800

float my_abs(float x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

int main()
{
	char *filename = "red.bmp";
	typedef unsigned char t_pixel[3];
	typedef t_pixel t_content[HEIGHT][WIDTH];
	t_content content;
	int cur_width, cur_height;
	t_bmpfile_info info;

	cur_width = 0;
	while (cur_width < WIDTH)
	{
		cur_height = 0;
		while (cur_height < HEIGHT)
		{
			float d0, d1, d2;
			d0 = sqrt((cur_height - HEIGHT/4)*(cur_height - HEIGHT/4) + (cur_width - WIDTH/2)*(cur_width - WIDTH/2));
			d1 = sqrt((cur_height - HEIGHT/2)*(cur_height - HEIGHT/2) + (cur_width - WIDTH/2)*(cur_width - WIDTH/2));
			d2 = sqrt((cur_height - HEIGHT/2)*(cur_height - HEIGHT/2) + (cur_width - WIDTH/4)*(cur_width - WIDTH/4));
			content[cur_height][cur_width][0] = 127 + 127 * sin(d0/200 * 3.14159 * 7000);
			content[cur_height][cur_width][1] = 127 + 127 * sin(d1/200 * 3.14159 * 7000);
			content[cur_height][cur_width][2] = 127 + 127 * sin(d2/200 * 3.14159 * 2000);
			cur_height++;
		}
		cur_width++;
	}
	info.content = (unsigned char *)content;
	info.width = WIDTH;
	info.height = HEIGHT;
	if (bmpfile_save(filename, &info) == bmpfile_ok)
		printf("File %s successfully created.\n", filename);
	else
		printf("ERROR creating file %s.\n", filename);
	return (0);
}
