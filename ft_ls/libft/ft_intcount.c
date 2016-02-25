/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:30:27 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/04 17:13:36 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intcount(int n)
{
	int		i;
	int		m;

	i = 0;
	m = 1;
	if (n == -2147483648 || n == 2147483647)
		return (10);
	if (n < 0)
		n = n * -1;
	while (n / m >= 1)
	{
		m = m * 10;
		i++;
	}
	if (n >= 0 && n < 10)
		i = 1;
	if (i > 10)
		return (10);
	return (i);
}