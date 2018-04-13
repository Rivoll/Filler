/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:48:38 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:48:39 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char		*ft_stradd_start(char *src, char *add)
{
	int		i;
	char	*dest;
	int		j;

	if (!src)
	{
		if (!(src = (char*)malloc(sizeof(char))))
			return (NULL);
		src[0] = '\0';
	}
	i = 0;
	j = 0;
	if (!(dest = (char *)malloc(sizeof(char) *
		(ft_strlen(src) + ft_strlen(add)) + 1)))
		return (NULL);
	while (add[i])
	{
		dest[i] = add[i];
		i++;
	}
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	ft_strdel(&src);
	return (dest);
}
