/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:34:44 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/17 08:34:45 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vector.h"

void *vector_get(t_vector *v, int index)
{
	if (index >= 0 && index < v->total)
	{
		return (v->items[index]);
	}
	return NULL;
}
