#include "minirt.h"
#include "libft.h"

void	t_minirt_object_static_get_color(t_minirt_object *object
								, t_minirt_scene *scene
								, t_minirt_intersection_info *info
								, t_minirt_color color)
{
	t_minirt_scene_light_iterator light_it;
	t_minirt_intersection_info		cur_info;
	t_minirt_scene_object_iterator	object_it;
	double coef;
	t_minirt_ray ray;
	(void) info;
	(void) scene;
	t_minirt_scene_get_light_iterator(scene, &light_it);
	t_vec3_lcomb(info->coord.time, info->ray->direction, info->ray->start, info->coord.position);
	while (t_minirt_scene_light_iterator_next(&light_it))
	{	
		coef = t_minirt_ray_init(&ray, info->coord.position, light_it.cur->position);
		cur_info.object = 0;
		cur_info.ray = &ray;
		cur_info.coord.time = coef;
		t_minirt_scene_get_object_iterator(scene, &object_it);
		while (!cur_info.object && t_minirt_scene_object_iterator_next(&object_it))
			object_it.cur->get_intersection_info(object_it.cur, &cur_info);
		if (cur_info.object)
			ft_memcpy(color, object->color, sizeof(t_minirt_color));
		else
			ft_memcpy(color, light_it.cur->pcolor.color, sizeof(t_minirt_color));
	}
}
