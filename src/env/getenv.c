//#include "minishell.h"
#include "../../includes/minishell.h"

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
