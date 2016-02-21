/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:16:25 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/04 22:22:29 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**t;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(t = (char**)malloc(sizeof(char*) * (ft_strcount(s, c) + 1))))
		return (NULL);
	while (i < ft_strcount(s, c))
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		t[i] = ft_strsub(s, k, ft_lencount(s, k, c));
		k = k + ft_lencount(s, k, c);
		i++;
	}
	t[i] = NULL;
	return (t);
}
