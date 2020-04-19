#include "test.h"
#include <math.h>

int main()
{
	t_vec3 axe = {1, 0, 0};
	double angle = 90;
	t_mat3 rot;

	rotation_matrix(axe, angle * M_PI / 180, rot);
	mat3_print(rot);
	return (0);
}
