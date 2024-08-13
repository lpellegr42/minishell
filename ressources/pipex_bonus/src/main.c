/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:30:05 by lpellegr          #+#    #+#             */
/*   Updated: 2024/08/07 16:28:45 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_pipe(char *cmd, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error_handler("pipe");
	pid = fork();
	if (pid == -1)
		error_handler("fork");
	if (pid == 0) //child process
	{
		dup2(pipe_fd[1], STDOUT_FILENO); //dup2 va copier 
		close(pipe_fd[0]);
		exec(cmd, envp);
	}
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[1]);
		wait(NULL);
	}
}

char	*dup_limiter(char *limiter)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(limiter) + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (limiter[i])
	{
		res[i] = limiter[i];
		i++;
	}
	res[i] = '\n';
	i++;
	res[i] = '\0';
	return (res);
}

void	here_doc_input(char **argv, int *pipe_fd)
{
	char	*line;
	char	*limiter;

	close(pipe_fd[0]);
	limiter = dup_limiter(argv[2]);
	while (1)
	{
		line = get_next_line(0);
		if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
		{
			free(line);
			free(limiter);
			close(pipe_fd[1]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, pipe_fd[1]);
		free(line);
	}
}

void	here_doc(char **argv)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		error_handler("pipe");
	pid = fork();
	if (pid == -1)
		error_handler("fork");
	if (!pid)
		here_doc_input(argv, pipe_fd);
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[1]);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_in;
	int		fd_out;
	int		parsing_flag;
	int		starting_arg;

	parsing_flag = parsing(argc, argv);
	if (parsing_flag == 2)
	{
		starting_arg = 3;
		fd_out = open_file(argv[argc - 1], 2);
		here_doc(argv);
	}
	else if (parsing_flag == 1)
	{
		starting_arg = 2;
		fd_in = open_file(argv[1], 0);
		fd_out = open_file(argv[argc - 1], 1);
		dup2(fd_in, 0);
	}
	while (starting_arg < (argc - 2))
		do_pipe(argv[starting_arg++], envp);
	dup2(fd_out, STDOUT_FILENO);
	exec(argv[argc - 2], envp);
	return (0);
}

wait(NULL)