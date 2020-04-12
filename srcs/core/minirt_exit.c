#include "minirt.h"
#include <stdlib.h>

void	minirt_exit(t_minirt *minirt, t_minirt_com exitcode)
{
	minirt_release(minirt);
	exit(exitcode);
}
