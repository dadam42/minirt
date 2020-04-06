#include "minirt.h"
#include <math.h>
#include "libft.h"

void					t_direction_from_filert(
							t_direction	dir,
							t_filert_direction	rtdir,
							t_direction			default_dir)
{
	double sqnorm;

	vec3_from_filert(dir, rtdir);
	sqnorm = t_vec3_sqnorm(dir);
	if (sqnorm > PREC)
		t_vec3_smult(1 / sqrt(sqnorm), dir, dir);
	else
		ft_memcpy(dir, default_dir, sizeof(t_direction));
}
