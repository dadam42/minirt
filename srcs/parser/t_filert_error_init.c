/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_filert_error_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:27:56 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:27:58 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

void	t_filert_error_init(t_filert_error *error)
{
	static char *(msg[]) = {
		"Parse error"
		, "Unknown type"
		, "int expected"
		, "float expected"
		, "end of line expected"
		, "bad separator"
		, "color compnent out of range, must be an integer >= 0 AND <= 255"
		, "intensity out of range, must be a float >=0"
		, "direction coordinate out of range, must be a float >= -1 AND <= 1"
		, "sphere's diameter out of range, must be a float >= 0"
		, "camera's fov out of range, must be a float >= 0 AND <= 180"
		, "resolution's parameter out of range, must be an int > 0"
		};

	error->msg = msg;
}
