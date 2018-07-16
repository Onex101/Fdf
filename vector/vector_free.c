#include "vector.h"

void vector_free(t_vector *v)
{
	free(v->items);
}