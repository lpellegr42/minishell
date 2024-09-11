#include "../../includes/minishell.h"

void	open_fd(t_data *data, char *file, int type, int flag)
{
	if (flag == 0)
	{
		data->fd = open(file, type, 0777);
	}
	else if (flag == 1)
		data->fd = open(file, type, 0777);
	else if (flag == 2)
		data->fd = open(file, type, 0777);
}

/**
 * @brief Handle the file opening according to
 * 	the redirections and here_doc parsing.
 * @param flag 
 */
void	handle_redir(t_data	*data, int i, int flag)
{
	char	*file;
	int		type;

	if (data->arg[i + 1])
		file = data->arg[i + 1];
	if (flag == 0)
	{
		data->flag_redir = 1;
		type = O_RDWR | O_CREAT | O_TRUNC;
	}
	else if (flag == 1)
	{
		data->flag_redir = 1;
		type = O_RDWR | O_CREAT | O_APPEND;
	}
	else if (flag == 2)
	{
		data->flag_redir = 0;
		type = O_RDONLY;
	}
	if (data->fd > 2)
		close(data->fd);
	if (data->arg[i + 1])
		open_fd(data, file, type, flag);
}

void	handle_redir_arg(t_data *data, int i)
{
	if (data->arg[i][0] == '>')
	{
		if (data->arg[i][1])
			handle_redir(data, i, 0);
		else
			handle_redir(data, i, 1);
	}
	else if (data->arg[i][0] == '<')
	{
		if (data->arg[i][1])
		{
			data->flag_redir = 0;
			data->fd = ft_heredoc(data->arg[i + 1]);
		}
		else
			handle_redir(data, i, 2);
	}

	data->arg = array_remove_at(data->arg, i + 1);
	data->arg = array_remove_at(data->arg, i);
}

void	parse_redir(t_data *data)
{
	int	i;

	i = 0;
	while (data->arg && data->arg[i])
	{
		if (is_redir(data->arg[i][0]))
			handle_redir_arg(data, i);
		else
			i++;
	}
}
