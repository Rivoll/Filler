/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 05:10:10 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/06 15:38:19 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	dest = NULL;
	dest = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (dest)
	{
		while (*s)
			dest[i++] = f(*s++);
		dest[i] = '\0';
	}
	return (dest);
}
