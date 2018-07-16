#include "vector.h"

void vector_init(t_vector *v)
{
	v->capacity = 1;
	v->total = 0;
	v->items = malloc(sizeof(void *) * v->capacity);
}