/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:18:11 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/23 22:23:10 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			init_newton(t_env *e)
{
	e->col = 1;
	e->pal = 1;
	e->x1 = -4;
	e->x2 = 4;
	e->y1 = -4;
	e->y2 = 4;
	e->ys = 0.0;
	e->m = 1;
	e->m2 = 1;
	e->xs = WINDOW_SIZE_W / 2;
	e->def = 0;
	e->ftype = 4;
	e->iter = ITERMAX / 2;
	return (1);
}

void		newton(t_env *e, t_calc c, int x, int y)
{
	t_color	*color;
	double	i2;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		error_param(2, 1);
	c.i = 0;
	i2 = 0;
	while (c.i < e->iter)
	{
		c.z_r2 = e->m * 2 * c.z_r / 3 - (c.z_r * c.z_r - c.z_i * c.z_i) / \
		(c.z_r * c.z_r + c.z_i * c.z_i) / (c.z_r * c.z_r + c.z_i * c.z_i) / 3;
		c.z_i2 = e->m2 * 2 * c.z_i / 3 + 2 * c.z_r * c.z_i / (c.z_r * c.z_r +\
		c.z_i * c.z_i) / (c.z_r * c.z_r + c.z_i * c.z_i) / 3;
		c.z_r = c.z_r2;
		c.z_i = c.z_i2;
		if (c.z_r * c.z_r + c.z_i * c.z_i < (e->xs / WINDOW_SIZE_W))
			i2 = c.i;
		c.i += 1;
	}
	if (i2 == e->iter)
		set_color(1, i2, e, color);
	else
		set_color(2, i2, e, color);
	draw_point(x, y, e, color);
	free(color);
}
