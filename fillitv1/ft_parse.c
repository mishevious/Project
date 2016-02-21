/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:29:42 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/13 19:27:37 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_char(char *str, t_global *global)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (ft_error(global, 4));
		if ((str[i] == '\n' && i != 4 && i != 9
				&& i != 14 && i != 19 && i != 20))
			return (ft_error(global, 5));
		if (i == 4 && str[i] != '\n')
			return (ft_error(global, 6));
		if (i == 9 && str[i] != '\n')
			return (ft_error(global, 7));
		if (i == 14 && str[i] != '\n')
			return (ft_error(global, 8));
		if (i == 19 && str[i] != '\n')
			return (ft_error(global, 9));
		if (i == 20 && str[i] != '\n' && str[i] != '\0')
			return (ft_error(global, 10));
		i++;
	}
	if (i < 20)
		return (ft_error(global, 100));
	return (1);
}

int			ft_tetri_case(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '#')
			i++;
		str++;
	}
	return (i);
}

int			ft_tetri_integr(char *str, t_global *global, int i, int k)
{
	while (str[i++])
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				k = 1;
			if (i > 0)
				if (str[i - 1] == '#')
					k = 1;
			if (i < 15)
				if (str[i + 5] == '#')
					k = 1;
			if (i > 5)
				if (str[i - 5] == '#')
					k = 1;
			if (k == 0)
				return (ft_error(global, 11));
			k = 0;
		}
	return (1);
}

int			ft_tetri_follow(char *str, t_global *global, int i)
{
	while (str[i++])
	{
		if (str[i] == '#')
		{
			if (i < 18)
				if (str[i + 1] == '#' && str[i + 2] == '#')
					return (1);
			if (i < 14)
				if (str[i + 1] == '#' && str[i + 6] == '#')
					return (1);
			if (i < 10)
				if (str[i + 5] == '#' && str[i + 10] == '#')
					return (1);
			if (i < 15)
				if (str[i + 5] == '#' && str[i + 4] == '#')
					return (1);
			if (i < 15)
				if (str[i + 5] == '#' && str[i + 1] == '#')
					return (1);
			if (i < 14)
				if (str[i + 5] == '#' && str[i + 6] == '#')
					return (1);
		}
	}
	return (ft_error(global, 110));
}

int			ft_parse(t_global *global)
{
	if (global->nb >= 26)
		return (ft_error(global, 12));
	if (!(ft_check_char(global->buf, global)))
		return (0);
	if (ft_tetri_case(global->buf) != 4)
		return (ft_error(global, 13));
	if (!(ft_tetri_integr(global->buf, global, 0, 0)))
		return (0);
	if (!(ft_tetri_follow(global->buf, global, 0)))
		return (0);
	if (!(ft_create_item(global)))
		return (ft_error(global, 14));
	global->nb++;
	return (1);
}
