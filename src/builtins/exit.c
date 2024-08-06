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

	tmp = env->next;
	while (env)
	{
		tmp = env->next;
		if (env->key)
			free(env->key);
		if (env->val)
			free(env->val);
		free(env);
		env = tmp;
	}
}

void	ft_exit(t_all *all)
{
	if (all->data)
		ft_free_data(all->data);
	if (all->env)
		ft_free_env(all->env);
	rl_clear_history();
	printf("exit\n");
	exit(EXIT_SUCCESS);
}