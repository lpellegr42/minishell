//#include "minishell.h"
#include "../../includes/minishell.h"

/* @brief testouille ma couille
 * @return str mon pepere
*/
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
	// else
	// 	ft_exec(all);
}
