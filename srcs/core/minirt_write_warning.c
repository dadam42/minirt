#include "minirt.h"

void	minirt_write_warning(t_minirt *minirt, t_minirt_warning wcode)
{
	minirt->write_warning(minirt, minirt->warn_msg[wcode]);
}