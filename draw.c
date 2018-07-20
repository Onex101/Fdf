/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 12:46:56 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/13 07:44:28 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		screen_transform(t_vec3 *v)
{
	t_point point;

	if (v->z > 1)
	{
		point.x = (((v->x) / v->z) + 1) * WIDTH / 2;
		point.y = ((-(v->y) / v->z) + 1) * HEIGHT / 2;
	}
	else
	{
		point.x = -1;
		point.y = -1;
	}
	return (point);
}

void		pnt_check(t_point *p1, t_point *p2)
{
	if (p2->x == -1 && p2->y == -1)
	{
		p1->x = -1;
		p1->y = -1;
	}
	else if (p1->x == -1 && p1->y == -1)
	{
		p2->x = -1;
		p2->y = -1;
	}
}

void		draw_map(t_param *p, t_line_list *map)
{
	size_t		i;
	t_point		p1;
	t_point		p2;
	t_vector	*v;
	int			*i_a;

	i = 0;
	v = map->ver_vec;
	i_a = map->ind_vec->array;
	while (i < map->ind_vec->used)
	{
		if (vector_get(map->ver_vec, map->ind_vec->array[i + 1]))
		{
			p1 = screen_transform(vector_get(v, i_a[i]));
			p2 = screen_transform(vector_get(v, i_a[i + 1]));
			pnt_check(&p1, &p2);
		}
		i += 2;
		draw_line(&p1, &p2, p);
	}
}

int			draw_screen(t_param *p)
{
	t_line_list	*trans_map;
	int			i;

	trans_map = t_map(p->map, &(p->s), &(p->r), &(p->t));
	mlx_clear_window(p->mlx, p->win);
	draw_map(p, trans_map);
	i = 0;
	while (i < trans_map->ver_vec->total)
		free(vector_get(trans_map->ver_vec, i++));
	free(trans_map->ver_vec);
	free_array(trans_map->ind_vec);
	free(trans_map);
	return (0);
}
