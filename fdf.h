/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 08:15:42 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/19 06:14:42 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define FOCAL_DISTANCE 200

typedef struct	s_line
{
	float x;
	float y;
}				t_line;

typedef	struct	s_vector
{
	float 		x;
	float		y;
	float 		x;
}				t_vector;

typedef struct s_vertex
{
	t_vector *local;
	t_vector *world;
	t_vector *aligned
}				t_vertex;

#endif
