/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_array_collection_iterator_deref.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:31:59 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:32:01 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_collection.h"

void	*array_collection_iterator_deref(
			t_array_collection_iterator *it)
{
	if (it->position >= 0 && it->position < it->collection->count)
		return (it->collection->content[it->position]);
	return (0);
}
