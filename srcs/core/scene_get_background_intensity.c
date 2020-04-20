/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_get_background_intensity.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:45:57 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:45:58 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	scene_get_background_intensity(t_scene *scene
										, t_intensity intensity)
{
	ft_memcpy(intensity
				, *scene->background_color, sizeof(t_intensity));
}
