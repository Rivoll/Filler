/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:51:16 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/29 07:20:29 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*dest;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	dest = NULL;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (dest)
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		while (s2[j])
			dest[i++] = s2[j++];
		dest[i] = '\0';
	}
	return (dest);
}
