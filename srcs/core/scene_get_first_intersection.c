/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_get_first_intersection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:50:47 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:50:48 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_get_first_intersection(t_scene *scene
										, t_intersection *inter)
{
	t_scene_object_iterator object;

	scene_get_object_iterator(scene, &object);
	while (object.next(&object))
		object.deref(&object)->get_first_intersection(
			object.deref(&object), inter);
}
