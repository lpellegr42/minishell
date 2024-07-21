//#include "minishell.h"
#include "../../includes/minishell.h"

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
void	ft_print_export(t_env *env)
{
	t_env	*tmp;
	int		i;

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
void	ft_export(t_data *data, t_env *env)
{
	ft_set_pos(env);
	// if (!data->arg)
	// {
	if (ft_strncmp(data->cmd, "export", 6) == 0)
		ft_print_export(env);
	// }
}
