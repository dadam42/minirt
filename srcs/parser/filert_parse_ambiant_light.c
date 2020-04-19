/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parse_ambiant_light.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:08:35 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:08:36 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

t_filert_parser_com	filert_parse_ambiant_light(char **str
												, t_filert_parsed_obj *obj)
{
	t_filert_parser_com	ret;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_pcolor(str, &obj->ambiant_light);
	if (ret != filert_internal)
		return (ret);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error_end_of_line_expected);
	return (filert_ambiant_light);
}
