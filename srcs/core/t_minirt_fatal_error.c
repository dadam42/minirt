#include "minirt.h"

void	t_minirt_fatal_error(t_minirt *minirt, t_minirt_com errcode)
{
	minirt->write_error(minirt, t_minirt_strerror(minirt, errcode));
	t_minirt_exit(minirt, minirt_error);
}
