/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtabi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 06:24:24 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/17 11:47:50 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void		ft_printtabi(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putnbr(tab[i++]);
		ft_putstr("\n");
	}
}
