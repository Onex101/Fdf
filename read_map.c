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
#include "./libft/includes/libft.h"
#include "fdf.h"

int ft_lstlen(t_list **alst)
{
	t_list	*tmp;
	int		i;
	tmp = *alst;

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void ft_poparr(char *str, t_vlst **vlst, int row, int col)
{
	char **arr;
	int i;
	int j;
	int k;

	arr = ft_strsplit(str);
	vlst = (t_vlst **)malloc(sizeof(t_vlst*) * row);
	*vlst = (t_vlst *)malloc(sizeof(t_vlst) *	col);
	k = 0;
	i = 0;
	while (i < col)
	{
		j = 0;
		while (j < row && arr[k])
		{
			vlst[i][j] = 
		}
	}
}

t_vlst **read_map(char *argv)
{
	int		fd;
	char	*line;
	int		count;
	int		len;
	char	*str;
	char	*tmp;
	t_vlst	**vlst;

	if (!argv)
		return (NULL);
	fd = open(argv, O_RDONLY);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	vlst = NULL;
	str = ft_strnew(1);
	count = 0;
	while (get_next_line(fd, &line))
	{
		if (count == 0)
			len = (ft_strlen(line) / 2) - 1;
		tmp = str;
		str = ft_strjoin(tmp, line);
		free(tmp);
		count++;
	}
	ft_poparr(str, vlst, count, len);
	return (arr);
}

// int	*list_arr(t_list *arr)
// {

// }

int main(int argc, char **argv)
{
	t_arrlst *arr;
	int i;

	if (argc == 2)
	{
		i = 0;
		arr = read_map(argv[1]);
		while (i < 10)
		{
			ft_putendl(*(arr->arr));
			arr = arr->next;
			i++;
		}
	}
}
