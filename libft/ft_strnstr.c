/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:48:11 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/05 22:53:35 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == '\0')
		return ((char *)big);
	while (*big && len > 0)
	{
		if (*big == *little && (size_t)ft_strlen(little) <= len)
		{
			if (ft_strncmp(big, little, (size_t)ft_strlen(little)) == 0)
				return ((char*)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
