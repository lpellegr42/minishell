#include "../../includes/minishell.h"

void	open_fd(t_data *data, char *file, int flag)
{
	int		type;

	if (flag == 0)
	{
		data->flag_out = 2;
		type = O_RDWR | O_CREAT | O_TRUNC;
		data->fd_out = open(file, type, 0777);
	}
	if (flag == 1)
	{
		data->flag_out = 1;
		data->fd_in = open(file, type, 0777);
		type = O_RDWR | O_CREAT | O_APPEND;

	}
	else if (flag == 2)
	{
		type = O_RDONLY;
		data->fd_in = open(file, type, 0777);
	}
}

/**
 * @brief Handle the file opening according to
 * 	the redirections and here_doc parsing.
 * @param flag 
 */
void	handle_redir(t_data	*data, int i, int flag)
{

	char	*file;

	if (data->arg[i + 1])
	{
		file = data->arg[i + 1];
		open_fd(data, file, flag);
	}
}

void	handle_redir_arg(t_data *data, int i)
{
	if (data->arg[i][0] == '>')
	{
		if (data->arg[i][1])
		{
			printf("handle_double_redir_out\n");
			handle_redir(data, i, 0);
		}
		else
		{
			printf("handle_simple_redir_out\n");
			handle_redir(data, i, 1);
		}
	}
	else if (data->arg[i][0] == '<')
	{
		if (data->arg[i][1])
		{
			data->delim = my_strdup(data->arg[i + 1]);
			printf("handle_here_doc\n");
			//handle here_doc_funct to add
		}
		else
		{
			printf("handle_simple_redir_in\n");
			handle_redir(data, i, 2);
		}
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
