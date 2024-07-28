//#include "minishell.h"
#include "../../includes/minishell.h"

char	*ft_key_copy(t_env *env, char *envp)
{
	int	i;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	env->key = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (envp[i] && envp[i] != '=')
	{
		env->key[i] = envp[i];
		i++;
	}
	env->key[i] = '\0';
	return (env->key);
}

char	*ft_val_copy(t_env *env, char *envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	if (envp[i] == '=')
		i++;
	env->val = malloc(sizeof(char) * ft_len(envp, i));
	j = 0;
	while (envp[i] && envp[i] != '\n')
	{
		env->val[j] = envp[i];
		i++;
		j++;
	}
	if (envp[i] == '\n')
	{
		env->val[j] = envp[i];
		i++;
		j++;
	}
	env->val[j] = '\0';
	return (env->val);
}

t_env	*ft_append_node(t_env *env, char *envp)
{
	t_env	*new;
	t_env	*last;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->key = ft_key_copy(new, envp);
	new->val = ft_val_copy(new, envp);
	new->set = 1;
	new->pos = 0;
	new->init = 0;
	if (!env)
		env = new;
	else
	{
		last = ft_last_node(env);
		last->next = new;
	}
	return (env);
}

void	ft_shlvl(t_env *env)
{
	t_env	*tmp;
	int		shlvl;

	shlvl = 0;
	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, "SHLVL", 5) == 0)
		{
			shlvl = ft_atoi(tmp->val);
			shlvl++;
			tmp->val = ft_itoa(shlvl);
		}
		tmp = tmp->next;
	}
}

t_env	*ft_copy_env(t_env *env, char **envp)
{
	int		i;
	t_env	*tmp;

	tmp = env;
	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "COLUMNS", 7) == 0 || ft_strncmp(envp[i], "LINES", 5) == 0))
			tmp = ft_append_node(tmp, envp[i]);
		i++;
	}
	ft_shlvl(tmp);
	return (tmp);
}
