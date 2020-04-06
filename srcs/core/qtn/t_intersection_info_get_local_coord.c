#include "minirt.h"

void	t_intersection_info_dummy_get_local_coord(
									t_intersection_info *info
									, t_local_coord *local)
{
	local = &info->coord.local;
}

void	t_intersection_info_clever_get_local_coord(
									t_intersection_info *info
									, t_local_coord *local_coord)
{
	t_position *position;

	info->get_position(info, position);
	info->obj->get_local_coord(info->obj, position, info->coord.local);
	info->get_local_coord = t_intersection_info_dummy_get_local_coord;
	info->get_local(info, local_coord);		
}
