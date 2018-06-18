/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 08:15:42 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/18 13:44:36 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_struct
{
	void 		*mlx;
	void 		*window;
	void 		*map;

}				t_struct;

typedef	struct	s_struct
{
	int x1;
	int	y1;
	int x2;
	int y2
}				t_line

#endif
