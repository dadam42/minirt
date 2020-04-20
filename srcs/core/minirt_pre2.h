/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_pre2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:26:30 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:29:07 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PRE2_H
# define MINIRT_PRE2_H
# include "minirt_pre1.h"

typedef t_vec3							t_color;
typedef	t_color							t_albedo;
typedef struct							s_resolution
{
	int	width;
	int	height;
}										t_resolution;

typedef	struct							s_observer
{
	t_position		position;
	t_resolution	resolution;
}										t_observer;

/*
**	t_film can be
**		- 'legacy'	(t_color array)
**		- 'rgb'		(t_rgb_comp array)
*/
typedef union							u_film
{
	t_intensity		*legacy;
	t_rgb_comp		*rgb;
}										t_film;

/*
** Convert (in place)size pixels from legacy to rgb starting at film
*/
void									film_legacy_to_rgb(t_film *film
															, int size);

/*
**	t_image : model for... an image, owns its film.
*/
typedef struct							s_image
{
	t_film			film;
	t_resolution	resolution;
}										t_image;

/*
**	t_screen : model for a screen.
**	t_screen can produce boxed_pixel_collections from a screen_box
*/
typedef	struct							s_screen
{
	t_resolution	resolution;
	t_size			pixel_size;
	t_position		ulc_position;
	t_translation	dh;
	t_translation	dw;
}										t_screen;

typedef struct s_boxed_pixel_collection	t_boxed_pixel_collection;
typedef struct s_screen_box				t_screen_box;
void									screen_get_boxed_pixel_collection(
										t_screen *screen
										, t_screen_box *box
										, t_boxed_pixel_collection
														*collection);
typedef int								t_screen_coord[2];

/*
**	t_screen_box : model for a rectangular window on a t_screen.
**	ulc and brc resp. stand for upper-left corner and bottom-right corner.
**	no check on these values is done : use with caution.
*/
struct									s_screen_box
{
	t_screen_coord	ulc;
	t_screen_coord	brc;
};

typedef enum							e_pixel_coord
{
	height, width
}										t_pixel_coord;

/*
**	t_boxed_pixel_collection : model for the collection of pixels of a screen
**	boxed by a screen_box
**	Can be used as an iterator with the function t_boxed_pixel_collection_next
**	Can produce film : obs is then usually the camera's position whose produced
**	the screen whose produced the the boxed_pixel_collection.
**	camera (+resolution)			-> screen
**	screen (+screen_box)			-> boxed_pixel_collection
**	boxed_pixel_collection(+obs +minirt)	-> film
**	(?) Can produce image but seems useless (?)
*/
typedef struct s_minirt					t_minirt;
typedef struct s_scene					t_scene;

struct									s_boxed_pixel_collection
{
	t_screen_coord	min;
	t_screen_coord	cur;
	t_screen_coord	max;
	t_position		position;
	t_translation	dh;
	t_translation	dw;
};

void									boxed_pixel_collection_get_film(
										t_boxed_pixel_collection
													*collection
										, t_minirt *minirt
										, t_position *obs
										, t_film *film);
void									boxed_pixel_collection_get_image(
										t_boxed_pixel_collection *collection
										, t_scene *scene
										, t_position *obs
										, t_image *image);
bool									boxed_pixel_collection_next(
										t_boxed_pixel_collection
													*collection);

/*
**	t_camera : model for a camera.
**	Can produce screens.
**	(?) Can also produce images and boxed_images... maybe useless (?)
*/

typedef	enum							e_camera_base
{
	right, view, up
}										t_camera_base;

typedef struct							s_camera
{
	t_mat3		base;
	t_position	position;
	double		fov;
}										t_camera;
void									camera_get_image(
										t_camera	*camera
										, t_scene	*scene
										, t_image	*image);
void									camera_get_screen(
										t_camera		*camera
										, t_resolution	*resolution
										, t_screen		*screen);
