#include "../../includes/minishell.h"

void	handle_redir_arg(t_data *data, int i)
{
	if (data->arg[i][0] == '>')
	{
		if (data->arg[i][1])
			printf("handle_double_redir_out\n");
		else
			printf("handle_simple_redir_out\n");
	}
	else if (data->arg[i][0] == '<')
	{
		if (data->arg[i][1])
			printf("handle_here_doc\n");
		else
			printf("handle_simple_redir_in\n");
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
