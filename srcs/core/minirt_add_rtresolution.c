#include "minirt.h"

t_minirt_com	minirt_add_rtresolution(t_minirt *minirt
									, t_filert_parsed_obj *parsed)
{
	if (((t_filert_resolution*)parsed)->x > 0)
		minirt->resolution.width = ((t_filert_resolution*)parsed)->x;
	else
	{
		minirt_write_warning(minirt, width_is_nul);
		minirt->resolution.width = minirt->default_display_width;
	}
	if (((t_filert_resolution*)parsed)->y > 0)
		minirt->resolution.height = ((t_filert_resolution*)parsed)->y;
	else
	{
		minirt_write_warning(minirt, height_is_nul);
		minirt->resolution.height = minirt->default_display_height;
	}
	return (minirt_ok);
}
