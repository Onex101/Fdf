/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:48:50 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/25 11:49:03 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void draw_line(t_line *line)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int m;

	void *window = get_window("Hello");

	dx =  fabs(line->x2 - line->x2);
	dy = -(fabs(line->y2 - line->y1));
	sx = line->x1 < line->x2 ? 1 : -1;
	sy = line->y1 < line->y2 ? 1 : -1;
	err = dx + dy;

	ft_putendl("Before while");
	while (line->x1 != line->x2 && line->y1 != line->y2)
	{

		mlx_pixel_put(get_mlx(), window, line->x1, line->y1, 0xFFFFFF);
		m = 2 * err;
		if (m >= dy)
		{ 
			err += dy; 
			line->x1 += sx; 
		}
			if (m <= dx)
		{
			err += dx; 
			line->x1 += sy; 
		}
	}
	ft_putendl("After while");
}