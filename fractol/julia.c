/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:18:11 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/23 22:23:31 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_julia(t_env *e)
{
	e->col = 1;
	e->pal = 1;
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2;
	e->y2 = 2;
	e->ys = 0.0;
	e->m = 1.0;
	e->xs = 0.0;
	e->def = 0;
	e->ftype = 2;
	e->iter = ITERMAX * 2;
	return (1);
}

void	julia(t_env *e, t_calc c, int x, int y)
{
	t_color *color;
	double	tmp;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		error_param(2, 1);
	c.i = 0;
	while (c.z_r * c.z_r + c.z_i * c.z_i <= 4.0 && c.i < e->iter)
	{
		tmp = c.z_r * e->m;
		c.z_r = c.z_r * c.z_r - c.z_i * c.z_i + e->xs * e->m;
		c.z_i = 2.0 * tmp * c.z_i + e->ys * e->m;
		c.i += 1;
	}
	if (c.i == e->iter)
		set_color(1, c.i, e, color);
	else
		set_color(2, c.i, e, color);
	draw_point(x, y, e, color);
	free(color);
}
