//#include "minishell.h"
#include "../../includes/minishell.h"

/* @brief Unset environment variables given in parameter.
 * @return Nothing
*/
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
				free(tmp->val);
				tmp->val = NULL;
				tmp->set = 0;
			}
			tmp = tmp->next;
		}
		i++;
	}
}
