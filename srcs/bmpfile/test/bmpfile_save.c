#include "bmpfile.h"
#include <stdio.h>
#include <math.h>
#define HEIGHT 2
#define WIDTH  2
typedef unsigned char t_pixel[3];
typedef t_pixel t_content[HEIGHT][WIDTH];

float my_abs(float x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

/*void	get_funny_flag(t_bmpfile_info *info, t_content *content)
{

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
			
			content[cur_height][cur_width][0] = 255;
			if (cur_width > 666)
				content[cur_height][cur_width][0] = 0;
			content[cur_height][cur_width][1] = 0;
			if (cur_width <= 666 && cur_width > 333)
				content[cur_height][cur_width][1] = 255;
			content[cur_height][cur_width][2] = 0;
			if (cur_width > 333)
				content[cur_height][cur_width][2] = 255;
			

			cur_height++;
		}
		cur_width++;
	}
}*/

void	get_wikipedia_content(t_bmpfile_info *info, t_content *content)
{
	(void)info;
	(*content)[0][0][0] = 255; 
	(*content)[0][0][1] = 0; 
	(*content)[0][0][2] = 0; 
	(*content)[0][1][0] = 0; 
	(*content)[0][1][1] = 255; 
	(*content)[0][1][2] = 0; 
	(*content)[1][0][0] = 0; 
	(*content)[1][0][1] = 0; 
	(*content)[1][0][2] = 255; 
	(*content)[1][1][0] = 255; 
	(*content)[1][1][1] = 255; 
	(*content)[1][1][2] = 255; 
}


void	get_red_content(t_bmpfile_info *info, t_content *content)
{
	int cur_width, cur_height;

	cur_width = 0;
	while (cur_width < info->width)
	{
		cur_height = 0;
		while (cur_height < info->height)
		{
			(*content)[cur_height][cur_width][0] = 255;
			(*content)[cur_height][cur_width][1] = 0;
			(*content)[cur_height][cur_width][2] = 0;
			cur_height++;
		}
		cur_width++;
	}
}


int main()
{
	char *filename = "red.bmp";
	t_content content;
	t_bmpfile_info info;

	info.width = WIDTH;
	info.height = HEIGHT;
	get_red_content(&info, &content);
	if (save_bmpfile(filename, (unsigned char*)content, &info) == bmpfile_ok)
		printf("File %s successfully created.\n", filename);
	else
		printf("ERROR creating file %s.\n", filename);
	return (0);
}
