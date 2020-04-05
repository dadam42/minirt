#include	"iterator.h"

void	t_oneway_iterator_init(t_oneway_iterator* it
							, t_oneway_iterator_move* next
							, t_oneway_iterator_deref* deref)
{
	it->next = next;
	it->deref = deref;
}


void	t_twoways_iterator_init(t_twoways_iterator* it
							, t_oneway_iterator_move* prev
							, t_oneway_iterator_move* next
							, t_oneway_iterator_deref* deref)
{
	t_oneway_iterator_init((t_oneway_iterator*)it, next, deref);
	it->prev = prev;
}
