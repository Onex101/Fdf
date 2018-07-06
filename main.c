/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:47:32 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/25 07:47:12 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>

double dim = 2; /*Dimensions of Orthogonal Box*/

int	main(int argc, char **argv)
{
	//void		*win;
	t_line_list *map;
	int 		i;
	
	if (argc == 2)
	{
		ft_putendl("Read Map");
		map = read_map(open(argv[1], O_RDONLY));			
		ft_putendl("Done Reading");
		for (i = 0; i < vector_total(map->ver_vec); i++)
			printf("%d ", (int)vector_get(map->ver_vec, i));
		printf("\n");
	}
	//win = get_window("fdf");

	//mlx_loop_hook(get_mlx(), loop, &param);
	//mlx_loop (get_mlx());
	return (0);
}
