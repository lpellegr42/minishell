/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:54:27 by lpellegr          #+#    #+#             */
/*   Updated: 2024/06/28 17:30:25 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argument_error(void)
{
	ft_putstr_fd("error: use pipex program as follow:\n\n", 2);
	ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n\n", 2);
	ft_putstr_fd("or\n\n", 2);
	ft_putstr_fd("./pipex infile cmd1 cmd2 ... cmdN outfile\n\n", 2);
	ft_putstr_fd("or\n\n", 2);
	ft_putstr_fd("./pipex here_doc LIMITER cmd1 cmd2 outfile\n", 2);
	exit(EXIT_FAILURE);
}

void	error_handler(char *error_msg)
{
	ft_putstr_fd(error_msg, 2);
	exit(EXIT_FAILURE);
}

void	free_arrays(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
