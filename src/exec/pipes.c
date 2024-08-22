//#include "minishell.h"
#include "../../includes/minishell.h"

void	perror_and_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	create_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		perror_and_exit("Pipe error");
}

pid_t	create_child_process(void)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		perror_and_exit("Fork error");
	return (pid);
}

void	execute_child_process(t_all *all, int input_fd, int pipe_fd[2])
{
	dup2(input_fd, STDIN_FILENO);
	if (all->data->next != NULL)
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	ft_choose_cmd(all);
	exit(all->err);
}

void	handle_parent_process(t_all *all, int pipe_fd[2], int *input_fd, pid_t pid)
{
	int status;

	waitpid(pid, &status, 0);
	all->err = (status >> 8);
	close(pipe_fd[1]);
	*input_fd = pipe_fd[0];
}

void	ft_do_pipe(t_all *all)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		input_fd;

	input_fd = 0;
	while (all->data)
	{
		create_pipe(pipe_fd);
		pid = create_child_process();
		if (pid == 0)
			execute_child_process(all, input_fd, pipe_fd);
		else
		{
			handle_parent_process(all, pipe_fd, &input_fd, pid);
			if (!all->data->next)
			{
				close(pipe_fd[0]);
				return ;
			}
			all->data = all->data->next;
		}
	}
}
