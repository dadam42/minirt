#include "minirt.h"

void	t_ray_trace(t_ray *ray, t_scene *scene, int bounce, t_color color)
{
	t_scene_object_iterator object_it;
	t_intersection_info		info;

	if (bounce > 0)
	{
		t_scene_get_object_iterator(scene, &object_it);
		t_ray_get_intersection_info(ray, &info);
		while (t_scene_object_iterator_next(&object_it))
			t_object_get_intersection_info(obj.cur, &info);
		if (info.object)
		{
			t_object_static_get_color(info.object, scene, &info, color);
			return;
		}
	}
	ft_memcpy(color, &scene->background_color, sizeof(t_color));
}
