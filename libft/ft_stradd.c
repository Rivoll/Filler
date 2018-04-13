/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 07:24:42 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/08 03:37:01 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char		*ft_stradd(char *src, char *add)
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
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (add[j])
		dest[i++] = add[j++];
	dest[i] = '\0';
	ft_strdel(&src);
	return (dest);
}
