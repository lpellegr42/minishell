//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_unset(t_data *data, t_env *env)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	i = 0;
	if (!data->arg)
		return ;
	while (data->arg[i])
	{
		tmp = env;
		while (tmp)
		{
			if (ft_strncmp(tmp->key, data->arg[i], ft_strlen(tmp->key)) == 0)
			{
				tmp->val = NULL;
				tmp->set = 0;
			}
			tmp = tmp->next;
		}
		i++;
	}
}
