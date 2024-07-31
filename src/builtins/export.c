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
	while (tmp)
	{
		current = env;
		while (ft_strncmp(current->key, tmp->key, ft_strlen(tmp->key)) == 0 ||
			ft_strncmp(current->key, "_", 1) == 0)
			current = current->next;
		while (current)
		{
			i = 0;
			while (current && current->key[i] == tmp->key[i])
				i++;
			if (current && tmp->key[i] > current->key[i])
				tmp->pos++;
			current = current->next;
			while (current && (ft_strncmp(current->key, tmp->key, ft_len(tmp->key, 0)) == 0 ||
				ft_strncmp(current->key, "_", 1) == 0))
				current = current->next;
		}
		tmp = tmp->next;
	}
}

void	ft_parse_export(t_env *env, char *str)
{
	t_env	*tmp;
	char	**pars;

	pars = ft_split_export(str, '=');
	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, pars[0], ft_strlen(pars[0])) == 0)
		{
			if (pars[1])
			{
				tmp->val = ft_strdup(pars[1]);
				tmp->set = 1;
			}
			else
				tmp->set = 2;
			break ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		tmp = ft_append_env(env, pars);
}

void	ft_print_export(t_env *env)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	i = 0;
	while (tmp)
	{
		if (tmp->pos == i && !(ft_strncmp(tmp->key, "_", ft_strlen(tmp->key)) == 0))
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
			if (!ft_isvalid(data->arg[i]))
			{
				red();
				printf("bash: export : '%s': not a valid identifier\n", data->arg[i]);
				reset();
			}
			ft_parse_export(env, data->arg[i]);
			i++;
		}
	}
}
