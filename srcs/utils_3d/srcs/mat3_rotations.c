#include "utils_3d.h"
#include <math.h>
#include "libft.h"

static	void canonical_rotation_matrix(double angle, t_mat3 canonical)
{
	canonical[0][0] = cos(angle);
	canonical[0][1] = -sin(angle);
	canonical[0][2] = 0;
	canonical[1][0] = sin(angle);
	canonical[1][1] = cos(angle);
	canonical[1][2] = 0;
	canonical[2][0] = 0;
	canonical[2][1] = 0;
	canonical[2][2] = 1;
}

void	rotation_matrix(t_vec3 axis, double angle, t_mat3 rot)
{
	static	t_mat3	canonical_base = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	t_mat3			canonical_rot;
	t_mat3			base;
	unsigned char	cur;

	canonical_rotation_matrix(angle, canonical_rot);
	ft_memcpy(base[2], axis, sizeof(t_vec3));
	cur = 0;
	while (cur < 3)
	{
		t_vec3_vprod(canonical_base[cur], base[2], base[1]);
		if (t_vec3_sqnorm(base[1]) > 0)
			break;
		cur++;
	}
	t_vec3_vprod(base[1], base[2], base[0]);
	t_mat3_prod(canonical_rot, base, rot);
	t_mat3_transpose(base, base);
	t_mat3_prod(base, rot, rot);
}
