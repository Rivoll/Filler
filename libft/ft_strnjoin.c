/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin..c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 06:43:46 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/14 06:43:47 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*ret;

	ret = NULL;
	if (s1 && s2)
	{
		if ((ret = (char*)malloc(sizeof(char)
		* ft_strlen(s1) + len + 1)) == NULL)
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strncat(ret, s2, len);
		free((char*)s1);
	}
	return (ret);
}
