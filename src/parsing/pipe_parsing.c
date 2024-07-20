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
	else //tester dans cas ou str[0] est un pipe -> segfault i think
	{
		node->type = PIPE;
		node->part1 = init_node(my_substr(node->str, 0, pipe_pos - 1));
		node->part2 = init_node(my_substr(node->str, pipe_pos + 1, my_strlen(node->str) - pipe_pos)); //+1 ou -1 sur strlen		parse_pipe(node->part2);
		parse_pipe(node->part2);
		return(node);
		//next_parsing_step
	}
}

/* 
	Return the first pipe found in the given string, return -1 if none is found.
*/
int	search_pipe(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|') //add between quote verif.
			return (i);
		i++;
	}
	return (-1); //no pipe in the str.
}
	//TRASH

// t_cmdtree	*parse_pipe(t_cmdtree *node, char *str)
// {
// 	t_cmdtree	*first_node;
// 	char	*first_pipe_pos;
// 	t_cmdtree	*part1;
// 	t_cmdtree	*part2;
// 	/* put in conditional structure recursively. */
// 	/* strchr to found the first occurence of a pipe if there is one in the string */
// 	/* create two subtring of that and put them in the two part of my binary tree. */

// 	first_node = node;
// 	first_pipe_pos = ft_strchr(str, '|'); //faire fct, first pipe
// 	part1 = ft_substr(str, 0, );
// 	part2 = ft_substr();
// 	//Allocates and fill part1 and 2.
	
// 	return (node); //or first node.
// }

/*
	Split the given string in two substring :
	One before the first pipe, one after the first pipe.
	TODO: fct must return le node comprenant mes 2 chaines de caracteres splittés. A definir, test funct for now.
*/

// void	split_on_pipe(t_cmdtree *node, char *str)
// {
// 	char		*before_pipe;
// 	char		*after_pipe;
// 	t_cmdtree	*part1;
// 	t_cmdtree	*part2;
// 	int pipe_pos;

// 	pipe_pos = first_pipe_pos(str);
// 	if (pipe_pos == -1)
// 	{
// 		(printf("no_pipe\n"));
// 		return ; //printf, test purpose.
// 	}
// 	else
// 	{
// 		before_pipe = my_substr(str, 0, pipe_pos - 1);
// 		after_pipe = my_substr(str, pipe_pos + 1, my_strlen(str) - pipe_pos);
// 		// printf("\nbefore pipe:$%s$\n\n after pipe:$%s$\n\n", before_pipe, after_pipe);
// 		node->type = PIPE;
// 		part1 = init_node(before_pipe);
// 		part2 = init_node(after_pipe);
// 	}
// }
