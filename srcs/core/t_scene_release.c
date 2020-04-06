#include "minirt.h"

void	t_scene_release(t_scene *scene)
{
	t_array_collection_release(&scene->objects_collection);
	t_array_collection_release(&scene->lights_collection);
	t_array_collection_release(&scene->cameras_collection);
}
