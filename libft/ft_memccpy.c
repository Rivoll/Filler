/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 01:05:20 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/05 22:13:28 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n && ((char*)src)[i] != c)
	{
		*((char*)dst) = ((char*)src)[i];
		i++;
		dst++;
	}
	if (i == (int)n)
		return (NULL);
	if (((char*)src)[i] == c)
		*((char*)dst++) = (unsigned char)c;
	return (dst);
}
