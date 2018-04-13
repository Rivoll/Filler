/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:40:16 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/17 11:49:30 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char		*ft_strndup(const char *str, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (len < 0)
		len = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i] && i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
