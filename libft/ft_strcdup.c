/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:51:55 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/22 13:52:16 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "include/libft.h"

char	*ft_strcdup(const char *s, char c)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[size] && s[size] != c)
		size++;
	if (!(str = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
