/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_pcolor_from_filert.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:24:13 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:24:15 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pcolor_from_filert(t_color *color
						, t_filert_pcolor *rtpcolor)
{
	color_from_filert(*color, rtpcolor->color);
	t_vec3_smult(rtpcolor->intensity, *color, *color);
}
