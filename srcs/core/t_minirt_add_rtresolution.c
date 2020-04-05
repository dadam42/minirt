#include "minirt.h"

t_minirt_com	t_minirt_add_rtresolution(t_minirt *minirt
									, t_filert_parsed_obj *parsed)
{
	minrt->resolution.width = ((t_filert_resolution*)parsed)->x;
	minrt->resolution.height = ((t_filert_resolution*)parsed)->y;
	return (minirt_ok);
}
