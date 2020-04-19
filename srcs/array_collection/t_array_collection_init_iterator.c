/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_array_collection_init_iterator.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:31:39 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:35:47 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_collection.h"

void	t_array_collection_init_fwiterator(t_array_collection *collection
											, t_array_collection_iterator *it)
{
	it->collection = collection;
	it->position = -1;
	it->next = t_array_collection_iterator_move_fw;
	it->deref = array_collection_iterator_deref;
}

void	t_array_collection_init_bwiterator(t_array_collection *collection
											, t_array_collection_iterator *it)
{
	it->collection = collection;
	it->position = collection->count;
	it->next = t_array_collection_iterator_move_bw;
	it->deref = array_collection_iterator_deref;
}
