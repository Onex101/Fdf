/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:34:51 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/17 08:34:53 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vector.h"

void vector_init(t_vector *v)
{
	v->capacity = 1;
	v->total = 0;
	v->items = malloc(sizeof(void *) * v->capacity);
}
