/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_write_warning.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:31:47 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:31:48 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	minirt_write_warning(t_minirt *minirt, t_minirt_warning wcode)
{
	minirt->write_warning(minirt, minirt->warn_msg[wcode]);
}
