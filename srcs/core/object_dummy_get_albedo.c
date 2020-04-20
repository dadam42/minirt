/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_dummy_get_albedo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:34:12 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:34:54 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	object_dummy_get_albedo(t_object *obj
								, t_object_coord *coord
								, t_albedo albedo)
{
	(void)coord;
	ft_memcpy(albedo, obj->albedo, sizeof(t_albedo));
}
