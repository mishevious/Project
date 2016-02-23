/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:22:37 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/20 18:29:20 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_windows(char *title, int width, int height, t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, width, height, title);
}

int		key_hook2(int keycode, t_env *e)
{
	if (keycode == 53)
		mlx_destroy_window(e->mlx, e->win);
	return (1);
}

void	ft_option(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 700, 450, "OPTIONS FRACTOL");
	mlx_hook(e.win, 2, 1, key_hook2, &e);
	mlx_string_put(e.mlx, e.win, 100, 30,
			0xFF0000, "Les options de \"FRACTOL\" :");
	mlx_string_put(e.mlx, e.win, 100, 100,
			0x00FF00, "- UP/DOWN/LEFT/RIGHT => Deplacements");
	mlx_string_put(e.mlx, e.win, 100, 150,
			0x00F0F0, "-   1, 2, 3, 4, 5    => Palette de couleur");
	mlx_string_put(e.mlx, e.win, 100, 200,
			0xF0F000, "-         =          => Changer l'elipse");
	mlx_string_put(e.mlx, e.win, 100, 250,
			0xF000F0, "-  RIGHT/LEFT CLIC   => DEZOOM/ZOOM");
	mlx_string_put(e.mlx, e.win, 100, 300,
			0x0000FF, "-    enter(pavnum)   => RESET ALL");
	mlx_string_put(e.mlx, e.win, 100, 350,
			0xFFFFFF, "-      return        => Deformation ON/OFF");
	mlx_string_put(e.mlx, e.win, 100, 350,
			0xFFFFFF, "-        +/-         => Iteration");
	mlx_loop(e.mlx);
}

void	draw_point(int x, int y, t_env *e, t_color *c)
{
	int i;

	i = (x * 4) + (y * WINDOW_SIZE_W * 4);
	if (i >= 0 && i < WINDOW_SIZE_W * WINDOW_SIZE_H * 4
		&& i < (y + 1) * WINDOW_SIZE_W * 4)
	{
		if (e->col == 1)
		{
			e->pimg[i] = ((int)(c->b * 256) % 256);
			e->pimg[++i] = ((int)(c->g * 256) % 256);
			e->pimg[++i] = ((int)(c->r * 256) % 256);
		}
		else if (e->col == 2)
		{
			e->pimg[i] = c->b;
			e->pimg[++i] = c->g;
			e->pimg[++i] = c->r;
		}
	}
}
