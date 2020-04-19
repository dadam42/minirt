/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_collection.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:30:47 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 17:30:50 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_COLLECTION_H
# define ARRAY_COLLECTION_H
# include <stdbool.h>
# define SIZE_INIT 2

typedef enum			e_array_collection_com
{
	array_collection_ok, array_collection_error
}						t_array_collection_com;

typedef struct			s_array_collection
{
	void	**content;
	int		count;
	int		size;
}						t_array_collection;

typedef struct s_array_collection_iterator
						t_array_collection_iterator;
typedef	bool			(*t_array_collection_iterator_next)
							(t_array_collection_iterator*);
typedef void			*(*t_array_collection_iterator_deref)
							(t_array_collection_iterator*);
typedef struct			s_array_collection_iterator
{
	t_array_collection					*collection;
	int									position;
	t_array_collection_iterator_next	next;
	t_array_collection_iterator_deref	deref;
}						t_array_collection_iterator;

t_array_collection_com	t_array_collection_add(t_array_collection *collection
											, void *elt);
void					t_array_collection_init(t_array_collection *collection);
void					t_array_collection_release
											(t_array_collection *collection);
void					t_array_collection_init_fwiterator(
							t_array_collection *collection
							, t_array_collection_iterator *it);
void					t_array_collection_init_bwiterator(
							t_array_collection	*collection
							, t_array_collection_iterator *it);
bool					t_array_collection_iterator_move_fw(
							t_array_collection_iterator *it);
bool					t_array_collection_iterator_move_bw(
							t_array_collection_iterator *it);
void					*array_collection_iterator_deref
							(t_array_collection_iterator *it);
#endif
