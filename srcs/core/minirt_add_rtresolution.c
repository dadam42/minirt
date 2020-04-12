#include "minirt.h"

t_minirt_com	minirt_add_rtresolution(t_minirt *minirt
									, t_filert_parsed_obj *parsed)
{
	minirt->resolution.width = ((t_filert_resolution*)parsed)->x;
	minirt->resolution.height = ((t_filert_resolution*)parsed)->y;
	return (minirt_ok);
}
