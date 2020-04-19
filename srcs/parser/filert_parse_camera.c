/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parse_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:11:30 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:11:31 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

t_filert_parser_com	filert_parse_camera(char **str, t_filert_parsed_obj *obj)
{
	t_filert_parser_com	ret;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_position(str, &obj->camera.position);
	if (ret != filert_internal)
		return (ret);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_direction(str, &obj->camera.direction);
	if (ret != filert_internal)
		return (ret);
	ret = filert_parse_float(str, &obj->camera.fov);
	if (ret != filert_internal)
		return (ret);
	if (!(obj->camera.fov > 0 && obj->camera.fov < 180))
		return (filert_error_fov_out_of_range);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error_end_of_line_expected);
	return (filert_camera);
}
