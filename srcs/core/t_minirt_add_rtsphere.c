#include "minirt.h"
#include <stdlib.h>


void			t_sphere_init_by_filert(t_sphere *sphere
										, t_filert_sphere *rtsphere)
{
	vec3_from_filert(sphere->center, rtsphere->center);
	sphere->radius = rtsphere->diameter / 2;
}

t_minirt_com	t_minirt_add_rtsphere(t_minirt *minirt
							, t_filert_parsed_obj *parsed)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	t_minirt_init_object(minirt, (object*)sphere);
	if (!sphere)
		return (minirt_error);
	ft_memcpy(object->color, color, sizeof(color));
	t_sphere_init_by_filert((object*)sphere, (t_filert_sphere*)parsed);
	if (t_scene_add_object((t_object*)sphere) != minirt_ok)
		return (minirt_error);
	return (minirt_ok);
}
