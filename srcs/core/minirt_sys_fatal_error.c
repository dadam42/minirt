#include "minirt.h"

void	minirt_sys_fatal_error(t_minirt *minirt)
{
	minirt_write_sys_error(minirt);
	minirt_exit(minirt, minirt_error);
}
