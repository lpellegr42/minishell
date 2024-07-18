#include "minishell.h"

t_env *ft_sort_env(t_env *env)
{
	t_env	*tmp;
	int 	i;
	
	tmp = env;
	i = 0;
	while (tmp)
	{
		while (tmp && tmp->next && tmp->key[i] == tmp->next->key[i])
			i++;
		if (tmp && tmp->next && tmp->key[i] > tmp->next->key[i])
		{
			ft_swap(&tmp);
			if (i != 0)
				i = 0;
			tmp = env;
		}
		else
		{
			if (i != 0)
				i = 0;
			tmp = tmp->next;
		}
	}
	return (env);
}

void	ft_export(char *line, t_data *data, t_env *env)
{
	t_env	*env_sorted;
	(void)line;
	(void)data;
	// if (!data->arg)
	// {
		env_sorted = ft_sort_env(env);
		while (env_sorted)
		{
			if (ft_strncmp(env_sorted->key, "_", 1) == 0)
				env_sorted = env_sorted->next;
			else if (env_sorted->set == 1)
			{
				printf("declare -x %s=\"%s\"\n", env_sorted->key, env_sorted->val);
				env_sorted = env_sorted->next;
			}
			else if (env_sorted->set == 2)
			{
				printf("declare -x %s\n", env_sorted->key);
				env_sorted = env_sorted->next;
			}
			else
				env_sorted = env_sorted->next;
		}
	// }
}
