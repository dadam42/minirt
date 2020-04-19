/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bmpfile_write_headers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:51:16 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:52:02 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmpfile.h"
#include "bmpfile_utils.h"
#include <unistd.h>

t_bmpfile_com	t_bmpfile_write_headers(t_bmpfile *bmpfile)
{
	if (write(bmpfile->fd, bmpfile->header, 14) != 14
		|| write(bmpfile->fd, bmpfile->infoheader, 40) != 40)
		return (bmpfile_error);
	bmpfile->write = t_bmpfile_write_no_header;
	return (bmpfile_ok);
}
