/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_array_collection_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:31:25 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:31:27 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_collection.h"

void	t_array_collection_init(t_array_collection *collection)
{
	collection->content = 0;
	collection->count = 0;
	collection->size = 0;
}
