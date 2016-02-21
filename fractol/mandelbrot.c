/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:18:11 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/20 19:53:59 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_mandelbrot(t_env *e)
{
	e->col = 1;
	e->pal = 1;
	e->x1 = -2.0;
	e->x2 = 2.0;
	e->y1 = -2.0;
	e->y2 = 2.0;
	e->ys = 0.0;
	e->xs = 0.0;
	e->def = 0;
	e->ftype = 1;
	e->iter = ITERMAX / 2;
}

void		mandelbrot(t_env *e, t_calc c, int x, int y)
{
	t_color	*color;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		error_param(2, 1);
	c.z_r = 0.0;
	c.z_i = 0.0;
	c.z_r2 = e->xs;
	c.z_i2 = e->ys;
	while (c.z_r2 + c.z_i2 >= 4)
		c.z_i2 -= 0.1;
	c.i = 0;
	while (c.z_r2 + c.z_i2 < 4 && c.i < e->iter)
	{
		c.z_i = 2 * c.z_i * c.z_r + c.c_i;
		c.z_r = c.z_r2 - c.z_i2 + c.c_r;
		c.z_r2 = c.z_r * c.z_r;
		c.z_i2 = c.z_i * c.z_i;
		c.i += 1;
	}
	if (c.i == e->iter)
		set_color(1, c.i, e, color);
	else
		set_color(2, c.i, e, color);
	draw_point(x, y, e, color);
	free(color);
}
