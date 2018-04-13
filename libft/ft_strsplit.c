/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 11:42:30 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/02 19:37:06 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int		ft_count(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			count++;
		while (str[i] && str[i] == c)
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
	int		k;

	if (!s || !(dest = (char**)malloc(sizeof(char*) * (ft_count(s, c) + 1))))
		return (NULL);
	j = 0;
	k = 0;
	while (s[k] == c)
		k++;
	while (s[k])
	{
		if (!(dest[j] = (char*)malloc(sizeof(char) *
		(ft_len_word(s + k, c) + 1))))
			return (NULL);
		i = 0;
		while (s[k] && s[k] != c)
			dest[j][i++] = s[k++];
		dest[j++][i] = '\0';
		while (s[k] && s[k] == c)
			k++;
	}
	dest[j] = NULL;
	return (dest);
}
