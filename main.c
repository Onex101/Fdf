/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:47:32 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/25 07:47:12 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void project(t_vertex *vertex)
{
	if(!vertex->aligned.z)
		vertex->aligned.z = 1;
	vertex->screen.x = FOCAL_DISTANCE * vertex->aligned.x / vertex->aligned.z + XOrigin;
	vertex->screen.y = FOCAL_DISTANCE * vertex->aligned.y / vertex->aligned.z + YOrigin;
}

void cube(double size)
{
	void **vertices;
	int *index;
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

	index = (int *)malloc(25);
	index[25] = '\0';
	index = {0,1,1,3,3,2,2,0,0,4,1,5,3,7,2,6,4,5,5,7,6,6,4};
}

int	main(void)
{
	t_struct	*win;
	t_line		*line;

	win = (t_struct *)malloc(sizeof(t_struct));
	line = (t_line *)(malloc)(sizeof(t_line));
	if (!win || !line)
		return (-1);
	win->mlx = mlx_init();
	win->window = mlx_new_window ((win->mlx) , 500, 500, "New Window" );

	mlx_loop_hook((win->mlx), &(draw_line), (void *)win);	
	//mlx_key_hook ( win->window, &draw_line, (void *)win);
	mlx_loop (win->mlx);
	return (0);
}
