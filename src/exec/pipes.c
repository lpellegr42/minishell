/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:29:06 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:29:07 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	perror_and_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

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

void	handle_parent_process(int *input_fd, int pipe_fd[2])
{
	close(pipe_fd[1]);
	if (*input_fd != 0)
		close(*input_fd);
	*input_fd = pipe_fd[0];
}

void	wait_for_children(t_all *all)
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			all->err = WEXITSTATUS(status);
	}
}

void	initialize_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		perror_and_exit("Pipe error");
}

void	ft_do_pipe(t_all *all)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		input_fd;

	input_fd = 0;
	while (all->data)
	{
		initialize_pipe(pipe_fd);
		pid = create_child_process();
		if (pid == 0)
			handle_child_process(all, input_fd, pipe_fd);
		else
		{
			handle_parent_process(&input_fd, pipe_fd);
			if (!all->data->next)
			{
				close(pipe_fd[0]);
				break;
			}
			all->data = all->data->next;
		}
	}
	wait_for_children(all);
}
