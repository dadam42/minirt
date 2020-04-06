#include "array_collection.h"
#include <stdlib.h>

void	t_array_collection_release(t_array_collection *collection)
{
	free(collection->content);
}
