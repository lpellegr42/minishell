//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	// while (data)
	// {
		if (data->arg)
		{
			while (data->arg[i])
			{
				free(data->arg[i]);
				i++;
			}
			free (data->arg);
		}
		if (data->cmd)
			free(data->cmd);
		if (data->here_doc)
			free(data->here_doc);
		free(data);
		// data = data->next;
	// }
}

void	ft_free_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		tmp = tmp->next;
		if (env->key)
			free(env->key);
		// printf("test : %s\n", env->val);
		if (env->val)
			free(env->val);
		free(env);
		env = tmp;
	}
}

void	ft_exit(t_data *data, t_env *env)
{
	if (data)
		ft_free_data(data);
	if (env)
		ft_free_env(env);
	rl_clear_history();
	exit(EXIT_SUCCESS);
}