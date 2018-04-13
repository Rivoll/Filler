/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:13:17 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/03 11:38:45 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memo;
	int		i;

	i = 0;
	memo = NULL;
	memo = (void*)malloc(sizeof(size_t) * size);
	if (memo)
	{
		while (i < (int)size)
			((char*)memo)[i++] = (unsigned char)0;
	}
	return (memo);
}
