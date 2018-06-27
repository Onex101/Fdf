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
	t_vertex	ver_arr[row][col];

	arr = ft_strsplit(str, ' ');
	k = 0;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col && arr[k])
		{
			ver_arr[i][j] = new_vertex(j/2, i/2, (double)ft_atoi(arr[k]));
			printf("Position:[%d][%d] x:%f y:%f z:%f \n", i, j, ver_arr[i][j].original->x, ver_arr[i][j].original->y, ver_arr[i][j].original->z);
			j++;
			k++;
		}
		i++;
	}
	free (arr);
	free (str);
	//draw(ver_arr, i, j);
}

void read_map(fd)
{
	char	*line;
	int		count;
	int		len;
	char	*str;
	char	*tmp;

	line = (char *)malloc(sizeof(char));
	if (!line)
		return ;
	str = ft_strnew(1);
	count = 0;
	while (get_next_line(fd, &line))
	{
		if (count == 0)
			len = (ft_strlen(line) / 2) + 1;
		tmp = ft_strjoin(str, " ");
		str = ft_strjoin(tmp, line);
		free(tmp);
		count++;
	}
	ft_popvarr(str, count, len);
}

void open_map(char *argv)
{
	int		fd;

	if (!argv)
		return ;
	fd = open(argv, O_RDONLY);
	//fd check needs to be written
	read_map(fd);
}

int main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = 0;
		open_map(argv[1]);
	}
}
