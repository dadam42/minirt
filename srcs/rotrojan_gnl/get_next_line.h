/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:16:44 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/08 18:56:45 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif
typedef enum e_gnl_com
{
	gnl_error = -1, gnl_continue = 1, gnl_eof = 0
}		t_gnl_com;

int			get_next_line(int fd, char **line);
char		*ft_strdup(char const *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(char const *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(char const *s, int c);

#endif
