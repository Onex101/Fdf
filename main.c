/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:47:32 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/19 06:52:49 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "fdf.h"
#include <stdio.h>

void project(t_vertex *vertex)
{
	if(!vertex->aligned.z)
		vertex->aligned.z = 1;
	vertex->screen.x = FOCAL_DISTANCE * vertex->aligned.x / vertex->aligned.z + XOrigin;
	vertex->screen.y = FOCAL_DISTANCE * vertex->aligned.y / vertex->aligned.z + YOrigin;
}

t_vector *new_vector(double x, double y, double z)
{
	t_vector *vector;
	vector = (t_vector *)malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->len = sqrt(x*x + y*y + z*z);
	return (vector);
}

t_vertex *new_vertex(double x, double y, double z)
{
	t_vertex *vertex;
	vertex = (t_vertex *)malloc(sizeof(t_vertex));
	if (!vertex)
		return (NULL);
	vertex->local = new_vector(x, y, z);
	if (!vertex->local)
		return (NULL);
	return (vertex);
}

void orgin_factor(t_vector *vector, double width, double height)
{
	vector->x = (vector->x + 1) * (width / 2);
	vector->y = (-vector->y * 1) * (height / 2);
}

void cube(double size)
{
	void **vertices;
	double side;

	vertices = (void **)malloc(sizeof(t_vertex *) * 8);
	if (!vertices)
		return ;
	side = size / 2;
	vertices[0] = new_vertex(-size, -size, -size);
	vertices[1] = new_vertex(size, -size, -size);
	vertices[2] = new_vertex(-size, size, -size);
	vertices[3] = new_vertex(size, size, -size);
	vertices[4] = new_vertex(-size, -size, size);
	vertices[5] = new_vertex(size, -size, size);
	vertices[6] = new_vertex(-size, size, size);
	vertices[7] = new_vertex(size, size, -size);
}