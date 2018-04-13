/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 01:14:05 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/05 22:14:16 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;
	size_t	i;

	i = 0;
	tmp = (void*)malloc(sizeof(char) * len);
	if (tmp)
	{
		while (i < len)
		{
			((char*)tmp)[i] = ((char*)src)[i];
			i++;
		}
		i = 0;
		while (i < len)
		{
			((char*)dst)[i] = ((char*)tmp)[i];
			i++;
		}
	}
	return (dst);
}
