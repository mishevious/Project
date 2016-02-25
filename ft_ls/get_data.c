/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:08:41 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/25 14:08:42 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dot(char *path)
{
	int	i;

	i = -1;
	if (ft_strlen(path) == 1 && path[0] == '.')
		return (1);
	else if (ft_strlen(path) == 2 && path[0] == '.' && path[1] == '.')
		return (1);
	else
		while (path[++i])
			if (path[i] != '.' && path[i] != '/')
				return (1);
	return (0);
}

void	get_data(t_env *e)
{
	int		i;

	i = -1;
	if (!(e->begin = (t_info**)malloc(sizeof(t_info*) * e->nb_path)))
		error_param(2, 1);
	while (i < e->nb_path)
		e->begin[++i] = NULL;
	i = -1;
	while (e->path[++i])
	{
	 	if (!ft_strcmp(e->path[i], "."))
			e->path[i] = ft_strjoin(e->path[i], "/");
		add_and_sort(e->path[i], e, &e->begin[i]);
		// if (nb_path > 1)
		// 	display_path(env);
		// display_list(env->begin);
		// if (!env->uppercase_r)
		display_files_l(e, e->begin[i]);
		// else 
		// display_files_l(env, *env->begin);
		// free_list(env);
		if (closedir(e->begin[i]->directory) == -1)
			perror(0);
	}
}
