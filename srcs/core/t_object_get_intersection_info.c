#include "minirt.c"

void	t_object_get_intersection_info(t_object *obj, t_intersection_info *info)
{
	t_time	time;

	time = info->coord.time;
	obj->get_intersection_time(obj, info->ray, &time);
	if (time < info->coord.time)
	{
		info->coord.time = time;
		info->object = obj;
	}
}
