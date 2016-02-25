/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:31:29 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/02 15:57:57 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if ((s1[i] == '\0' && s2[i] == '\0') || n == 0)
		return (0);
	while (i < n)
	{
		if (s2[i] == '\0' || s1[i] == '\0' || s2[i] != s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
