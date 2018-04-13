/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:42:13 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/12 02:51:25 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char		*ft_add_char(char *str, char c, int nb, int start)
{
	char	*tmp;
	int		i;
	int		repeat;
	int		j;

	i = 0;
	j = 0;
	repeat = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1 + nb))))
		return (NULL);
	while (i < start && str[i])
		tmp[j++] = str[i++];
	while (repeat < nb)
	{
		tmp[j++] = c;
		repeat++;
	}
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	ft_strdel(&str);
	return (tmp);
}
