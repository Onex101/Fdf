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

int ft_abs(int i)
{
	if (i < 0)
		return(i * -1);
	return (i);
}

// int	draw_line(t_struct *win)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	while (x < 500) 
// 	{
// 		y = 0;
// 		while (y < 500)
// 		{
// 			mlx_pixel_put ((win->mlx), (win->window), x, y, 0xFFFFFF);
// 			y += x + 1;
// 			printf("Y");
// 		}
// 		x += 1;
// 	}
// 	mlx_clear_window((win->mlx), (win->window));
// 	return (0);
// }

int draw_line(t_line *line)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int m;

	dx =  ft_abs (line->x2 - line->x1);
	dy = -ft_abs (line->y2 - line->y1);
	sx = line->x1 < line->x2 ? 1 : -1;
	sy = line->y1 < line->y2 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		printf("Hi");
		mlx_pixel_put((line->box->mlx), (line->box->window), line->x1, line->y1, 0xFFFFFF);
		if (line->x1 == line->x2 && line->y1 == line->y2) 
			break;
		m = 2 * err;
		if (m >= dy)
		{ 
			err += dy; 
			line->x1 += sx; 
		}
		if (m <= dx)
		{
			err += dx; 
			line->y1 += sy; 
		}
	}
	return (0);
}

int clock(t_line *line)
{
	int points;

	points = 2000;
	// while (points > 1500)
	// {
	// 	draw_line(line);
	// 	points--;
	// 	line->x1 += 1;
	// }
	while (points > 1000)
	{
		draw_line(line);
		points--;
		line->y1 += 1;
	}
	while (points > 500)
	{
		draw_line(line);
		points--;
		line->x1 -= 1;
	}
	while (points)
	{
		draw_line(line);
		points--;
		line->y1 -= 1;
	}
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
	line->box = win;
	line->x1 = 0;
	line->x2 = 250;
	line->y1 = 0;
	line->y2 = 250;
	mlx_loop_hook((win->mlx), &(clock), (void *)line);	
	//mlx_key_hook ( win->window, &draw_line, (void *)win);
	mlx_loop (win->mlx);
	return (0);
}
