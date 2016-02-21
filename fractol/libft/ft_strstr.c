/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:04:13 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/02 16:21:49 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s2[0])
		return ((char *)(s1));
	while (s1[i] != '\0')
	{
		j = i;
		while (s1[j] == s2[k])
		{
			k++;
			if (!s2[k])
				return ((char *)(&s1[i]));
			j++;
		}
		k = 0;
		i++;
	}
	return (NULL);
}
