/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:29:17 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/11 19:29:18 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char		**ft_creat_tab(int x, int y, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (y + 1))))
		return (NULL);
	while (i < x)
	{
		if (!(tab[i++] = (char*)malloc(sizeof(char) * (x + 1))))
			return (NULL);
	}
	if (c)
	{
		i = 0;
		while (i < y)
		{
			j = 0;
			while (j < x)
				tab[i][j++] = c;
			tab[i++][j] = '\0';
		}
		tab[i] = 0;
	}
	return (tab);
}
