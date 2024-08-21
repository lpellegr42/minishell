//#include "minishell.h"
#include "../../includes/minishell.h"


// t_cmdtree	*parse_pipe(t_cmdtree *node)
// {
// 	int pipe_pos;

// 	pipe_pos = search_pipe(node->str);
// 	if (pipe_pos == -1)
// 	{
// 		// next_parsing_step (in main parse funct)
// 		return (NULL);
// 	}
// 	else //tester dans cas ou str[0] est un pipe -> should work with split
// 	{
// 		node->type = PIPE;
// 		//(free) la data de base
// 		node->str = init_node(my_substr(node->str, 0, pipe_pos));
// 		node->part2 = init_node(my_substr(node->str, pipe_pos + 1, my_strlen(node->str) - pipe_pos - 1)); //+1 ou -1 sur strlen		parse_pipe(node->part2);
// 		parse_pipe(node->part2);
// 		return(node);
// 		//next_parsing_step
// 	}
// }

void	parse_pipe(t_data *node)
{
	char *temp;
	int pipe_pos;

	temp = NULL;
	pipe_pos = search_pipe(node->line);
	if (pipe_pos == -1)
	{
		if (temp)
			free(temp);
		return ;
	}
	else //tester dans cas ou str[0] est un pipe -> should work with split
	{
		temp = my_strdup(node->line);
		//node->type = PIPE;
		free(node->line);
		node->line = my_substr(temp, 0, pipe_pos);
		node->next = init_node();
		node->next->line = my_substr(temp, pipe_pos + 1, my_strlen(temp) - pipe_pos - 1);
		//HANDLE FD
		free (temp);
		return ;
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
// /**
//  * Return 1 on error, 0 if it's ok.
//  */
// int empty_pipe_check(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] != '|')
// 	{
// 		if (i > 0 && is_only_whitespace(line, 0, i - 1))
// 				return (1);
// 	}
// 	while(line[i])
// 	{
// 		if (line[i] == '|')
// 		{
// 			while (line[i] && is_whitespace(line[i]))
// 				i++;
// 			if (line[j] == '\0' || line[i] == '\n' || line[j] == '|')
// 				return (1);
// 		}
// 		i++;
// 	}
// }



