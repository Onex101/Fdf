/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/27 06:26:02 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

typedef struct	vector
{
	void		**items;
	int			capacity;
	int			total;
} 				vector;

void		vector_init(vector *);
int			vector_total(vector *);
static void vector_resize(vector *, int);
void		vector_add(vector *, void *);
void		vector_set(vector *, int, void *);
void		*vector_get(vector *, int);
void		vector_delete(vector *, int);
void		vector_free(vector *);

#endif