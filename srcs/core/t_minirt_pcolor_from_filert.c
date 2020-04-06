#include "minirt.h"

void	t_pcolor_from_filert(
							t_pcolor			*pcolor
							, t_filert_pcolor	*rtpcolor)
{
	t_color_from_filert(pcolor->color, rtpcolor->color);
	pcolor->intensity = rtpcolor->intensity;
}
