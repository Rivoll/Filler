/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 06:32:32 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/17 11:48:40 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void		ft_sorttab(int *tab, int size)
{
	int		i;
	int		flag;

	if (size < 2)
		return ;
	while (1)
	{
		i = 0;
		--size;
		flag = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				flag = 1;
			}
			++i;
		}
		if (flag == 0)
			return ;
	}
}
