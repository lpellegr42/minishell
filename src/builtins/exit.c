//#include "minishell.h"
#include "../../includes/minishell.h"

/* @brief Frees the data nodes.
 * @return Nothing
*/
void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	// while (data)
	// {
	// if (data->str)
	// 	free(data->str);
	if (data->arg)
		free_tab_tab(data->arg);
	if (data->cmd)
		free(data->cmd);
	if (data->here_doc)
		free(data->here_doc);
	free(data);
	data = NULL;
		// data = data->next;
	// }
}

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

	ret = 0;
	if (all->data)
	{
		if (ft_strncmp(all->data->cmd, "exit", 5) == 0 && all->data->arg)
			ret = ft_atoi(all->data->arg[0]);
		ft_free_data(all->data);
	}
	if (all->env)
		ft_free_env(all->env);
	if (all->env_cpy)
		ft_free_tab(all->env_cpy);
	rl_clear_history();
	printf("exit\n");
	exit(ret);
}
