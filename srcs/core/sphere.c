#include "minirt.h"
#include "libft.h"
#include <math.h>

void	sphere_init(t_sphere *sphere)
{
	sphere->object.get_first_intersection = sphere_get_first_intersection;
	sphere->object.get_normal = sphere_get_normal;
	sphere->object.get_albedo = object_dummy_get_albedo;
	sphere->object.get_coord = sphere_get_coord;
}

void	sphere_get_first_intersection(t_object *obj
								, t_intersection *inter)
{
	t_vec3	os;
	t_float	ucoefs[2];
	t_float	time;

	t_vec3_init_by_plot3(obj->origin, inter->ray->start, os);
	ucoefs[1] = t_vec3_sqnorm(os)
				- ((t_sphere*)obj)->radius * ((t_sphere*)obj)->radius;
	ucoefs[0] = 2 * t_vec3_sprod(os, inter->ray->direction);
	if (get_minimum_positive_upy2_solution_if_exists(ucoefs
													, &time, inter->time))
	{
		inter->time = time;
		inter->object = obj;
	}
}

void	sphere_get_coord(t_object *obj
						, t_position pos
						, t_object_coord *coords)
{
	t_position lpos;

	t_vec3_init_by_plot3(obj->origin, pos, lpos);
	t_mat3_dapply_vec3(lpos, obj->base, coords->cartesian);
	//coords->local[0] = acos(coords->cartesian[2] / ((t_sphere*)obj)->radius);
	//coords->local[1] = atan2(coords->cartesian[1], coords->cartesian[0]);
}

void	sphere_get_normal(t_object* obj
						, t_object_coord *coords
						, t_vec3 dir)
{
	t_vec3_smult(1 / ((t_sphere*)obj)->radius, coords->cartesian
						, dir);
	t_mat3_apply_vec3(obj->base, dir, dir);
}
