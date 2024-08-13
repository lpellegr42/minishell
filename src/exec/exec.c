//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_docmd(t_all *all)
{
	char	*path;
	int		pid;

	pid = 0;	
	path = ft_getpath(all->data->cmd, all->env_cpy);
	if (!path)
	{
		red();
		printf("-Minishell: %s: ", all->data->cmd);
		ft_display_err("No such file or directory\n", all, 127);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, all->data->arg, all->env_cpy) == -1)
		{
			red();
			printf("-Minishell: %s: ", all->data->cmd);
			ft_display_err("command not found\n", all, 127);
			exit(all->err);
		}
	}
	else
		waitpid(pid, &all->err, 0);
	free(path);
}

void	ft_exec(t_all *all)
{
	// int	pid;

	// pid = 0;
	if (all->data->next == NULL)
		ft_builtins(all);
	// else
	// {
	// 	while (all->data)
	// 	{

	// 	}
	// }
}


// Comprendre les forks
// Apprendre la différence entre parents et enfants 
// Parser la variable PATH
// Dans execve : /usr/bin/<cmd>, cmd, envp
// Voilà bisous 
// Faire vite très vite très très vite 