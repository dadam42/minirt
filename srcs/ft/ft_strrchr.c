/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:14:35 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/10 17:31:36 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *fwd;

	fwd = s;
	while (*fwd)
		fwd++;
	while (fwd >= s)
	{
		if (*fwd == (char)c)
			return ((char*)fwd);
		fwd--;
	}
	return (NULL);
}
