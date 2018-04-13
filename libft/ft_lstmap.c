/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 05:20:27 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/06 15:08:19 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	if (!lst)
		return (NULL);
	new = (t_list*)malloc(sizeof(t_list));
	first = new;
	if (new)
	{
		new = f(lst);
		first = new;
		while (lst->next)
		{
			new->next = f(lst->next);
			new = new->next;
			lst = lst->next;
		}
	}
	return (first);
}
