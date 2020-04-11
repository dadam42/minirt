#include "minirt.h"
#include <stdlib.h>

void	t_minirt_release(t_minirt* minirt)
{
	t_scene_release(&minirt->scene);
}
