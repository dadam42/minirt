/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_add_prop_from_filert.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:54:07 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:54:12 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt_com	minirt_add_prop_from_filert(t_minirt *minirt
							, t_filert_parser_com type
							, t_filert_parsed_obj *parsed)
{
	if (type == filert_resolution)
		return (minirt_add_rtresolution(minirt, parsed));
	return (minirt_add_rtambiant_light(minirt, parsed));
}
