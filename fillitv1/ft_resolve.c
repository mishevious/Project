/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:10:00 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/13 13:24:49 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid_item(t_global *global, t_item *it, int y, int x)
{
	if (it->inter)
		if (*it->inter == 1)
			return (0);
	if (it->used == 2 || x + it->xmin < 0
			|| x + it->xmax > global->size - 1
			|| y + it->ymax > global->size - 1)
		return (0);
	if (global->square[y + it->yx[0][0]][x + it->yx[0][1]] != '.')
		return (0);
	if (global->square[y + it->yx[1][0]][x + it->yx[1][1]] != '.')
		return (0);
	if (global->square[y + it->yx[2][0]][x + it->yx[2][1]] != '.')
		return (0);
	if (global->square[y + it->yx[3][0]][x + it->yx[3][1]] != '.')
		return (0);
	return (1);
}

int		ft_use_item(t_global *global, t_item *it, int y, int x)
{
	while (it)
	{
		if (ft_valid_item(global, it, y, x))
			if (ft_write_item(global, it, y, x))
				return (1);
		it = it->next;
	}
	global->space++;
	if (global->space > global->maxspace)
	{
		global->space--;
		return (0);
	}
	return (ft_lowerspace(global, yx(y, x, global), xy(x, global)));
}

int		ft_write_item(t_global *global, t_item *item, int y, int x)
{
	global->square[y + item->yx[0][0]][x + item->yx[0][1]] = item->id;
	global->square[y + item->yx[1][0]][x + item->yx[1][1]] = item->id;
	global->square[y + item->yx[2][0]][x + item->yx[2][1]] = item->id;
	global->square[y + item->yx[3][0]][x + item->yx[3][1]] = item->id;
	item->used++;
	global->used++;
	if (ft_resolve(global, yx(y, x, global), xy(x, global)))
		return (1);
	else
	{
		item->used--;
		global->used--;
		global->square[y + item->yx[0][0]][x + item->yx[0][1]] = '.';
		global->square[y + item->yx[1][0]][x + item->yx[1][1]] = '.';
		global->square[y + item->yx[2][0]][x + item->yx[2][1]] = '.';
		global->square[y + item->yx[3][0]][x + item->yx[3][1]] = '.';
		return (0);
	}
}

int		ft_resolve(t_global *global, int y, int x)
{
	t_item	*item;

	item = global->item;
	if (global->used == global->nb)
		return (1);
	if (y == global->size - 1 && x == global->size - 1)
		return (0);
	if (global->square[y][x] != '.')
		return (ft_resolve(global, yx(y, x, global), xy(x, global)));
	return (ft_use_item(global, item, y, x));
}
