/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_add_rtlight.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:57:38 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:57:39 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>

t_minirt_com	minirt_add_rtlight(t_minirt *minirt
							, t_filert_parsed_obj *parsed)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (minirt_mem_error);
	vec3_from_filert(light->position, parsed->light.position);
	pcolor_from_filert(&light->color, &parsed->light.pcolor);
	return (scene_add_light(&minirt->scene, light));
}
