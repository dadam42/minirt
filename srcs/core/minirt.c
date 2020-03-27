#include "minirt.h"
#include "libft.h"
#include "bmpfile.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
void	vec3_print(t_vec3 vec)
{
	printf("<%.12f, %.12f, %f>\n", vec[0], vec[1], vec[2]);
}

short	int_sphere_ray(t_minirt_sphere *sphere, t_minirt_ray *ray)
{
	t_vec3	tmp;
	float	b;
	float	c;
	float	delta;

	t_vec3_init_by_plot3(ray->start, sphere->center, tmp);
	c = t_vec3_sqnorm(tmp) - sphere->radius * sphere->radius;
	b = 2 * t_vec3_sprod(tmp, ray->direction);
	delta = b * b - 4 * c;
	if (delta > 0)
		return (1);
	return (0);	
}

short t_minirt_sphere_inter_ray(t_minirt_sphere *sphere, t_minirt_ray *ray, double *t)
{
	t_vec3	tmp;
	float	b;
	float	c;
	float	delta;

	t_vec3_init_by_plot3(ray->start, sphere->center, tmp);
	c = t_vec3_sqnorm(tmp) - sphere->radius * sphere->radius;
	b = 2 *t_vec3_sprod(tmp, ray->direction);
	delta = b * b - 4 * c;
	if (delta > 0)
	{
		delta = sqrt(delta);
		if ((((c = (-b + delta) / 2) < *t) ||
			((c = (-b - delta) / 2) < *t))
			&& c > PREC)
		{
			*t = c;
			return (1);
		}
	}
	return (0);
}

int display()
{
	return (0);
}

int main()
{
	display();
	return (0);
}
