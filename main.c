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

int main(void)
{
	float matrix[4][4];
	float mat1[4][4];
	float mat2[4][4];

}

t_vector *new_vector(float x, float y, float z)
{
	t_vector *vector;
	vector = (t_vector *)malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vertex *new_vertex(float x, float y, float z)
{
	t_vertex *vector;
	vertex = (t_vertex *)malloc(sizeof(t_vertex));
	if (!vertex)
		return (NULL);
	vertex->local = new_vector(x, y, z);
	if (!vertex->local)
		return (NULL);
	return (vertex);
}