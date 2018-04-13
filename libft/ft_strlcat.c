/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:45:26 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/06 11:44:14 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		n;
	int		i;
	int		value;

	i = 0;
	value = ft_strlen(dst) + ft_strlen(src);
	if (ft_strlen(dst) > size)
		return (size + ft_strlen(src));
	n = size - ft_strlen(dst) - 1;
	while (*dst)
		dst++;
	while (*src && i < n)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (value);
}
