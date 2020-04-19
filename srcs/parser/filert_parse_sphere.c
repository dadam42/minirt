/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parse_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:25:23 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:25:25 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

t_filert_parser_com	filert_parse_sphere(char **str
												, t_filert_parsed_obj *obj)
{
	t_filert_parser_com	ret;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_position(str, &obj->sphere.center);
	if (ret != filert_internal)
		return (ret);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_float(str, &obj->sphere.diameter);
	if (ret != filert_internal)
		return (ret);
	if (obj->sphere.diameter < 0)
		return (filert_error_sphere_diameter_out_of_range);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_color(str, &obj->sphere.color);
	if (ret != filert_internal)
		return (ret);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error_end_of_line_expected);
	return (filert_sphere);
}
