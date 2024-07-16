#include "../includes/minishell.h"

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
	if (!env)
		env = new;
	else
	{
		last = ft_last_node(env);
		last->next = new;
	}
	return (env);
}
t_env	*ft_copy_env(t_env *env, char **envp)
{
	int	i;
	
	i = 0;
	while (envp[i])
	 	printf("%s\n", envp[i++]);
	i = 0;
	while (envp[i])
	{	
		env = ft_append_node(env, envp[i]);
		// printf("%s=%s\n", env->key, env->val);
		env = env->next;
		i++;
	}
	return (env);
}
