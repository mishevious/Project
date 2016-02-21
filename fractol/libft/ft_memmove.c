/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:39:35 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/04 15:01:07 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	if (!(temp = (unsigned char*)malloc(sizeof(*temp) * len)))
		return (NULL);
	while (i < len)
	{
		temp[i] = ((unsigned char*)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((unsigned char*)dst)[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
