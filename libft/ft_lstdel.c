/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 04:38:00 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/06 16:44:02 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *next_tmp;

	tmp = *alst;
	if (!del || !*alst)
		return ;
	while (tmp)
	{
		next_tmp = tmp->next;
		del((tmp)->content, (tmp)->content_size);
		free(tmp);
		tmp = next_tmp;
	}
	*alst = NULL;
}
