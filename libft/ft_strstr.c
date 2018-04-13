/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:26:45 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/05 22:26:15 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;

	i = 0;
	if (!big)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == *little)
		{
			if (ft_strncmp(big + i, little, ft_strlen(little)) == 0)
				return ((char*)big);
		}
		i++;
	}
	return (NULL);
}
