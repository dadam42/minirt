#include "minirt.h"

void	t_scene_get_light_iterator(t_scene *scene
									, t_scene_light_iterator *it)
{
	it->lights = scene->lights;
	it->curidx = -1;
	it->maxidx = scene->nlights;
	it->cur = (it->maxidx > 0 ? scene->lights[0] : 0);
}

void	t_scene_get_object_iterator(t_scene *scene
									, t_scene_object_iterator *it)
{
	it->objects = scene->objects;
	it->curidx = -1;
	it->maxidx = scene->nobjects;
	it->cur = (it->maxidx > 0 ? scene->objects[0] : 0);
}

bool	t_scene_object_iterator_next(
				t_scene_object_iterator *it)
{
	it->curidx++;
	if (it->curidx < it->maxidx)
	{
		it->cur = it->objects[it->curidx];
		return (true);
	}
	return (false);	
}

bool	t_scene_light_iterator_next(
				t_scene_light_iterator *it)
{
	it->curidx++;
	if (it->curidx < it->maxidx)
	{
		it->cur = it->lights[it->curidx];
		return (true);
	}
	return (false);	
}