void									camera_get_boxed_image(
										t_camera		*camera
										, t_scene		*scene
										, t_image		*image
										, t_screen_box	*box);

/*
**	t_ray : model for a ray.
**	Can produce color
**	scene_get_ray_intensity(t_ray*, t_scene*, t_color) is the terminal point
**		of the raytracing algorithm when recurse is used
**		and the entry point when there's no recursion.
*/
typedef struct							s_ray
{
	t_position	start;
	t_direction	direction;
}										t_ray;

/*
** t_ray_init returns the distance between orig and target
*/
t_distance								ray_init(
										t_ray			*ray
										, t_position	orig
										, t_position	target);

/*
** (?)
** color_ray : Never used, to remove
** (?)
*/
typedef struct							s_color_ray
{
	t_ray	ray;
	t_color	color;
}										t_color_ray;

typedef struct							s_light
{
	t_position	position;
	t_color		color;
}										t_light;

typedef	t_color							t_ambiant_light;

typedef struct s_intersection			t_intersection;

/*
**	t_object : structural specification of all visible objects.
**				mostly pointers on functions excepted for :
**				position, base which create object's specific coordinates
**				system.
**	During the ray-tracing algorithm, ray's will be cast from an
**  observer's point of view in a given direction.
**  If it exists, the nearest object must be asked for many things
**	to create an intersection (see struct s_intersection too)
**	First : is the object intersected by the ray, and is it intersected
**			before others objects ?
**	inter.position : position in minirt's canonical base.
**	inter.time: duration between cast and intersection.
**	->set_intersection.
**
**		coords	: necessary coordinates for further calculuses,
**					each object is free to set up one or both of
**				+ coords.position : position of the object in
**									object's coordinates system.
**				+ coords.local : a 2d vector of t_float useful to
**								map properties as albedo, normal etc,
**								in specific realisations of an object.
**								sphere will certainly use spherical coordinates
**								while cylinder will use cylindrical coordinates
**								triangles barycentric ones...
**		normal : normal vector in pointing in the semi-space (affine) in witch
**				the starting position of the ray stands.
**		normal_dir : can be ext_normal or int_normal to express if the normal
**					points 'out' the object or 'in' the object.
*/

typedef struct s_object					t_object;
typedef struct s_object_coord			t_object_coord;
/*
**		Catalog of pointers,
**		_each_ one of these must be defined by
**		any new object realisation
*/

typedef void							(*t_object_get_intersection)
											(t_object*, t_intersection*);
typedef void							(*t_object_get_albedo)
										(t_object*, t_object_coord*, t_albedo);
typedef void							(*t_object_get_coord)
										(t_object*, t_position
										, t_object_coord*);
typedef void							(*t_object_get_normal)
										(t_object*, t_object_coord*
										, t_normal);
struct									s_object
{
	t_base						base;
	t_position					origin;
	t_color						albedo;
	t_object_get_intersection	get_first_intersection;
	t_object_get_coord			get_coord;
	t_object_get_normal			get_normal;
	t_object_get_albedo			get_albedo;
};

void									object_pre_init(
										t_object		*object
										, t_position	origin
										, t_base		base);

bool									object_base_init(
										t_object		*object
										, t_direction	norm
										, t_base		canonical);
/*
**	Predefined pointers
*/

void									object_dummy_get_albedo
										(t_object *obj
										, t_object_coord *coord
										, t_albedo albedo);
void									object_noop_get_first_intersection(
										t_object *object
										, t_intersection *inter);
void									object_noop_get_coord(
										t_object *object
											, t_position position
											, t_object_coord *coord);
void									object_noop_get_normal(t_object *object
											, t_object_coord *coord
											, t_normal normal);

/*
**	The following realisations of the above t_object type can use a couple of
**	coordinates system to localize a point on its surface :
**		cartesian 	: 	a t_vec3 aka t_position in the global coordinates
**						system which will be provided by the t_minirt struct
**						(see canonical member)
**		local		:	a t_float[2] aka t_local_coord which will be computed,
**						if needed it can be of various coordinates system,
**						typically spherical for a sphere,
**						barycentric for a triangle,
**						cylindrical for cylinders...
*/

