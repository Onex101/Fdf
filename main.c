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
#include <fcntl.h>
#include <math.h>

void			object_transform(t_param *p)
{
	static double	rotate;
	static int		done;

	if (done != 1)
	{
		done = 1;
		rotate = 0;
	}
	else
		rotate += 0.1;
	p->s.x = 1;
	p->s.y = 1;
	p->s.z = 1;
	p->r.x = 0.3 * M_PI;
	p->r.y = 0 * M_PI;
	p->r.z = 0 * M_PI;
	p->t.x = 0;
	p->t.y = -p->map->max_y / 2;
	p->t.z = p->map->max_y * 2;
}

int				file_check(char *str)
{
	char *f_ext;

	f_ext = ft_strstr(str, ".fdf");
	if (!f_ext)
		ft_putendl("Error: Not a valid file");
	else if (ft_strlen(f_ext) == 4)
		return (1);
	return (0);
}

void			init_param(t_line_list *map, t_param *p)
{
	t_vec3		*s;
	t_vec3		*t;
	t_vec3		*r;

	s = new_vertex(1, -1, -1);
	t = new_vertex(-(map->max_x / 2.0), -(map->max_y / 2.0), 0);
	r = new_vertex(0, 0, 0);
	p->map = t_map(map, s, r, t);
	p->map->max_x = map->max_x;
	p->map->max_y = map->max_y;
	p->map->max_z = map->max_z;
	p->mlx = mlx_init();
	if (!p->mlx)
	{
		ft_putendl("Error: Failed to initialize mlx");
		exit(0);
	}
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "FDF");
	free(s);
	free(r);
	free(t);
}

int				exit_catch(void *p)
{
	(void)p;
	exit(0);
}

int				main(int argc, char **argv)
{
	t_line_list *map;
	t_param		*p;

	if (argc == 2 && file_check(argv[1]))
	{
		map = read_map(open(argv[1], O_RDONLY));
		if (!(p = (t_param *)malloc(sizeof(t_param))))
			return (-1);
		init_param(map, p);
		object_transform(p);
		mlx_loop_hook(p->mlx, draw_screen, p);
		mlx_key_hook(p->win, key_hook, p);
		mlx_hook(p->win, 17, 0, exit_catch, NULL);
		mlx_loop(p->mlx);
	}
	return (0);
}
