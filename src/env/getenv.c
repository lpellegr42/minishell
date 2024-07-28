//#include "minishell.h"
#include "../../includes/minishell.h"

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
