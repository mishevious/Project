/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:50:58 by gmarguer          #+#    #+#             */
/*   Updated: 2015/11/25 16:57:50 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!s2[0])
		return ((char *)(s1));
	while (i < n && s1[i] != '\0')
	{
		j = i;
		k = 0;
		while (s1[j] == s2[k] && j < n)
		{
			k++;
			if (s2[k] == '\0')
				return ((char *)(&s1[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
