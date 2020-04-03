#include "minirt.h"
#include "libft.h"
#include "bmpfile.h"
#include <stdio.h>
#include <math.h>

void	vec3_print(t_vec3 vec)
{
	printf("<%.12f, %.12f, %f>\n", vec[0], vec[1], vec[2]);
}

short	int_sphere_ray(t_minirt_geom_sphere *sphere, t_minirt_ray *ray)
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

void t_minirt_sphere_get_intersection_info(t_minirt_object *obj
									, t_minirt_intersection_info *info)
{
	t_vec3	tmp;
	double	ot;
	double	b;
	double	c;
	double	delta;

	t_vec3_init_by_plot3(obj->geom.sphere.center, info->ray->start, tmp);
	c = t_vec3_sqnorm(tmp) - obj->geom.sphere.radius * obj->geom.sphere.radius;
	b = 2 * t_vec3_sprod(tmp, info->ray->direction);
	delta = b * b - 4 * c;
	if (delta < PREC)
		return ;
	delta = sqrt(delta);
	ot = (-b + delta) / 2;
	while (1)
	{
		if (ot < info->coord.time && ot < delta + 2*SQPREC && ot > 2*SQPREC)
			break ;
		ot -= delta;
		if (ot < info->coord.time && ot > 2*SQPREC)
			break ;
		return ;
	}
	info->coord.time = ot;
	info->object = obj;
}

void	t_minirt_object_dummy_get_color(t_minirt_object *obj, t_minirt_local_coord coord, t_minirt_color color)
{
	(void)coord;
	ft_memcpy(color, obj->color, sizeof(t_minirt_color));
}

void	t_minirt_sphere_get_more_intersection_info(t_minirt_object* obj, t_minirt_intersection_info *info)
{
	t_vec3	local_position;

	t_vec3_init_by_plot3(info->coord.position, obj->geom.sphere.center, info->coord.position);
	t_vec3_smult(1 / obj->geom.sphere.radius, info->coord.position, info->normal);
	if (t_vec3_sprod(info->ray->direction, info->normal) > 0)
		t_vec3_smult(-1, info->normal, info->normal);
	t_mat3_apply_vec3(obj->base, info->coord.position, local_position);
	info->coord.local[0] = acos(local_position[0] / obj->geom.sphere.radius);
	info->coord.local[1] = asin(local_position[2] / obj->geom.sphere.radius);
}

int main()
{
	t_minirt_base	canonical = {{1, 0, 0},{0, 1, 0},{0,0,1}};
	t_minirt_camera camera = {.position = {0,-4,0}, .base[view] = {0,1,0}, .base[right] = {1, 0,0}, .fov = 60};	
	t_minirt_object sphere0 = {.geom={.sphere = {.center = {0,0,0}, .radius = 2}}
							, .color = {1, 0, 0}
							, .get_intersection_info = t_minirt_sphere_get_intersection_info};
	t_minirt_light light0 = {.position = {6,0,0}, .pcolor = {.intensity = 4000, .color = {0, 1, 0}}};
	t_minirt minirt = {.scene = {.nobjects = 1, .nlights = 1},
						.camera = &camera,
						.resolution = {.height = 1000 ,.width = 1000},
						};
	t_minirt_ambiant_light ambiant_light = {.color={1,1,1}, .intensity=2};
	t_minirt_color background_color = {0,0,0};
	t_minirt_com ret;
	
	t_minirt_object **sphere_obj = malloc(minirt.scene.nobjects * sizeof(t_minirt_object*));
	t_vec3_vprod(camera.base[right], camera.base[view], camera.base[up]);
	ft_memcpy(sphere0.base, canonical, sizeof(t_minirt_base));
	sphere_obj[0] = &sphere0;
	minirt.scene.objects = sphere_obj;
	ft_memcpy(&minirt.scene.ambiant_light, &ambiant_light, sizeof(t_minirt_ambiant_light));
	ft_memcpy(&minirt.scene.background_color, &background_color, sizeof(t_minirt_color));
	t_minirt_light **lights = malloc(minirt.scene.nlights * sizeof(t_minirt_light*));
	lights[0] = &light0;
	minirt.scene.lights = lights;
	char	filename[] = "display.bmp";

	ret = t_minirt_save_bmpfile(&minirt, filename);
	if (ret == minirt_ok)
		printf("%s successfully created.\n", filename);
	else
		printf("Error while creating %s.\n", filename);
	free(sphere_obj);
	return (0);
}
/*void	t_minirt_ray_init(t_minirt_ray *ray, t_minirt_position position, t_minirt_direction direction)
{
	ft_memcpy(ray->start, position, sizeof(t_minirt_position));
	ft_memcpy(ray->direction, direction, sizeof(t_minirt_direction));
}

void	t_minirt_intersection_info_init(t_minirt_intersection_info *info, t_minirt_ray *ray)
{
	info->object = 0;
	info->coord.time = 10e15;
	info->ray = ray;
}*/

