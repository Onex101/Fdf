#include "vector.h"

void vector_add(t_vector *v, void *item)
{
	if (v->capacity == v->total)
		vector_resize(v, v->capacity * 2);
	v->items[(int)(v->total)++] = item;
}