struct									s_object_coord
{
	t_position		cartesian;
	t_local_coord	local;
};

/*
** t_plane
*/

typedef	t_object						t_plane;

typedef	bool							(*t_planar_get_first_intersection_test)
										(t_object *object
										, t_intersection *inter
										, t_time time);

void									planar_get_first_intersection(
										t_object			*object
										, t_intersection	*inter
										, t_planar_get_first_intersection_test
															test);
bool									planar_get_first_intersection_test_ok(
										t_object			*object
										, t_intersection	*inter
										, t_time			time);
void									plane_get_first_intersection(
										t_object			*object
										, t_intersection	*inter);
void									plane_get_coord(
										t_object			*object
										, t_position		position
										, t_object_coord *coord);
void									plane_get_normal(
										t_object			*object
										, t_object_coord	*coord
										, t_direction		normal);
/*
** t_sphere :  a realisation of t_object defined above.
*/

typedef struct							s_sphere
{
	t_object	object;
	t_size		radius;
}										t_sphere;

void									sphere_init(t_sphere *sphere);
void									sphere_get_first_intersection(
										t_object			*obj
										, t_intersection	*intersection);
void									*sphere_get_albedo(
										t_object			*obj
										, t_object_coord	*coord
										, t_albedo			albedo);
void									sphere_get_coord(
										t_object			*obj
										, t_position		position
										, t_object_coord	*coord);
void									sphere_get_normal(
										t_object			*obj
										, t_object_coord	*coord
										, t_vec3			dir);
/*
**	t_cylinder
*/

typedef struct							s_cylinder
{
	t_object	object;
	t_size		radius;
	t_size		height;
}										t_cylinder;

void									cylinder_get_first_intersection(
										t_object			*obj
										, t_intersection	*intersection);
void									*cylinder_get_albedo(
										t_object			*obj
										, t_object_coord	*coord
										, t_albedo			albedo);
void									cylinder_get_coord(
										t_object			*obj
										, t_position		position
										, t_object_coord	*coord);
void									cylinder_get_normal(
										t_object			*obj
										, t_object_coord	*coord
										, t_vec3			dir);
/*
** t_square
*/

typedef struct							s_square
{
	t_object	object;
	t_float		size;
}										t_square;

void									square_get_first_intersection(
										t_object			*obj
										, t_intersection	*intersection);
void									*square_get_albedo(
										t_object			*obj
										, t_object_coord	*coord
										, t_albedo			albedo);
void									square_get_coord(
										t_object			*obj
										, t_position		position
										, t_object_coord	*coord);
void									square_get_normal(
										t_object			*obj
										, t_object_coord	*coord
										, t_vec3 dir);
bool									square_get_first_intersection_test(
										t_object			*obj
										, t_intersection	*inter
										, t_time			time);

/*
**	t_intersection : 	heart of ray tracing algorithm's datas.
**						it gather and cache any data required for
**						the ray tracing algorithm.
**	rson stands for the scalar product of ray's direction and the normal
**		pointing outside the object.
**	the normal is eventually flipped in intersection_complete to point in the
**	ray.start's semi-space :
**
**		  R	 N
**		   \ |
**		____\|_____
**		     I
*/

struct									s_intersection
{
	t_object		*object;
	t_ray			*ray;
	t_time			time;
	t_albedo		albedo;
	t_float			*intensity;
	t_position		position;
	t_object_coord	coord;
	t_direction		normal;
	t_float			rson;
};

void									intersection_init(t_intersection *inter
										, t_ray *ray, t_time time
										, t_intensity intensity);
void									intersection_complete(
										t_intersection *inter);
void									intersection_set_own_intensity(
										t_intersection *inter);
#endif