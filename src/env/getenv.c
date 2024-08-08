//#include "minishell.h"
#include "../../includes/minishell.h"

char	*ft_join(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		newstr[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (free(s1), newstr);
}

t_env	*ft_append_env(t_env *env, char **str)
{
	t_env	*new;
	t_env	*last;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->key = ft_strdup(str[0]);
	if (str[1])
	{
		new->val = ft_strdup(str[1]);
		new->set = 1;
	}
	else
	{
		new->val = NULL;
		new->set = 2;
	}
	new->pos = 0;
	last = ft_last_node(env);
	last->next = new;
	return (env);
}

void	ft_modify_env(char *s1, char *s2, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(s1, tmp->key, ft_strlen(s1)) == 0)
		{
			free(tmp->val);
			tmp->val = ft_strdup(s2);
			return ;
		}
		tmp = tmp->next;
	}
}

char	*ft_getenv(char *str, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(str, tmp->key, ft_strlen(str)) == 0)
			return (tmp->val);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_reset_env(t_all *all)
{
	int		i;
	t_env	*tmp;

	if (all->env_cpy)
		free_tab(all->env_cpy);
	all->env_cpy = malloc(sizeof(char *) * (ft_lstsize(all->env) + 1));
	i = 0;
	tmp = all->env;
	while (tmp)
	{
		all->env_cpy[i] = ft_strdup(tmp->key);
		if (tmp->val)
		{
			all->env_cpy[i] = ft_join(all->env_cpy[i], "=");
			all->env_cpy[i] = ft_join(all->env_cpy[i], tmp->val);
		}
		tmp = tmp->next;
		i++;
	}
	all->env_cpy[i] = NULL;
}
