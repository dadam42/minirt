#include "minirt.h"
#include <math.h>

void	t_minirt_pixel_collection_init(t_minirt_pixel_collection *collection
									, t_minirt_camera *camera
									, t_minirt_resolution *resolution
									, t_minirt_screen_box *box)
{
	double	pixel_size;

	pixel_size = 2 * tan(camera->fov / 2 * PI / 180) / resolution->width;
	t_vec3_smult(pixel_size, camera->right, collection->dw);
	t_vec3_smult(pixel_size, camera->up, collection->dh);
	collection->height = box->ulc[minirt_height];
	t_vec3_lcomb((-(double)resolution->height + 1) / 2 + collection->height, collection->dh, camera->view, collection->position);
	collection->width_min = box->ulc[minirt_width];
	collection->width = collection->width_min - 1;
	t_vec3_lcomb((-(double)resolution->width - 1) / 2 + collection->width, collection->dw, collection->position, collection->position);
	t_vec3_lcomb(-resolution->width + 1, collection->dw, collection->dh, collection->dh);
	collection->height_max = box->brc[minirt_height];
	collection->width_max = box->brc[minirt_width];
}

char	t_minirt_pixel_collection_next(t_minirt_pixel_collection *collection)
{
	collection->width++;
	if (collection->width < collection->width_max)
	{
		t_vec3_add(collection->position, collection->dw, collection->position);
		return (1);
	}
	collection->height++;
	if (collection->height < collection->height_max)
	{
		collection->width = collection->width_min;
		t_vec3_add(collection->position, collection->dh, collection->position);
		return (1); 
	}
	return (0);
}

