/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 22:01:21 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/23 22:14:35 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <uuid/uuid.h>
# include <stdio.h>
# include "libft/libft.h"

# define CHECK_FLAGS "Ratrl"

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct				s_info
{
	char					*path;
	DIR						*directory;
	struct dirent			*dir_data;
	struct dirent			dir_cpy;
	struct stat				file_stat;
	struct s_info			*next;
	struct s_info			*down;
}							t_info;

typedef struct				s_env
{
	char					**path;
	t_info					**begin;
	t_info					*fi;
	char					uppercase_g;
	char					uppercase_r;
	char					t;
	char					a;
	char					lowercase_r;
	char					lowercase_g;
	char					l;
	char					*tmp;
	int						nb_path;
	char					*full_path;
}							t_env;

t_env						*create_env(char **path);
t_info						*create_list(char *path, t_env *e, t_info **begin);
t_info   					*create_next_list(char *path, t_env *e,\
t_info *begin);
void           				add_and_sort(char *path, t_env *e, t_info **begin);
void						push_down(char *path, t_env *e, \
t_info *list);
char						*ft_j(char *path, char *dir_name);
void						sort(t_env *e, t_info *to_add, t_info **begin);
void						sort_down(t_env *e, t_info *list, \
t_info *to_add);
int							parser(int ac, char **av, t_env *e, int i);
void						error_param(int type, int ex);
void						error_path(int ex, char *str);
void						init_path(t_env *e);
int							fill_path(t_env *e, int j, char **av);
void						get_data(t_env *e);
void						display_files_l(t_env *e, t_info *begin);
void						permission(struct stat *file);

#endif
