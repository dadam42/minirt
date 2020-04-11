#include "minirt.h"
#include <stdlib.h>

void	t_minirt_exit(t_minirt *minirt, t_minirt_com exitcode)
{
	t_minirt_release(minirt);
	exit(exitcode);
}
