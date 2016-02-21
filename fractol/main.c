/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:17:39 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/20 19:44:12 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_param(char *av, t_env *e)
{
	if ((av[0] != 'M' && av[0] != 'J' && av[0] != 'A' && av[0] != 'N') || av[1])
		error_param(1, 1);
	if (av[0] == 'M')
		init_mandelbrot(e);
	if (av[0] == 'J')
		init_julia(e);
	if (av[0] == 'A')
		init_ark(e);
	if (av[0] == 'N')
		init_newton(e);
}

int			expose_hook(t_env *e)
{
	reload(e);
	return (0);
}

void		new_window(t_env *e2)
{
	draw_windows("FRACTOL MISHE 2", WINDOW_SIZE_W, WINDOW_SIZE_H, e2);
	mlx_mouse_hook(e2->win, mouse, e2);
	mlx_hook(e2->win, 6, 64, &mouse2, e2);
	mlx_hook(e2->win, 2, 3, key_hook, e2);
	mlx_expose_hook(e2->win, expose_hook, e2);
	mlx_loop(e2->mlx);
}

void		fractol(char **av, int ac)
{
	t_env	e;
	t_env	e2;

	if (ac == 3)
	{
		check_param(av[2], &e2);
		e.e2 = &e2;
		e.param = 2;
		ac = 2;
	}
	check_param(av[1], &e);
	draw_windows("FRACTOL MISHE 1", WINDOW_SIZE_W, WINDOW_SIZE_H, &e);
	mlx_hook(e.win, 6, 64, &mouse2, &e);
	mlx_mouse_hook(e.win, mouse, &e);
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}

int			main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 2 || ac > 3)
		error_param(1, 1);
	fractol(av, ac);
	return (0);
}
