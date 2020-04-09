#include "minirt.h"
#include "libft.h"

void	t_scene_get_light_influence(t_scene* scene, t_intersection *inter)
{
	t_scene_light_iterator	light;
	t_intersection			shadow_inter;
	t_ray					shadow_ray;
	t_size					dist;

	t_scene_get_light_iterator(scene, &light);
	while (light.next(&light))
	{
		dist = t_ray_init(&shadow_ray, inter->position
						, light.deref(&light)->position);
		t_intersection_init(&shadow_inter, scene, &shadow_ray);
		if (!shadow_inter.object)
		{
			t_vec3_lcomb(t_vec3_sprod(shadow_ray.direction, inter->normal)
						/ dist
						, light.deref(&light)->color, inter->light_influence
						, inter->light_influence);
		}
	}
}
