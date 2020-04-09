#include "minirt.h"

void	t_pcolor_from_filert(
							t_color			*color
							, t_filert_pcolor	*rtpcolor)
{
	t_color_from_filert(*color, rtpcolor->color);
	t_vec3_smult(rtpcolor->intensity, *color, *color);
}
