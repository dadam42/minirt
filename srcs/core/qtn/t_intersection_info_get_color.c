#include "minirt.h"
#include "libft.h"

void	t_intersection_info_get_color(t_intersection_info *info
								, t_scene *scene
								, t_color color)
{
	t_scene_light_iterator light_it;
	t_intersection_info		cur_info;
	t_scene_object_iterator	object_it;
	t_pcolor					light_contibution;
	t_intensity				cur_intensity;
	t_float					tmp;
	t_ray ray;
	t_position				inter_position;
	(void) info;
	(void) scene;
	t_scene_get_light_iterator(scene, &light_it);
	t_vec3_lcomb(info->coord.time, info->ray->direction, info->ray->start, info->coord.position);
	ft_memcpy(light_contibution, scene->ambiant_light, sizeof(t_pcolor));
	ft_memcpy(inter_position, info->coord.position, sizeof(t_position));
	while (t_scene_light_iterator_next(&light_it))
	{	
		cur_intensity = t_ray_init(&ray, inter_position, light_it.cur->position);
		cur_intensity = 1 / (cur_intensity * cur_intensity);
		cur_info.object = 0;
		cur_info.ray = &ray;
		cur_info.coord.time = coef;
		t_scene_get_object_iterator(scene, &object_it);
		while (!cur_info.object && t_scene_object_iterator_next(&object_it))
			object_it.cur->get_intersection_info(object_it.cur, &cur_info);
		if (cur_info.object)
			ft_memcpy(color, object->color, sizeof(t_color));
		else
		{
			//ft_memcpy(color, light_it.cur->pcolor.color, sizeof(t_color));
			cur_intensity *= t_vec3_sprod(info->normal, ray.direction);
			if (cur_intensity  <= 0)
				continue;
			
		}
	}
}
