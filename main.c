/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:47:32 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/18 13:52:06 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "fdf.h"
#include <time.h>

int	draw_line(t_struct *win)
{
	int x;
	int y;

	x = 0;
	while (x < 500) 
	{
		y = 0;
		while (y < 500)
		{
			mlx_pixel_put ((win->mlx), (win->window), x, y, 0xFFFFFF);
			y += x + 1;
			printf("Y");
		}
		x += 1;
	}
	mlx_clear_window((win->mlx), (win->window));
	return (0);
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
