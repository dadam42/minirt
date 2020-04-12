#include "minirt.h"
#include "libft.h"

t_minirt_com	minirt_add_rtambiant_light(t_minirt *minirt
									, t_filert_parsed_obj *parsed)
{
	pcolor_from_filert(&minirt->scene.ambiant_light, &parsed->ambiant_light);
	return (minirt_ok);
}