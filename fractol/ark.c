/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:18:11 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/20 18:29:45 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_ark(t_env *e)
{
	e->col = 1;
	e->pal = 1;
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2;
	e->y2 = 2;
	e->ys = 0.0;
	e->xs = 0.0;
	e->def = 0;
	e->ftype = 3;
	e->iter = ITERMAX / 2;
}

void	ark(t_env *e, t_calc c, int x, int y)
{
	t_color *color;
	double	tmp;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		error_param(2, 1);
	c.z_r = ft_abs_double(c.z_r2);
	c.z_i = ft_abs_double(c.z_i2);
	c.i = 0;
	while (c.z_r * c.z_r + c.z_i * c.z_i <= 4.0 && c.i < e->iter)
	{
		tmp = c.z_r;
		c.z_r = ft_abs_double(c.z_r) * ft_abs_double(c.z_r)
			- ft_abs_double(c.z_i) * ft_abs_double(c.z_i) + c.z_r2;
		c.z_i = 2 * ft_abs_double(tmp) * ft_abs_double(c.z_i) + c.z_i2;
		c.i++;
	}
	if (c.i == e->iter)
		set_color(1, c.i, e, color);
	else
		set_color(2, c.i, e, color);
	draw_point(x, y, e, color);
	free(color);
}
