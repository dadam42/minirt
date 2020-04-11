#include "minirt.h"
#include <math.h>

void	t_sphere_set_intersection_alt(t_object *obj
		, t_ray *ray, t_intersection *inter)
{
	t_vec3			n;
	t_vec3			h;
	double			s;
	double			dlt;
	double			time;

	t_vec3_init_by_plot3(ray->start, ((t_sphere*)obj)->center, n);
	t_vec3_smult(s = t_vec3_sprod(ray->direction, n), ray->direction, h);
	t_vec3_init_by_plot3(n, h, h);
	dlt = ((t_sphere*)obj)->radius * ((t_sphere*)obj)->radius- t_vec3_sqnorm(h);
	if (dlt < 0)
		return;
	dlt = sqrt(dlt);
	time = s - dlt;
	while (1)
	{
		if (time > 0 && time < inter->time)
			break ;
		time += 2 * dlt;
		if (time > 0 && time < inter->time)
			break;
		return;
	}
	inter->time = time;
	inter->object = obj;
}
