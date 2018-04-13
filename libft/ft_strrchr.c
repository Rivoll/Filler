/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:25:46 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/05 22:47:39 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	while (*s != (char)c && i > 0)
	{
		s--;
		i--;
	}
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
