/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:05:51 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:13:09 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

static void	minirt_init_warn_msg(t_minirt *minirt)
{
	static char *(warn_msg[]) = {
		"Direction was too small, changed to negx direction"
		"relatively to canonical base.\n"
		, "Height was not positive, changed to default height : 800.\n"
		, "Width was not positive, changed to default width : 800.\n"
		, "Object can't be displayed.\n"
	};

	minirt->warn_msg = warn_msg;
}

static void	minirt_init_err_msg(t_minirt *minirt)
{
	static char *(err_msg[]) = {
		"Minirt error.\n"
		, "Minirt mem error.\n"
		, "Minirt parse error.\n"
		, "Minirt object has not been initialized correctly.\n"
	};

	minirt->err_msg = err_msg;
}

void		minirt_init(t_minirt *minirt)
{
	static t_base		canonical = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	static t_direction	default_direction = {-1, 0, 0};

	minirt->stdoutput = 1;
	minirt->erroutput = 2;
	minirt->write_error = minirt_errwrite;
	minirt->write_info = minirt_stdwrite;
	minirt->write_warning = minirt_stdwrite;
	minirt->canonical = &canonical;
	minirt->default_direction = &default_direction;
	minirt->default_display_width = 800;
	minirt->default_display_height = 800;
	minirt_init_err_msg(minirt);
	minirt_init_warn_msg(minirt);
	scene_init(&minirt->scene);
}
