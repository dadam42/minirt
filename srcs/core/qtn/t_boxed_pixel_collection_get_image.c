#include "minirt.h"
#include "libft.h"

void	t_boxed_pixel_collection_get_image(
						t_boxed_pixel_collection *collection
						, t_scene	*scene
						, t_position	*obs
						, t_image	*image)
{
	t_ray					ray;
	
	ft_memcpy(ray.start, *obs, sizeof(t_position));
	while (1)
	{
		t_vec3_init_by_plot3(ray.start, collection->position, ray.direction);
		t_vec3_normalize(ray.direction);
		t_ray_get_color(&ray, scene
			, image->film.legacy[collection->cur[height] * image->resolution.width
									+ collection->cur[width]]);
		if (t_boxed_pixel_collection_next(collection))
			continue;
		break;
	}
}

