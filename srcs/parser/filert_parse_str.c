/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parse_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:26:14 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:26:36 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

t_filert_parser_com	filert_parse_str(char **str
									, char *parsed)
{
	while (**str == *parsed && *parsed)
	{
		(*str)++;
		parsed++;
	}
	if (*parsed)
		return (filert_error);
	return (filert_internal);
}
