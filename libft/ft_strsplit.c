/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:00:55 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/22 13:19:21 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			**ft_strsplit(char const *s, char c)
{
	char	**str_arr;
	int		num_words;

	if (!s)
		return (NULL);
	num_words = ft_strcount(s, c);
	str_arr = (char **)malloc(sizeof(char *) * num_words);
	if (!str_arr)
		return (NULL);
	str_arr = ft_poparr(str_arr, num_words, s, c);
	return (str_arr);
}
