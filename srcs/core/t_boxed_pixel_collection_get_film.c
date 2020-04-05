#include "minirt.h"
#include "libft.h"

void	t_boxed_pixel_collection_get_film(
						t_boxed_pixel_collection *collection
						, t_minirt	*minirt
						, t_position	*obs
						, t_film		*film)
{
	t_ray					ray;
	t_color					*cur_color;
	
	ft_memcpy(ray.start, *obs, sizeof(t_position));
	cur_color = film->legacy;
	while (1)
	{
		t_vec3_init_by_plot3(ray.start, collection->position, ray.direction);
		t_vec3_normalize(ray.direction);
		t_ray_trace(&ray, minirt->scene, minirt->max_bounce, *cur_color);
		if (t_boxed_pixel_collection_next(collection))
		{
			cur_color++;
			continue;
		}
		break;
	}
}
