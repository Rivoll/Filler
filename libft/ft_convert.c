/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 09:03:55 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/12 04:06:11 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char				*ft_convert(char *nb, int base_nb, int new_base, int maj)
{
	char			*dest;
	long long int	tmp;

	tmp = ft_atlli_base(nb, base_nb, 0);
	dest = ft_llitoa_base(tmp, new_base, maj);
	return (dest);
}