/*void	t_minirt_get_light_influence(t_minirt *minirt, t_minirt_intersection_info *info, t_minirt_pcolor *light_influence)
{
	int							cur_light;
	int							cur_object;
	t_minirt_intersection_info	cur_info;
	t_minirt_ray				ray;
	double						coef;
	t_minirt_direction			normal;

	ft_memcpy(ray.start, info->coord.position, sizeof(t_minirt_position));

	ft_memcpy(light_influence, &minirt->ambiant_light, sizeof(t_minirt_pcolor));
	t_vec3_smult(light_influence->intensity, light_influence->color, light_influence->color);
	cur_light = 0;
	while(cur_light < minirt->scene.nlights)
	{
		t_vec3_init_by_plot3(ray.start, minirt->scene.lights[cur_light]->position, ray.direction);
		coef = 1 / t_vec3_sqnorm(ray.direction);
		t_vec3_smult(sqrt(coef), ray.direction, ray.direction);
		t_minirt_intersection_info_init(&cur_info, &ray);
		cur_object = 0;
		while (cur_object < minirt->scene.nobjects)
		{
			minirt->scene.objects[cur_object]->get_intersection_info(minirt->scene.objects[cur_object], &ray, &cur_info);
			if (cur_info.object)
				break;
			cur_object++;
		}
		if (cur_object == minirt->scene.nobjects)
		{
			t_vec3_init_by_plot3(info->object->geom.sphere.center, info->coord.position, normal);
			t_vec3_normalize(normal);
			coef *= fabs(t_vec3_sprod(ray.direction, normal) * minirt->scene.lights[cur_light]->pcolor.intensity);
			t_vec3_lcomb(coef, minirt->scene.lights[cur_light]->pcolor.color, light_influence->color, light_influence->color);
			light_influence->intensity += coef;
		}
		cur_light++;
	}
	t_vec3_smult(1/light_influence->intensity, light_influence->color, light_influence->color);
}*/

/*void	t_minirt_get_color(t_minirt *minirt, t_minirt_ray *ray, t_minirt_color color)
{
	t_minirt_intersection_info	info;
	t_minirt_pcolor				light_influence;
	int		cur_obj;
	
	cur_obj = 0;
	t_minirt_intersection_info_init(&info, ray);
	while (cur_obj < minirt->scene.nobjects)
	{
		minirt->scene.objects[cur_obj]->get_intersection_info(minirt->scene.objects[cur_obj], ray, &info);
		cur_obj++;
	}
	ft_memcpy(&light_influence, &minirt->ambiant_light, sizeof(t_minirt_pcolor));
	if (info.object)
	{
		t_vec3_smult(info.coord.time, ray->direction, info.coord.position);
		t_vec3_add(info.coord.position, ray->start, info.coord.position);
		t_minirt_get_light_influence(minirt, &info, &light_influence);
		t_vec3_mult(light_influence.color, info.object->color, color);
		t_vec3_smult(light_influence.intensity, color, color);
	}
	else
	{
		color[0] = minirt->background_color[0];
		color[1] = minirt->background_color[1];
		color[2] = minirt->background_color[2];
	}
}*/


