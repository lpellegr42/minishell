//#include "minishell.h"
#include "../../includes/minishell.h"

void	parse_pipe(t_data *data)
{
	char	**parsed_line;
	int		pipe_pos;
	int		i;

	i = 0;
	pipe_pos = search_pipe(data->line);
	if (pipe_pos == -1)
		return ;
	else //tester dans cas ou str[0] est un pipe -> should work with split
	{
		parsed_line = shell_split(data->line, '|'); 
		while(parsed_line[i])
		{
			free(data->line);
			data->line = my_strdup(parsed_line[i]);
			i++;
			if (parsed_line[i] != NULL)
			{
				data->next = init_node();
				data = data->next;
			}
		}
		free_tab_tab(parsed_line);
	}
}

/**
 * @brief Search for the a pipe char '|' in the given string.
 * @return 	Return the position of the first pipe found in the given string. -1 if none is found.
*/
int	search_pipe(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|' && str[i - 1] != '\\' && !is_in_quote(str, i, 1))
			return (i);
		i++;
	}
	return (-1); //no pipe in the str.
}
