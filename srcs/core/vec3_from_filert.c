/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_from_filert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 03:03:46 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 03:03:47 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>
#include <libft.h>

void			vec3_from_filert(t_vec3 minirt_vec, float filert_vec[3])
{
	unsigned char cur;

	cur = 0;
	while (cur < 3)
	{
		minirt_vec[cur] = filert_vec[cur];
		cur++;
	}
}
