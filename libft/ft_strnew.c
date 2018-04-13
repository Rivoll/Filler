/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 03:34:21 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/02 06:32:27 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = NULL;
	new_str = (char*)malloc(sizeof(char) * (size + 1));
	if (new_str)
	{
		while (i < (int)size)
			new_str[i++] = '\0';
		new_str[i] = '\0';
	}
	return (new_str);
}
