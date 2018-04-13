/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:29:19 by pkeita            #+#    #+#             */
/*   Updated: 2017/09/16 15:09:52 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int		ft_count_word(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' '))
			i++;
		while (str[i] && str[i] != '\t' && str[i] != '\n' && str[i] != ' ')
			i++;
		if (str[i - 1] != '\t' && str[i - 1] != '\n' && str[i - 1] != ' ')
			count++;
	}
	return (count);
}
