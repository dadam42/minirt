/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sys.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:02:57 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:02:58 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d42_sys.h"

void			t_sys_init(t_sys *sys)
{
	sys->endianess = sys_get_endianess();
	if (sys->endianess == sys_little_endian)
	{
		sys->dump_to_little_endian = sys_preserv_endianess_dump;
		sys->dump_to_big_endian = sys_invert_endianess_dump;
	}
	else
	{
		sys->dump_to_little_endian = sys_invert_endianess_dump;
		sys->dump_to_big_endian = sys_preserv_endianess_dump;
	}
}
