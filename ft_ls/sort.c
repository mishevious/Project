/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 03:00:26 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/24 15:22:41 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include "ft_ls.h"

void		ascii_sort(t_info **begin, t_info *to_add)
{
	t_info	*current_list;

	current_list = *begin;
	if ((ft_strcmp(to_add->dir_data->d_name,
						current_list->dir_data->d_name) < 0))
	{
		
		to_add->next = current_list;
		*begin = to_add;
		// printf("begin =%p, add =%p\n", *begin, to_add);
		// printf("begin =%s\n", begin[0]->dir_data->d_name);
		return ;
	}
	while (current_list->next)
	{
		if ((ft_strcmp(to_add->dir_data->d_name,
						current_list->dir_data->d_name) > 0) &&
			(ft_strcmp(to_add->dir_data->d_name,
						current_list->next->dir_data->d_name) < 0))
		{
			to_add->next = current_list->next;
			current_list->next = to_add;
			return ;
		}
		current_list = current_list->next;
	}
	current_list->next = to_add;
}

void		reverse_sort(t_info **begin, t_info *to_add)
{
	t_info	*current_list;

	current_list = *begin;
	if ((ft_strcmp(to_add->dir_data->d_name,
						current_list->dir_data->d_name) > 0))
	{
		to_add->next = current_list;
		*begin = to_add;
		return ;
	}
	while (current_list->next)
	{
		if ((ft_strcmp(to_add->dir_data->d_name,
						current_list->dir_data->d_name) < 0) &&
			(ft_strcmp(to_add->dir_data->d_name,
						current_list->next->dir_data->d_name) > 0))
		{
			to_add->next = current_list->next;
			current_list->next = to_add;
			return ;
		}
		current_list = current_list->next;
	}
	current_list->next = to_add;
}

void		time_sort(t_info **begin, t_info *to_add)
{
	t_info	*current_list;

	current_list = *begin;
	if (to_add->file_stat.st_mtime >= current_list->file_stat.st_mtime)
	{
		to_add->next = current_list;
		*begin = to_add;
		return ;
	}
	while (current_list->next)
	{
		if (to_add->file_stat.st_mtime <= current_list->file_stat.st_mtime
			&& to_add->file_stat.st_mtime >=
			current_list->next->file_stat.st_mtime)
		{
			to_add->next = current_list->next;
			current_list->next = to_add;
			return ;
		}
		current_list = current_list->next;
	}
	current_list->next = to_add;
}

void		reverse_time_sort(t_info **begin, t_info *to_add)
{
	t_info	*current_list;

	current_list = *begin;
	if (to_add->file_stat.st_mtime <= current_list->file_stat.st_mtime)
	{
		to_add->next = current_list;
		*begin = to_add;
		return ;
	}
	while (current_list->next)
	{
		if (to_add->file_stat.st_mtime >= current_list->file_stat.st_mtime
			&& to_add->file_stat.st_mtime <=
			current_list->next->file_stat.st_mtime)
		{
			to_add->next = current_list->next;
			current_list->next = to_add;
			return ;
		}
		current_list = current_list->next;
	}
	current_list->next = to_add;
}

void		sort(t_env *e, t_info *to_add, t_info **begin)
{
	if (e->lowercase_r && e->t)
	 	reverse_time_sort(begin, to_add);
	else if (e->t)
		time_sort(begin, to_add);
	else if (e->lowercase_r)
		reverse_sort(begin, to_add);
	else
		ascii_sort(begin, to_add);
}
