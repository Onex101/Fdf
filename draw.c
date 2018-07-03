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

t_line *new_line(t_vector *vec1, t_vector *vec2)
{
	t_line *line;

	ft_putendl("Newline create");
	line = (t_line *)malloc(sizeof(t_line));
	line->x1 = vec1->x;
	line->y1 = vec1->y;
	line->x2 = vec2->x;
	line->y2 = vec2->x;
	ft_putendl("Newline return");
	return (line);
}

void draw_grid(t_vertex	**ver_arr)
{
	
	int i;
	int j;
	t_line *line;

	i = 0;
	ft_putendl("Entered draw_grid");
	while (ver_arr[i])
	{
		ft_putendl("i increment");
		j = 0;
		while (ver_arr[i][j].original)
		{
			ft_putstr("j = ");
			ft_putnbr(j);
			ft_putendl("");
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putendl("");
			if (ver_arr[i][j].original && ver_arr[i][j + 1].original)
			{
				ft_putendl("Drawing to the side");
				line = new_line(ver_arr[i][j].original, ver_arr[i][j + 1].original);
				draw_line(line);
				free(line);
				ft_putendl("Drawing to side done");
			}
			if (ver_arr[i][j].original && ver_arr[i + 1][j].original)
			{
				ft_putendl("Drawing down");
				line = new_line(ver_arr[i][j].original, ver_arr[i + 1][j].original);
				draw_line(line);
				free(line);
				ft_putendl("Drawing down done");
			}
			j++;
		}
		i++;
		ft_putendl("Hello");
	}
	ft_putendl("Done draw_grid");
}
