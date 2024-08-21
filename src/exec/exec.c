//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_exec_cmd(char *path, char **args, t_all *all)
{
	int		ret;
	pid_t	pid;

	pid = 0;
	ret = 0;
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, all->env_cpy) == -1)
		{
			printf("-Minishell: %s: ", all->data->cmd);
			ft_display_err("command not found\n", all, 127);
			exit(all->err);
		}
	}
	else
	{
		waitpid(pid, &ret, 0);
		all->err = (ret >> 8);
	}
}

void	ft_docmd(t_all *all)
{
	char	*path;
	char	**args;

	path = ft_getpath(all->data->cmd, all->env_cpy);
	if (!path)
	{
		printf("-Minishell: %s: ", all->data->cmd);
		ft_display_err("Command not found\n", all, 127);
		return ;
	}
	args = ft_get_args(path, all->data->arg);
	ft_exec_cmd(path, args, all);
	free(path);
	ft_free_tab(args);
}

void	ft_exec(t_all *all)
{

	ft_reset_env(all);
	// printf("test %p\n", all->data->cmd);
	if (!all->data->cmd)
		return ;
	if (all->data->cmd != NULL && all->data->next == NULL)
	{
		ft_choose_cmd(all);
	}
	// else
	// 	ft_do_pipe(all);
	// printf("test\n");
	if (all->data->cmd != NULL)
	{
		ft_free_data(all->data);
	}

}
