/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_load_filert_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:23:24 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:23:25 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_cursor_line(t_minirt *minirt, t_filert_load_loop_state *state)
{
	while (state->cur >= state->line)
	{
		state->cur--;
		if (*state->cur == '\t')
			minirt->write_error(minirt, "\t");
		else
			minirt->write_error(minirt, " ");
	}
}
