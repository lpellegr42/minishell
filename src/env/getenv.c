//#include "minishell.h"
#include "../../includes/minishell.h"

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
