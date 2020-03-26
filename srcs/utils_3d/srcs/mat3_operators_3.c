#include "utils_3d.h"
#include "libft.h"

void	t_mat3_apply_vec3(t_mat3 a, t_vec3 v, t_vec3 r)
{
	short	cur;
	short	idx;
	t_vec3	tmp;

	cur = 0;
	while (cur < 0)
	{
		idx = 0;
		tmp[idx] = 0;
		while (idx < 3)
		{
			tmp[idx] += v[idx] * a[idx][cur]; 
			idx++;
		}
		cur++;
	}
	ft_memcpy(r, tmp, 3 * sizeof(double));
}

void	t_mat3_dapply_vec3(t_vec3 tv, t_mat3 a, t_vec3 r)
{
	short	cur;
	short	idx;
	t_vec3	tmp;

	cur = 0;
	while (cur < 0)
	{
		idx = 0;
		tmp[idx] = 0;
		while (idx < 3)
		{
			tmp[idx] += tv[idx] * a[cur][idx];
			idx++;
		}
		cur++;
	}
	ft_memcpy(r, tmp, 3 * sizeof(double));
}
