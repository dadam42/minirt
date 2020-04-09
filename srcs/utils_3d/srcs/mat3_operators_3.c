#include "utils_3d.h"
#include "libft.h"

void	t_mat3_apply_vec3(t_mat3 a, t_vec3 v, t_vec3 r)
{
	unsigned char	ldx;
	unsigned char	cdx;
	t_vec3			tmp;

	ldx = 0;
	while (ldx < 3)
	{
		cdx = 0;
		tmp[ldx] = 0;
		while (cdx < 3)
		{
			tmp[ldx] += v[cdx] * a[ldx][cdx];
			cdx++;
		}
		ldx++;
	}
	ft_memcpy(r, tmp, sizeof(t_vec3));
}

void	t_mat3_dapply_vec3(t_vec3 tv, t_mat3 a, t_vec3 r)
{
	unsigned char	ldx;
	unsigned char	cdx;
	t_vec3			tmp;

	cdx = 0;
	while (cdx < 3)
	{
		ldx = 0;
		tmp[cdx] = 0;
		while (ldx < 3)
		{
			tmp[cdx] += tv[ldx] * a[ldx][cdx];
			ldx++;
		}
		cdx++;
	}
	ft_memcpy(r, tmp, sizeof(t_vec3));
}
