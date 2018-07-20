/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:47:32 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/25 07:47:12 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line_list		*t_map(t_line_list *map, t_vec3 *s, t_vec3 *r, t_vec3 *t)
{
	t_mat		*m;
	t_line_list *new_map;
	int			i;
	t_vec3		*v;

	m = matrix_master(s, t, r);
	new_map = new_line_list();
	i = 0;
	while (i < map->ver_vec->total)
	{
		v = (t_vec3 *)vector_get(map->ver_vec, i);
		vector_add(new_map->ver_vec, matrix_vec_mult(v, m));
		i++;
	}
	i = 0;
	while (i < (int)map->ind_vec->used)
		add_array(new_map->ind_vec, map->ind_vec->array[i++]);
	free(m);
	return (new_map);
}
