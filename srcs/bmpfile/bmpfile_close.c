/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmpfile_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:42:05 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:42:08 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmpfile.h"
#include <unistd.h>
#include <fcntl.h>

void			bmpfile_close(t_bmpfile *bmpfile)
{
	close(bmpfile->fd);
}
