/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:26:10 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/06 15:48:47 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strtrim(char const *s)
{
	int		d;
	char	*dest;
	int		f;
	int		i;

	if (!s)
		return (NULL);
	f = ft_strlen(s);
	i = 0;
	d = 0;
	(f == 0) ? f += 0 : f--;
	while (d <= f && (s[f] == ' ' || s[f] == '\t' || s[f] == '\n'))
		f--;
	while ((s[d] == ' ' || s[d] == '\n' || s[d] == '\t') && s[d])
		d++;
	if (f - d >= 0)
		dest = (char *)malloc(sizeof(char) * (f - d + 2));
	else
		dest = (char*)malloc(sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[d] && d <= f)
		dest[i++] = s[d++];
	dest[i] = '\0';
	return (dest);
}
