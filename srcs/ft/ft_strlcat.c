/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:47:52 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/12 11:23:10 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t bufsize)
{
	char		*fwd_dst;
	const char	*fwd_src;
	int			size_dst;
	int			overloaded;

	overloaded = 0;
	fwd_dst = dst;
	while (*fwd_dst++ && bufsize > 0)
		bufsize--;
	size_dst = (--fwd_dst - dst);
	if (!bufsize)
		overloaded = 1;
	fwd_src = src;
	while (bufsize > 1 && *fwd_src)
	{
		*fwd_dst = *fwd_src;
		fwd_src++;
		fwd_dst++;
		bufsize--;
	}
	if (!overloaded)
		*fwd_dst = 0;
	while (*fwd_src)
		fwd_src++;
	return (size_dst + fwd_src - src);
}
