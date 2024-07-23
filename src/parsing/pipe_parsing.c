//#include "minishell.h"
#include "../../includes/minishell.h"

t_cmdtree	*parse_pipe(t_cmdtree *node)
{
	int pipe_pos;

	pipe_pos = search_pipe(node->str);
	if (pipe_pos == -1)
	{
		// next_parsing_step
		return (NULL); //secu for now
	}
	else //tester dans cas ou str[0] est un pipe -> segfault i think -> gerer ce cas
	{
		node->type = PIPE;
		node->part1 = init_node(my_substr(node->str, 0, pipe_pos));
		node->part2 = init_node(my_substr(node->str, pipe_pos + 1, my_strlen(node->str) - pipe_pos - 1)); //+1 ou -1 sur strlen		parse_pipe(node->part2);
		parse_pipe(node->part2);
		return(node);
		//next_parsing_step
	}
}

/* 
 * @brief Search for the a pipe char '|' in the given string.
 * @param test c'est test @param test1
 * @return 	Return the first pipe found in the given string, return -1 if none is found.
*/
int	search_pipe(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|' && str[i - 1] != '\\' /* && !quote_verif */ ) //add between quote verif.
			return (i);
		i++;
	}
	return (-1); //no pipe in the str.
}

