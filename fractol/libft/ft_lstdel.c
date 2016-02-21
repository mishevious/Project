/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:06:01 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/05 18:50:14 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*move;

	lst = *alst;
	while (lst)
	{
		move = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = move;
	}
	*alst = NULL;
}
