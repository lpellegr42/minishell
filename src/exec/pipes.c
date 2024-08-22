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
	int fd[2];
	pid_t	pid;
	int prev_fd;
	t_data	*tmp;

	prev_fd = 0;
	tmp = all->data;
	while (all->data)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(prev_fd, 0);
			if (all->data->next != NULL)
			{
				dup2(fd[1], 1);
			}
			close(fd[0]);
			ft_choose_cmd(all);
			exit(all->err); // remplacer par code d'erreur type : "execve error" ou something like that.
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			prev_fd = fd[0];
			if (all->data->next)
				all->data = all->data->next;
			else
			{
				all->data = tmp;
				return ;
			}
		}
	}
}