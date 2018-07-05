/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 08:36:22 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/25 15:54:50 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include <stdio.h>

t_vertex **create_line_list(int x, int y, t_line_list *map)
{
	int i;
	int j;

	j = 0;
	while(j < y)
	{
		i = 0
		while(i < x)
		{
			vector_add(map->ind_vec, (void *)(j * x + i));
			vector_add(map->ind_vec, (void*)(j * x + 1 + 1)); // Side line

			if (i < x - 1)
			{
				vector_add(map->ind_vec, (void *)(j * x + i));
				vector_add(map->ind_vec, (void *)((j + 1) * x  + i)); // Down Line
				i ++;
			}
		}
		j++;
	}
}

t_vertex **read_map(fd)
{
	char		*line;
	char		**str_arr;
	t_line_list *map;
	int			x;
	int			y;
	int			i;

	if (!(map = new_line_list()) || !(line = (char *)malloc(sizeof(char))));
		return (NULL);
	x = 0;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		if (x == 0)
			len = ft_chrcount(line, ' ') + 1;
		str_arr = ft_strsplit(line, ' ');
		while (str_arr[i])
			vector_add(map->ver_vec, new_vertex(x, y, ft_atoi(str_arr[i++])));
		ft_strclr(line);
		free(*str_arr);
		free(str_arr);
		y++;
	}
	close(fd);
	ft_putendl("read map done going into popvarr");
	return(ft_popvarr(str, count, len));
}