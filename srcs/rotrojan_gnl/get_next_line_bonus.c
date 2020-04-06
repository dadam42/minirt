/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 00:53:56 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/13 22:06:40 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		free_link_and_return(t_list **current, int to_return)
{
	t_list		*tmp;

	tmp = (*current)->next;
	if ((*current)->s_buf)
		free((*current)->s_buf);
	free(*current);
	*current = tmp;
	return (to_return);
}

static t_list	**select_fd_buf(int fd, t_list **fd_buf_list)
{
	t_list		**current;

	current = fd_buf_list;
	while (*current)
	{
		if (fd == ((*current)->fd))
			return (current);
		current = &((*current)->next);
	}
	if (!((*current) = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	(*current)->fd = fd;
	(*current)->s_buf = NULL;
	(*current)->next = NULL;
	return (current);
}

static int		append_line(int fd, char **line, t_list **current, int ret)
{
	char	*tmp;

	tmp = (*current)->s_buf;
	while (*tmp && *tmp != '\n')
		tmp++;
	if (*tmp == '\n')
	{
		if (!(*line = ft_substr((*current)->s_buf, 0, tmp - (*current)->s_buf)))
			return (free_link_and_return(current, -1));
		if (!(tmp = ft_strdup(++tmp)))
			return (free_link_and_return(current, -1));
		free((*current)->s_buf);
		(*current)->s_buf = tmp;
	}
	else if (!*tmp)
	{
		if (ret == BUFFER_SIZE)
			get_next_line(fd, line);
		if (!(*line = ft_strdup((*current)->s_buf)))
			return (free_link_and_return(current, -1));
		free((*current)->s_buf);
		(*current)->s_buf = NULL;
		return (free_link_and_return(current, 0));
	}
	return (1);
}

static int		check_and_return(int fd, char **line, t_list **current, int ret)
{
	if (ret < 0)
		return (free_link_and_return(current, -1));
	if ((!ret && (!(*current)->s_buf || !*((*current)->s_buf))) || !current)
	{
		*line = ft_strdup("");
		return (free_link_and_return(current, 0));
	}
	return (append_line(fd, line, current, ret));
}

int				get_next_line(int fd, char **line)
{
	static t_list		*fd_buf_list;
	t_list				**current;
	char				r_buf[BUFFER_SIZE + 1];
	int					ret;
	char				*tmp;

	if (fd < 0 || !line)
		return (-1);
	current = select_fd_buf(fd, &fd_buf_list);
	while ((ret = read(fd, r_buf, BUFFER_SIZE)) > 0)
	{
		r_buf[ret] = '\0';
		if (!(tmp = ft_strjoin((*current)->s_buf, r_buf)))
			return (free_link_and_return(current, -1));
		free((*current)->s_buf);
		(*current)->s_buf = tmp;
		if (ft_strchr((*current)->s_buf, '\n'))
			break ;
	}
	return (check_and_return(fd, line, current, ret));
}
