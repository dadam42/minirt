#include "minirt.h"
#include "libft.h"

void	t_ray_get_color(t_ray *ray
								, t_scene *scene
								, t_color color)
{
	t_scene_object_iterator	obj;
	t_intersection_info		info;

	t_scene_get_object_iterator(scene, &obj);
	t_ray_get_intersection_info(ray, &info);
	while (t_scene_object_iterator_next(&obj))
		t_object_get_intersection_info(obj.cur, &info);
	if (info.object)
		t_object_static_get_color(info.object, scene, &info, color);
	else
		ft_memcpy(color, &scene->background_color, sizeof(t_color));
}
