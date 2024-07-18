//#include "minishell.h"
#include "../../includes/minishell.h"

t_cmdtree	*parse_pipe(t_cmdtree *node, char *str)
{
	t_cmdtree	*first_node;
	char	*first_pipe_pos;
	char	*part1;
	char	*part2;
	/* put in conditional structure recursively. */
	/* strchr to found the first occurence of a pipe if there is one in the string */
	/* create two subtring of that and put them in the two part of my binary tree. */

	first_node = node;
	first_pipe_pos = ft_strchr(str, '|'); //faire fct, first pipe
	part1 = ft_substr(str, 0, );
	part2 = ft_substr();
	//Allocates and fill part1 and 2.
	
	return (node); //or first node.
}

/* 
	Return the first pipe found in the given string, return -1 if none is found.
*/
int	pipe_pos(char *str)
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

void	split_on_pipe(t_cmdtree *node)
{
	int i;
	int pipe_pos;

	i = 0;
	if (pipe_pos == -1)
	{
		exit(EXIT_FAILURE);
		return(printf("no_pipe\n"));
	}
	else
	{
		ft_substr();
	}
}