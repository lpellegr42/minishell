//#include "minishell.h"
#include "../../includes/minishell.h"

int	ft_is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "env", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(cmd, "export", 6) == 0)
		return (1);
	else if (ft_strncmp(cmd, "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		return (1);
	else
		return (0);
}

/* @brief Runs the correct builtin or exec
 * @return Nothing
*/
void	ft_choose_cmd(t_all *all)
{
	int	fd_in;
	int	fd_out;

	fd_in = -1;
	fd_out = -1;
	if (all->data->delim)
		ft_heredoc(all->data->delim);
	// else if (all->data->fd_in != -1)
	// {
	// 	fd_in = open(/*fd_in*/, O_RDONLY);
	// 	dup2(fd_in, 0);
	// }
	// else if (all->data->fd_out != -1)
	// {
	// 	fd_out = ft_handle_out(all);
	// }
	if (ft_is_builtin(all->data->cmd))
		ft_builtins(all);
	else
		ft_docmd(all);
	if (fd_in != -1)
		close(fd_in);
	if (fd_out != -1)
		close(fd_out);
	// if (all->data->next)
	// 	all->data = all->data->next;
}


void	ft_builtins(t_all *all)
{
	if (ft_strncmp(all->data->cmd, "env", 3) == 0)
		ft_env(all->env);
	else if (ft_strncmp(all->data->cmd, "unset", 5) == 0)
		ft_unset(all->data, all->env);
	else if (ft_strncmp(all->data->cmd, "export", 6) == 0)
		ft_export(all);
	else if (ft_strncmp(all->data->cmd, "echo", 4) == 0)
		ft_echo(all);
	else if (ft_strncmp(all->data->cmd, "pwd", 3) == 0)
		ft_pwd(all);
	else if (ft_strncmp(all->data->cmd, "cd", 2) == 0)
		ft_cd(all);
	else if (ft_strncmp(all->data->cmd, "exit", 4) == 0)
		ft_exit(all);
}
