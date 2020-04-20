/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_get_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:40:44 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 10:19:55 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>

void	camera_get_screen(t_camera *camera
						, t_resolution *resolution
						, t_screen *screen)
{
	ft_memcpy(&screen->resolution, resolution, sizeof(t_resolution));
	t_vec3_add(camera->position, camera->base[view], screen->ulc_position);
	screen->pixel_size = 2 * tan(camera->fov / 2 * PI / 180 )
						/ resolution->width;
	t_vec3_smult(screen->pixel_size, camera->base[right], screen->dw);
	t_vec3_smult(-screen->pixel_size, camera->base[up], screen->dh);
	t_vec3_lcomb(- (resolution->width - 1) / (t_float)2, screen->dw
			, screen->ulc_position, screen->ulc_position);
	t_vec3_lcomb(- (resolution->height - 1) / (t_float)2, screen->dh
			, screen->ulc_position, screen->ulc_position);
}
