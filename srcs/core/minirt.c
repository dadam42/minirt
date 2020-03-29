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

char t_minirt_sphere_intersect_ray(t_minirt_object *obj
									, t_minirt_ray *ray
									, double *t)
{
	t_vec3	tmp;
	double	ot;
	float	b;
	float	c;
	float	delta;

	t_vec3_init_by_plot3(ray->start, obj->geom.sphere.center, tmp);
	c = t_vec3_sqnorm(tmp) - obj->geom.sphere.radius * obj->geom.sphere.radius;
	b = 2 * t_vec3_sprod(tmp, ray->direction);
	delta = b * b - 4 * c;
	if (delta < PREC)
		return (0);
	delta = sqrt(delta);
	ot = (-b + delta) / 2;
	while (1)
	{
		if (ot < *t)
			break;
		ot -= delta;
		if (ot < *t)
			break;
		return (0);
	}
	*t = ot;
	return (1);
}

void	t_minirt_ray_init(t_minirt_ray *ray, t_minirt_position position, t_minirt_direction direction)
{
	ft_memcpy(ray->start, position, sizeof(t_minirt_position));
	ft_memcpy(ray->direction, direction, sizeof(t_minirt_direction));
}

void	t_minirt_ray_get_color(t_minirt_ray *ray, t_minirt_scene *scene, t_minirt_pcolor al, t_minirt_color color)
{
	double	t;
	double  lt;
	int		cur_obj;
	int		cur_light;
	t_minirt_pcolor light_influence;
	t_minirt_object *best;
	t_minirt_ray	tmpray;
	
	best = 0;
	cur_obj = 0;
	t = 10e15;
	
	while (cur_obj < scene->nobjects)
	{
		if (scene->objects[cur_obj]->intersect_ray(scene->objects[cur_obj], ray, &t))
			best = scene->objects[cur_obj];
		cur_obj++;
	}
	if (best)
	{
		cur_light = 0;
		ft_memcpy(light_influence, al, sizeof(t_minirt_pcolor));
		while (cur_light < scene->nlight)
		{
			t_vec3d_lcomb(t, ray->direction, ray->start, tmpray.start);
			t_vec3d_init_by_plot3(tmpray.start, scene->lights[cur_light]->position, tmpray.direction);
			cur_obj = 0;
			lt = 10e15;
			while (! scene->objs[cur_obj]->intersect_ray(scene->objs[cur_obj], tmpray, &lt))
			{
				lt = 10e15;
				cur_objs++;
			}
			if (cur_objs == scene->nobjects)
			{
				t_vec3_lcomb(scene->lights[cur_light]->intensity , scene->lights[cur_light]->intensity, )
			}
			cur_light++;
		}
		color[minirt_blue] = best->color[minirt_blue];
		color[minirt_red] = best->color[minirt_red];
		color[minirt_green] = best->color[minirt_green];
	}
	else
	{
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
	}
}

void	t_minirt_camera_get_image(t_minirt *minirt
								, t_minirt_screen_box *box
								, t_minirt_image image)
{
	t_minirt_pixel_collection	cur_pixel;
	t_minirt_ray				cur_ray;
	t_minirt_color				cur_color;

	t_minirt_pixel_collection_init(&cur_pixel, minirt->camera, &minirt->resolution, box);
	while (t_minirt_pixel_collection_next(&cur_pixel))
	{
		t_minirt_ray_init(&cur_ray, minirt->camera->position
							, cur_pixel.position);
		t_vec3_normalize(cur_ray.direction);
		t_minirt_ray_get_color(&cur_ray, &minirt->scene, cur_color);
		ft_memcpy(image.minirt, cur_color, sizeof(t_minirt_color));
		image.minirt++;
	}
}

int main()
{
	t_minirt_object sphere1 = {.geom={.sphere = {.center = {0,0,3}, .radius = 1}}
							, .color = {0, 1, 0}
							, .intersect_ray = t_minirt_sphere_intersect_ray};
	t_minirt_object sphere2 = {.geom={.sphere = {.center = {0,1,3}, .radius = 1}}
							, .color = {0, 0, 1}
							, .intersect_ray = t_minirt_sphere_intersect_ray};
	t_minirt_object sphere3 = {.geom={.sphere = {.center = {0,-1,3}, .radius = 1}}
							, .color = {1, 0, 0}
							, .intersect_ray = t_minirt_sphere_intersect_ray};
	t_minirt_light light = {.position = {5 ,-4 , 3}, .pcolor={.color = {1, 0, 0}, .intensity=8}};
	t_minirt_light *lights = &light;
	t_minirt_camera camera = {.position = {0,0,0}, .view = {0,0,1}, .right = {0,1,0}, .up ={1,0,0}, .fov = 120};
	t_minirt minirt = {.scene = {.lights = &lights, .nobjects = 3, .nlights = 1},
						.camera = &camera,
						.resolution = {.height = 400, .width = 800}};
	t_minirt_com ret;
	t_minirt_object **sphere_obj = malloc(3 * sizeof(t_minirt_object*));
	sphere_obj[0] = &sphere1;
	sphere_obj[1] = &sphere2;
	sphere_obj[2] = &sphere3;
	minirt.scene.objects = sphere_obj;

	char	filename[] = "display.bmp";

	ret = t_minirt_camera_save_bmpfile(&minirt, filename);
	if (ret == minirt_ok)
		printf("%s successfully created.\n", filename);
	else
		printf("Error while creating %s.\n", filename);
	free(sphere_obj);
	return (0);
}
