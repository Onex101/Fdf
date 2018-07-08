#include "fdf.h"

void init_array(t_array *a, size_t size)
{
  a->array = (int *)malloc(size * sizeof(int));
  a->used = 0;
  a->size = size;
}

void add_array(t_array *a, int element)
{
	int *tmp;

	tmp = (int *)malloc(sizeof(int) * a->size * 2);
	if (a->used == a->size)
	{
		ft_memcpy(tmp, a->array, sizeof(void *) * a->size);
		free(a->array);
		if (tmp)
		{
			a->array = tmp;
			a->size *= 2;
		}
		a->size *= 2;
	}
	a->array[a->used++] = element;
}

void free_array(t_array *a)
{
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

t_line_list	*new_line_list(void)
{
	t_line_list	*line_list;
	
	line_list = (t_line_list *)malloc(sizeof(t_line_list));
	line_list->ver_vec = (t_vector*)malloc(sizeof(t_vector));
	vector_init(line_list->ver_vec);
	line_list->ind_vec = (t_array*)malloc(sizeof(t_array));
	init_array(line_list->ind_vec, 1);
	return (line_list);
}
