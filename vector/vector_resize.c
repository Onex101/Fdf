#include "vector.h"

void vector_resize(t_vector *v, int capacity)
{
	void **items;

	items = (void **)malloc(sizeof(void *) * capacity);
	ft_memcpy(items, v->items, sizeof(void *) * v->capacity);
	free(v->items);
	if (items)
	{
		v->items = items;
		v->capacity = capacity;
	}
}
