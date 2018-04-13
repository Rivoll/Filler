/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:55:10 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/18 00:13:59 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int	ft_coun_digit(unsigned long long nb, int base)
{
	int		result;

	result = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= base;
		result++;
	}
	return (result);
}

char		*ft_ullitoa_base(unsigned long long nb, int base, int maj)
{
	char	*dest;
	int		nb_char;

	if (base < 2 || base > 36 || (maj != 0 && maj != 1))
		return (NULL);
	nb_char = ft_coun_digit(nb, base);
	if (!(dest = (char*)malloc(sizeof(char) * (nb_char + 1))))
		return (NULL);
	dest[nb_char--] = '\0';
	while (nb_char >= 0)
	{
		if (nb % base >= 10)
			dest[nb_char--] = nb % base + 87 + maj * -32;
		else
			dest[nb_char--] = nb % base + '0';
		nb /= base;
	}
	return (dest);
}
