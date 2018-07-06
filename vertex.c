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

t_vec3	*new_vertex(double x, double y, double z)
{
	t_vec3 *vertex;

	vertex = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!vertex)
	 	return (NULL);
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
	return (vertex);
}

void	del_vertex(t_vec3 *vertex)
{
	if (vertex)
		free(vertex);
}
