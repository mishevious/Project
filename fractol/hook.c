/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:42:06 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/20 19:44:00 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_move(int keycode, t_env *e)
{
	double	tmp;

	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		tmp = (e->y2 - e->y1) / MOVE_SPEED;
		e->y1 += (keycode == KEY_DOWN ? tmp : -tmp);
		e->y2 += (keycode == KEY_DOWN ? tmp : -tmp);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
	{
		tmp = (e->x2 - e->x1) / MOVE_SPEED;
		e->x1 += (keycode == KEY_RIGHT ? tmp : -tmp);
		e->x2 += (keycode == KEY_RIGHT ? tmp : -tmp);
	}
}

int			mouse2(int x, int y, t_env *e)
{
	if (e->def == 1)
	{
		e->xs = (e->x2 - e->x1) * x / WINDOW_SIZE_W + e->x1;
		e->ys = (e->y2 - e->y1) * y / WINDOW_SIZE_H + e->y1;
		expose_hook(e);
	}
	if (e->param == 2)
	{
		e->param = 1;
		new_window(e->e2);
	}
	return (1);
}

int			mouse(int button, int x, int y, t_env *e)
{
	double	tmpx;
	double	tmpy;

	tmpx = (e->x2 - e->x1) * x / WINDOW_SIZE_W + e->x1;
	tmpy = (e->y2 - e->y1) * y / WINDOW_SIZE_H + e->y1;
	if (button == 1 || button == 4)
	{
		e->x1 = tmpx + ((e->x1 - tmpx) / 2);
		e->x2 = e->x2 + ((tmpx - e->x2) / 2);
		e->y1 = tmpy + ((e->y1 - tmpy) / 2);
		e->y2 = e->y2 + ((tmpy - e->y2) / 2);
	}
	else if (button == 2 || button == 5)
	{
		e->x1 = e->x1 - ((e->x2 - e->x1) / 2);
		e->x2 = e->x2 + ((e->x2 - e->x1) / 2);
		e->y1 = e->y1 - ((e->y2 - e->y1) / 2);
		e->y2 = e->y2 + ((e->y2 - e->y1) / 2);
	}
	expose_hook(e);
	return (1);
}

void		zero(t_env *e, int keycode)
{
	if (e->ftype == 1 && keycode == KEY_ZERO)
		init_mandelbrot(e);
	else if (e->ftype == 2 && keycode == KEY_ZERO)
		init_julia(e);
	else if (keycode == KEY_DEF && e->def == 0)
		e->def = 1;
	else if (keycode == KEY_DEF && e->def == 1)
		e->def = 0;
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		leave();
	else if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
		|| keycode == KEY_RIGHT)
		key_move(keycode, e);
	else if (keycode == KEY_PAL1)
		e->pal = 1;
	else if (keycode == KEY_PAL2)
		e->pal = 2;
	else if (keycode == KEY_PAL3)
		e->pal = 3;
	else if (keycode == KEY_PAL4)
		e->pal = 4;
	else if (keycode == KEY_PAL5)
		e->pal = 5;
	else if (keycode == 31)
		ft_option();
	else if (keycode == KEY_COL && e->col == 1)
		e->col = 2;
	else if (keycode == KEY_COL && e->col == 2)
		e->col = 1;
	else if (keycode == KEY_ZERO || keycode == KEY_DEF)
		zero(e, keycode);
	expose_hook(e);
	return (0);
}
