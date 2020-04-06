#include "minirt.h"

void	t_scene_init(t_scene *scene)
{
	t_array_collection_init(&scene->objects_collection);
	t_array_collection_init(&scene->lights_collection);
	t_array_collection_init(&scene->cameras_collection);
}
