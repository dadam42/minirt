#include "minirt.h"

void	t_minirt_sys_fatal_error(t_minirt *minirt)
{
	t_minirt_write_sys_error(minirt);
	t_minirt_exit(minirt, minirt_error);
}
