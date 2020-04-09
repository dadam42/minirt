#include "minirt.h"
#include "libft.h"

void	t_minirt_init(t_minirt *minirt)
{
	static t_base		canonical = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	static t_direction	default_direction = {-1, 0, 0};

	minirt->canonical = &canonical;
	minirt->default_direction = &default_direction;
	t_scene_init(&minirt->scene);
}
