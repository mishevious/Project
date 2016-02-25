/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 05:26:16 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/23 22:41:25 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sorting_flags(t_env *e)
{
	int		i;
	int		y;
	int		k;
	char	*tmp;

	i = -1;
	k = -1;
	if (!(tmp = ft_memalloc(ft_strlen(e->tmp) + 1)))
		error_param(2, 1);
	ft_strcpy(tmp, e->tmp);
	while (CHECK_FLAGS[++i])
	{
		y = -1;
		while (tmp[++y])
			if (tmp[y] == CHECK_FLAGS[i])
				e->tmp[++k] = tmp[y];
	}
	free(tmp);
}

void	check_opt(char *str, t_env *e)
{
	int		i;
	int		y;

	i = 0;
	while (str[++i])
	{
		if (!ft_strchr(CHECK_FLAGS, str[i]))
		{
			ft_putstr_fd("ft_ls: illegal option -- ", 2);
			ft_putchar_fd(str[i], 2);
			ft_putchar_fd('\n', 2);
			error_param(1, 1);
		}
	}
	if (i == 1)
		error_param(1, 1);
	i = -1;
	while (CHECK_FLAGS[++i])
	{
		y = -1;
		while (str[++y])
			if (CHECK_FLAGS[i] == str[y] && !ft_strchr(e->tmp, str[y]))
				e->tmp[ft_strlen(e->tmp)] = str[y];
	}
	sorting_flags(e);
}

int		check_path(char *str)
{
	struct stat buf;
	int			i;

	i = 0;
	while (str[++i])
		if (ft_isprint(str[i]) == 0)
		{
			error_path(2, str);
			return (0);
		}
	if (stat(str, &buf) == -1)
	{
		error_path(2, str);
		return (0);
	}
	return (1);
}

int		parser(int ac, char **av, t_env *e, int i)
{
	int j;
	int k;

	k = 0;
	if (ac > 1)
	{
		while (av[i] && av[i][0] == '-')
			check_opt(av[i++], e);
		j = i;
		while (av[i])
		{
			e->nb_path += check_path(av[i++]);
			k++;
		}
		if (e->nb_path > 0)
			fill_path(e, j, av);
		else if (k == 0)
			init_path(e);
	}
	return (1);
}

int		fill_path(t_env *e, int j, char **av)
{
	int		i;

	i = 0;
	if (!(e->path = (char**)malloc(sizeof(char*) * (e->nb_path + 1))))
		error_param(2, 1);
	e->path[e->nb_path] = NULL;
	while (av[j])
	{
		if (check_path(av[j]) == 1)
			if (!(e->path[i++] = ft_strdup(av[j])))
				error_param(2, 1);
		j++;
	}
	return (1);
}
