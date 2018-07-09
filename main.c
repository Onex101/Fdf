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
#include <math.h>

t_line_list *transform_map(t_line_list *map, t_vec3 *scale, t_vec3 *rotate, t_vec3 *translate)
{
	t_mat		*s;
	t_mat		*t;
	t_mat		*r;
	t_mat		*m;
	t_line_list *new_map;
	int			i;

	s = matrix_scale(scale);
	t = matrix_translate(translate);
	r = matrix_rotate(rotate);
	m = matrix_master(s, t, r);
	free (s);
	free (t);
	free (r);

	//int j = 0;
	//i= 0;
	// while (i < 4)
	// {
	// 	j = 0;
	// 	while (j < 4)
	// 	{
	// 		printf("%f\n", m->mat[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }

	i = 0;
	new_map = new_line_list();
	// while(i < map->ver_vec->total)
	// {
	// 		ft_putendl("Check map exists");
	// 		printf("Map: 	 x = [%f] y = [%f] z = [%f]\n", ((t_vec3 *)(map->ver_vec->items[i]))->x, ((t_vec3 *)(map->ver_vec->items[i]))->y,((t_vec3 *)(map->ver_vec->items[i]))->z);
	// 		ft_putendl("Map exists");
	// 		i++;
	// }
	i = 0;
	while (i < map->ver_vec->total)
	{
		printf("Map: 	 x = [%f] y = [%f] z = [%f]\n", ((t_vec3 *)(map->ver_vec->items[i]))->x, ((t_vec3 *)(map->ver_vec->items[i]))->y,((t_vec3 *)(map->ver_vec->items[i]))->z);
		vector_add(new_map->ver_vec, matrix_vec_mult(vector_get(map->ver_vec, i), m));
		printf("New Map: x = [%f] y = [%f] z = [%f]\n", ((t_vec3 *)(new_map->ver_vec->items[i]))->x, ((t_vec3 *)(new_map->ver_vec->items[i]))->y, ((t_vec3 *)(new_map->ver_vec->items[i]))->z);
		i++;
	}
	i = 0;
	while (i < (int)map->ind_vec->used)
		add_array(new_map->ind_vec, map->ind_vec->array[i++]);
	i = 0;
	// while (i < (int)new_map->ind_vec->used)
	// {
	// 	printf("Pos [%d] = %d\n", i, new_map->ind_vec->array[i]);
	// 	i++;
	// }
	free(m);
	ft_putendl("Transform done");
	return (new_map);
}

void	init_transform(t_param *param)
{
	param->s.x = 1;
	param->s.y = 1;
	param->s.z = 1;
	param->r.x = 0;
	param->r.y = 0.01;
	param->r.z = 0;
	param->t.x = -10;
	param->t.y = param->map->max_z * -1.0;
	param->t.z = param->map->max_z * 1.0;
}

int draw_screen(t_param *p)
{
	t_line_list	*trans_map;
	size_t i;

	i = 0;

	ft_putendl("draw_screen");
	trans_map = transform_map(p->map, &p->s, &p->r, &p->t);
	ft_putendl("Trans map done");
	mlx_clear_window(get_mlx(), get_window("Hello"));
	draw_map(trans_map);
	ft_putendl("Done");
	free(trans_map);
	ft_putendl("Done");
	return (0);
}

int	main(int argc, char **argv)
{
	t_line_list *map;
	t_param		*p;
	int 		i;
	t_vec3		*s;
	t_vec3		*t;
	t_vec3		*r;
	
	if (argc == 2)
	{
		map = read_map(open(argv[1], O_RDONLY));
		s = new_vertex(1, -1, 1);
		t = new_vertex((map->max_x / 2.0), -map->max_y / 2.0, 10);
		r = new_vertex(10, 10, 10);
		p = (t_param *)malloc(sizeof(t_param));
		i = 0;
		ft_putendl("Transform map");
		p->map = transform_map(map, s, r, t);
		ft_putendl("Map transformation complete");
		init_transform(p);
		mlx_loop_hook(get_mlx(), &draw_screen, p);
		mlx_loop (get_mlx());
		ft_putendl("Map done");
	}
	return (0);
}
