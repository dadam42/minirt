#include "minirt.h"
#include "libft.h"

void	t_intersection_init(t_intersection *inter
						, t_scene *scene, t_ray *ray, t_time time)
{
	t_scene_object_iterator	object_it;
	
	inter->object = 0;
	inter->ray = ray;
	inter->time = time;
	ft_memcpy(inter->light_influence, scene->ambiant_light, sizeof(t_color));
	t_scene_get_object_iterator(scene, &object_it);
	while (object_it.next(&object_it))
		t_object_preset_intersection(object_it.deref(&object_it), inter);
}
