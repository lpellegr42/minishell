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

void	ft_set_pos(t_env *env)
{
	t_env	*tmp;
	t_env	*current;
	int		i;
	
	tmp = env;
	i = 0;
	while (tmp)
	{
		current = env;
		if (ft_strncmp(current->key, tmp->key, ft_strlen(current->key)) == 0)
				current = current->next;
		while (current)
		{
			while (current->key[i] == tmp->key[i])
				i++;
			if (tmp->key[i] > current->key[i])
				tmp->pos++;
			if (i != 0)
				i = 0;
			current = current->next;
			if (current && ft_strncmp(current->key, tmp->key, ft_strlen(current->key)) == 0)
				current = current->next;
		}
		tmp = tmp->next;
	}
}

void	ft_export(char *line, t_data *data, t_env *env)
{
	(void)data;
	(void)line;

	t_env	*tmp;
	int		i;
	
	ft_set_pos(env);
	tmp = env;
	i = 0;
	while (tmp)
	{
		if (tmp->pos == i && !(ft_strncmp(tmp->key, "_", 1) == 0))
		{
			if (tmp->set == 1)
				printf("declare -x %s=\"%s\"\n", tmp->key, tmp->val);
			else if (tmp->set == 2)
				printf("declare -x %s\n", tmp->key);
			i++;
			tmp = env;
		}
		else
			tmp = tmp->next;	
	}
}


// t_env *ft_sort_env(t_env **env)
// {
// 	t_env *tmp;
// 	int 	i;
	
// 	tmp = *env;
// 	i = 0;
// 	while (*env)
// 	{
// 		if (*env && (*env)->next && (*env)->key[i] == (*env)->next->key[i])
// 			i++;
// 		else if (*env && (*env)->next && (*env)->key[i] > (*env)->next->key[i])
// 		{
// 			// ft_print_list("1 : env", (*env));
// 			// ft_print_list("1 : (*env)", (*env));
// 			// ft_swap(env);
// 			if (i != 0)
// 				i = 0;
// 			*env = tmp;
// 			// ft_print_list("2 : env", tmp);
// 			// ft_print_list("2 : tmp", tmp);
// 		}
// 		else
// 		{
// 			if (i != 0)
// 				i = 0;
// 			*env = (*env)->next;
// 		}
// 	}
// 	return (tmp);
// }

// void	ft_export(char *line, t_data *data, t_env **env)
// {
// 	t_env	*env_sorted;
// 	(void)line;
// 	(void)data;
// 	// if (!data->arg)
// 	// {
// 		env_sorted = ft_sort_env(env);
// 		while (env_sorted)
// 		{
// 			if (ft_strncmp(env_sorted->key, "_", 1) == 0)
// 				env_sorted = env_sorted->next;
// 			else if (env_sorted->set == 1)
// 			{
// 				printf("declare -x %s=\"%s\"\n", env_sorted->key, env_sorted->val);
// 				env_sorted = env_sorted->next;
// 			}
// 			else if (env_sorted->set == 2)
// 			{
// 				printf("declare -x %s\n", env_sorted->key);
// 				env_sorted = env_sorted->next;
// 			}
// 			else
// 				env_sorted = env_sorted->next;
// 		}
// 	// }
// }
