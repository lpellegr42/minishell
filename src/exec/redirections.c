/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:29:12 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:33:18 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	free_and_close(char *line, int fd)
{
	close(fd);
	fd = open(".tmp", O_RDONLY, 0777);
	unlink(".tmp");
	free(line);
	return (fd);
}

int	ft_heredoc(char *delim)
{
	int		fd;
	char	*line;

	fd = open(".tmp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (1)
	{
		line = readline(">");
		if (!line)
		{
			printf("here-document delimited by EOF (wanted '%s')\n", delim);
			return (free_and_close(line, fd));
		}
		if (ft_strcmp(line, delim) == 0)
		{
			return (free_and_close(line, fd));
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

// Reunir ces deux fonctions pour manager les fd.
// all->data->fd

void	ft_handle_out(t_all *all)
{
	int	stdout_cpy;

	stdout_cpy = dup(STDOUT_FILENO);

	if (all->data->fd != -1)
		dup2(all->data->fd, STDOUT_FILENO);
	ft_choose_cmd(all);
	dup2(stdout_cpy, STDOUT_FILENO);
	close(stdout_cpy);
}

void	ft_handle_in(t_all *all)
{

	int	stdin_cpy;

	stdin_cpy = dup(STDIN_FILENO);
	if (all->data->fd != -1)
		dup2(all->data->fd, STDIN_FILENO);
	ft_choose_cmd(all);
	dup2(stdin_cpy, STDIN_FILENO);
	close(stdin_cpy);
}