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
	t_mat		*m;
	t_line_list *new_map;
	int			i;

	//ft_putendl("Transform map");
	m = matrix_master(scale, translate, rotate);
	new_map = new_line_list();
	i = 0;
	while (i < map->ver_vec->total)
	{
		vector_add(new_map->ver_vec, matrix_vec_mult(vector_get(map->ver_vec, i), m));
		i++;
	}
	i = 0;
	while (i < (int)map->ind_vec->used)
		add_array(new_map->ind_vec, map->ind_vec->array[i++]);
	free(m);
	//ft_putendl("Transform map return");
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
		rotate += 0.1;
	//ft_putendl("Transform object");
	p->s.x = 1;
	p->s.y = 1;
	p->s.z = 1;
	p->r.x = 0.3 * M_PI;
	p->r.y = 0 * M_PI;
	p->r.z = 0 * M_PI;
	p->t.x = 0;
	p->t.y = -p->map->max_y / 2;
	p->t.z = p->map->max_y * 2;
	//ft_putendl("Done transforming object");
}

int draw_screen(t_param *p)
{
	t_line_list	*trans_map;
	int i;

	ft_putendl("Draw Screen");
	trans_map = transform_map(p->map, &(p->s), &(p->r), &(p->t));
	mlx_clear_window(p->mlx, p->win);
	draw_map(p, trans_map);
	i = 0;
	while (i < trans_map->ver_vec->total)
		free(vector_get(trans_map->ver_vec, i++));
	free(trans_map->ver_vec);
	free_array(trans_map->ind_vec);
	free(trans_map);
	ft_putendl("Draw Screen Return");
	return (0);
}

int file_check(char *str)
{
	char *f_ext;

	f_ext = ft_strstr(str, ".fdf");
	if (!f_ext)
		ft_putendl("Not a valid file");
	else if (ft_strlen(f_ext) == 4)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_line_list *map;
	t_param		*p;
	t_vec3		*s;
	t_vec3		*t;
	t_vec3		*r;
	
	if (argc == 2 && file_check(argv[1]))
	{
		map = read_map(open(argv[1], O_RDONLY));
		s = new_vertex(1, -1, -1);
		t = new_vertex(-(map->max_x / 2.0), -(map->max_y / 2.0), 0);
		r = new_vertex(0 , 0, 0);
		if (!(p = (t_param *)malloc(sizeof(t_param))))
			return (-1);
		p->map = transform_map(map, s, r, t);
		free(s);
		free(r);
		free(t);
		ft_putendl("Assign max x,y,z");
		p->map->max_x = map->max_x;
		p->map->max_y = map->max_y;
		p->map->max_z = map->max_z;
		p->mlx = mlx_init();
		p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "FDF");
		ft_putendl("Done assigning max x,y,z");
		object_transform(p);
		//int i = -1;
		// while (++i < p->map->ver_vec->capacity)
		// {
		// 	ft_putnbr(i);
		// 	ft_putstr(" = ");
		// 	ft_putnbr(((t_vec3 *)(vector_get(p->map->ver_vec, i)))->x);
		// 	ft_putendl("");
		// }
		ft_putendl("Enter Loop_hook");
		//get_mlx();
		//draw_screen(p);
		mlx_loop_hook(p->mlx, draw_screen, p);
		ft_putendl("Enter key_hook");
		mlx_key_hook(p->win, key_hook, p);
		//printf("Parameters for translation:\n t.x = %f\n t.y = %f\n t.z = %f\n", p->t.x, p->t.y, p->t.z);
		ft_putendl("Enter Loop");
		mlx_loop(p->mlx);
		ft_putendl("Next loop");
	}
	return (0);
}
