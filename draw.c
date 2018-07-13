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


t_point		screen_transform(t_vec3 *v)
{
	t_point point;
	static double flux;
	static int done;

	if (done != 1)
	{
		done = 1;
		flux = 0;
	}
	else
		flux = rand();
	if (v->z == 0)
		v->z = 1;
	point.x = (((v->x) / flux) + 1) * WIDTH/2;
	point.y = ((-(v->y)/ flux) + 1) * HEIGHT/2;

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
		// ft_putnbr(map->ind_vec->array[i]);
		// ft_putendl("");
		if (vector_get(map->ver_vec, map->ind_vec->array[i + 1]))
		{
			p1 = screen_transform(vector_get(map->ver_vec, map->ind_vec->array[i]));
			p2 = screen_transform(vector_get(map->ver_vec, map->ind_vec->array[i + 1]));
		}
		i += 2;
		// ft_putendl("Enter draw_line");
		ft_putstr("Point x1 = ");
		ft_putnbr(p1.x);
		ft_putendl("");
		ft_putstr("Point y1 = ");
		ft_putnbr(p1.y);
		ft_putendl("");
		ft_putstr("Point x2 = ");
		ft_putnbr(p2.x);
		ft_putendl("");
		ft_putstr("Point y2 = ");
		ft_putnbr(p2.y);
		ft_putendl("");
		draw_line(&p1, &p2);
		//ft_putendl("Draw_line done");
	}
}