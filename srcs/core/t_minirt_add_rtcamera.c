#include "minirt.h"
#include <math.h>
#include <stdlib.h>

static void		select_camera_orientation(t_minirt *minirt, t_camera *camera)
{
	unsigned char	cur;
	t_float	sqnorm;

	cur = 2;
	while (cur !=0)
	{
		t_vec3_vprod(camera->base[view], minirt->canonical[cur]
			, camera->base[right]);
		sqnorm = t_vec3_sqnorm(camera->base[right]);
		if (sqnorm > PREC)
			break;
		cur++;
	}
	t_vec3_smult(1 / sqrt(sqnorm), camera->base[right], camera->base[right]);
	t_vec3_vprod(camera->base[right], camera->base[view], camera->base[up]);
}


t_minirt_com	t_minirt_add_rtcamera(t_minirt *minirt
									, t_filert_parsed_obj *parsed)
{
	t_camera *camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (minirt_mem_error);
	t_direction_from_filert(camera->base[view], parsed->camera.direction,
		minirt->default_direction);
	vec3_from_filert(camera->position, parsed->camera.position);
	camera->fov = parsed->camera.fov;
	select_camera_orientation(minirt, camera);
	return (t_scene_add_camera(&minirt->scene, camera));
}
