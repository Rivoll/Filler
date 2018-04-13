/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:43:09 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:43:10 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char		*ft_add_char_end(char *str, char c, int nb)
{
	char	*tmp;
	int		i;
	char	*tmp2;

	if (!(tmp = (char*)malloc(sizeof(char) * nb + 1)))
		return (NULL);
	i = 0;
	while (i < nb)
		tmp[i++] = c;
	tmp[i] = '\0';
	tmp2 = ft_strjoin(str, tmp);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (tmp2);
}
