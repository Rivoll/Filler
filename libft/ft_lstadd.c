/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 05:03:34 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/06 17:56:06 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new)
	{
		if (!(*alst))
		{
			*alst = new;
			return ;
		}
		new->next = *alst;
		*alst = new;
	}
}
