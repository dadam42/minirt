#include "minirt.h"
#include <stdlib.h>

void	minirt_release(t_minirt* minirt)
{
	scene_release(&minirt->scene);
}
