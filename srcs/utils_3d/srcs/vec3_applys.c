#include "utils_3d.h"


void	t_vec3_apply(t_vec3 a, t_real_app app, t_vec3 r)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		r[cur] = app(a[cur]);
		cur++;
	}
}

void	t_vec3_apply2(t_vec3 a, t_vec3 b, t_bireal_app app, t_vec3 r)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		r[cur] = app(a[cur], b[cur]);
		cur++;
	}
}
