//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_builtins(t_data *data, t_env *env)
{
	if (ft_strncmp(data->cmd, "env", 3) == 0)
		ft_env(env);
	else if (ft_strncmp(data->cmd, "unset", ft_strlen(data->cmd)) == 0)
		ft_unset(data, env);
	else if(ft_strncmp(data->cmd, "export", ft_strlen(data->cmd)) == 0)
		ft_export(data, env);
	else if (ft_strncmp(data->cmd, "echo", ft_strlen(data->cmd)) == 0)
		ft_echo(data);
	else if (ft_strncmp(data->cmd, "pwd", ft_strlen(data->cmd)) == 0)
		ft_pwd(env);
	else if (ft_strncmp(data->cmd, "cd", ft_strlen(data->cmd)) == 0)
		ft_cd(data, env);
	else if (ft_strncmp(data->cmd, "exit", ft_strlen(data->cmd)) == 0)
		ft_exit(data, env);
}
