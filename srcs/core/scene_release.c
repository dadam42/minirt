/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:55:03 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:55:04 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>

void	scene_release(t_scene *scene)
{
	t_scene_object_iterator object;
	t_scene_camera_iterator	camera;
	t_scene_light_iterator	light;

	scene_get_object_iterator(scene, &object);
	while (object.next(&object))
		free(object.deref(&object));
	scene_get_camera_iterator(scene, &camera);
	while (camera.next(&camera))
		free(camera.deref(&camera));
	scene_get_light_iterator(scene, &light);
	while (light.next(&light))
		free(light.deref(&light));
	t_array_collection_release(&scene->object_collection);
	t_array_collection_release(&scene->light_collection);
	t_array_collection_release(&scene->camera_collection);
}
