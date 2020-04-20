/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flipped_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:47:30 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:51:42 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"

void	get_flipped_direction(t_vec3 dir, t_vec3 normal, t_vec3 flipped)
{
	t_vec3_smult(-1, dir, flipped);
	t_vec3_lcomb(2 * t_vec3_sprod(normal, dir), normal, flipped, flipped);
}
