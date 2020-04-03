#include "minirt.h"
#include "libft.h"

void	t_minirt_intersection_info_init(t_minirt_intersection_info *info, t_minirt_ray *ray)
{
	info->ray = ray;
	info->coord.time = FARAWAY;
	info->object = 0;
}

void	t_minirt_ray_get_color(t_minirt_ray *ray
								, t_minirt_scene *scene
								, t_minirt_color color)
{
	t_minirt_scene_object_iterator	obj;
	t_minirt_intersection_info		info;

	t_minirt_scene_get_object_iterator(scene, &obj);
	t_minirt_intersection_info_init(&info, ray);
	while (t_minirt_scene_object_iterator_next(&obj))
		obj.cur->get_intersection_info(obj.cur, &info);
	if (info.object)
	{
		t_minirt_object_static_get_color(info.object, scene, &info, color);
	}
	else
		ft_memcpy(color, &scene->background_color, sizeof(t_minirt_color));
}
