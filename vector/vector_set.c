/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:35:10 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/17 08:35:12 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vector.h"

void vector_set(t_vector *v, int index, void *item)
{
	if (index >= 0 && index < v->total)
		v->items[index] = item;
}
