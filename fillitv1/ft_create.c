/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:01:56 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/13 12:54:52 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_global	*ft_create_global(char *file)
{
	t_global	*global;
	int			i;

	i = 0;
	if (!(global = (t_global*)malloc(sizeof(t_global))))
		return (NULL);
	global->file = ft_strsub(file, 0, ft_strlen(file));
	if (!(global->buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (NULL);
	while (i < BUF_SIZE)
		global->buf[i++] = '\0';
	global->buf[i] = '\0';
	global->nb = 0;
	global->space = 0;
	global->size = 0;
	global->error = 0;
	global->item = NULL;
	global->square = NULL;
	return (global);
}

void		ft_yx(char *str, t_item *elem, int y, int x)
{
	int		i;
	int		temp[2];
	int		bloc;

	i = 0;
	bloc = 0;
	while (y++ < 4)
	{
		while (x++ < 4)
		{
			if (str[i] == '#')
			{
				temp[0] = bloc > 0 ? temp[0] : y;
				temp[1] = bloc > 0 ? temp[1] : x;
				elem->yx[bloc][0] = y - temp[0];
				elem->yx[bloc][1] = x - temp[1];
				bloc++;
			}
			i++;
		}
		x = -1;
	}
}

void		ft_minmax(t_item *item)
{
	int		i;
	int		xmin;
	int		xmax;
	int		ymax;

	i = 0;
	xmin = 0;
	xmax = 0;
	ymax = 0;
	while (i < 4)
	{
		xmin = xmin > item->yx[i][1] ? item->yx[i][1] : xmin;
		xmax = xmax < item->yx[i][1] ? item->yx[i][1] : xmax;
		ymax = ymax < item->yx[i][0] ? item->yx[i][0] : ymax;
		i++;
	}
	item->xmin = xmin;
	item->xmax = xmax;
	item->ymax = ymax;
}

t_item		*ft_create_elem(t_global *global)
{
	t_item	*elem;
	int		y;
	int		x;

	y = -1;
	x = -1;
	if (!(elem = (t_item*)malloc(sizeof(t_item))))
		return (NULL);
	elem->id = 'A' + global->nb;
	elem->used = 1;
	elem->inter = NULL;
	ft_yx(global->buf, elem, y, x);
	ft_minmax(elem);
	elem->next = NULL;
	return (elem);
}

int			ft_create_item(t_global *global)
{
	t_item		*list;

	if (global->item)
	{
		list = global->item;
		while (list->next)
			list = list->next;
		if (!(list->next = ft_create_elem(global)))
			return (ft_error(global, 20));
	}
	else
	if (!(global->item = ft_create_elem(global)))
		return (ft_error(global, 20));
	return (1);
}
