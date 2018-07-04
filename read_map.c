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

t_vertex **ft_popvarr(char *str, int row, int col)
{
	char		**arr;
	int			i;
	int			j;
	int			k;
	t_vertex	**ver_arr;

	ft_putendl("Popvarr start");
	ver_arr = (t_vertex **)malloc(sizeof(t_vertex *) * row + 1);
	arr = ft_strsplit(str, ' ');
	free (str);
	k = 0;
	i = 0;
	ver_arr[row] = NULL;
	while (i < row)
	{
		j = 0;
		ver_arr[i] = (t_vertex *)malloc(sizeof(t_vertex) * col + 1);  
		while (j < col && arr[k])
		{
			ver_arr[i][j] = new_vertex(j * 10, i * 10, (double)ft_atoi(arr[k]));
			printf("Position:[%d][%d] x:%f y:%f z:%f \n", i, j, ver_arr[i][j].original->x, ver_arr[i][j].original->y, ver_arr[i][j].original->z);
			j++;
			k++;
		}
		ver_arr[i][j].original = NULL;
		i++;
	}
	free (arr);
	return (ver_arr);
}

t_vertex **read_map(fd)
{
	char		*line;
	char		**str_arr;
	t_line_list *map;
	int			x;
	int			y;
	int			i;

	ft_putendl("Read map begin");
	map = new_line_list();
	line = (char *)malloc(sizeof(char));
	if (!line)
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