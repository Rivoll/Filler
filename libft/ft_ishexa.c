/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 08:38:51 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/09 08:38:53 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int			ft_ishexa(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		i++;
	if (i > 8)
		return (0);
	if (str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))
		return (0);
	i = 2;
	while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] >= 'a' &&
		str[i] <= 'f') && !(str[i] >= 'A' && str[i] <= 'F'))
			return (0);
		i++;
	}
	return (1);
}
