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

void draw_line(t_point *pnt1, t_point *pnt2)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int m;

	// ft_putnbr(pnt1->x);
	// ft_putendl("");
	// ft_putnbr(pnt1->y);
	// ft_putendl("");
	// ft_putnbr(pnt2->x);
	// ft_putendl("");
	// ft_putnbr(pnt2->y);
	dx =  abs(pnt2->x - pnt1->x);
	dy = -(abs(pnt2->y - pnt1->y));
	sx = pnt1->x < pnt2->x ? 1 : -1;
	sy = pnt1->y < pnt2->y ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		mlx_pixel_put(get_mlx(), get_window("Hello"), pnt1->x, pnt1->y, 0xFFFFFF);
		m = 2 * err;
		if (m >= dy)
		{ 
			err += dy; 
			pnt1->x += sx; 
		}
		if (m <= dx)
		{
			err += dx; 
			pnt1->y += sy; 
		}
	}
}