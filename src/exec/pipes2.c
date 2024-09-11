/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:55:19 by lpellegr          #+#    #+#             */
/*   Updated: 2024/09/11 20:58:55 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

pid_t	create_child_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror_and_exit("Fork error");
	return (pid);
}

void	handle_child_process(t_all *all, int input_fd, int pipe_fd[2])
{
	if (all->data->next != NULL)
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			perror_and_exit("dup2 error");
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (dup2(input_fd, STDIN_FILENO) == -1)
		perror_and_exit("dup2 error");
	if (input_fd != 0)
		close(input_fd);
	if (all->data->fd != -1 && all->data->flag_redir != -1)
	{
		if (all->data->flag_redir == 0)
			ft_handle_in(all);
		else if (all->data->flag_redir == 1)
			ft_handle_out(all);
	}
	else
		ft_choose_cmd(all);
	exit(all->err);
}
