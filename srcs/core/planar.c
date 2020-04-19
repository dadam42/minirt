#include "minirt.h"

void	planar_get_first_intersection(t_object *object
									, t_intersection *inter
									, t_planar_get_first_intersection_test test)
{
	t_float nproj;
	t_float	time;
	t_position os;

	nproj = t_vec3_sprod(inter->ray->direction, object->base[2]);
	if (nproj > PREC || nproj < -PREC)
	{
		t_vec3_init_by_plot3(object->origin, inter->ray->start, os);
		time = - t_vec3_sprod(os, object->base[2]) / nproj;
		if (time > PREC && time < inter->time && test(object, inter, time))
		{
			inter->time = time;
			inter->object = object;
		}
	}
}

bool	planar_get_first_intersection_test_ok(t_object *object
											, t_intersection *inter
											, t_time time)
{
	(void)object;
	(void)inter;
	(void)time;
	return (true);
}
