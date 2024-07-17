#include "minishell.h"

void	ft_env(t_env *env)
{
	while (env)
	{
		if (env->set == 1)
			printf("%s=%s\n", env->key, env->val);
		env = env->next;
	}
}

// void	ft_export(t_env *env)
// {

// }

void	ft_builtins(t_data *data, t_env *env)
{
	if (ft_strncmp(data->cmd, "env", 3) == 0)
		ft_env(env);
}
