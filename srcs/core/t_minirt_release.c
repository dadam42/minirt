#include "minirt.h"
#include <stdlib.h>

void	t_minirt_release(t_minirt* minirt)
{
	t_scene_object_iterator object;
	t_scene_camera_iterator	camera;
	t_scene_light_iterator	light;

	t_scene_get_object_iterator(&minirt->scene, &object);
	while (object.next(&object))
		free(object.deref(&object));
	t_scene_get_camera_iterator(&minirt->scene, &camera);
	while (camera.next(&camera))
		free(camera.deref(&camera));
	t_scene_get_light_iterator(&minirt->scene, &light);
	while (light.next(&light))
		free(light.deref(&light));
	t_scene_release(&minirt->scene);
}
