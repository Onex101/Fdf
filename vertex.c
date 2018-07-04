/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/27 06:26:02 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void new_vector(t_vector **vector, double x, double y, double z)
{
	*vector = (t_vector *)malloc(sizeof(t_vector));
	if (!*vector)
	 	return ;
	(*vector)->x = x + 250;
	(*vector)->y = -y + 250;
	(*vector)->z = z;
}

t_vertex new_vertex(double x, double y, double z)
{
	t_vertex vertex;
	new_vector(&vertex.original, x, y, z);
	vertex.screen = NULL;
	vertex.aligned = NULL;
	return (vertex);
}

void	del_vector(t_vector *vector)
{
	if (vector)
		free(vector);
}

void	del_vertex(t_vertex *vertex)
{
	if (vertex)
	{
		del_vector(vertex->original);
		del_vector(vertex->screen);
		del_vector(vertex->aligned);
		free(vertex);
	}
}
