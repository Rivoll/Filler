/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atlli_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:46:33 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:46:34 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

long long int		ft_atlli_base(char *nb, int base_nb, int maj)
{
	long long int	result;
	int				sign;
	int				i;

	if (base_nb > 36 || base_nb < 2)
		return (-1);
	sign = 1;
	i = 0;
	result = 0;
	nb[i] == '+' ? i++ : 0;
	nb[i] == '-' ? sign = -1 : 0;
	nb[i] == '-' ? i++ : 0;
	while (nb[i])
	{
		if (nb[i] >= '0' && nb[i] <= '9')
			result = result * base_nb + nb[i++] - '0';
		else if ((nb[i] >= 'a' && nb[i] <= 'j') || (nb[i] >= 'A' &&
			nb[i] <= 'J'))
			result = result * base_nb - (97 - maj * 30) + nb[i++];
		else
			break ;
	}
	return (result * sign);
}
