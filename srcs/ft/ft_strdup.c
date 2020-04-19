/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:23:59 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/15 14:27:43 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*fwd_ret;
	size_t	len;

	len = ft_strlen(s1);
	if ((ret = malloc(len * sizeof(char) + 1)))
	{
		fwd_ret = ret;
		while (*s1)
			*fwd_ret++ = *s1++;
		*fwd_ret = 0;
	}
	return (ret);
}
