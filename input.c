/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:40:54 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/16 06:41:12 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int		adjust_rotate(int keycode, t_param *p)
{
	double rotate;

	rotate = 0.1;
	if (keycode == 0)
		p->r.y += fmod((rotate * M_PI), 2);
	else if (keycode == 2)
		p->r.y -= fmod((rotate * M_PI), 2);
	else if (keycode == 13)
		p->r.x += fmod((rotate * M_PI), 2);
	else if (keycode == 1)
		p->r.x -= fmod((rotate * M_PI), 2);
	else if (keycode == 12)
		p->r.z += fmod((rotate * M_PI), 2);
	else if (keycode == 14)
		p->r.z -= fmod((rotate * M_PI), 2);
	else
		return (0);
	return (1);
}

int		adjust_scale(int keycode, t_param *p)
{
	double scale;

	scale = 0.01;
	if (keycode == 116)
		p->s.z += scale;
	if (keycode == 121)
		p->s.z -= scale;
	else
		return (0);
	return (1);
}

int		adjust_trans(int keycode, t_param *p)
{
	double trans;

	trans = 2;
	if (keycode == 123)
		p->t.x -= trans;
	else if (keycode == 124)
		p->t.x += trans;
	else if (keycode == 126)
		p->t.y += trans;
	else if (keycode == 125)
		p->t.y -= trans;
	else
		return (0);
	return (1);
}

int		key_hook(int keycode, t_param *p)
{
	if ((adjust_rotate(keycode, p) == 1))
		;
	else if ((adjust_scale(keycode, p) == 1))
		;
	else if ((adjust_trans(keycode, p) == 1))
		;
	if (keycode == 15)
		object_transform(p);
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	return (0);
}
