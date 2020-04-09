#inclide "minirt.h"

void	t_intersection_info_init(t_intersection_info *info, t_ray *ray)
{
	t_scene_object_iterator	object_it;
	
	info->object = 0;
	info->ray = ray;
	info->time = FOREVER;
	t_scene_get_object_iterator(&object_it);
	while (object_it.next(&object_it))
		t_object_set_intersection_info(object_it.deref(&object_it), info);
}
