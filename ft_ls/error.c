/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 05:26:33 by maboukra          #+#    #+#             */
/*   Updated: 2016/02/23 22:29:19 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		error_param(int type, int ex)
{
	if (type == 1)
	{
		ft_putstr_fd("\033[0musage: ./ft_ls \033[32m[-Ratrl]\
\033[0m [file ...]\n", 2);
	}
	else if (type == 2)
		ft_putstr_fd("Malloc error.\n", 2);
	else if (type == 3)
	{	
		perror(0);
		// ft_putstr_fd("\033[31mft_ls: ", 2);
		// ft_putstr_fd(NOM DU DOSSIER INEXISTANT, 2);
		// ft_putstr_fd("No such file or directory\033[0m\n", 2);
	}
	if (ex == 1)
		exit(EXIT_SUCCESS);
}

void		error_path(int ex, char *str)
{
	ft_putstr_fd("\033[31mft_ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	perror(0);	
	ft_putstr_fd("\033[0m", 2);
	if (ex == 1)
		exit(EXIT_SUCCESS);
}
