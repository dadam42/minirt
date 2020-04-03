#ifndef MINIRT_H
# define MINIRT_H
# include "utils_3d.h"
# include <stddef.h>
# include <stdbool.h>
# define PI 3.141592653589793
# define PREC 1e-15
# define SQPREC 1e-6
# define FARAWAY	1e15

typedef enum			e_minirt_com
{
	minirt_ok, minirt_error
}						t_minirt_com;

typedef t_vec3			t_minirt_position;
typedef t_vec3			t_minirt_direction;
typedef	t_vec3			t_minirt_translation;
typedef	t_mat3			t_minirt_base;
typedef double			t_minirt_float;
typedef t_minirt_float			t_minirt_size;
typedef t_minirt_float			t_minirt_intensity;
typedef unsigned char	t_minirt_rgb_comp;
typedef t_minirt_rgb_comp	t_minirt_pixel_color[3];
typedef t_minirt_size		t_minirt_local_coord[2];
typedef enum			e_minirt_comp
{
	minirt_red, minirt_green, minirt_blue
}						t_minirt_comp;

typedef t_vec3			t_minirt_color;
typedef struct	s_minirt_resolution
{
	int	width;
	int	height;
}				t_minirt_resolution;

typedef struct	s_minirt_pcolor
{
	t_minirt_color		color;
	t_minirt_intensity	intensity;
}				t_minirt_pcolor;

/*
**	t_minirt_image can be
**		- 'legacy' (t_minirt_color array) 
**		- 'rgb'		(t_minirt_rgp_comp array)			
*/

typedef union	u_minirt_film
{
	t_minirt_color	*legacy;
	t_minirt_rgb_comp	*rgb;
}				t_minirt_film;

typedef struct	s_minirt_image
{
	t_minirt_film		film;
	t_minirt_resolution	resolution;
}				t_minirt_image;

/*
**	t_minirt_camera
*/
typedef int				t_minirt_screen_coord[2];
typedef enum			e_minirt_pixel_coord
{
	height, width
}						t_minirt_pixel_coord;

typedef struct	s_minirt_boxed_pixel_collection
{
	t_minirt_screen_coord	min;
	t_minirt_screen_coord	cur;
	t_minirt_screen_coord	max;
	t_minirt_position		position;
	t_minirt_translation	dh;
	t_minirt_translation	dw;
}				t_minirt_boxed_pixel_collection;

typedef	struct			s_minirt_screen
{
	t_minirt_resolution		resolution;
	t_minirt_size			pixel_size;
	t_minirt_position		ulc_position;
	t_minirt_translation	dh;
	t_minirt_translation	dw;
}						t_minirt_screen;

typedef struct			s_minirt_screen_box
{
	t_minirt_screen_coord	ulc;
	t_minirt_screen_coord	brc;
}						t_minirt_screen_box;

typedef	enum	e_minirt_camera_base
{
	right, view, up
}				t_minirt_camera_base;

typedef struct	s_minirt_camera
{
	t_mat3				base;
	t_minirt_position	position;
	double				fov;
}				t_minirt_camera;
// -- t_minirt_camera

typedef struct	s_minirt_ray
{
	t_minirt_position	start;
	t_minirt_direction	direction;
}				t_minirt_ray;

typedef struct	s_minirt_color_ray
{
	t_minirt_ray		ray;
	t_minirt_color		color;
}				t_minirt_color_ray;

typedef struct	s_minirt_light
{
	t_minirt_position	position;
	t_minirt_pcolor		pcolor;
}				t_minirt_light;

typedef	t_minirt_pcolor t_minirt_ambiant_light;

// -- geoms

typedef struct	s_minirt_geom_sphere
{
	t_minirt_position	center;
	t_minirt_size		radius;
}				t_minirt_geom_sphere;

typedef struct	s_minirt_geom_cylinder
{
	t_minirt_position	position;
	t_minirt_size		height;
	t_minirt_size		radius;
}				t_minirt_geom_cylinder;

typedef struct	s_minirt_geom_plane
{
	t_minirt_position	position;
}				t_minirt_geom_plane;

typedef struct	s_minirt_geom_triangle
{
	t_minirt_position	vertex[3];
}				t_minirt_geom_triangle;

typedef	struct	s_minirt_geom_square
{
	t_minirt_position	blc;
}				t_minirt_geom_square;

