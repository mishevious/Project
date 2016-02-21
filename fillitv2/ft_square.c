/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:10:30 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/14 19:10:03 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		freesquare(t_global *global)
{
	int		y;

	y = 0;
	while (y < global->size - 1)
	{
		free(global->square[y]);
		y++;
	}
	free(global->square);
}

int			ft_create_square(t_global *global)
{
	int		i;

	i = 0;
	if (global->square)
		freesquare(global);
	global->square = (char**)malloc(sizeof(char*) * (global->size + 1));
	if (!global->square)
		return (0);
	while (i < global->size)
	{
		if (!(global->square[i] = ft_strnew(global->size)))
			return (0);
		i++;
	}
	return (1);
}

int			ft_piece(t_global *g, int size)
{
	g->size = size;
	if (g->nb == 4 || g->nb == 9 || g->nb == 16 || g->nb == 25)
		g->maxspace = 0;
	else if (g->nb == 6 || g->nb == 12 || g->nb == 20)
		g->maxspace = 1;
	else if (g->nb == 3 || g->nb == 8 || g->nb == 15 || g->nb == 24)
		g->maxspace = 4;
	else if (g->nb == 5 || g->nb == 11 || g->nb == 19)
		g->maxspace = 5;
	else if (g->nb == 7 || g->nb == 14 || g->nb == 23 || g->nb == 2)
		g->maxspace = 8;
	else if (g->nb == 10 || g->nb == 18 || g->nb == 13)
		g->maxspace = 9;
	else if (g->nb == 13 || g->nb == 22)
		g->maxspace = 12;
	else if (g->nb == 17)
		g->maxspace = 13;
	else if (g->nb == 21)
		g->maxspace = 16;
	else if (g->nb == 26)
		g->maxspace = 17;
	return (1);
}

int			ft_size_square(t_global *global)
{
	if (global->nb < 5)
		return (ft_piece(global, 1));
	else if (global->nb > 4 && global->nb < 7)
		return (ft_piece(global, 5));
	else if (global->nb > 6 && global->nb < 10)
		return (ft_piece(global, 6));
	else if (global->nb > 9 && global->nb < 13)
		return (ft_piece(global, 7));
	else if (global->nb > 12 && global->nb < 17)
		return (ft_piece(global, 8));
	else if (global->nb > 16 && global->nb < 21)
		return (ft_piece(global, 9));
	else if (global->nb > 20 && global->nb < 26)
		return (ft_piece(global, 10));
	else if (global->nb == 26)
		return (ft_piece(global, 11));
	return (1);
}

int			ft_square(t_global *g)
{
	if (!(ft_size_square(g)))
		return (0);
	if (!(ft_create_square(g)))
		return (0);
	while (!ft_resolve(g, 0, 0))
	{
		g->size++;
		g->maxspace = g->maxspace + g->size * 2 - 1;
		if (!(ft_create_square(g)))
			return (0);
	}
	return (1);
}
