#include "array_collection.h"
#include "libft.h"
#include <stdlib.h>

static	t_array_collection_com	enlarge_array_collection(t_array_collection *collection)
{
	void	**ncontent;
	int		nsize;

	if (collection->size == 0)
	{
		ncontent = malloc(SIZE_INIT * sizeof(void*));
		if (!ncontent)
			return (array_collection_error);
		nsize = SIZE_INIT;
	}
	else
	{
		ncontent = malloc(collection->size * 2 * sizeof(void*));
		if (!ncontent)
			return (array_collection_error);
		nsize = collection->size * 2;
		ft_memcpy(ncontent, collection->content
				, collection->size * sizeof(void*));
		free(collection->content);
	}
	collection->content = ncontent;
	collection->size = nsize;
	return (array_collection_ok);
}

t_array_collection_com 	t_array_collection_add(t_array_collection *collection
												, void	*elt)
{
	if (collection->count == collection->size)
		if (enlarge_array_collection(collection) == array_collection_error)
			return	(array_collection_error);
	collection->content[collection->count] = elt;
	collection->count++;
	return (array_collection_ok);
}
