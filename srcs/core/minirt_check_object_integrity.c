/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_check_object_integrity.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:59:39 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:59:40 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt_com	minirt_check_object_integrity(t_minirt *minirt
											, t_object *object)
{
	(void)minirt;
	while (1)
	{
		if (object->get_albedo == 0)
			return (minirt_error);
		if (object->get_coord == 0)
			return (minirt_error);
		if (object->get_first_intersection == 0)
			return (minirt_error);
		break ;
	}
	return (minirt_ok);
}
