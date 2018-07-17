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
	ft_putendl("Create line list");
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
				c = ((j + 1) * x) + i;
				add_array(map->ind_vec, (c)); 
			}
			i++;
		}
		j++;
	}
	ft_putendl("Line list created");
}

void free_str_arr(char **str_arr)
{
	int i;

	i = 0;
	while (str_arr[i])
		i++;
	while (--i)
		free(str_arr[i]);
	free(str_arr);
}

t_line_list *read_map(int fd)
{
	char			*line;
	char			**str_arr;
	t_line_list 	*map;
	size_t			x;
	size_t			y;
	t_vec3			*v;

	ft_putendl("Read Map");
	if (!(map = new_line_list()) || !(line = (char *)malloc(sizeof(char))))
		return (NULL);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		//ft_putendl("Str_split");
		str_arr = ft_strsplit(line, ' ');
		//ft_putendl("Str_split done");
		while (str_arr[x])
		{
			// ft_putendl("Str_arr at x exists");
			// ft_putendl("Create new vertex");
			v = new_vertex(x, y, ft_atoi(str_arr[x])/2);
			// ft_putendl("Vertex created");
			// ft_putendl("Vertex add");
			vector_add(map->ver_vec, v);
			// ft_putendl("Vertex added");
			// ft_putendl("Get max z");
			map->max_z = ft_atoi(str_arr[x]) > map->max_z ? ft_atoi(str_arr[x]) : map->max_z;
			x++;
			// ft_putendl("Loop iternation done");
		}
		// ft_putendl("GNL WHILE LOOP iteration done");
		ft_strclr(line);
		// ft_putendl("free arr");
		free_str_arr(str_arr); // write function to free double str array
		// ft_putendl("Free array done");
		y++;
	}
	free(line);
	map->max_y = y;
	map->max_x = x;
	close(fd);
	// ft_putendl("Create line list");
	create_line_list(x, y, map);
	// ft_putendl("Read Map Complete");
	return(map);
}
