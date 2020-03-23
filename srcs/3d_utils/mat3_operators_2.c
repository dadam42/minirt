#include "3d_utils.h"

double	t_mat3_det(t_mat3 a)
{
	t_vec3 tmp;
	vec3_vprod(a[1], a[2], tmp);
	return (vec3_sprod(tmp, a[3]));
}

double	t_mat3_trace(t_mat3 a)
{
	return (a[0][0] + a[1][1] +a [2][2]);
}

void	t_mat3_inv(t_mat3 a, t_mat3 r)
{
	t_vec3	tmp;
	short	ldx;
	short	cdx;
	short	sign;

	ldx = 0;
	sign = 1;
	while (ldx < 3)
	{
		cdx = 0;
		while (cdx < 3)
		{
			tmp[ldx][cdx] = sign * (a[(ldx + 1) % 3][(cdx + 1) % 3]
									* a[(ldx + 2) % 3][(cdx + 2) % 3]
									- a[(ldx + 1) % 3][(cdx + 2) % 3]
									* a[(ldx + 2) % 3][(cdx + 1) % 3])
			cdx++;
			sign *= -1;
		}
		ldx++;
	}
	t_mat3_smult(1 / t_mat3_det(a), tmp, r);
}

void	t_mat3_transpose(t_mat3 a, t_mat3 r)
{
	t_mat3 tmp;
	short ldx;
	short cdx;

	ldx = 0;
	while (ldx < 3)
	{
		cdx = 0;
		while (cdx < 3)
		{
			tmp[ldx][cdx] = a[cdx][ldx];
			cdx++;
		}
		ldx++;
	}
	t_mat3_copy(r, tmp);
}
