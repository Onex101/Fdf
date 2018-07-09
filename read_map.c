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

void create_line_list(size_t x, size_t y, t_line_list *map)
{
	size_t i;
	size_t j;
	size_t c;

	j = 0;
	while(j < y)
	{
		i = 0;
		while(i < x)
		{
			if (i < x - 1) // Side line
			{
				c = j * x + i;
				add_array(map->ind_vec, (c));
				c++;
				add_array(map->ind_vec, (c));
			}
			if (j < y - 1) // Down Line
			{
				c = j * x + i;
				add_array(map->ind_vec, (c));
				c = (j + 1) * x + i;
				add_array(map->ind_vec, (c)); 
			}
			i++;
		}
		j++;
	}
}

t_line_list *read_map(int fd)
{
	char			*line;
	char			**str_arr;
	t_line_list 	*map;
	size_t			x;
	size_t			y;
	size_t			i;
	t_vec3			*v;

	if (!(map = new_line_list()) || !(line = (char *)malloc(sizeof(char))))
		return (NULL);
	x = 0;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		if (x == 0)
			x = ft_chrcount(line, ' ') + 1;
		str_arr = ft_strsplit(line, ' ');
		while (str_arr[i])
		{
			v = new_vertex(i, y, ft_atoi(str_arr[i]));
			vector_add(map->ver_vec, v);
			map->max_z = ft_atoi(str_arr[i]) > map->max_z ? ft_atoi(str_arr[i]) : map->max_z;
			i++;
		}
		ft_strclr(line);
		free(str_arr);
		y++;
	}
	map->max_y = y;
	map->max_x = x;
	close(fd);
	create_line_list(x, y, map);
	return(map);
}