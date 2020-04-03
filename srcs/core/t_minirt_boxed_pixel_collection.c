#include "minirt.h"

bool	t_minirt_boxed_pixel_collection_next(
			t_minirt_boxed_pixel_collection *collection)
{
	collection->cur[width]++;
	if (collection->cur[width] < collection->max[width])
	{
		t_vec3_add(collection->position, collection->dw, collection->position);
		return (true);
	}
	collection->cur[height]++;
	if (collection->cur[height] < collection->max[height])
	{
		collection->cur[width] = collection->min[width];
		t_vec3_add(collection->position, collection->dh, collection->position);
		return (true);
	}
	return (false);
}
