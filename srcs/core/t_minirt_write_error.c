#include "minirt.h"

void	t_minirt_write_error(t_minirt *minirt, t_minirt_com errcode)
{
	minirt->write_error(minirt, t_minirt_strerror(minirt, errcode));
}
