#include "minirt.h"

void	t_intersection_info_dummy_get_position(
									t_intersection_info *info
									, t_position *position)
{
	position = &info->coord.position;
}

void	t_intersection_info_clever_get_position(
									t_intersection_info *info
									, t_position *position)
{
	t_vec3_lcomb(info->coord.time, info->ray->direction
				, info->ray->start, info->coord.position);
	info->get_position = t_intersection_info_dummy_get_position;
	info->getposition(info, position);
}
