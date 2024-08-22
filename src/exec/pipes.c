//#include "minishell.h"
#include "../../includes/minishell.h"

// void	ft_handle_fd(t_all *all, int *fd)
// {
// 	if (all->data->next == NULL)
// 		dup2(all->data->fd_out, 1);
// 	close(fd[1]);
// 	dup2(fd[0], 0);
// 	close(fd[0]);
// }

// void	ft_do_pipe(t_all *all)
// {
// 	int		fd[2];
// 	pid_t	pid;


// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], all->data->fd_out);
// 		close(fd[1]);
// 		ft_choose_cmd(all);
// 	}
// 	else
// 	{
// 		wait(NULL);
// 		//waitpid(pid, &all->err, 0);
// 		ft_handle_fd(all, fd);
// 		if (all->data->next == NULL)
// 		{
// 			all->data = all->data->next;
// 			ft_builtins(all);
// 		}
// 		else
// 			ft_do_pipe(all);
// 	}
// }

void	ft_do_pipe(t_all *all)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		input_fd;
	t_data	*tmp;
	int		status;

	input_fd = 0;
	tmp = all->data;
	status = 0;
	while (all->data)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("Pipe error");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Fork error");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			dup2(input_fd, STDIN_FILENO);
			if (all->data->next != NULL)
				dup2(pipe_fd[1], STDOUT_FILENO);
			close(pipe_fd[0]);
			ft_choose_cmd(all);
			exit(all->err); // remplacer par code d'erreur type : "execve error" ou something like that.
		}
		else
		{
			waitpid(pid, &status, 0);
			all->err = (status >> 8);
			close(pipe_fd[1]);
			input_fd = pipe_fd[0];
			if (!all->data->next)
			{
				close(pipe_fd[0]);
				all->data = tmp;
				return ;
			}
			all->data = all->data->next;
		}
	}
}