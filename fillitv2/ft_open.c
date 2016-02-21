/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:26:46 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/10 00:28:43 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_open(t_global *global)
{
	global->fd = open(global->file, O_RDONLY);
	if (global->fd == -1)
		return (ft_error(global, 2));
	if (!(ft_read(global)))
		return (0);
	if (close(global->fd) == -1)
		return (ft_error(global, 3));
	return (1);
}
