#include "minirt.h"
#include <math.h>

bool	square_get_first_intersection_test(t_object *obj
										, t_intersection *inter
										, t_time time)
{
	t_position	position;
	t_float		x;
	t_float		y;

	t_vec3_lcomb(time, inter->ray->direction, inter->ray->start, position);
	t_vec3_init_by_plot3(obj->origin, position, position);
	x = t_vec3_sprod(position, obj->base[0]);
	y = t_vec3_sprod(position, obj->base[1]);
	if (fabs(x) < ((t_square*)obj)->size && (fabs(y) < ((t_square*)obj)->size))
		return (true);
	return (false);
}

void	square_get_first_intersection(t_object *obj, t_intersection *inter)
{
	planar_get_first_intersection(obj, inter
								, square_get_first_intersection_test);
}
