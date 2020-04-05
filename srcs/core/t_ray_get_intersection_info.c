#include "minirt.h"

void	t_ray_get_intersection_info(t_ray *ray, t_intersection_info *info)
{
	info->ray = ray;
	info->coord.time = FOREVER;
	info->object = 0;
}
