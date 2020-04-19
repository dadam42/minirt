/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 00:40:31 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/17 15:36:18 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cur;
	t_list	*prev;

	ret = NULL;
	prev = NULL;
	while (lst)
	{
		if ((cur = malloc(sizeof(t_list))))
		{
			cur->content = f(lst->content);
			if (prev)
				prev->next = cur;
			prev = cur;
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
	}
	return (ret);
}
