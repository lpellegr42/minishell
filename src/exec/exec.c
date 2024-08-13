//#include "minishell.h"
#include "../../includes/minishell.h"

// void	ft_exec(t_all *all)
// {
// 	t_data	*tmp_d;

// 	tmp_d = all->data;
// 	if (all->data->here_doc)
// 	{
// 		printf("heredoc");
// 		return ;
// 	}
// 	// while (tmp->d)
// }

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
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, &all->err, 0);

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