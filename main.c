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
// 	10return (0);
// }

int draw_line(t_line *line)
{
	int dx;
	int dy;
	int sx;
	int sy;
	float err;
	int m;

	dx = ft_abs (line->x2 - line->x1);
	dy = ft_abs (line->y2 - line->y1);
	sx = line->x1 < line->x2 ? 1 : -1;
	sy = line->y1 < line->y2 ? 1 : -1;
	err = (dx > dy) ? dx/2 : -dy/2;
	if (line->x1 == line->x2 && line->y1 == line->y2)
		return (-1);
	while (1)
	{
		mlx_pixel_put((line->box->mlx), (line->box->window), line->x1, line->y1, 0xFFFFFF);
		// if (line->x1 == line->x2 && line->y1 == line->y2)
		// 	printf("x1: [%d], y1: [%d], x2: [%d], y2: [%d]\n", line->x1, line->y1, line->x2, line->y2);
		if (line->x1 == line->x2 && line->y1 == line->y2)
			break;
		m = err;
		if (m < dy)
		{ 
			err += dx; 
			line->y1 += sy; 
		}
		if (m > -dx)
		{
			err -= dy; 
			line->x1 += sx; 
		}
	}
	printf("x1: [%d], y1: [%d], x2: [%d], y2: [%d]\n", line->x1, line->y1, line->x2, line->y2);
	return (0);
}

void draw_circle(t_line *line)
{
	mlx_pixel_put((line->box->mlx), (line->box->window), line->x1 + line->x2, line->y1 + line->y2, 0xFFFFFF);
	mlx_pixel_put((line->box->mlx), (line->box->window), line->x1 - line->x2, line->y1 + line->y2, 0xFFFFFF);
	mlx_pixel_put((line->box->mlx), (line->box->window), line->x1 + line->x2, line->y1 - line->y2, 0xFFFFFF);
	mlx_pixel_put((line->box->mlx), (line->box->window), line->x1 - line->x2, line->y1 - line->y2, 0xFFFFFF);
	mlx_pixel_put((line->box->mlx), (line->box->window), line->x1 + line->y2, line->y1 + line->x2, 0xFFFFFF);
	mlx_pixel_put((line->box->mlx), (line->box->window), line->x1 - line->y2, line->y1 + line->x2, 0xFFFFFF);
	mlx_pixel_put((line->box->mlx), (line->box->window), line->x1 + line->y2, line->y1 - line->x2, 0xFFFFFF);
	mlx_pixel_put((line->box->mlx), (line->box->window), line->x1 - line->y2, line->y1 - line->x2, 0xFFFFFF);
}

int circle(t_line *line)
{
	int d;
	int x;
	int y;

	line->x2 = 0;
	line->y2 = 100;
	x = line->x2;
	y = line->y2;
	d = 3 - 2*(line->y2);
	while (line->x2 < line->y2)
	{
		draw_circle(line);
		line->x2 += 1;
		if (d < 0)
			d += 4*(line->x2) + 6;
		else
		{
			line->y2 -= 1;
			d = d + 4*(line->x2 - line->y2) + 10;
		}
		draw_circle(line);
		line->x2 += 1;
	}
	return (0);
}

int parabola_w_lines(t_line *line)
{
	int x;
	int y;

	x = line->x1;
	while (line->y1 > 0)
	{
		printf("Hello");
		y = line->y1;
		draw_line(line);
		line->x1 = x;
		line->y1 = y - 5;
		line->x2 += 5;
		mlx_clear_window((line->box->mlx), (line->box->window));
	}
	return (0);
}

void	origin_factor(t_line *line, int w, int h)
{
	line->x1 = line->x1 * w/2 + h/2;
	line->y1 = -line->y1 * w/2 + h/2;
	line->x2 = line->x2 * w/2 + h/2;
	line->y2 = -line->y2 * w/2 + h/2;
}

int	main(void)
{
	t_struct	*win;
	t_line		*line;
	int			width  = 500;
	int			height = 500;

	win = (t_struct *)malloc(sizeof(t_struct));
	line = (t_line *)(malloc)(sizeof(t_line));
	if (!win || !line)
		return (-1);
	win->mlx = mlx_init();
	win->window = mlx_new_window ((win->mlx) , width, height, "New Window" );
	line->box = win;
	line->x1 = 0;
	line->y1 = 0;
	line->x2 = 0;
	line->y2 = 100;
	origin_factor(line, width, height);
	mlx_loop_hook((win->mlx), &(circle), (void *)line);	
	//mlx_key_hook ( win->window, &draw_line, (void *)win);
	mlx_loop (win->mlx);
	return (0);
}
