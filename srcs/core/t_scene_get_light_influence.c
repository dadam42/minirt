#include "minirt.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

static t_float	light_intensity(t_float dist, t_vec3 shdir, t_intersection *inter)
{
	double ret;
	double spec;
	double spec_addition;
	//static int ncall = 0;

	ret = 0;
	spec_addition = 0;
	spec = t_vec3_sprod(inter->ray->direction, shdir);
	//printf("%f\n", spec);
	if (spec > 0)
	{//ncall++, printf("%d\n", ncall);
		spec_addition = -2 * inter->ray_dot_normal;
		ret = spec * spec * spec;
	}
	return ((1 / dist + spec_addition) * t_vec3_sprod(shdir, inter->normal)
			+ ret);
}

void	t_scene_get_light_influence(t_scene* scene, t_intersection *inter)
{
	t_scene_light_iterator	light;
	t_intersection			shadow_inter;
	t_ray					shadow_ray;
	t_size					distcoef;

	t_scene_get_light_iterator(scene, &light);
	while (light.next(&light))
	{
		distcoef = t_ray_init(&shadow_ray, inter->position
						, light.deref(&light)->position);
		t_intersection_init(&shadow_inter, scene, &shadow_ray, distcoef);
		if (!shadow_inter.object)
		{
			distcoef = light_intensity(distcoef, shadow_ray.direction, inter);
			//distcoef = t_vec3_sprod(shadow_ray.direction, inter->normal) / distcoef;
			t_vec3_lcomb(distcoef, light.deref(&light)->color
						, inter->light_influence, inter->light_influence);
		}
	}
}
