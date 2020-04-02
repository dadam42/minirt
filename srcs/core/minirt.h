#ifndef MINIRT_H
# define MINIRT_H
# include "utils_3d.h"
# include <stddef.h>
# define PI 3.141592653589793
# define PREC 1e-15
# define SQPREC 1e-6


typedef enum			e_minirt_com
{
	minirt_ok, minirt_error
}						t_minirt_com;
typedef t_vec3			t_minirt_position;
typedef t_vec3			t_minirt_direction;
typedef	t_vec3			t_minirt_translation;
typedef t_vec3			t_minirt_color;
typedef unsigned char	t_minirt_rgb_comp;
typedef double			t_minirt_intensity;
typedef double			t_minirt_size;

typedef union u_minirt_image
{
	t_minirt_color		*minirt;
	t_minirt_rgb_comp	*rgb;
}			t_minirt_image;
typedef unsigned char	t_minirt_pixel_color[3];
typedef enum	e_minirt_comp
{
	minirt_red, minirt_green, minirt_blue
}						t_minirt_comp;


typedef int				t_minirt_screen_coord[2];
typedef enum	e_minirt_pixel_coord
{minirt_height, minirt_width}
				t_minirt_pixel_coord;
typedef struct			s_minirt_screen_box
{
	t_minirt_screen_coord	ulc;
	t_minirt_screen_coord	brc;
}						t_minirt_screen_box;

typedef struct	s_minirt_pixel_collection
{
	int	height;
	int width;
	int height_max;
	int width_max;
	int width_min;
	t_minirt_position position;
	t_minirt_translation	dh;
	t_minirt_translation	dw;
}				t_minirt_pixel_collection;

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

typedef struct	s_minirt_camera
{
	t_minirt_position	position;
	t_minirt_direction	view;
	t_minirt_direction	up;
	t_minirt_direction	right;
	double				fov;
}				t_minirt_camera;

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

typedef struct	s_minirt_sphere
{
	t_minirt_position	center;
	t_minirt_size		radius;
}				t_minirt_sphere;

typedef struct	s_minirt_cylinder
{
	t_minirt_position	base;
	t_minirt_direction	axe_dir;
	t_minirt_size		height;
	t_minirt_size		radius;
}				t_minirt_cylinder;

typedef struct	s_minirt_plane
{
	t_minirt_position	position;
	t_minirt_direction	axe_normal;
}				t_minirt_plane;

typedef struct	s_minirt_triangle
{
	t_minirt_position	vertex[3];
}				t_minirt_triangle;

typedef	struct	s_minirt_square
{
	t_minirt_position	bl_vertex;
	t_minirt_direction	norm;
}				t_minirt_square;

typedef union	u_minirt_geom
{
	t_minirt_sphere		sphere;
	t_minirt_cylinder	cylinder;
	t_minirt_plane		plane;
	t_minirt_triangle	triangle;
	t_minirt_square		square;
}				t_minirt_geom;

typedef struct s_minirt_object
				t_minirt_object;

typedef struct	s_minirt_intersection_info
{
	t_minirt_object	*object;
	t_minirt_ray	*ray;
	union			u_coord
	{
		double				time;
		t_minirt_position	position;
		t_minirt_size		local[2];
	}				coord;
}				t_minirt_intersection_info;

typedef void	(*t_minirt_object_get_intersection_info)(t_minirt_object*, t_minirt_ray*, t_minirt_intersection_info *info);
struct	s_minirt_object
{
	t_minirt_geom			geom;
	t_minirt_color			color;
	t_minirt_object_get_intersection_info	get_intersection_info;
};

typedef struct	s_minirt_scene
{
	t_minirt_light	**lights;
	int				nlights;
	t_minirt_object	**objects;
	int				nobjects;
}				t_minirt_scene;

typedef struct	s_minirt
{
	t_minirt_scene	scene;
	t_minirt_camera	*camera;
	t_minirt_resolution resolution;
	t_minirt_color		background_color;
	t_minirt_ambiant_light	ambiant_light;
}				t_minirt;

void	t_minirt_pixel_collection_init(t_minirt_pixel_collection *collection
									, t_minirt_camera *camera
									, t_minirt_resolution *resolution
									, t_minirt_screen_box *box);
char	t_minirt_pixel_collection_next(t_minirt_pixel_collection *collection);
t_minirt_com	t_minirt_camera_save_bmpfile(t_minirt *minirt
									, char *filename);
void	t_minirt_camera_get_image(t_minirt *minirt
								, t_minirt_screen_box *box
								, t_minirt_image image);
#endif
