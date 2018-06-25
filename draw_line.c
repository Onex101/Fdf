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

void draw_line(t_vector vec1, t_vector vec2, t_window window)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int m;

	dx =  abs(vec2.x - vec1.x);
	dy = -(abs(vec2.y - vec1.y));
	sx = vec1.x < vec2.x ? 1 : -1;
	sy = vec1.y < vec2.y ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		mlx_pixel_put((window->mlx), (window->win), vec1.x, vec1.y, 0xFFFFFF);
		if (vec1.x == vec2.x && vec1.y == vec2.y) 
			break;
		m = 2 * err;
		if (m >= dy)
		{ 
			err += dy; 
			vec1.x += sx; 
		}
			if (m <= dx)
		{
			err += dx; 
			vec1.y += sy; 
		}
	}
}