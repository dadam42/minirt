#include "minirt.h"
#include <stdlib.h>
#include "libft.h"

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
	t_minirt_init_object(minirt, (t_object*)sphere);
	if (!sphere)
		return (minirt_error);
	t_color_from_filert(((t_object*)sphere)->albedo, parsed->sphere.color);
	t_sphere_init_by_filert(sphere, (t_filert_sphere*)parsed);
	((t_object*)sphere)->set_intersection = t_sphere_set_intersection;
	((t_object*)sphere)->get_albedo = t_object_dummy_get_albedo;
	((t_object*)sphere)->get_coord = t_sphere_get_coord;
	((t_object*)sphere)->get_normal = t_sphere_get_normal;
	return (t_scene_add_object(&minirt->scene, (t_object*)sphere));
}
