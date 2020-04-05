#ifndef ITERATOR_H
# define ITERATOR_H

typedef struct	s_oneway_iterator
				t_oneway_iterator;
typedef	void	(*t_oneway_iterator_move)(t_oneway_iterator*);
typedef	void	*(*t_oneway_iterator_deref)(t_oneway_iterator*);

struct			s_oneway_iterator
{
	t_oneway_iterator_move	next;
	t_oneway_iterator_deref	deref;
};
void	t_oneway_iterator_init(t_oneway_iterator* it
							, t_oneway_iterator_move* next
							, t_oneway_iterator_deref* deref);

typedef struct	s_twoways_iterator
				t_twoways_iterator;
struct			s_twoways_iterator
{
	t_oneway_iterator		fw;
	t_oneway_iterator_move	prev;
};
void	t_twoways_iterator_init(t_twoways_iterator* it
							, t_oneway_iterator_move* prev
							, t_oneway_iterator_move* next
							, t_oneway_iterator_deref* deref);
#endif
