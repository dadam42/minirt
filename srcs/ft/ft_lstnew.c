/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:51:48 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/15 18:51:58 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *ret;

	if ((ret = malloc(sizeof(t_list))))
	{
		ret->next = NULL;
		ret->content = content;
	}
	return (ret);
}
