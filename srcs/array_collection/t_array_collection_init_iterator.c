#include "array_collection.h"

void	t_array_collection_init_iterator(
				t_array_collection	*collection
				, t_array_collection_iterator *it)
{
	it->collection = collection;
	it->position = -1;
}

void	t_array_collection_init_bwiterator(
				t_array_collection	*collection
				, t_array_collection_iterator *it)
{
	it->collection = collection;
	it->position = collection->count;
}
