#include "minirt.h"
#include <stdlib.h>

t_minirt_com	t_minirt_add_rtlight(t_minirt *minirt
							, t_filert_parsed_obj *parsed)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (minirt_mem_error);
	vec3_from_filert(light->position, parsed->light.position);
	t_pcolor_from_filert(&light->pcolor, &parsed->light.pcolor);
	return (t_scene_add_light(&minirt->scene, light));	
}
