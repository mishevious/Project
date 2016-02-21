/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 19:39:55 by ylarbi            #+#    #+#             */
/*   Updated: 2016/01/04 14:30:56 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 21

typedef	struct s_item	t_item;
struct			s_item
{
	char		id;
	int			*inter;
	int			used;
	int			yx[4][2];
	int			xmin;
	int			xmax;
	int			ymax;
	t_item		*next;
};

typedef	struct s_global	t_global;
struct			s_global
{
	int			nb;
	t_item		*item;
	int			size;
	int			space;
	int			maxspace;
	int			error;
	int			fd;
	char		**square;
	char		*file;
	char		*buf;
	int			used;
};

unsigned int	ft_strlen(char *str);
int				ft_open(t_global *global);
int				ft_read(t_global *global);
int				ft_parse(t_global *global);
int				ft_create_item(t_global *global);
int				ft_square(t_global *global);
int				ft_error(t_global *global, int id);
int				ft_resolve(t_global *global, int y, int x);
int				ft_write_item(t_global *global, t_item *item, int y, int x);
int				xy(int x, t_global *global);
int				yx(int y, int x, t_global *global);
int				ft_lowerspace(t_global *global, int y, int x);
int				ft_solve(t_global *global, int y, int x, t_item *item);
char			*ft_strsub(char *s, unsigned int start, int len);
char			*ft_strnew(int size);
void			fillit(char *file);
void			ft_write_square(t_global *global);
void			freesquare(t_global *global);
void			ft_index_item(t_global *global);
void			ft_inter(t_global *global);
t_global		*ft_create_global(char *file);

#endif
