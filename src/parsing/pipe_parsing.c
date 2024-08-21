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

// int empty_pipe_check(char *str)
// {

// }



