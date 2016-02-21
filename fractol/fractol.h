/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:18:28 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/20 19:52:18 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

# define WINDOW_SIZE_H 800
# define WINDOW_SIZE_W 800
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_PAL1 18
# define KEY_PAL2 19
# define KEY_PAL3 20
# define KEY_PAL4 21
# define KEY_PAL5 23
# define KEY_PAL6 22
# define KEY_COL 24
# define KEY_ZERO 76
# define KEY_DEF 36
# define ITERMAX 100
# define MOVE_SPEED 50

typedef struct	s_color {
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct	s_calc {
	int			x;
	int			y;
	int			i;
	int			w;
	int			h;
	double		z_r;
	double		z_i;
	double		z_r2;
	double		z_i2;
	double		c_r;
	double		c_i;
	double		zoom_x;
	double		zoom_y;
}				t_calc;

typedef struct s_env	t_env;

struct			s_env {
	t_calc		c;
	t_env		*e2;
	void		*mlx;
	void		*win;
	void		*img;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		xs;
	double		ys;
	char		*pimg;
	int			ftype;
	int			bpp;
	int			s_line;
	int			ed;
	int			fract;
	int			iter;
	int			i;
	int			pal;
	int			def;
	int			param;
	int			col;
};

void			init_mandelbrot(t_env *e);
void			init_julia(t_env *e);
void			init_ark(t_env *e);
void			init_newton(t_env *e);

void			leave(void);
void			error_param(int type, int ex);
int				ft_abs(int nb);
double			ft_abs_double(double n);
double			d_power(double nb, int power);

int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse(int button, int x, int y, t_env *e);
int				mouse2(int x, int y, t_env *e);

void			draw_windows(char *title, int width, int height, t_env *e);
void			draw_point(int x, int y, t_env *e, t_color *c);
void			ft_option(void);

void			set_color(int nb, int i, t_env *e, t_color *c);

void			reload(t_env *e);
void			new_window(t_env *e2);

void			mandelbrot(t_env *e, t_calc c, int x, int y);
void			julia(t_env *e, t_calc c, int x, int y);
void			ark(t_env *e, t_calc c, int x, int y);
void			newton(t_env *e, t_calc c, int x, int y);

#endif
