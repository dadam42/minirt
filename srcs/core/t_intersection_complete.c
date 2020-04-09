#include "minirt.h"

void	t_intersection_complete(t_intersection *inter)
{
	t_vec3_lcomb(inter->time, inter->ray->direction, inter->ray->start
				, inter->position);
	inter->object->get_coord(inter->object, inter->position, &inter->coords);
	inter->object->get_normal(inter->object, &inter->coords, inter->normal);
	inter->object->get_albedo(inter->object, &inter->coords, inter->albedo);
}
