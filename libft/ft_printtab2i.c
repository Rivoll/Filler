/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab2i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:42:40 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/06 03:20:07 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_printtab2i(int **tab2i, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			ft_putstr("tab[");
			ft_putnbr(j);
			ft_putstr("][");
			ft_putnbr(i);
			ft_putstr("] = ");
			ft_putnbr(tab2i[j][i++]);
			ft_putchar('\n');
		}
		j++;
	}
}
