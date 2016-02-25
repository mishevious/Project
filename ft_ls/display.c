/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 07:02:09 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/25 15:52:31 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				permission(struct stat *file)
{
	if ((S_IFMT & file->st_mode) == S_IFREG)
		ft_putchar('-');
	else if ((S_IFMT & file->st_mode) == S_IFDIR)
		ft_putchar('d');
	else if ((S_IFMT & file->st_mode) == S_IFCHR)
		ft_putchar('c');
	else if ((S_IFMT & file->st_mode) == S_IFBLK)
		ft_putchar('b');
	else if ((S_IFMT & file->st_mode) == S_IFIFO)
		ft_putchar('p');
	else if ((S_IFMT & file->st_mode) == S_IFLNK)
		ft_putchar('l');
	else if ((S_IFMT & file->st_mode) == S_IFSOCK)
		ft_putchar('s');
	else
		ft_putchar('?');
	((file->st_mode & S_IRUSR) == S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	((file->st_mode & S_IWUSR) == S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	((file->st_mode & S_IXUSR) == S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
	((file->st_mode & S_IRGRP) == S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	((file->st_mode & S_IWGRP) == S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	((file->st_mode & S_IXGRP) == S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	((file->st_mode & S_IROTH) == S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	((file->st_mode & S_IWOTH) == S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	((file->st_mode & S_IXOTH) == S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
}

static void			display_time(char *time)
{
	int				i;

	i = 4;
	while (i < 16)
		ft_putchar(time[i++]);
}

static void			file_l(t_info *f) // remplacer les putchar(' ') par une fonction qui forme les colonnes "parfaites"
{
	struct group	*gp;
	struct passwd	*pass;
	char			*time;

	gp = getgrgid(f->file_stat.st_gid);
	pass = getpwuid(f->file_stat.st_uid);
	time = ctime(&f->file_stat.st_mtime);
	permission(&f->file_stat);//permissions
	ft_putchar(' ');
	ft_putnbr((int)f->file_stat.st_nlink);//links
	ft_putchar(' ');
	ft_putstr(pass->pw_name);//user name
	ft_putchar(' ');
	ft_putstr(gp->gr_name);//group name
	ft_putchar(' ');
	ft_putnbr(f->file_stat.st_size);//group name
	ft_putchar(' ');
	display_time(time);//modification time
	ft_putchar(' ');
	ft_putendl(f->dir_data->d_name);//file name
}

static void			simple_display(t_info *node, char *str)
{
	ft_putstr(str);
	node->next ? ft_putstr("   ") : NULL;
}

void				display_files_l(t_env *env, t_info *begin)
{
	t_info	*tmp;
	t_info	*tmp2;

	tmp = begin;
	tmp2 = NULL;
	(env->uppercase_r) ? ft_putendl(ft_strjoin(begin->path, ":")) : NULL;
	while (tmp && tmp->dir_data)
	{
		env->l ? file_l(tmp) : simple_display(tmp, tmp->dir_data->d_name);
		if (!tmp2 && tmp->down)
			tmp2 = tmp;
		tmp = tmp->next;
		if (!tmp)
			ft_putchar('\n');

	}
	while (tmp2)
	{
		if (tmp2->down)
			display_files_l(env, tmp2->down);
		tmp2 = tmp2->next;
	}
}
