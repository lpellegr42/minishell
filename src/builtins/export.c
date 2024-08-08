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
		while (!ft_check_node(current->key, tmp->key))
			current = current->next;
		while (current)
		{
			i = 0;
			while (current && current->key[i] == tmp->key[i])
				i++;
			if (current && tmp->key[i] > current->key[i])
				tmp->pos++;
			current = current->next;
			while (current && !ft_check_node(current->key, tmp->key))
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
	free_tab(pars);
}

void	ft_print_export(t_env *env)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	i = 0;
	while (tmp)
	{
		if (tmp->pos == i && ft_check_node(tmp->key, NULL))
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

void	ft_export(t_all *all)
{
	int	i;

	i = 0;
	ft_reset_pos(all->env);
	ft_set_pos(all->env);
	if (!all->data->arg)
		ft_print_export(all->env);
	else
	{
		while (all->data->arg[i])
		{
			if (!ft_isvalid(all->data->arg[i]))
			{
				red();
				printf("bash: export : '%s'", all->data->arg[i]);
				ft_display_err(": not a valid identifier\n", all, 1);
			}
			ft_parse_export(all->env, all->data->arg[i]);
			i++;
		}
	}
	all->err = 0;
}
