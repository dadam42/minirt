/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 00:38:40 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/17 15:22:04 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *fwd_lst;
	t_list *prev_lst;

	fwd_lst = *lst;
	while (fwd_lst)
	{
		del(fwd_lst->content);
		prev_lst = fwd_lst;
		fwd_lst = fwd_lst->next;
		free(prev_lst);
	}
}
