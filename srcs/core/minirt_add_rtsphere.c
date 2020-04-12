#include "minirt.h"
#include <stdlib.h>
#include "libft.h"

void			sphere_init_by_filert(t_sphere *sphere
										, t_filert_sphere *rtsphere)
{
	sphere->radius = rtsphere->diameter / 2;
}

t_minirt_com	minirt_add_rtsphere(t_minirt *minirt
							, t_filert_parsed_obj *parsed)
{
	t_sphere	*sphere;
	t_position	position;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (minirt_error);
	vec3_from_filert(position, ((t_filert_sphere*)parsed)->center);
	minirt_init_object(minirt, (t_object*)sphere, position, *minirt->canonical);
	color_from_filert(((t_object*)sphere)->albedo, parsed->sphere.color);
	sphere_init_by_filert(sphere, (t_filert_sphere*)parsed);
	((t_object*)sphere)->set_intersection = sphere_set_intersection;
	((t_object*)sphere)->get_albedo = object_dummy_get_albedo;
	((t_object*)sphere)->get_coord = sphere_get_coord;
	((t_object*)sphere)->get_normal = sphere_get_normal;
	return (scene_add_object(&minirt->scene, (t_object*)sphere));
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
