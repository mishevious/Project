/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:45:26 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/14 18:14:42 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bzero(t_global *global)
{
	int		i;

	i = 0;
	while (i < BUF_SIZE)
	{
		global->buf[i] = '\0';
		i++;
	}
}

int		ft_read(t_global *global)
{
	int	rd;

	rd = 0;
	while ((rd = read(global->fd, global->buf, BUF_SIZE)) > 0)
	{
		global->buf[BUF_SIZE] = '\0';
		if (!(ft_parse(global)))
			return (0);
		ft_bzero(global);
	}
	if (global->nb == 0)
		return (0);
	return (1);
}
