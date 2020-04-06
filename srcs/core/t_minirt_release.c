#include "minirt.h"

void	t_minirt_release(t_minirt* minirt)
{
	t_scene_release(&minirt->scene);
}
