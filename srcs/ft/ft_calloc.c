/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:58:04 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/12 11:20:57 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void				*ret;
	char				*fwd_ret;
	unsigned long long	rsize;

	rsize = count * size;
	if ((ret = malloc(rsize)))
	{
		fwd_ret = ret;
		while (rsize-- > 0)
		{
			*(fwd_ret) = 0;
			fwd_ret++;
		}
	}
	return (ret);
}
