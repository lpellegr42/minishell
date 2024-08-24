//#include "minishell.h"
#include "../../includes/minishell.h"

void	perror_and_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

pid_t	create_child_process(void)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		perror_and_exit("Fork error");
	return (pid);
}

void	child_process_exec(t_all *all, int input_fd, int *pipe_fd)
{

	if (all->data->next != NULL)
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	dup2(input_fd, STDIN_FILENO);
	close(pipe_fd[0]);
	ft_choose_cmd(all);
	exit(all->err);
}

void	parent_process(t_all *all, int pipe_fd[2], int *input_fd, pid_t pid)
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
		if (pipe(pipe_fd) == -1)
			perror_and_exit("Pipe error");
		pid = create_child_process();
		if (pid == 0)
			child_process_exec(all, input_fd, pipe_fd);
			//free_funct_there ?
		else
		{
			parent_process(all, pipe_fd, &input_fd, pid);
			if (!all->data->next)
			{
				close(pipe_fd[0]);
				return ;
			}
			all->data = all->data->next;
		}
	}
}
