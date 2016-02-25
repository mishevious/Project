/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:15:36 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/02 17:19:18 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		output;
	int		sign;

	output = 0;
	sign = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\v' || *str == '\f')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			output = output * 10 + *str - '0';
		if (*str >= '0' && *str <= '9')
			sign = sign ? sign : 1;
		else if (*str == '-' && !sign)
			sign = -1;
		else if (*str == '+' && !sign)
			sign = 1;
		else if (output || sign || (*str < '0'
					|| *str > '9'))
			break ;
		str++;
	}
	return (output * sign);
}
