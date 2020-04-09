#include "array_collection.h"

void	*array_collection_iterator_deref(
			t_array_collection_iterator *it)
{
	if (it->position >= 0 && it->position < it->collection->count)
		return (it->collection->content[it->position]);
	return (0);
}
