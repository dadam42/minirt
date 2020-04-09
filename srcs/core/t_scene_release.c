#include "minirt.h"

void	t_scene_release(t_scene *scene)
{
	t_array_collection_release(&scene->object_collection);
	t_array_collection_release(&scene->light_collection);
	t_array_collection_release(&scene->camera_collection);
}
