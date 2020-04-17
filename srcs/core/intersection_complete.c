#include "minirt.h"

void	intersection_complete(t_intersection *inter)
{
	t_vec3_lcomb(inter->time, inter->ray->direction
				, inter->ray->start, inter->position);
	inter->object->get_coord(inter->object, inter->position
							, &inter->coord);
	inter->object->get_albedo(inter->object, &inter->coord
							, inter->albedo);
	inter->object->get_normal(inter->object, &inter->coord
							, inter->normal);
	inter->rson = t_vec3_sprod(inter->normal, inter->ray->direction);
	if (inter->rson > 0)
		t_vec3_smult(-1, inter->normal, inter->normal);
}
