/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:29:02 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:29:03 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exec_cmd(char *path, char **args, char **env, t_all *all)
{
	int		ret;
	pid_t	pid;

	pid = 0;
	ret = 0;
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, env) == -1)
		{
			printf("-Minishell: %s: ", all->data->cmd);
			ft_display_err("command not found\n", all, 127);
			exit(all->err);
		}
	}
	else
	{
		waitpid(pid, &ret, 0);
		all->err = (ret >> 8);
	}
}

void	ft_docmd(t_all *all)
{
	char	*path;
	char	**args;
	char	**envp;

	envp = ft_reset_env(all->env);
	path = ft_getpath(all->data->cmd, envp);
	if (!path)
	{
		printf("-Minishell: %s: ", all->data->cmd);
		ft_display_err("Command not found\n", all, 127);
		ft_free_tab(envp);
		return ;
	}
	args = ft_get_args(path, all->data->arg);
	ft_exec_cmd(path, args, envp, all);
	free(path);
	ft_free_tab(args);
	ft_free_tab(envp);
	all->err = 0;
}

// void	ft_exec(t_all *all)
// {
// 	t_data	*tmp;

// 	if (!all->data->cmd)
// 		return ;
// 	tmp = all->data;
// 	ft_do_pipe(all);
// 	all->data = tmp;
// 	if (all->data->cmd != NULL)
// 		ft_free_data(all->data);
// }

void	ft_exec(t_all *all)
{
	t_data	*tmp;

	if (!all->data->cmd)
		return ;
	if (all->data->cmd != NULL && all->data->next == NULL)
	{
		if (all->data->fd != -1 && all->data->flag_redir != -1)
		{
			if (all->data->flag_redir == 0)
				ft_handle_in(all);
			else if (all->data->flag_redir == 1)
				ft_handle_out(all);
		}
		else
			ft_choose_cmd(all);
	}
	else
	{
		tmp = all->data;
		ft_do_pipe(all);
		all->data = tmp;
	}
	if (all->data->cmd != NULL)
		ft_free_data(all->data);
}
