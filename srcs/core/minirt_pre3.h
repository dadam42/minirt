/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_pre3.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:23:57 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:27:48 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PRE3_H
# define MINIRT_PRE3_H
# include "minirt_pre2.h"

/*
**	t_scene and iterators : basically gathering visual objects and lights
**	defines its iterators if the type of collection is changed so the
**	other parts of the program don't have to be changed
*/

typedef struct							s_scene
{
	t_array_collection	light_collection;
	t_array_collection	object_collection;
	t_array_collection	camera_collection;
	t_color				*background_color;
	t_color				*black;
	t_ambiant_light		ambiant_light;
}										t_scene;
typedef struct s_scene_object_iterator	t_scene_object_iterator;

struct									s_scene_object_iterator
{
	t_array_collection_iterator		iterator;
	bool							(*next)(t_scene_object_iterator*);
	t_object						*(*deref)(t_scene_object_iterator*);
};

typedef struct s_scene_light_iterator	t_scene_light_iterator;

struct									s_scene_light_iterator
{
	t_array_collection_iterator		iterator;
	bool							(*next)(t_scene_light_iterator*);
	t_light							*(*deref)(t_scene_light_iterator*);
};

typedef struct s_scene_camera_iterator	t_scene_camera_iterator;
struct									s_scene_camera_iterator
{
	t_array_collection_iterator		iterator;
	bool							(*next)(t_scene_camera_iterator*);
	t_camera						*(*deref)(t_scene_camera_iterator*);
};

void									scene_get_object_iterator(
										t_scene						*scene
										, t_scene_object_iterator	*it);
void									scene_get_light_iterator(
										t_scene						*scene
										, t_scene_light_iterator	*it);
void									scene_get_camera_iterator(
										t_scene						*scene
										, t_scene_camera_iterator	*it);
void									scene_get_light_influence(
										t_scene						*scene
										, t_intersection			*inter);
void									scene_get_background_intensity(
										t_scene						*scene
										, t_intensity				intensity);
void									scene_get_ray_intensity(
										t_scene						*scene
										, t_ray						*ray
										, t_intensity				intensity);
void									scene_set_intersection_intensity(
										t_scene						*scene
										, t_intersection			*inter);
void									scene_get_first_intersection(
										t_scene						*scene
										, t_intersection			*inter);
void									scene_init(t_scene			*scene);
void									scene_release(t_scene		*scene);

/*
** t_scene's functions
*/

t_minirt_com							scene_add_object(
										t_scene						*scene
										, t_object					*object);
t_minirt_com							scene_add_light(
										t_scene						*scene
										, t_light					*light);
t_minirt_com							scene_add_camera(
										t_scene						*scene
										, t_camera					*camera);

#endif
