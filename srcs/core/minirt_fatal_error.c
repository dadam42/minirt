#include "minirt.h"

void	minirt_fatal_error(t_minirt *minirt, t_minirt_com errcode)
{
	minirt->write_error(minirt, minirt_strerror(minirt, errcode));
	minirt_exit(minirt, minirt_error);
}
