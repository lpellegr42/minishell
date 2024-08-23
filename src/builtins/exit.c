//#include "minishell.h"
#include "../../includes/minishell.h"

/* @brief Frees the data nodes.
 * @return Nothing
*/
void	ft_free_data(t_data *data)
{
	t_data	*temp;

	if (!data)
		return ;
	while (data)
	{
		if (data->line)
		{
			free(data->line);
			data->line = NULL;
		}
		if (data->arg)
			free_tab_tab(data->arg);
		if (data->cmd)
		{
			free(data->cmd);
			data->cmd = NULL;
		}
		if (data->here_doc)
		{
			free(data->here_doc);
			data->here_doc = NULL;
		}
		temp = data->next;
		free(data);
		data = NULL;
		data = temp;
	}
}

// void	free_single_data_node(t_data *data)
// {
// 	if (data->line)
// 		{
// 			free(data->line);
// 			data->line = NULL;
// 		}
// 		if (data->arg)
// 			free_tab_tab(data->arg);
// 		if (data->cmd)
// 		{
// 			free(data->cmd);
// 			data->cmd = NULL;
// 		}
// 		if (data->here_doc)
// 		{
// 			free(data->here_doc);
// 			data->here_doc = NULL;
// 		}
// 		free(data);
// 		data = NULL;
// }

/* @brief Frees environments nodes
 * @return Nothing
*/
void	ft_free_env(t_env *env)
{
	t_env	*tmp;

	tmp = env->next;
	while (env)
	{
		tmp = env->next;
		if (env->key)
			free(env->key);
		if (env->val)
			free(env->val);
		free(env);
		env = tmp;
	}
}

/* @brief Exits properly the program. Free the structs.
 * @return Nothing
*/
void	ft_exit(t_all *all)
{
	int ret;
	if (all->data)
	{
		if (ft_strncmp(all->data->cmd, "exit", 5) == 0 && all->data->arg)
		{
			ret = ft_atoi(all->data->arg[0]);
			if (ret > 256)
				ret = ret % 256;
			all->err = ret;
		}
		ft_free_data(all->data);
	}
	if (all->env)
		ft_free_env(all->env);
	if (all->env_cpy)
		ft_free_tab(all->env_cpy);
	rl_clear_history();
	printf("exit\n");
	exit(all->err);
}
