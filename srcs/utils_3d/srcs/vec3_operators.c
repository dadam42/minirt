#include "utils_3d.h"

void t_vec3_add(t_vec3 a, t_vec3 b, t_vec3 r)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		r[cur] = a[cur] + b[cur];
		cur++;
	}
}

void	t_vec3_lcomb(double l, t_vec3 a, t_vec3 b, t_vec3 r)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		r[cur] = l * a[cur] + b[cur];
		cur++;
	}
}

double	t_vec3_sprod(t_vec3 a, t_vec3 b)
{
	return (a[0]*b[0] + a[1]*b[1] + a[2]*b[2]);
}

void	t_vec3_vprod(t_vec3 a, t_vec3 b, t_vec3 r)
{
	int		cur;
	t_vec3	tmp;

	cur = 0;
	while (cur < 3)
	{
		tmp[cur] = a[(cur + 1) % 3] 
					* b[(cur + 2) % 3]
					- a[(cur + 2) % 3]
					* b[(cur + 1) % 3];
		cur++;
	}
	cur = 0;
	while (cur < 3)
	{
		r[cur] = tmp[cur];
		cur++;
	}
}

void	t_vec3_mult(t_vec3 a, t_vec3 b, t_vec3 r)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		r[cur] = a[cur] * b[cur];
		cur++;
	}
}
