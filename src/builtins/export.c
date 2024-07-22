//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_reset_pos(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		tmp->pos = 0;
		tmp = tmp->next;
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

// void	ft_append_env(t_env *env, char *str)
// {

// }

void	ft_parse_export(t_env *env, char *str)
{
	// t_env	*tmp;
	(void)env;
	int i = 0;
	char	**pars;

	pars = ft_split(str, '=');
	while (pars[i])
	{
		printf("test : %s\n", pars[i]);
		i++;
	}
	// tmp = env;

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
	int	i;

	i = 0;
	ft_reset_pos(env);
	ft_set_pos(env);
	if (!data->arg)
			ft_print_export(env);
	else
	{
		while (data->arg[i])
		{
			ft_parse_export(env, data->arg[i]);
			i++;
			// ft_append_env(env, arg[i]);
		}
	}
}
