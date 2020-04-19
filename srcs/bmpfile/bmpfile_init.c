/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmpfile_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:52:53 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:54:20 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmpfile.h"
#include "bmpfile_utils.h"
#include "libft.h"
#define FILLER 66

void	bmpfile_init(t_bmpfile *bmpfile, t_bmpfile_info *info)
{
	unsigned char cur;

	ft_memcpy(bmpfile, info, sizeof(t_bmpfile_info));
	bmpfile->padding = (4 - (info->width & 3)) & 3;
	bmpfile->bpp = 24;
	t_bmpfile_set_headers(bmpfile);
	bmpfile->hcur = 0;
	bmpfile->wcur = 0;
	bmpfile->write = 0;
	cur = 0;
	while (cur < 3)
	{
		bmpfile->padder[cur] = FILLER;
		cur++;
	}
}
