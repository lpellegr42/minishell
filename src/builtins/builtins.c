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
	// if (all->data->here_doc)
	// 	ft_heredoc(all->data->here_doc);
	if (ft_is_builtin(all->data->cmd))
		ft_builtins(all);
	else
		ft_docmd(all);
	// if (all->data->next)
	// 	all->data = all->data->next;
}

// void	ft_heredoc(char *str)
// {
// 	int		fd;
// 	char	*line;

// 	ulink(".tmp")
// 	fd = open(".tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	while (1)
// 	{
// 		line = readline(">");
// 		if (!line)
// 		{
// 			printf("here-document delimited by EOF (wanted '%s')\n", str);
// 			close(fd);
// 			free(line);
// 			return ;
// 		}
// 		if (ft_strncmp(line, str, ft_strlen(str)) == 0)
// 		{
// 			free(line);
// 			close(fd);
// 			return ;
// 		}
// 		write(fd, line, ft_strlen(line));
// 		write(fd, "\n", 1);
// 		free(line);
// 	}
// }

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
