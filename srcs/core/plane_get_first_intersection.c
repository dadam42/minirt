/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get_first_intersection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:42:42 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:42:43 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	plane_get_first_intersection(t_object *object
									, t_intersection *inter)
{
	planar_get_first_intersection(object, inter
		, planar_get_first_intersection_test_ok);
}
