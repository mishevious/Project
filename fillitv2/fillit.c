/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 23:31:16 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/14 18:16:16 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(t_global *global, int id)
{
	global->error = id;
	return (0);
}

void	ft_item_clear(t_item **begin_list)
{
	t_item	*tmp;
	t_item	*list;

	list = *begin_list;
	tmp = NULL;
	while (list)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = NULL;
		free(list);
		list = tmp;
	}
}

void	ft_freeall(t_global *global)
{
	if (global->file)
		free(global->file);
	if (global->square)
		freesquare(global);
	if (global->buf)
		free(global->buf);
	if (global->item)
		ft_item_clear(&global->item);
	if (global)
		free(global);
}

void	ft_printerror(t_global *global)
{
	write(1, "error\n", 6);
	ft_freeall(global);
}

void	fillit(char *file)
{
	t_global	*global;

	if (!(global = ft_create_global(file)))
	{
		write(1, "error\n", 6);
		return ;
	}
	if (!(ft_open(global)))
	{
		ft_printerror(global);
		return ;
	}
	ft_inter(global);
	if (!(ft_square(global)))
	{
		ft_printerror(global);
		return ;
	}
	ft_write_square(global);
	ft_freeall(global);
}
