/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:48:30 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:48:31 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char	*ft_str_replace(char *erase, char *new)
{
	if (erase)
		ft_strdel(&erase);
	return (ft_strdup(new));
}
