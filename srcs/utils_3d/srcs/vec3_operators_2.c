#include "utils_3d.h"
#include <math.h>

void t_vec3_smult(double l, t_vec3 a, t_vec3 r)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		r[cur] = l * a[cur];
		cur++;
	}
}

double	t_vec3_sqnorm(t_vec3 a)
{
	return (a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

void	t_vec3_normalize(t_vec3 a)
{
	t_vec3_smult(sqrt(t_vec3_sqnorm(a)), a, a);
}
