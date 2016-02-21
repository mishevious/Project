/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 08:23:39 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/13 12:52:34 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_change_x(t_item *item)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (item->xmin < 0)
			item->yx[i][1] = item->yx[i][1] + (item->xmin * -1);
		i++;
	}
	item->xmax = item->xmax + item->xmin * -1;
	item->xmin = 0;
}

void	ft_index_item(t_global *global)
{
	t_item	*item;

	item = global->item;
	while (item)
	{
		ft_change_x(item);
		item = item->next;
	}
}
