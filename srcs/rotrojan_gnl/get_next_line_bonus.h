/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:00:15 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/12 07:31:48 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct		s_list
{
	int					fd;
	char				*s_buf;
	struct s_list		*next;
}					t_list;

int					get_next_line(int fd, char **line);
char				*ft_strdup(char const *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(char const *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strchr(char const *s, int c);

#endif
