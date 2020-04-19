/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:18:50 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/15 17:04:40 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*ret;
	char	*fwd_ret;
	size_t	idx;

	size = ft_strlen(s);
	if ((ret = malloc((size + 1) * sizeof(char))))
	{
		fwd_ret = ret;
		idx = 0;
		while (idx < size)
		{
			*fwd_ret++ = f(idx, *s++);
			idx++;
		}
	}
	return (ret);
}
