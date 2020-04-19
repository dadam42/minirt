/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_applys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:52:45 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:52:46 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"

void	t_vec3_apply(t_vec3 a, t_real_app app, t_vec3 r)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		r[cur] = app(a[cur]);
		cur++;
	}
}

void	t_vec3_apply2(t_vec3 a, t_vec3 b, t_bireal_app app, t_vec3 r)
{
	short cur;

	cur = 0;
	while (cur < 3)
	{
		r[cur] = app(a[cur], b[cur]);
		cur++;
	}
}
