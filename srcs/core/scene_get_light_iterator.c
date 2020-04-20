/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_get_light_iterator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:51:52 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:51:53 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*scene_light_iterator_deref(t_scene_light_iterator *iterator)
{
	return ((t_light*)
			((t_array_collection_iterator*)iterator)->deref(
				(t_array_collection_iterator*)iterator));
}

bool	scene_light_iterator_next(t_scene_light_iterator *iterator)
{
	return (((t_array_collection_iterator*)iterator)->next(
				(t_array_collection_iterator*)iterator));
}

void	scene_get_light_iterator(t_scene *scene
					, t_scene_light_iterator *iterator)
{
	t_array_collection_init_fwiterator(&scene->light_collection
							, (t_array_collection_iterator*)iterator);
	iterator->next = scene_light_iterator_next;
	iterator->deref = scene_light_iterator_deref;
}
