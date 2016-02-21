/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:07:07 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/20 18:29:33 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	gen_fract(t_env *e, t_calc c, int x, int y)
{
	if (e->ftype == 1)
		mandelbrot(e, c, x, y);
	if (e->ftype == 2)
	{
		c.z_r = (e->x2 - e->x1) * x / WINDOW_SIZE_W + e->x1;
		c.z_i = (e->y2 - e->y1) * y / WINDOW_SIZE_H + e->y1;
		julia(e, c, x, y);
	}
	if (e->ftype == 3)
	{
		c.z_r2 = (e->x2 - e->x1) * x / WINDOW_SIZE_W + e->x1;
		c.z_i2 = (e->y2 - e->y1) * y / WINDOW_SIZE_H + e->y1;
		ark(e, c, x, y);
	}
	if (e->ftype == 4)
	{
		c.z_r = (e->x2 - e->x1) * x / WINDOW_SIZE_W + e->x1;
		c.z_i = (e->y2 - e->y1) * y / WINDOW_SIZE_H + e->y1;
		newton(e, c, x, y);
	}
}

void	create(t_env *e, t_calc c)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINDOW_SIZE_H)
	{
		c.c_i = e->y1 + y * c.zoom_y;
		x = -1;
		while (++x < WINDOW_SIZE_W)
		{
			c.c_r = e->x1 + x * c.zoom_x;
			gen_fract(e, c, x, y);
		}
	}
}

t_calc	init(t_env *e)
{
	t_calc c;

	c.z_r = 0;
	c.z_i = 0;
	c.h = WINDOW_SIZE_H;
	c.w = WINDOW_SIZE_W;
	c.zoom_x = (e->x2 - e->x1) / WINDOW_SIZE_W;
	c.zoom_y = (e->y2 - e->y1) / WINDOW_SIZE_H;
	return (c);
}

void	reload(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WINDOW_SIZE_W, WINDOW_SIZE_H);
	e->pimg = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->ed));
	e->c = init(e);
	create(e, e->c);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}
