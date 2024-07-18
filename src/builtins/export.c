//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_print_list(char *str, t_env *lst)
{
	while (lst)
	{
		printf("%s, %s\n", str, lst->key);
		lst = lst->next;
	}
}

t_env *ft_sort_env(t_env **env)
{
	t_env *tmp;
	int 	i;
	
	tmp = *env;
	i = 0;
	while (*env)
	{
		if (*env && (*env)->next && (*env)->key[i] == (*env)->next->key[i])
			i++;
		else if (*env && (*env)->next && (*env)->key[i] > (*env)->next->key[i])
		{
			// ft_print_list("1 : env", (*env));
			// ft_print_list("1 : (*env)", (*env));
			ft_swap(env);
			if (i != 0)
				i = 0;
			// tmp = *env;
			// ft_print_list("2 : env", tmp);
			// ft_print_list("2 : tmp", tmp);
		}
		else
		{
			if (i != 0)
				i = 0;
			*env = (*env)->next;
		}
	}
	return (tmp);
}

void	ft_export(char *line, t_data *data, t_env **env)
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
