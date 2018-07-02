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

void ft_popvarr(char *str, int row, int col)
{
	char		**arr;
	int			i;
	int			j;
	int			k;
	t_vertex	**ver_arr;

	ft_putendl("Popvarr start");
	ver_arr = (t_vertex **)malloc(sizeof(t_vertex *) * row);
	arr = ft_strsplit(str, ' ');
	free (str);
	k = 0;
	i = 0;
	while (i < row)
	{
		j = 0;
		ver_arr[i] = (t_vertex *)malloc(sizeof(t_vertex) * col);  
		while (j < col && arr[k])
		{
			ver_arr[i][j] = new_vertex(j * 10, i * 10, (double)ft_atoi(arr[k]));
			printf("Position:[%d][%d] x:%f y:%f z:%f \n", i, j, ver_arr[i][j].original->x, ver_arr[i][j].original->y, ver_arr[i][j].original->z);
			j++;
			k++;
		}
		i++;
	}
	free (arr);
	ft_putendl("popvarr end going into draw_grid");
	draw_grid(ver_arr, i, j);
}

int read_map(fd)
{
	char	*line;
	int		count;
	int		len;
	char	*str;
	char	*tmp;
	int 	i;

	ft_putendl("Read map begin");
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (-1);
	str = ft_strnew(1);
	count = 0;
	i = 1;
	while (get_next_line(fd, &line) > 0)
	{
		ft_putnbr(i);
		ft_putendl("");
		if (count == 0)
		{
			len = ft_chrcount(line, ' ') + 1;
			ft_putnbr(len);
		}
		tmp = ft_strjoin(str, " ");
		str = ft_strjoin(tmp, line);
		free(tmp);
		count++;
	}
	close(fd);
	ft_putendl("read map done going into popvarr");
	ft_popvarr(str, count, len);
	return (0);
}

int open_map(char *argv)
{
	int		fd;

	if (!argv)
		return (-1);
	fd = open(argv, O_RDONLY);
	read_map(fd);
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		i = 0;
		//open_map(argv[1]);
		ft_putendl("Read Map start");
		mlx_loop (get_mlx());
		mlx_loop_hook(get_mlx(), &read_map, (void *)&fd);
		ft_putendl("Read map done");
		//mlx_loop (get_mlx());
		//mlx_loop_hook(get_mlx(), &open_map, argv[1]);
	}
	return (1);
}
