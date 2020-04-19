/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_array_collection_release.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:32:38 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:34:20 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_collection.h"
#include <stdlib.h>

void	t_array_collection_release(t_array_collection *collection)
{
	free(collection->content);
}
