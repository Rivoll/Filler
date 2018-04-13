/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 08:22:43 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/09 08:22:47 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int		ft_count_word(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			count++;
		if (str[i])
			i++;
	}
	return (count);
}

static int		ft_len_word(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != c && str[i])
	{
		i++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**dest;

	if (!s)
		return (NULL);
	if (!(dest = (char**)malloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (NULL);
	j = 0;
	while (*s)
	{
		if (!(dest[j] = (char*)malloc(sizeof(char) * (ft_len_word(s, c) + 1))))
			return (NULL);
		i = 0;
		while (*s && *s != c)
			dest[j][i++] = *s++;
		dest[j++][i] = '\0';
		if (*s)
			s++;
	}
	dest[j] = NULL;
	return (dest);
}
