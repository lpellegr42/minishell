//#include "minishell.h"
#include "../../includes/minishell.h"

int	ft_is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else
		return (0);
}

/* @brief Runs the correct builtin or exec
 * @return Nothing
*/
void	ft_choose_cmd(t_all *all)
{
	if (ft_is_builtin(all->data->cmd))
		ft_builtins(all);
	else
		ft_docmd(all);
}

void	ft_builtins(t_all *all)
{
	if (ft_strncmp(all->data->cmd, "env", 3) == 0)
		ft_env(all->env);
	else if (ft_strncmp(all->data->cmd, "unset", 5) == 0)
		ft_unset(all->data, all->env);
	else if (ft_strncmp(all->data->cmd, "export", 6) == 0)
		ft_export(all);
	else if (ft_strncmp(all->data->cmd, "echo", 4) == 0)
		ft_echo(all);
	else if (ft_strncmp(all->data->cmd, "pwd", 3) == 0)
		ft_pwd(all);
	else if (ft_strncmp(all->data->cmd, "cd", 2) == 0)
		ft_cd(all);
	else if (ft_strncmp(all->data->cmd, "exit", 4) == 0)
		ft_exit(all);
	all->err = 0;
}

// free de la struct avant execve.
// copie des data needed dans un malloc. 