#include "vector.h"

void *vector_get(t_vector *v, int index)
{
	if (index >= 0 && index < v->total)
	{
		return (v->items[index]);
	}
	return NULL;
}