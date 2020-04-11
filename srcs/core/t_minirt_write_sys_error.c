#include "minirt.h"
#include <errno.h>
#include <string.h>

void	t_minirt_write_sys_error(t_minirt *minirt)
{
	extern int errno;
	if (errno != 0)
	{
		minirt->write_error(minirt, "System says :\n");
		minirt->write_error(minirt, strerror(errno));
		minirt->write_error(minirt, "\n");
	}
}
