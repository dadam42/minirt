/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operators_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:55:45 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:55:46 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"
#include <math.h>

void	t_vec3_smult(double l, t_vec3 a, t_vec3 r)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		r[cur] = l * a[cur];
		cur++;
	}
}

double	t_vec3_sqnorm(t_vec3 a)
{
	return (a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

double	t_vec3_normalize(t_vec3 a)
{
	double ret;

	ret = sqrt(t_vec3_sqnorm(a));
	t_vec3_smult(1 / ret, a, a);
	return (ret);
}
