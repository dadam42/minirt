#include "minirt.h"
#include <math.h>
#include "libft.h"

void	cylinder_get_first_intersection(t_object *object, t_intersection *inter)
{
	t_base	base;
	t_float norm;
	t_ray	locray;
	t_float	sqrad;
	t_float disc;
	t_float time;
	t_float	height;

	t_vec3_vprod(inter->ray->direction, object->base[2], base[1]);
	norm = t_vec3_sqnorm(base[1]);
	if (norm < PREC)
		return;
	norm = sqrt(norm);
	t_vec3_smult(1 / norm, base[1], base[1]);
	ft_memcpy(base[2], object->base[2], sizeof(t_direction));
	t_vec3_vprod(base[1], base[2], base[0]);
	t_vec3_init_by_plot3(object->origin, inter->ray->start, locray.start);
	t_mat3_apply_vec3(base, locray.start, locray.start);
	//t_mat3_dapply_vec3(locray.start, base, locray.start);
	sqrad = ((t_cylinder*)object)->radius * ((t_cylinder*)object)->radius;
	disc = sqrad - locray.start[1] * locray.start[1];
	if (disc <= 0)
		return;
	disc = sqrt(disc);
	locray.direction[2] = t_vec3_sprod(inter->ray->direction, object->base[2]);
	locray.direction[0] = norm / (locray.direction[2] * locray.direction[2] - 1);
	time = 1 / locray.direction[0] * (-locray.start[0] + disc);
	if (time > SQPREC && time < inter->time)
	{
		height = locray.start[2] + time * locray.direction[2];
		if (height > 0 && height < ((t_cylinder*)object)->height)
		{
			inter->time = time;
			inter->object = object;
			return;
		}
	}
	time = 1 / locray.direction[0] * (-locray.start[0] - disc);
	if (time > SQPREC && time < inter->time)
	{
		height = locray.start[2] + time * locray.direction[2];
		if (height > 0 && height < ((t_cylinder*)object)->height)
		{
			inter->time = time;
			inter->object = object;
			return;
		}
	}
}

void	cylinder_get_coord(t_object *obj, t_position pos
							, t_object_coord *coords)
{
	t_position lpos;

	t_vec3_init_by_plot3(obj->origin, pos, lpos);
	t_mat3_dapply_vec3(lpos, obj->base, coords->cartesian);
}

void	cylinder_get_normal(t_object *obj, t_object_coord *coords
							, t_vec3 normal)
{
	normal[0] = coords->cartesian[0];
	normal[1] = coords->cartesian[1];
	normal[2] = 0;
	t_vec3_smult(1 / ((t_cylinder*)obj)->radius, normal, normal);
	t_mat3_apply_vec3(obj->base, normal, normal);
}
