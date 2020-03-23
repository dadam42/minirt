#ifndef TEST_H
# define TEST_H
# include <stdio.h>
# include "utils_3d.h"

void	vec3_print(t_vec3 vec);
void	mat3_print(t_mat3 mat);
short	mat3_equal(t_mat3 a, t_mat3 b);
short	vec3_equal(t_vec3 a, t_vec3 b);
double	double_abs(double a);

#endif
