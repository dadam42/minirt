#include "minirt.h"
#include "libft.h"
#include <stdbool.h>
#include <math.h>

static bool	get_coef_if_matter(t_scene *scene, t_light *light
							, t_intersection *inter, t_float *coef)
{
	t_intersection	shinter;
	t_ray			shray;
	t_float			distance;
	t_intensity		intensity;
	t_float			spec;

	distance = ray_init(&shray, inter->position, light->position);
	*coef = t_vec3_sprod(shray.direction, inter->normal);
	if (*coef < 0)
		return (false);
	intersection_init(&shinter, &shray, distance, (t_float*)intensity);
	scene_get_first_intersection(scene, &shinter);
	if (shinter.object)
		return (false);
	*coef /= distance * distance;
	get_flipped_direction(shray.direction, inter->normal, shray.direction);
	(void)spec;
	spec = -t_vec3_sprod(inter->ray->direction, shray.direction);
	if (spec > 0)
	{
		*coef += pow(spec, 4);
	}
	return (true);
}


void	scene_set_intersection_intensity(t_scene *scene
									, t_intersection *inter)
{
	t_scene_light_iterator	light;
	t_float					coef;

	ft_memcpy(inter->intensity, scene->ambiant_light, sizeof(t_intensity));
	scene_get_light_iterator(scene, &light);
	while (light.next(&light))
	{
		if (get_coef_if_matter(scene, light.deref(&light), inter, &coef))
			t_vec3_lcomb(coef, light.deref(&light)->color
						, inter->intensity, inter->intensity);
	}
}
