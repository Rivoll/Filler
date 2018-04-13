/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 05:17:32 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/06 15:39:13 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (!s || !f)
		return (NULL);
	i = 0;
	dest = NULL;
	dest = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dest)
	{
		while (s[i])
		{
			dest[i] = f(i, (char)s[i]);
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
