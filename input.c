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
#include <stdio.h>
#include <math.h>

int		adjust_rotate(int keycode, t_param *p)
{
	double rotate;

	rotate = 0.1;
	if (keycode == 0) /*ROTATE LEFT*/
		p->r.y += fmod((rotate * M_PI), 2);
	else if (keycode == 2) /*ROTATE RIGHT*/
		p->r.y -= fmod((rotate * M_PI), 2);
	else if (keycode == 13) /*ROTATE UP*/
		p->r.x += fmod((rotate * M_PI), 2);
	else if (keycode == 1) /*ROTATE DOWN*/
		p->r.x -= fmod((rotate * M_PI), 2);
	else if (keycode == 12)	/*ROTATE AROUND Z*/
		p->r.z += fmod((rotate * M_PI), 2);
	else if (keycode == 14) /*ROTATE AROUND -Z*/
		p->r.z -= fmod((rotate * M_PI), 2);
	else if (keycode == 57) /*Stop rotation*/
	{
		p->r.x = 0;
		p->r.y = 0;
		p->r.z = 0;
	}
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
	if (keycode == 123) /*TRANS RIGHT*/
		p->t.x -= trans;
	else if (keycode == 124)/*TRANS LEFT*/
		p->t.x += trans;
	else if (keycode == 126)/*TRANS UP*/
		p->t.y += trans;
	else if (keycode == 125)/*TRANS DOWN*/
		p->t.y -= trans;
	else
		return (0);
	return (1);
}

int		key_hook(int keycode, t_param *p)
{
	ft_putendl("Enter key_hook");
	if ((adjust_rotate(keycode, p) == 1))
		;
	else if ((adjust_scale(keycode, p) == 1))
		;
	else if ((adjust_trans(keycode, p) == 1))
		;
	if (keycode == 15)
		object_transform(p);
	if (keycode == 53)
		exit(0);
	printf("Parameters for translation:\n t.x = %f\n t.y = %f\n t.z = %f\n", p->t.x, p->t.y, p->t.z);
	printf("Parameters for scale:\n s.x = %f\n s.y = %f\n s.z = %f\n", p->s.x, p->s.y, p->s.z);
	printf("Parameters for rotation:\n r.x = %f\n r.y = %f\n r.z = %f\n", p->r.x, p->r.y, p->r.z);
	return (0);
}
