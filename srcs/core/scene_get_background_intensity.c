#include "minirt.h"
#include "libft.h"

void	scene_get_background_intensity(t_scene *scene
										, t_intensity intensity)
{
	ft_memcpy(intensity
				, *scene->background_color, sizeof(t_intensity));
}
