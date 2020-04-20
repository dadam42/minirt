/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:39:25 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:39:26 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	plane_get_first_intersection(t_object *object, t_intersection *inter)
{
	planar_get_first_intersection(object, inter
								, planar_get_first_intersection_test_ok);
}

void	plane_get_coord(t_object *obj
						, t_position pos
						, t_object_coord *coords)
{
	t_position lpos;

	t_vec3_init_by_plot3(obj->origin, pos, lpos);
	t_mat3_dapply_vec3(lpos, obj->base, coords->cartesian);
}

void	plane_get_normal(t_object *obj
						, t_object_coord *coords
						, t_vec3 normal)
{
	(void)coords;
	ft_memcpy(normal, obj->base[2], sizeof(t_direction));
}
