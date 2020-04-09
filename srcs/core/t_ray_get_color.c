#include "minirt.h"
#include "libft.h"

void	t_ray_get_color(
			t_ray		*ray
			, t_minirt	*minirt
			, t_color	color)
{
	t_intersection	inter;
	
	t_intersection_init(&inter, &minirt->scene, ray, FOREVER);	
	if (inter.object)
	{
		t_intersection_complete(&inter);
		t_scene_get_light_influence(&minirt->scene, &inter);
		t_vec3_mult(inter.albedo, inter.light_influence, color);
	}
	else
		ft_memcpy(color, *minirt->scene.background_color, sizeof(t_color));
}
