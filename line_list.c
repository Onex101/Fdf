/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:10:22 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/09 08:10:27 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ********************************************************************	****** */

#include "fdf.h"

void init_array(t_array *a, size_t size)
{
  a->array = (int *)malloc(size * sizeof(int));
  a->used = 0;
  a->size = size;
}

void free_array(t_array *a)
{
	a->array = NULL;
	a->used = 0;
	a->size = 0;
	free(a->array);
}

void add_array(t_array *a, int element)
{
	int *tmp;
	size_t i;

	if (a->used == a->size)
	{
		tmp = (int *)malloc(sizeof(int) * a->size * 2);
		if (tmp)
		{
			i = 0;
			while(i < a->used)
			{
				tmp[i] = a->array[i];
				i++;
			}
		}
		free(a->array);
		a->array = tmp;
		a->size *= 2;
	}
	a->array[a->used++] = element;
}

t_line_list	*new_line_list(void)
{
	t_line_list	*line_list;
	
	line_list = (t_line_list *)malloc(sizeof(t_line_list));
	line_list->ver_vec = (t_vector*)malloc(sizeof(t_vector));
	vector_init(line_list->ver_vec);
	line_list->ind_vec = (t_array*)malloc(sizeof(t_array));
	init_array(line_list->ind_vec, 2);
	return (line_list);
}