typedef union	u_minirt_geom
{
	t_minirt_geom_sphere		sphere;
	t_minirt_geom_cylinder		cylinder;
	t_minirt_geom_plane			plane;
	t_minirt_geom_triangle		triangle;
	t_minirt_geom_square		square;
}				t_minirt_geom;

typedef struct s_minirt_object
				t_minirt_object;

typedef struct	s_minirt_intersection_info
				t_minirt_intersection_info;

typedef void	(*t_minirt_object_get_intersection_info)(t_minirt_object*, t_minirt_intersection_info *info);
typedef void	(*t_minirt_object_get_more_intersection_info)(t_minirt_object*, t_minirt_intersection_info *info);
typedef void	(*t_minirt_object_get_color)(t_minirt_object*, t_minirt_local_coord, t_minirt_color);
struct	s_minirt_object
{
	t_minirt_geom								geom;
	t_minirt_base								base;
	t_minirt_color								color;
	t_minirt_object_get_intersection_info		get_intersection_info;
	t_minirt_object_get_more_intersection_info	get_more_intersection_info;
	t_minirt_object_get_color					get_color;
};

struct	s_minirt_intersection_info
{
	t_minirt_object		*object;
	t_minirt_ray		*ray;
	t_minirt_direction	normal;
	union			u_coord
	{
		double					time;
		t_minirt_position		position;
		t_minirt_local_coord	local;
	}				coord;
};

typedef struct	s_minirt_scene
{
	t_minirt_light			**lights;
	int						nlights;
	t_minirt_object			**objects;
	int						nobjects;
	t_minirt_color			background_color;
	t_minirt_ambiant_light	ambiant_light;
}				t_minirt_scene;

typedef	struct	s_minirt_scene_light_iterator
{
	t_minirt_light	**lights;
	t_minirt_light	*cur;
	int				curidx;
	int				maxidx;
}				t_minirt_scene_light_iterator;

typedef struct	s_minirt_scene_object_iterator
{
	t_minirt_object	**objects;
	t_minirt_object	*cur;
	int				curidx;
	int				maxidx;
}				t_minirt_scene_object_iterator;

typedef struct	s_minirt
{
	t_minirt_scene	scene;
	t_minirt_camera	*camera;
	t_minirt_resolution resolution;
}				t_minirt;

void	t_minirt_boxed_pixel_collection_get_film(
						t_minirt_boxed_pixel_collection *collection
						, t_minirt_scene	*scene
						, t_minirt_position	*obs
						, t_minirt_film		*film);
bool	t_minirt_boxed_pixel_collection_next(
							t_minirt_boxed_pixel_collection *collection);
t_minirt_com	t_minirt_save_bmpfile(t_minirt *minirt
									, char *filename);
void	t_minirt_camera_get_boxed_image(t_minirt_camera *camera
								, t_minirt_scene	*scene
								, t_minirt_image *image
								, t_minirt_screen_box *box);
void	t_minirt_camera_get_image(t_minirt_camera *camera
							, t_minirt_scene *scene
							, t_minirt_image *image);
void	t_minirt_camera_get_screen(t_minirt_camera *camera
									, t_minirt_resolution *resolution
									, t_minirt_screen *screen);
void	t_minirt_screen_get_boxed_pixel_collection(t_minirt_screen *screen
								, t_minirt_screen_box *box
								, t_minirt_boxed_pixel_collection *collection);
t_minirt_size	t_minirt_ray_init(t_minirt_ray *ray
						, t_minirt_position orig
						, t_minirt_position target);
void	t_minirt_ray_get_color(t_minirt_ray *ray
							, t_minirt_scene *scene
							, t_minirt_color color);
void	t_minirt_scene_get_object_iterator(t_minirt_scene *scene
									, t_minirt_scene_object_iterator *it);
void	t_minirt_scene_get_light_iterator(t_minirt_scene *scene
									, t_minirt_scene_light_iterator *it);
bool	t_minirt_scene_object_iterator_next(
				t_minirt_scene_object_iterator *it);
bool	t_minirt_scene_light_iterator_next(
				t_minirt_scene_light_iterator *it);
void	t_minirt_object_static_get_color(t_minirt_object *object
								, t_minirt_scene *scene
								, t_minirt_intersection_info *info
								, t_minirt_color color);
#endif
