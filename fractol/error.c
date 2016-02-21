/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:22:44 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/20 19:43:13 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		ft_abs_double(double n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

double		d_power(double nb, int power)
{
	int		i;
	double	ret;

	if (power == 0)
		return (1);
	i = 1;
	ret = nb;
	while (i != power)
	{
		ret *= nb;
		i++;
	}
	return (ret);
}

int			ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void		leave(void)
{
	exit(EXIT_SUCCESS);
}

void		error_param(int type, int ex)
{
	if (type == 1)
	{
		ft_putstr_fd("________________________________\n", 2);
		ft_putstr_fd("|\033[31m-\033[0m usage: fractol \033[32mitem1 item2\
\033[0m  |\n", 2);
		ft_putstr_fd("|______________________________|\n", 2);
		ft_putstr_fd("|\033[32mitems\
\033[0m :                       |\n", 2);
		ft_putstr_fd("|	\033[32mM\033[0m 	\033[36m(Mandelbrot)\
\033[0m   |\n", 2);
		ft_putstr_fd("|	\033[32mJ\033[0m 	\033[36m(Julia)\
\033[0m        |\n", 2);
		ft_putstr_fd("|	\033[32mA\033[0m 	\033[36m(Ark Ship)\
\033[0m     |\n", 2);
		ft_putstr_fd("|	\033[32mN\033[0m 	\033[36m(Newton)\
\033[0m       |\n", 2);
		ft_putstr_fd("|______________________________|\n", 2);
	}
	else if (type == 2)
		ft_putstr_fd("Malloc error.\n", 2);
	if (ex == 1)
		exit(EXIT_SUCCESS);
}
