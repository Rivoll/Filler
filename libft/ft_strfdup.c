/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 08:30:18 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/09 08:30:19 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strfdup(char **s1)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(*s1) || !s1)
		return (NULL);
	dest = NULL;
	dest = (char *)malloc(sizeof(char) * ft_strlen(*s1) + 1);
	if (dest)
	{
		while ((*s1)[i])
		{
			dest[i] = (*s1)[i];
			i++;
		}
		dest[i] = '\0';
	}
	free(*s1);
	*s1 = NULL;
	return (dest);
}
