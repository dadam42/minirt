/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_endianess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:02:42 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:03:22 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d42_sys.h"

t_sys_endianess	sys_get_endianess(void)
{
	t_endianess_tester tester;

	tester.my_int = 1;
	if (tester.my_int_bytes[0] == 1)
		return (sys_little_endian);
	return (sys_big_endian);
}

void			sys_preserv_endianess_dump(void *in, void *out, size_t len)
{
	unsigned char	*ucin;
	unsigned char	*ucout;

	ucin = in;
	ucout = out;
	while (len > 0)
	{
		*ucin = *ucout;
		ucin++;
		ucout++;
		len--;
	}
}

void			sys_invert_endianess_dump(void *in, void *out, size_t len)
{
	unsigned char *ucin;
	unsigned char *ucout;

	ucin = in;
	ucout = out + len - 1;
	while (len > 0)
	{
		*ucin = *ucout;
		ucin++;
		ucout--;
		len--;
	}
}
