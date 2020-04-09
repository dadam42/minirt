#include "minirt.h"
#include <math.h>

void	t_sphere_set_intersection_alt(t_object *obj
										, t_ray *ray, t_intersection *inter)
{
	t_vec3			tmp;
	double			delta;
	double			time;
	unsigned char	cur;
	double			sn;

	t_vec3_init_by_plot3(ray->start, ((t_sphere*)obj)->center, tmp);
	t_vec3_lcomb(-t_vec3_sprod(tmp, ray->direction), ray->direction, tmp, tmp);
	delta = ((t_sphere*)obj)->radius * ((t_sphere*)obj)->radius - t_vec3_sqnorm(tmp);
	if (delta < PREC)
		return;
	delta = sqrt(delta);
	cur = 4;
	while (1)
		if ((sn = ray->direction[--cur]) > PREC)
		{
			sn = fabs(tmp[cur] / sn);
			break;
		}
	while (1)
	{
		if (((time = sn - delta) > SQPREC) && time < inter->time - PREC)
			break;
		if ((time += 2 * delta) > SQPREC && time < inter->time - PREC)
			break;
		return;
	}
	inter->time = time;
	inter->object = obj;
}
