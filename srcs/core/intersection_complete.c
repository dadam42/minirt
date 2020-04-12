#include "minirt.h"

void	intersection_complete(t_intersection *inter)
{
	t_vec3_lcomb(inter->time, inter->ray->direction, inter->ray->start
				, inter->position);
	inter->object->get_coord(inter->object, inter->position, &inter->coords);
	inter->object->get_normal(inter->object, &inter->coords, inter->normal);
	inter->ray_dot_normal = t_vec3_sprod(inter->ray->direction, inter->normal);
	if (inter->ray_dot_normal > 0)
	{
		t_vec3_smult(-1, inter->normal, inter->normal);
		inter->ray_dot_normal *= -1;
	}
	inter->object->get_albedo(inter->object, &inter->coords, inter->albedo);
}
