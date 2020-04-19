/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_array_collection_iterator_moves.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:32:16 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:36:50 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_collection.h"

bool	t_array_collection_iterator_move_fw(t_array_collection_iterator *it)
{
	it->position++;
	if (it->position < it->collection->count)
		return (true);
	return (false);
}

bool	t_array_collection_iterator_move_bw(t_array_collection_iterator *it)
{
	it->position--;
	if (it->position >= 0)
		return (true);
	return (false);
}
