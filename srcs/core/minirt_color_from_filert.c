#include "minirt.h"

void	color_from_filert(t_color color, t_filert_color rtcolor)
{
	unsigned char cur;

	cur = 0;
	while (cur < 3)
	{
		color[cur] = (t_float)rtcolor[cur] / 255;
		cur++;
	}
}
