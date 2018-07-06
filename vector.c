/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/27 06:26:02 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/includes/libft.h"
#include "vector.h"

void vector_init(t_vector *v)
{
	ft_putendl("Entered init");
	v->capacity = 4;
	ft_putendl("Cap done");
	v->total = 0;
	ft_putendl("malloc");
	v->items = malloc(sizeof(void *) * v->capacity);
	ft_putendl("malloc done");
}

int vector_total(t_vector *v)
{
	return (v->total);
}

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

void vector_add(t_vector *v, void *item)
{
	if (v->capacity == v->total)
		vector_resize(v, v->capacity * 2);
	v->items[v->total++] = item;
}

void vector_set(t_vector *v, int index, void *item)
{
	if (index >= 0 && index < v->total)
		v->items[index] = item;
}

void *vector_get(t_vector *v, int index)
{
	if (index >= 0 && index < v->total)
		return v->items[index];
	return NULL;
}

void vector_delete(t_vector *v, int index)
{
	int i;
	if (index < 0 || index >= v->total)
		return;
	v->items[index] = NULL;
	i = index;
	while (i < v->total - 1)
	{
		v->items[i] = v->items[i + 1];
		v->items[i + 1] = NULL;
		i++;
	}
	v->total--;
	if (v->total > 0 && v->total == v->capacity / 4)
		vector_resize(v, v->capacity / 2);
}

void vector_free(t_vector *v)
{
	free(v->items);
}
