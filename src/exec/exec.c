//#include "minishell.h"
#include "../../includes/minishell.h"

char	**ft_get_args(char *path, char **arg)
{
	char	**tab;
	int	i;
	int	j;

	tab = malloc(sizeof(char *) * (ft_tab_len(arg) + 2));
	tab[0] = ft_strdup(path);
	i = 0;
	j = 1;
	while (arg && arg[i])
	{
		tab[j] = ft_strdup(arg[i]);
		i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);	
}

void	ft_docmd(t_all *all)
{
	char	*path;
	char	**args;

	pid_t	pid;

	pid = 0;	
	path = ft_getpath(all->data->cmd, all->env_cpy);
	if (!path)
	{
		printf("-Minishell: %s: ", all->data->cmd);
		ft_display_err("No such file or directory\n", all, 127);
		return ;
	}
	args = ft_get_args(path, all->data->arg);
	// printf("%s, %s\n", args[0], args[1]);
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
		waitpid(pid, &all->err, 0);
	free(path);
	ft_free_tab(args);
}

void	ft_exec(t_all *all)
{
	if (all->data->next == NULL)
		ft_builtins(all);
	data_clear(all);
	// else
	// 	ft_do_pipe(all);
}

// Comprendre les forks
// Apprendre la différence entre parents et enfants 
// Parser la variable PATH
// Dans execve : /usr/bin/<cmd>, cmd, envp
// Voilà bisous 
// Faire vite très vite très très vite 