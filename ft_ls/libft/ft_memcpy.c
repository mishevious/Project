/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:24:15 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/04 18:45:24 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str1;
	char	*str2;
	int		i;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	str1 = (char *)dst;
	str2 = (char *)src;
	while (n)
	{
		str1[i] = str2[i];
		i++;
		n--;
	}
	return (dst);
}
