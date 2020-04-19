#include "minirt.h"

void	scene_get_ray_intensity(
			t_scene		*scene	
			, t_ray		*ray
			, t_intensity	intensity)
{
	t_intersection	inter;

	intersection_init(&inter, ray, FOREVER, intensity);
	scene_get_first_intersection(scene, &inter);
	if (inter.object)
	{
		intersection_complete(&inter);
		scene_set_intersection_intensity(scene, &inter);
		t_vec3_mult(inter.intensity, inter.albedo, intensity);
	}
	else
		scene_get_background_intensity(scene, intensity);
}