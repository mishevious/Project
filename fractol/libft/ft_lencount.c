/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lencount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:01:04 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/04 18:54:44 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lencount(char const *s, int index, char c)
{
	int		i;

	i = 0;
	while (s[index] != '\0' && s[index] != c)
	{
		index++;
		i++;
	}
	return (i);
}