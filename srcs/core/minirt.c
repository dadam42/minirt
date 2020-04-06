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

	t_minirt_init(&minirt);
	msg = t_minirt_load_filert(&minirt, "scene.rt");
	if (msg != minirt_ok)
		printf("Error.\n");
	else
		printf("Ok.\n");
	t_minirt_release(&minirt);
	return(0);
}
