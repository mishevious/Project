/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 22:31:35 by gmarguer          #+#    #+#             */
/*   Updated: 2016/02/21 14:48:56 by gmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_end_line(char *tmp2, char *tmp)
{
	if (!tmp2)
		return (0);
	*tmp2 = '\0';
	tmp2++;
	ft_strcpy(tmp, tmp2);
	ft_memset(tmp2, 0, ft_strlen(tmp2));
	return (1);
}

char	*ft_strjoin_free(char **line, char *buf)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
	return (*line);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	int			end;
	char		buf[BUFF_SIZE + 1];
	char		*tmp2;
	static char tmp[2147483648][BUFF_SIZE];

	end = 0;
	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!(*line = *tmp[fd] ? ft_strdup(tmp[fd]) : ft_strnew(1)))
		return (-1);
	while (!(tmp2 = ft_strchr(*line, '\n')) &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (buf[ret] == '\0')
			end = 1;
		buf[ret] = '\0';
		if (!(*line = ft_strjoin_free(line, buf)))
			return (-1);
	}
	if (ft_end_line(tmp2, tmp[fd]) == 1 || end == 1 || ret > 0)
		return (1);
	return (ret == 0 ? 0 : -1);
}
