#include "minirt.h"
#include "libft.h"

void	plane_get_first_intersection(t_object *object, t_intersection *inter)
{
	t_float nproj;
	t_float	time;
	t_position os;

	nproj = t_vec3_sprod(inter->ray->direction, object->base[2]);
	if (nproj > PREC || nproj < -PREC)
	{
		t_vec3_init_by_plot3(object->origin, inter->ray->start, os);
		time = - t_vec3_sprod(os, object->base[2]) / nproj;
		if (time > PREC && time < inter->time)
		{
			inter->time = time;
			inter->object = object;
		}
	}
}

void	plane_get_coord(t_object *obj
						, t_position pos
						, t_object_coord *coords)
{
	t_position lpos;

	t_vec3_init_by_plot3(obj->origin, pos, lpos);
	t_mat3_dapply_vec3(lpos, obj->base, coords->cartesian);
}

void	plane_get_normal(t_object *obj
						, t_object_coord *coords
						, t_vec3 normal)
{
	(void)coords;
	ft_memcpy(normal, obj->base[2], sizeof(t_direction));
}
