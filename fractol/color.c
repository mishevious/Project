/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:54:46 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/20 18:30:09 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_redblue(t_color *c, int i, t_env *e)
{
	if (e->pal == 3)
	{
		c->r = 0.5 + 0.5 * cos(3.0 + i * 0.15 + 1);
		c->g = 0.5 + 0.5 * cos(3.0 + i * 0.15);
		c->b = 0.5 + 0.5 * cos(3.0 + i * 0.15);
	}
	else if (e->pal == 1)
	{
		c->r = 0.5 + 0.5 * cos(3.0 + i * 0.15);
		c->g = 0.5 + 0.5 * cos(3.0 + i * 0.15);
		c->b = 0.5 + 0.5 * cos(3.0 + i * 0.15 + 1);
	}
}

void	set_mix1(t_color *c, int i, t_env *e)
{
	if (e->pal == 4)
	{
		c->r = 0.5 + 0.5 * cos(3.0 + i * 0.15 + 1);
		c->g = 0.5 + 0.5 * cos(3.0 + i * 0.15 + 0.5);
		c->b = 0.5 + 0.5 * cos(3.0 + i * 0.15);
	}
	else if (e->pal == 5)
	{
		c->r = 0.5 + 0.5 * cos(3.0 + i * 0.15);
		c->g = 0.5 + 0.5 * cos(3.0 + i * 0.15);
		c->b = 0.5 + 0.5 * cos(3.0 + i * 0.15);
	}
	else if (e->pal == 6)
	{
		c->r = 0.5 + 0.5 * cos(3.0 + i * 0.15 + 1);
		c->g = 0.5 + 0.5 * cos(3.0 + i * 0.15 + 1);
		c->b = 0.5 + 0.5 * cos(3.0 + i * 0.15 + 1);
	}
}

void	epilep(t_color *c, int i, t_env *e, int nb)
{
	if (nb == 2)
	{
		c->r = e->pal == 3 ? (int)(i * 2.5) % 256 : 0;
		c->g = e->pal == 2 ? (int)(i * 2.5) % 256 : 0;
		c->b = e->pal == 1 ? (int)(i * 2.5) % 256 : 0;
		if (e->pal > 3)
		{
			c->r = (int)(i * 2.5) % 256;
			c->g = (int)(i * 2.5) % 256;
			c->b = (int)(i * 2.5) % 256;
		}
	}
}

void	mid(t_env *e, t_color *c)
{
	if (e->col == 1)
	{
		c->r = 0;
		c->g = 0;
		c->b = 0;
	}
	else if (e->col == 2 && e->pal > 3)
	{
		c->r = 255;
		c->g = 255;
		c->b = 255;
	}
	else if (e->col == 2)
	{
		c->r = 0;
		c->g = 0;
		c->b = 0;
	}
}

void	set_color(int nb, int i, t_env *e, t_color *c)
{
	if (nb == 1)
		mid(e, c);
	else if (e->col == 2)
		epilep(c, i, e, nb);
	else if (nb == 2 && (e->pal == 4 || e->pal == 5 || e->pal == 6))
		set_mix1(c, i, e);
	else if (nb == 2 && (e->pal == 3 || e->pal == 1))
		set_redblue(c, i, e);
	else if (nb == 2 && e->pal == 2)
	{
		c->r = 0.5 + 0.5 * cos(3.0 + i * 0.15);
		c->g = 0.5 + 0.5 * cos(3.0 + i * 0.15 + 1);
		c->b = 0.5 + 0.5 * cos(3.0 + i * 0.15);
	}
}
