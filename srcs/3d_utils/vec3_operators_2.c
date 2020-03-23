#include "3d_utils.h"

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
