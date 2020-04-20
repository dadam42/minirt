/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color_from_filert.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:01:54 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:01:55 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	color_from_filert(t_color color, t_filert_color rtcolor)
{
	unsigned char cur;

	cur = 0;
	while (cur < 3)
	{
		color[cur] = (t_float)rtcolor[cur] / 255;
		cur++;
	}
}
