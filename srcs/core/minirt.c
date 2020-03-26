#include "minirt.h"
#include "libft.h"
#include "bmpfile.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
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

int display()
{
	t_minirt_camera 	camera = {.position = {0,0.,0.}, .view = {0.,0.,1}, .up = {1., 0., 0}, .fov = 130.};
	t_minirt_image 		image = {.content = 0, .width=931., .height=932.};
	t_minirt_sphere 	sphere = {.center = {0.,0.,1}, .radius=0.8};
	unsigned char		white[3] = {255,255,255};
	unsigned char		black[3] = {0,0,0};
	t_minirt_position	cur_pixel_position;
	t_vec3				dw;
	t_vec3				dh;
	t_minirt_direction	camera_right;
	double				pixel_size;
	t_minirt_ray		ray;
	char				*filename="display.bmp";
	double				t;(void)t;

	camera.fov = camera.fov * PI / 180;
	t_vec3_normalize(camera.view);
	image.content = malloc(image.width * image.height * sizeof(t_minirt_pixel));
	if (! image.content)
		return (1);
	t = 1e+15;
	t_vec3_vprod(camera.view, camera.up, camera_right);
	pixel_size = 2 * tan(camera.fov / 2) / image.width;
	t_vec3_smult(pixel_size, camera_right, dw);
	t_vec3_lcomb((-image.width - 1)/2, dw, camera.view, cur_pixel_position);
	t_vec3_smult(-pixel_size, camera.up, dh);
	t_vec3_lcomb((-image.height + 1) / 2, dh, cur_pixel_position, cur_pixel_position);
	t_vec3_lcomb(-image.width, dw, dh, dh);
	int hdx;
	int wdx;
	hdx = 0;
	ft_memcpy(ray.start, camera.position, sizeof(t_minirt_position));
	while (hdx < image.height)
	{
		wdx = 0;
		vec3_print(cur_pixel_position);
		while (wdx < image.width)
		{
			t_vec3_add(cur_pixel_position, dw, cur_pixel_position);
			t_vec3_init_by_plot3(camera.position, cur_pixel_position, ray.direction);
			t_vec3_normalize(ray.direction);
			//printf("%.2f", t_vec3_sqnorm(ray.direction));
			if (int_sphere_ray(&sphere, &ray))
			{
				ft_memcpy(image.content[hdx * image.width + wdx], white, sizeof(white));
			}
			else
			{
				ft_memcpy(image.content[hdx * image.width + wdx], black, sizeof(black));
			}
			wdx++;
		}
		t_vec3_add(cur_pixel_position, dh, cur_pixel_position);
		hdx++;
	}
	bmpfile_save(filename, (t_bmpfile_info *)&image);
	free(image.content);
	return (0);
}

int main()
{
	display();
	return (0);
}
