/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_tabi2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 08:38:38 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/09 08:38:39 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int			**ft_creat_tabi2(int x, int y)
{
	int		**tab;
	int		i;
	int		j;

	i = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * y)))
		ft_exit("Malloc failed");
	while (i < y)
	{
		j = 0;
		if (!(tab[i] = (int*)malloc(sizeof(int) * x)))
			ft_exit("Malloc failed");
		while (j < x)
			tab[i][j++] = 0;
		i++;
	}
	return (tab);
}
