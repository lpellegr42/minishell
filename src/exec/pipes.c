//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_handle_fd(t_all *all, int *fd)
{
	if (all->data->next == NULL)
		dup2(all->data->fd_out, 1);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
}

void	ft_do_pipe(t_all *all)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], all->data->fd_out);
		close(fd[1]);
		ft_choose_cmd(all);
	}
	else
	{
		waitpid(pid, &all->err, 0);
		ft_handle_fd(all, fd);
		if (all->data->next == NULL)
		{
			all->data = all->data->next;
			ft_builtins(all);
		}
		else
			ft_do_pipe(all);
	}
}
