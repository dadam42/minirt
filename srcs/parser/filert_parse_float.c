/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parse_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:16:49 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:40:12 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

static t_filert_parser_com	filert_parse_float_tr_com(t_filert_parser_com com)
{
	if (com == filert_internal)
		return (filert_internal);
	else
		return (filert_error_float_expected);
}

static void					filert_parse_float_loop(char **str
													, float *parsed, float cur)
{
	while (1)
	{
		*parsed += cur * (**str - '0');
		cur /= 10;
		(*str)++;
		if (!(**str >= '0' && **str <= '9'))
			break ;
	}
}

t_filert_parser_com			filert_parse_float(char **str
												, float *parsed)
{
	short				isneg;
	t_filert_parser_com	int_part_com;
	int					int_part;
	float				cur;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	isneg = 0;
	if (**str == '-')
		isneg = 1;
	int_part_com = filert_parse_int(str, &int_part);
	*parsed = int_part;
	if (!(**str == '.'))
		return (filert_parse_float_tr_com(int_part_com));
	(*str)++;
	if (!(**str >= '0' && **str <= '9'))
		return (filert_parse_float_tr_com(int_part_com));
	cur = (isneg == 1 ? -0.1 : 0.1);
	filert_parse_float_loop(str, parsed, cur);
	return (filert_internal);
}
