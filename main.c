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

double dim = 2; /*Dimensions of Orthogonal Box*/

int	main(void)
{
	void	*win;

	win = get_window("fdf");

	//mlx_loop_hook(get_mlx(), loop, &param);
	mlx_loop (get_mlx());
	return (0);
}
