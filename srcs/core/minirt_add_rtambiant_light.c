/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_add_rtambiant_light.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:54:30 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:54:31 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

t_minirt_com	minirt_add_rtambiant_light(t_minirt *minirt
									, t_filert_parsed_obj *parsed)
{
	pcolor_from_filert(&minirt->scene.ambiant_light, &parsed->ambiant_light);
	return (minirt_ok);
}
