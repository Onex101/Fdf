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

void ft_lstaddend(t_list **alst, t_list *new) // Needs to go into libft
{
	t_list *tmp;

	tmp = *alst;
	if (new)
	{
		while (tmp)
			tmp = tmp->next
		tmp->next = new;
	}
}

int **read_map(char **argc)
{
	int fd;
	char *line;
	char *c;
	int i;
	int j;
	t_list *row;
	t_list *arr;

	if (!argc)
		return (-1);
	fd = open(argc, O_RDONLY);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (-1);
	i = 0;
	while (get_next_line(fd, &line))
	{
		j = 0;
		while(*line)
		{
			c = line;
			while (ft_isdigit(*c))
				c++
			if(ft_isdigit(*line))
			{
				if (!row)
					row = ft_lstnew(NULL, ft_atoi(ft_strcdup(line, c)));
				else
					ft_lstaddend(row, ft_lstnew(NULL, ft_atoi(ft_strcdup(line, c))));
			}
			line += ft_strclen(line, c);
			if (!arr)
				arr = ft_lstnew(row, j);
			else
				ft_lstaddend(arr, ft_lstnew(row, j);
			j++;
		}
		i++;
	}
	return (arr);
}
