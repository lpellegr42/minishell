//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_free1(t_data *data)
{
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
	}
	if (data->cmd)
	{
		free(data->cmd);
		data->cmd = NULL;
	}
	if (data->arg)
		free_tab_tab(data->arg);
}

void	ft_free2(t_data *data)
{
	if (data->delim)
	{
		free(data->delim);
		data->delim = NULL;
	}
	if (data->redir_in)
	{
		free(data->redir_in);
		data->redir_in = NULL;
	}
	if (data->redir_out)
	{
		free(data->redir_out);
		data->redir_out = NULL;
	}
}

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
		ft_free1(data);
		ft_free2(data);
		close(data->fd_in);
		close(data->fd_out);
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
// 		if (data->delim)
// 		{
// 			free(data->delim);
// 			data->delim = NULL;
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
	int	ret;

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
	rl_clear_history();
	printf("exit\n");
	exit(all->err);
}
