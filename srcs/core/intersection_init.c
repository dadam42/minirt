/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:53:32 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:53:34 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	intersection_init(t_intersection *inter
							, t_ray *ray, t_time time
							, t_intensity intensity)
{
	inter->object = 0;
	inter->ray = ray;
	inter->time = time;
	inter->intensity = intensity;
}
