#include "minirt.h"

void	minirt_write_error(t_minirt *minirt, t_minirt_com errcode)
{
	minirt->write_error(minirt, minirt_strerror(minirt, errcode));
}
