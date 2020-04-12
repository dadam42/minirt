#include "minirt.h"
#include "libft.h"
#include <math.h>

void sphere_set_intersection(t_object *obj
									, t_ray *ray, t_intersection *inter)
{
	t_vec3	tmp;
	double	it;
	double	b;
	double	c_or_delta;

	t_vec3_init_by_plot3(((t_sphere*)obj)->center, ray->start, tmp);
	c_or_delta = t_vec3_sqnorm(tmp)
				- ((t_sphere*)obj)->radius * ((t_sphere*)obj)->radius;
	b = 2 * t_vec3_sprod(tmp, ray->direction);
	c_or_delta = b * b - 4 * c_or_delta;
	if (c_or_delta < PREC)
		return ;
	c_or_delta = sqrt(c_or_delta);
	it = (-b - c_or_delta) / 2;
	while (1)
	{
		if (it < inter->time - PREC && it > SQPREC)
			break ;
		it += c_or_delta;
		if (it < inter->time - PREC && it > SQPREC)
			break ;
		return ;
	}
	inter->time = it;
	inter->object = obj;
}

void					sphere_get_coord
							(t_object* obj, t_position pos, t_object_coord *coords)
{
	t_position lpos;

	t_vec3_init_by_plot3(((t_sphere*)obj)->center, pos, lpos);
	t_mat3_dapply_vec3(lpos, obj->base, coords->cartesian);
	coords->local[0] = acos(coords->cartesian[2] / ((t_sphere*)obj)->radius);
	coords->local[1] = atan2(coords->cartesian[1], coords->cartesian[0]);
}

void					sphere_get_normal
							(t_object* obj, t_object_coord *coords,  t_vec3 dir)
{
	t_vec3_smult(1 / ((t_sphere*)obj)->radius, coords->cartesian
						, dir);
	t_mat3_apply_vec3(obj->base, dir, dir);
}
