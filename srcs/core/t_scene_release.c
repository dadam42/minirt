#include "minirt.h"
#include <stdlib.h>

void	t_scene_release(t_scene *scene)
{
	t_scene_object_iterator object;
	t_scene_camera_iterator	camera;
	t_scene_light_iterator	light;

	t_scene_get_object_iterator(scene, &object);
	while (object.next(&object))
		free(object.deref(&object));
	t_scene_get_camera_iterator(scene, &camera);
	while (camera.next(&camera))
		free(camera.deref(&camera));
	t_scene_get_light_iterator(scene, &light);
	while (light.next(&light))
		free(light.deref(&light));
	t_array_collection_release(&scene->object_collection);
	t_array_collection_release(&scene->light_collection);
	t_array_collection_release(&scene->camera_collection);
}
