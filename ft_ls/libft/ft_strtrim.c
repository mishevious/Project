/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:47:33 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/04 17:21:12 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i < j / 2)
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '\0')
			&& j > 0 && j >= i)
		j--;
	if (!(temp = ft_strnew(j - i + 1)))
		return (NULL);
	while (i <= j)
	{
		temp[k] = s[i];
		i++;
		k++;
	}
	temp[k] = '\0';
	return (temp);
}
