#include "minirt.h"
#include "libft.h"
extern canonical;

void	t_sphere_init(t_sphere *sphere, t_position center, t_size radius, t_color color)
{
	ft_memcpy(sphere->center, center, sizeof(t_position));
	sphere->radius = radius;
	((t_object*)sphere)->get_intersection_time = t_sphere_get_intersection_time;
	((t_object*)sphere)->get_normal = t_sphere_get_normal;
	((t_object*)sphere)->get_local_albedo = t_object_dummy_get_albedo;
	((t_object*)sphere)->get_local_coord = t_sphere_get_local_coord;
}

void t_sphere_get_intersection_time(t_object *obj
									, t_ray *ray, t_time *time)
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
		if (it < *time && it > SQPREC)
			break ;
		it += delta;
		if (it < *time && it > SQPREC)
			break ;
		return ;
	}
	*time = it;
}
