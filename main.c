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

//double rotate = 0;

t_line_list *transform_map(t_line_list *map, t_vec3 *scale, t_vec3 *rotate, t_vec3 *translate)
{
	t_mat		*s;
	t_mat		*t;
	t_mat		*r;
	t_mat		*m;
	t_line_list *new_map;
	int			i;
	//int 		j;

	s = matrix_scale(scale);
	t = matrix_translate(translate);
	r = matrix_rotate(rotate);
	m = matrix_master(s, t, r);
	free (s);
	free (t);
	free (r);

	new_map = new_line_list();
	i = 0;
	while (i < map->ver_vec->total)
	{
		// j = rand() % 1;
		// if (j == 1)
		// 	((t_vec3 *)(map->ver_vec->items[i]))->z *= -1;
		// else
		//((t_vec3 *)(map->ver_vec->items[i]))->z = rand() % 2;
		//printf("Map: 	 x = [%f] y = [%f] z = [%f]\n", ((t_vec3 *)(map->ver_vec->items[i]))->x, ((t_vec3 *)(map->ver_vec->items[i]))->y,((t_vec3 *)(map->ver_vec->items[i]))->z);
		vector_add(new_map->ver_vec, matrix_vec_mult(vector_get(map->ver_vec, i), m));
		//printf("New Map: x = [%f] y = [%f] z = [%f]\n", ((t_vec3 *)(new_map->ver_vec->items[i]))->x, ((t_vec3 *)(new_map->ver_vec->items[i]))->y, ((t_vec3 *)(new_map->ver_vec->items[i]))->z);
		i++;
	}
	i = 0;
	while (i < (int)map->ind_vec->used)
		add_array(new_map->ind_vec, map->ind_vec->array[i++]);
	i = 0;
	free(m);
	return (new_map);
}

void	object_transform(t_param *p)
{
	static double rotate;
	static int done;

	if (done != 1)
	{
		done = 1;
		rotate = 0;
	}
	else
		rotate += 0.0001;
	p->s = new_vertex(1, 1, 1); 
	p->r = new_vertex(0 * M_PI, rotate * M_PI, 0 * M_PI);
	//printf("max_x: %d max_y: %d max_z: %d\n", p->map->max_x, p->map->max_y, p->map->max_z);
	p->t = new_vertex(0, -p->map->max_y / 2, p->map->max_y * 2);
}

int draw_screen(t_param *p)
{
	t_line_list	*trans_map;
	int i;

	object_transform(p);
	trans_map = transform_map(p->map, p->s, p->r, p->t);
	mlx_clear_window(get_mlx(), get_window("Hello"));
	draw_map(trans_map);
	i = 0;
	//while (i < trans_map->ver_vec->capacity)
	//	free(trans_map->ver_vec->items);
	free(p->s);
	free(p->r);
	free(p->t);
	free_array(trans_map->ind_vec);
	free(trans_map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_line_list *map;
	t_param		*p;
	t_vec3		*s;
	t_vec3		*t;
	t_vec3		*r;
	
	if (argc == 2)
	{
		map = read_map(open(argv[1], O_RDONLY));
		//printf("max_x: %d max_y: %d max_z: %d\n", map->max_x, map->max_y, map->max_z);
		s = new_vertex(1, -1, -1);
		t = new_vertex(-(map->max_x / 2.0), -(map->max_y / 2.0), 0);
		r = new_vertex(0 , 0, 0);
		p = (t_param *)malloc(sizeof(t_param));
		ft_putendl("Transform map");
		p->map = transform_map(map, s, r, t);
		p->map->max_x = map->max_x;
		p->map->max_y = map->max_y;
		p->map->max_z = map->max_z;
		free(s);
		free(t);
		free(r);
		ft_putendl("Map transformation complete");
		mlx_loop_hook(get_mlx(), &draw_screen, p);
		mlx_loop (get_mlx());
		ft_putendl("Map done");
	}
	return (0);
}
