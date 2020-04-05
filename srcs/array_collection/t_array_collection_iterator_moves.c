#include "array_collection.h"

bool	t_array_collection_iterator_move_fw(t_array_collection_iterator *it)
{
	it->position++;
	if (it->position < it->collection->count)
		return (true);
	return (false);	
}

bool	t_array_collection_iterator_move_bw(t_array_collection_iterator *it)
{
	it->position--;
	if (it->position >= 0)
		return (true);
	return (false);
}
