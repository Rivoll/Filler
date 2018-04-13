/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 03:16:05 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/17 11:49:04 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char		*ft_strfsub(char **s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!*s)
		return (NULL);
	i = 0;
	dest = NULL;
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (dest)
	{
		while (i < len)
			dest[i++] = (*s)[start++];
		dest[i] = '\0';
	}
	free(*s);
	s = NULL;
	return (dest);
}
