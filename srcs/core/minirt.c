#include "minirt.h"
#include "libft.h"
#include "bmpfile.h"
#include <stdio.h>
#include <math.h>

void	vec3_print(t_vec3 vec)
{
	printf("<%.12f, %.12f, %f>\n", vec[0], vec[1], vec[2]);
}

short	int_sphere_ray(t_minirt_sphere *sphere, t_minirt_ray *ray)
{
	t_vec3	tmp;
	float	b;
	float	c;
	float	delta;

	t_vec3_init_by_plot3(ray->start, sphere->center, tmp);
	c = t_vec3_sqnorm(tmp) - sphere->radius * sphere->radius;
	b = 2 * t_vec3_sprod(tmp, ray->direction);
	delta = b * b - 4 * c;
	if (delta > 0)
		return (1);
	return (0);	
}

short t_minirt_sphere_inter_ray(t_minirt_sphere *sphere, t_minirt_ray *ray, double *t)
{
	t_vec3	tmp;
	float	b;
	float	c;
	float	delta;

	t_vec3_init_by_plot3(ray->start, sphere->center, tmp);
	c = t_vec3_sqnorm(tmp) - sphere->radius * sphere->radius;
	b = 2 *t_vec3_sprod(tmp, ray->direction);
	delta = b * b - 4 * c;
	if (delta > 0)
	{
		delta = sqrt(delta);
		if ((((c = (-b + delta) / 2) < *t) ||
			((c = (-b - delta) / 2) < *t))
			&& c > PREC)
		{
			*t = c;
			return (1);
		}
	}
	return (0);
}

void	t_minirt_ray_init(t_minirt_ray *ray, t_minirt_position position, t_minirt_direction direction)
{
	ft_memcpy(ray->start, position, sizeof(t_minirt_position));
	ft_memcpy(ray->direction, direction, sizeof(t_minirt_direction));
}

void	t_minirt_ray_get_color(t_minirt_ray *ray, t_minirt_scene *scene, t_minirt_color color)
{
	if (int_sphere_ray(scene, ray))
	{
		color[0] = 1;
		color[1] = 1;
		color[2] = 1;
	}
	else
	{
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
	}
}

void	t_minirt_camera_get_image(t_minirt_camera *camera
								, t_minirt_resolution *resolution
								, t_minirt_screen_box *box
								, t_minirt_image image
								, t_minirt_scene *scene)
{
	t_minirt_pixel_collection	cur_pixel;
	t_minirt_ray				cur_ray;
	t_minirt_color				cur_color;

	t_minirt_pixel_collection_init(&cur_pixel, camera, resolution, box);
	while (t_minirt_pixel_collection_next(&cur_pixel))
	{
		t_minirt_ray_init(&cur_ray, camera->position, cur_pixel.position);
		t_vec3_normalize(cur_ray.direction);
		t_minirt_ray_get_color(&cur_ray, scene, cur_color);
		ft_memcpy(image, cur_color, sizeof(t_minirt_color));
		image++;
	}
}


int main()
{
	t_minirt_sphere sphere = {.center = {0,0,3}, .radius = 1};
	t_minirt_camera camera = {.position = {0,0,0}, .view = {0,0,1}, .right = {0,1,0}, .up ={1,0,0}, .fov = 120};
	t_minirt_resolution resolution= {.height = 800, .width = 1000};
	t_minirt_com ret;
	char	filename[] = "display.bmp";

	ret = t_minirt_save_bmpfile(&sphere, filename, &camera, &resolution);
	if (ret == minirt_ok)
		printf("%s successfully created.\n", filename);
	else
		printf("Error while creating %s.\n", filename);
	return (0);
}
