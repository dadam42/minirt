/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_direction_from_filert.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:01:08 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:01:42 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include "libft.h"

void					direction_from_filert(t_minirt *minirt,
							t_direction dir,
							t_filert_direction rtdir)
{
	double sqnorm;

	vec3_from_filert(dir, rtdir);
	sqnorm = t_vec3_sqnorm(dir);
	if (sqnorm > PREC)
		t_vec3_smult(1 / sqrt(sqnorm), dir, dir);
	else
	{
		minirt_write_warning(minirt, direction_is_nul);
		ft_memcpy(dir, minirt->default_direction, sizeof(t_direction));
	}
}
