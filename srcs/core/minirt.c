#include "minirt.h"
#include "libft.h"
#include "bmpfile.h"
#include <stdio.h>
#include <math.h>

void	vec3_print(t_vec3 vec)
{
	printf("<%.12f, %.12f, %f>\n", vec[0], vec[1], vec[2]);
}

int main()
{
	t_minirt		minirt;
	t_minirt_com	msg;
	t_scene_camera_iterator camera;

	t_minirt_init(&minirt);
	msg = t_minirt_load_filert(&minirt, "bonnel.rt");
	if (msg != minirt_ok)
		printf("Error.\n");
	else
	{
		t_scene_get_camera_iterator(&minirt.scene, &camera);
		camera.next(&camera);
		minirt.camera = camera.deref(&camera);
		t_save_bmpfile(&minirt, "display.bmp");
		printf("Ok.\n");
	}
	t_minirt_release(&minirt);
	return(0);
}
