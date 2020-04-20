/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_write_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:30:34 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:30:35 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	minirt_write_error(t_minirt *minirt, t_minirt_com errcode)
{
	minirt->write_error(minirt, minirt_strerror(minirt, errcode));
}
