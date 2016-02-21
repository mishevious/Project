/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:04:53 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/13 12:51:06 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strsub(char *s, unsigned int start, int len)
{
	char	*buf;
	int		count;

	count = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if ((buf = (char *)malloc(sizeof(*buf) * (len + 1))) == NULL)
		return (NULL);
	{
		while (count < len && s[start] != '\0')
		{
			buf[count] = s[start];
			start++;
			count++;
		}
		buf[count] = '\0';
	}
	return (char *)(buf);
}
