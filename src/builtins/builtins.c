//#include "minishell.h"
#include "../../includes/minishell.h"

/* @brief testouille ma couille
 * @return str mon pepere
*/
void	ft_builtins(t_all *all)
{
	if (ft_strncmp(all->data->cmd, "env", 3) == 0)
		ft_env(all->env);
	else if (ft_strncmp(all->data->cmd, "unset", ft_strlen(all->data->cmd)) == 0)
		ft_unset(all->data, all->env);
	else if(ft_strncmp(all->data->cmd, "export", ft_strlen(all->data->cmd)) == 0)
		ft_export(all);
	else if (ft_strncmp(all->data->cmd, "echo", ft_strlen(all->data->cmd)) == 0)
		ft_echo(all);
	else if (ft_strncmp(all->data->cmd, "pwd", ft_strlen(all->data->cmd)) == 0)
		ft_pwd(all);
	else if (ft_strncmp(all->data->cmd, "cd", ft_strlen(all->data->cmd)) == 0)
		ft_cd(all);
	else if (ft_strncmp(all->data->cmd, "exit", ft_strlen(all->data->cmd)) == 0)
		ft_exit(all);
}
