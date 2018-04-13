/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:05:17 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/06 11:42:08 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int		power(int nb, int power)
{
	int nb_bis;

	nb_bis = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= nb_bis;
		power--;
	}
	return (nb);
}

static int		count_digit(int nbr)
{
	int result;

	result = 0;
	if (nbr == 0)
		result = 1;
	else
	{
		while (nbr != 0)
		{
			nbr /= 10;
			result++;
		}
	}
	return (result);
}

static char		*ft_itoa_min(int n)
{
	char	*dest;
	int		i;
	int		nb_de_char;

	dest = NULL;
	dest = (char*)malloc(sizeof(char) * 12);
	dest[0] = '-';
	dest[1] = '2';
	i = 2;
	n = 147483648;
	nb_de_char = 9;
	while (nb_de_char != 0)
		dest[i++] = ((n / power(10, --nb_de_char)) % 10) + '0';
	dest[i] = '\0';
	return (dest);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*dest;
	int		nb_de_char;

	i = 0;
	dest = NULL;
	nb_de_char = count_digit(n);
	if (n == -2147483648)
		return (ft_itoa_min(n));
	if (n >= 0)
		dest = (char*)malloc(sizeof(char) * (nb_de_char + 1));
	else
		dest = (char*)malloc(sizeof(char) * (nb_de_char + 2));
	if (dest == NULL)
		return (NULL);
	if (n < 0)
	{
		dest[i++] = '-';
		n = -n;
	}
	while (nb_de_char != 0)
		dest[i++] = ((n / power(10, --nb_de_char)) % 10) + '0';
	dest[i] = '\0';
	return (dest);
}
