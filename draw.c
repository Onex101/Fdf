/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 12:46:56 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/27 12:46:58 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	*get_mlx(void)
{
	static void	*mlx;

	if (!mlx)
	{
		mlx = mlx_init();
	}
	return (mlx);
}

void	*get_window(char *title)
{
	static void *window;

	if (!window)
		window = mlx_new_window(get_mlx(), WIDTH, HEIGHT, title);
	return (window);
}


t_point 	screen_transform(t_vec3 *v)
{
	double z_scale;
	t_point point;

	z_scale = 1 / (v->z);
	point.x = ((v->x) * z_scale + 1.0) * WIDTH/2.0;
	point.y= (-(v->y) * z_scale + 1.0) * HEIGHT/2.0;
	return (point);
}

void		draw_map(t_line_list *map)
{
	size_t	i;
	t_point	p1;
	t_point	p2;

	i = 0;
	while (i < map->ind_vec->used)
	{

		p1 = screen_transform(vector_get(map->ver_vec, map->ind_vec->array[i]));
		p2 = screen_transform(vector_get(map->ver_vec, map->ind_vec->array[i + 1]));
		printf("p1 = %f, p2 = %f", p1.x, p2.x);
		i += 2;
		if (p1.x < 500 && p1.y < 500)
			draw_line(&p1, &p2);
	}
	ft_putnbr(map->ind_vec->array[i]);
	ft_putendl("");
	ft_putnbr(i);
	ft_putendl("");
}