/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:49:42 by gmarguer          #+#    #+#             */
/*   Updated: 2015/12/04 17:50:06 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(*dst) * (ft_strlen(s1) + 1))))
		return (NULL);
	return (ft_strcpy(dst, s1));
}
