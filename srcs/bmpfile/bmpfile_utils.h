/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmpfile_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:55:20 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:55:22 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMPFILE_UTILS_H
# define BMPFILE_UTILS_H
# include "bmpfile.h"

t_bmpfile_com	t_bmpfile_write_with_headers(t_bmpfile *bmpfile
											, unsigned char *content
											, int	len);
t_bmpfile_com	t_bmpfile_write_no_header(t_bmpfile *bmpfile
										, unsigned char *content
										, int	len);
void			t_bmpfile_set_headers(t_bmpfile *bmpfile);
t_bmpfile_com	t_bmpfile_write_headers(t_bmpfile *bmpfile);
#endif
