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

	path = ft_getpath(all->data->cmd, all->env_cpy);
	if (execve(path, all->data->arg, all->env_cpy) == -1)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}

}

void	ft_exec(t_all *all)
{
	pid_t	pid;
	int		pipe_fd[2];

	pid = 0;
	if (pipe(pipe_fd) == -1)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		ft_docmd(all);
	else
		wait(NULL);
}


// Comprendre les forks
// Apprendre la différence entre parents et enfants 
// Parser la variable PATH
// Dans execve : /usr/bin/<cmd>, cmd, envp
// Voilà bisous 
// Faire vite très vite très très vite 