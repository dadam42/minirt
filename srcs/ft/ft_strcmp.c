/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:19:19 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/15 14:32:47 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *str1, const char *str2)
{
	while (((unsigned char)*str1 == (unsigned char)*str2) &&
		(*str1))
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
