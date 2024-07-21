//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_unset(t_data *data, t_env *env)
{
	t_env	*tmp;
	int		i;
	
	tmp = env;
	i = 0;
	while (data->arg[i])
	{
		while (tmp)
		{
			if (ft_strncmp(tmp->key, data->arg[0], ft_strlen(data->arg[0])) == 0)
			{
				tmp->val = NULL;
				tmp->set = 0;
			}
			// if (ft_strncmp(tmp->key, line, ft_strlen(line)) == 0)
			// {
			// 	tmp->val = NULL;
			// 	tmp->set = 0;
			// }
			tmp = tmp->next;
		}
		i++;
	}
}
