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
	else //if (parse pipe)
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
	//else if (parse_pipe == -1)
	// parse redir dans cas de pipe.
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
	return	(-1); //no pipe in the str.
}

int check_start_pipe(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_whitespace(line[i]))
		i++;
	if (line[i] == '|')
		return (1);
	return (0);
}

int check_middle_pipes(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '|')
		{
			int j = i - 1;
			while (j >= 0 && is_whitespace(line[j]))
				j--;
			if (j < 0 || line[j] == '|')
				return (1);
			j = i + 1;
			while (is_whitespace(line[j]))
				j++;
			if (line[j] == '|' || line[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int check_end_pipe(char *line)
{
    int i = ft_strlen(line) - 1;

    while (i >= 0 && is_whitespace(line[i]))
        i--;
    if (line[i] == '|')
        return (1);
    return (0);
}
