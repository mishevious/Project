/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:13:56 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/25 14:13:58 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_j(char *path, char *dir_name)
{
	int     len;
	char    *join;

	join = NULL;
	if (path && dir_name)
	{
		len = ft_strlen(path) + ft_strlen(dir_name);
		if (!(join = ft_strnew(len + 2)))
			error_param(2, 1);
		join = ft_strcpy(join, path);
		join = ft_strcat(join, "/");
		join = ft_strcat(join, dir_name);
		// free(path);
	}
	return (join);
}

t_bool		is_hidden_file(char *file_path)
{
	return (file_path && file_path[0] == '.');
}

t_info		*create_list(char *path, t_env *e, t_info **begin)
{
	t_info    *list;

	if (!(list = (t_info*)malloc(sizeof(t_info))))
		error_param(2, 1);
	if (!(list->path = ft_strdup(path)))
		error_param(2, 1);
	list->next = NULL;
	list->down = NULL;
	if (!(list->directory = opendir(list->path)))
		return (NULL);
	if (!(list->dir_data = readdir(list->directory)))
			return (NULL);
	if (lstat(ft_j(path, list->dir_data->d_name), &list->file_stat) == -1)
		perror(0);
	while (list->dir_data && !e->a && is_hidden_file(list->dir_data->d_name))
		list->dir_data = readdir(list->directory);
	if (list && list->dir_data && e->uppercase_r
		&& S_ISDIR(list->file_stat.st_mode))
		if (ft_strcmp(list->dir_data->d_name, "..")
			&& ft_strcmp(list->dir_data->d_name, "."))
			add_and_sort(ft_j(path, list->dir_data->d_name), e, &list->down);
	return (list);
}

t_info    *create_next_list(char *path, t_env *e, t_info *begin)
{
	t_info    *list;

	if (!(list = (t_info*)malloc(sizeof(t_info))))
		error_param(2, 1);
	if (!(list->path = ft_strdup(path)))
		error_param(2, 1);
	list->next = NULL;
	list->down = NULL;
	list->directory = begin->directory;
	if (!(list->dir_data = readdir(list->directory)))
		return (NULL);
	while (list->dir_data && !e->a && is_hidden_file(list->dir_data->d_name))
		list->dir_data = readdir(list->directory);
	if (list->dir_data)
		if (lstat(ft_j(path, list->dir_data->d_name),
			&list->file_stat) == -1)
			perror(0);
	if (list && list->dir_data && e->uppercase_r && S_ISDIR(list->file_stat.st_mode))
		if (ft_strcmp(list->dir_data->d_name, "..")
			&& ft_strcmp(list->dir_data->d_name, "."))
				add_and_sort(ft_j(path, list->dir_data->d_name), e, &list->down);
	return (list);
}

void            add_and_sort(char *path, t_env *e, t_info **begin)
{
	t_info		*to_add;
	*begin = create_list(path, e, begin);
	while ((to_add = create_next_list(path, e, *begin)))
	{
		if ((*begin)->dir_data && to_add->dir_data)
			sort(e, to_add, begin);
	}
}
