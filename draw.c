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

void	*get_mlx(void)
{
	static void	*mlx;

	if (!mlx)
		mlx = mlx_init();
	return (mlx);
}

void	*get_window(char *title)
{
	static void *window;

	if (!window)
		window = mlx_new_window(get_mlx(), WIDTH, HEIGHT, title);
	return (window);
}

void draw_grid(t_vertex	**ver_arr, int row, int col)
{
	int i;
	int j;

	i = 0;
	ft_putendl("Hello");
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (ver_arr[i][j].original && ver_arr[i][j + 1].original)
				draw_line(ver_arr[i][j].original, ver_arr[i][j + 1].original);
			if (ver_arr[i][j].original && ver_arr[i + 1][j].original)
				draw_line(ver_arr[i][j].original, ver_arr[i + 1][j].original);
			j++;
		}
		i++;
	}
}
