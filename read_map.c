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

void			create_line_list(size_t x, size_t y, t_line_list *map)
{
	size_t i;
	size_t j;
	size_t c;

	j = -1;
	while (++j < y)
	{
		i = -1;
		while (++i < x)
		{
			if (i < x - 1)
			{
				c = j * x + i;
				add_array(map->ind_vec, (c));
				add_array(map->ind_vec, (++c));
			}
			if (j < y - 1)
			{
				c = j * x + i;
				add_array(map->ind_vec, (c));
				c = ((j + 1) * x) + i;
				add_array(map->ind_vec, (c));
			}
		}
	}
}

void			free_str_arr(char **str_arr)
{
	int i;

	i = 0;
	while (str_arr[i])
		i++;
	while (--i)
		free(str_arr[i]);
	free(str_arr);
}

void			map_check(char *line, int *c_line)
{
	if (!*c_line)
		*c_line = ft_strcount(line, ' ');
	else if (*c_line != ft_strcount(line, ' '))
	{
		ft_putendl("Error: Map is not rectangular");
		exit(0);
	}
}

void			create_vertex_list(t_line_list *map, char *line, int y)
{
	char			**s;
	size_t			x;
	t_vec3			*v;

	x = 0;
	s = ft_strsplit(line, ' ');
	while (s[x])
	{
		v = new_vertex(x, y, ft_atoi(s[x]) / 2);
		vector_add(map->ver_vec, v);
		map->max_z = ft_atoi(s[x]) > map->max_z ? ft_atoi(s[x]) : map->max_z;
		x++;
	}
	map->max_x = x;
	ft_strclr(line);
	free_str_arr(s);
}

t_line_list		*read_map(int fd)
{
	char			*line;
	t_line_list		*map;
	size_t			y;
	int				c_line;

	if (!(map = new_line_list()))
		return (NULL);
	y = 0;
	c_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map_check(line, &c_line);
		create_vertex_list(map, line, y);
		y++;
	}
	if (y == 0 && c_line == 0)
	{
		ft_putendl("Error: File does not exist");
		exit(0);
	}
	free(line);
	map->max_y = y;
	close(fd);
	create_line_list(map->max_x, y, map);
	return (map);
}
