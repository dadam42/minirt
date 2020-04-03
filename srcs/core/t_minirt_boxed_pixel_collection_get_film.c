#include "minirt.h"
#include "libft.h"

void	t_minirt_boxed_pixel_collection_get_film(
						t_minirt_boxed_pixel_collection *collection
						, t_minirt_scene	*scene
						, t_minirt_position	*obs
						, t_minirt_film		*film)
{
	t_minirt_ray					ray;
	t_minirt_color					*cur_color;
	
	ft_memcpy(ray.start, *obs, sizeof(t_minirt_position));
	cur_color = film->legacy;
	while (1)
	{
		t_vec3_init_by_plot3(ray.start, collection->position, ray.direction);
		t_vec3_normalize(ray.direction);
		t_minirt_ray_get_color(&ray, scene, *cur_color);
		if (t_minirt_boxed_pixel_collection_next(collection))
		{
			cur_color++;
			continue;
		}
		break;
	}
}
