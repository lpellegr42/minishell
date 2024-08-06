/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:21:34 by lpellegr          #+#    #+#             */
/*   Updated: 2024/06/28 19:49:33 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(int argc, char **argv)
{
	int	is_here_doc;
	int	parsing_flag;

	if (argc < 5)
	{
		argument_error();
		exit(EXIT_FAILURE);
	}
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
		is_here_doc = 1;
	else
		is_here_doc = 0;
	parsing_flag = argument_checking(argc, is_here_doc);
	if (!parsing_flag)
		exit(EXIT_FAILURE);
	return (parsing_flag);
}

int	argument_checking(int argc, int is_here_doc)
{
	if ((!is_here_doc && argc < 5) || (is_here_doc && argc < 6))
	{
		argument_error();
		exit(EXIT_FAILURE);
	}
	if (is_here_doc == 1)
		return (2);
	return (1);
}
