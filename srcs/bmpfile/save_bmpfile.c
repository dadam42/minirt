/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmpfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:47:56 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:48:01 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmpfile.h"
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "d42_sys.h"
#include "bmpfile_utils.h"
#define BPP 3

t_bmpfile_com			save_bmpfile(char *filename, unsigned char *content
									, t_bmpfile_info *info)
{
	t_bmpfile_com	ret;
	t_bmpfile		bmpfile;
	int				cur_line;

	bmpfile_init(&bmpfile, info);
	if (bmpfile_open(&bmpfile, filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)
		== bmpfile_error)
		return (bmpfile_error);
	cur_line = info->height - 1;
	ret = bmpfile_ok;
	while (cur_line >= 0 && ret == bmpfile_ok)
	{
		ret = bmpfile.write(&bmpfile
			, content + BPP * info->width * cur_line, info->width);
		cur_line--;
	}
	bmpfile_close(&bmpfile);
	return (ret);
}
