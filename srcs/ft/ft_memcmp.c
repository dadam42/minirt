/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:20:07 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/10 17:25:31 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	while (len-- > 0)
	{
		if (*((const char*)str1) != *((const char*)str2))
			return (*((unsigned char*)str1) - *((unsigned char*)str2));
		str1++;
		str2++;
	}
	return (0);
}
