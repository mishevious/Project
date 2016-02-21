/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:55:27 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/12 17:33:07 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_cmp_inter(t_item *item1, t_item *item2)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < 4)
	{
		while (x < 2)
		{
			if (item1->yx[y][x] != item2->yx[y][x])
				return ;
			x++;
		}
		x = 0;
		y++;
	}
	item1->inter = &item2->used;
}

void	ft_inter(t_global *global)
{
	t_item *item1;
	t_item *item2;

	item1 = global->item;
	item2 = global->item;
	while (item1)
	{
		while (item1->id != item2->id)
		{
			ft_cmp_inter(item1, item2);
			item2 = item2->next;
		}
		item2 = global->item;
		item1 = item1->next;
	}
}
