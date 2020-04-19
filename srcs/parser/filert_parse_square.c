/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parse_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:25:57 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:25:59 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

t_filert_parser_com	filert_parse_square(char **str
												, t_filert_parsed_obj *obj)
{
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_position(str, &obj->square.center) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_direction(str, &obj->square.orth) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_float(str, &obj->square.size) == filert_error)
		return (filert_error);
	if (obj->square.size < 0)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_color(str, &obj->square.color) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error);
	return (filert_square);
}
