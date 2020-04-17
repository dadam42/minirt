#include "minirt.h"

t_minirt_com	minirt_add_prop_from_filert(t_minirt *minirt
							, t_filert_parser_com type
							, t_filert_parsed_obj *parsed)
{
	if (type == filert_resolution)
		return (minirt_add_rtresolution(minirt, parsed));
	return (minirt_add_rtambiant_light(minirt, parsed));
}
