/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:58:55 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/02 16:26:34 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char *)s);
	while (i >= 0 && s[i] != (char)c)
		i--;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
