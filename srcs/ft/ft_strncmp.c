/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:26:11 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/12 10:33:50 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (((unsigned char)*str1 == (unsigned char)*str2) &&
			(*str1) && n > 0)
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)*(str1) - (unsigned char)*(str2));
}
