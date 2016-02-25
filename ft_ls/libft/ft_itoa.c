/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:20:12 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/05 18:10:37 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		div;
	int		sign;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strintmin());
	sign = n < 0 ? 1 : 0;
	n = n < 0 ? n * -1 : n;
	div = ft_power(10, ft_intcount(n));
	if (!(str = ft_strnew(ft_intcount(n) + sign)))
		return (NULL);
	if (sign == 1)
		str[i++] = '-';
	while (div >= 1)
	{
		str[i] = n / div + 48;
		n = n % div;
		div = div / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
