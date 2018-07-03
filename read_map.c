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
	//ft_putendl("popvarr end going into draw_grid");
	//draw_grid(ver_arr, i, j);
}

t_vertex **read_map(fd)
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
		return (NULL);
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
	return(ft_popvarr(str, count, len));
}

int open_map(char *argv)
{
	int		fd;

	if (!argv)
		return (-1);
	return(fd = open(argv, O_RDONLY));
}

int loop(t_vertex **ver_arr)
{
	ft_putendl("Draw grid");
	draw_grid(ver_arr);
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	t_vertex **ver_arr;

	if (argc == 2)
	{
		i = 0;
		ver_arr = read_map(open_map(argv[1]));

		//mlx_loop (get_mlx());
		mlx_loop_hook(get_mlx(), &loop, (void *)ver_arr);
		ft_putendl("Read map done");
		mlx_loop(get_mlx());
		//mlx_loop (get_mlx());
		//mlx_loop_hook(get_mlx(), &open_map, argv[1]);
	}
	return (1);
}
