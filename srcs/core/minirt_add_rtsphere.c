#include "minirt.h"
#include <stdlib.h>
#include "libft.h"

void			sphere_init_by_filert(t_sphere *sphere
										, t_filert_sphere *rtsphere)
{
	sphere->radius = rtsphere->diameter / 2;
}

t_object	*minirt_add_rtsphere(t_minirt *minirt
							, t_filert_parsed_obj *parsed)
{
	t_sphere	*sphere;
	t_position	position;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (0);
	vec3_from_filert(position, ((t_filert_sphere*)parsed)->center);
	object_pre_init(&sphere->object, position, *minirt->canonical);
	color_from_filert(sphere->object.albedo, parsed->sphere.color);
	sphere_init_by_filert(sphere, (t_filert_sphere*)parsed);
	sphere_init(sphere);
	if (sphere->radius < PREC)
	{
		minirt_write_warning(minirt, size_is_nul);
		sphere->object.get_first_intersection =
										object_noop_get_first_intersection;
	}
	return (&sphere->object);
}

/*
t_minirt_com	t_minirt_add_rtsphere(t_minirt *minirt
								, t_filert_parsed_obj *parsed)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		t_minirt_fatal_error(minirt, minirt_mem_error);
	t_color_from_filert(sphere->obj.);
}*/
