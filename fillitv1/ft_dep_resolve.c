/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_resolve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 13:23:10 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/13 13:28:15 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		xy(int x, t_global *global)
{
	if (x + 1 == global->size)
		return (0);
	return (x + 1);
}

int		yx(int y, int x, t_global *global)
{
	if (x + 1 == global->size)
		return (y + 1);
	return (y);
}

int		ft_lowerspace(t_global *global, int y, int x)
{
	if (ft_resolve(global, y, x))
		return (1);
	else
	{
		global->space--;
		return (0);
	}
}
