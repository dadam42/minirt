#include "minirt.h"

void	pcolor_from_filert(
							t_color			*color
							, t_filert_pcolor	*rtpcolor)
{
	color_from_filert(*color, rtpcolor->color);
	t_vec3_smult(rtpcolor->intensity, *color, *color);
}
