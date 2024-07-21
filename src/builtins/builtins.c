//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_builtins(t_data *data, t_env *env)
{
	if (ft_strncmp(data->cmd, "env", 3) == 0)
		ft_env(env);
	else if (ft_strncmp(data->cmd, "unset", 5) == 0)
		ft_unset(data, env);
	else if(ft_strncmp(data->cmd, "export", 6) == 0)
		ft_export(data, env);
}
