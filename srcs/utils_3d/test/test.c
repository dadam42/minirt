#include "test.h"
#define PREC 1e-15

void	vec3_print(t_vec3 vec)
{
	printf("<%.2f, %.2f, %.2f>", vec[0], vec[1], vec[2]);
}

void	mat3_print(t_mat3 mat)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		printf ("|");
		vec3_print(mat[cur]);
		printf("|\n");
		cur++;
	}
}

double double_abs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

short	mat3_equal(t_mat3 a, t_mat3 b)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		if (!vec3_equal(a[cur], b[cur]))
			return (0);
		cur++;
	}
	return (1);
}

short	vec3_equal(t_vec3 a, t_vec3 b)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		if (double_abs(a[cur] - b[cur]) > PREC)
			return (0);
		cur++;
	}
	return (1);
}
